#pragma once

#include <Windows.h>
#include <iostream>
#include <string>

/**
* Funkcja konwertujaca z formatu USI na format europejski i na opak.
* @param ruch - string konwertowanego ruch
* @return string przekonwartowanego ruchu
*/
std::string konwersjaRuchuGraUSISilnik(std::string ruch) {
    // ruch np.: a4a3
    std::string tmp;
    char tmp2[2] = { ' ' };
    int size = 0;

    // zamiana miejscami kol i wier
    if (ruch[1] == '*') {
        tmp = ruch.substr(3, 1) + ruch.substr(2, 1);
    }
    else {
        tmp = ruch.substr(1, 1) + ruch.substr(0, 1) + ruch.substr(3, 1) + ruch.substr(2, 1);
    }

    if (ruch[4] == '+') {
        tmp += "+";
    }

    // sprawdzenie jakie literzy trzeba zamieniæ
    if (tmp.find('a') != std::string::npos) tmp2[size++] = 'a';
    if (tmp.find('b') != std::string::npos) tmp2[size++] = 'b';
    if (tmp.find('c') != std::string::npos) tmp2[size++] = 'c';
    if (tmp.find('d') != std::string::npos) tmp2[size++] = 'd';
    if (tmp.find('f') != std::string::npos) tmp2[size++] = 'f';
    if (tmp.find('g') != std::string::npos) tmp2[size++] = 'g';
    if (tmp.find('h') != std::string::npos) tmp2[size++] = 'h';
    if (tmp.find('i') != std::string::npos) tmp2[size++] = 'i';

    // zamiana 
    if (tmp2[0] == 'a' || tmp2[1] == 'a') {
        std::replace(tmp.begin(), tmp.end(), 'a', 'i'); // zamieñ 'a' na 'i'
    }
    if (tmp2[0] == 'b' || tmp2[1] == 'b') {
        std::replace(tmp.begin(), tmp.end(), 'b', 'h'); // zamieñ 'b' na 'h'
    }
    if (tmp2[0] == 'c' || tmp2[1] == 'c') {
        std::replace(tmp.begin(), tmp.end(), 'c', 'g'); // zamieñ 'c' na 'g'
    }
    if (tmp2[0] == 'd' || tmp2[1] == 'd') {
        std::replace(tmp.begin(), tmp.end(), 'd', 'f'); // zamieñ 'd' na 'f'
    }
    if (tmp2[0] == 'f' || tmp2[1] == 'f') {
        std::replace(tmp.begin(), tmp.end(), 'f', 'd'); // zamieñ 'f' na 'd'
    }
    if (tmp2[0] == 'g' || tmp2[1] == 'g') {
        std::replace(tmp.begin(), tmp.end(), 'g', 'c'); // zamieñ 'g' na 'c'
    }
    if (tmp2[0] == 'h' || tmp2[1] == 'h') {
        std::replace(tmp.begin(), tmp.end(), 'h', 'b'); // zamieñ 'h' na 'b'
    }
    if (tmp2[0] == 'i' || tmp2[1] == 'i') {
        std::replace(tmp.begin(), tmp.end(), 'i', 'a'); // zamieñ 'i' na 'a'
    }

    // zamiana miejscami kol i wier
    if (ruch[1] == '*') {
        tmp.insert(0, ruch, 0, 2);
    }


    return tmp;
}

/**
* Klasa silnika Shogi. Klasa silnika programu oraz jego polaczenia.
*/
class botShogi {
private:
    /* Informacje po³aczenia z programem (poni¿ej w private) */
    PROCESS_INFORMATION pi = { 0 };
    STARTUPINFO sti = { 0 };
    SECURITY_ATTRIBUTES sats = { sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };
    HANDLE pipin_w, pipin_r, pipout_w, pipout_r;
    char buffer[5000];
    DWORD writ, read, available;


public:
    std::string ruchyUSI; /*!< String przetrzymujacy w formacie USI wykonane ruchy */

    /**
    * Destruktor zamykajacy polaczenie i program
    */
    ~botShogi() {
        WriteFile(pipin_w, "quit\n", 5, &writ, NULL);
        if (pipin_w != NULL) CloseHandle(pipin_w);
        if (pipin_r != NULL) CloseHandle(pipin_r);
        if (pipout_w != NULL) CloseHandle(pipout_w);
        if (pipout_r != NULL) CloseHandle(pipout_r);
        if (pi.hProcess != NULL) CloseHandle(pi.hProcess);
        if (pi.hThread != NULL) CloseHandle(pi.hThread);
    }

    /**
    * Konstruktor bezargumentowy inicjujacy polaczenie (pipy) oraz sam program slinika
    */
    botShogi() {

        ruchyUSI = "";
        pipin_w = pipin_r = pipout_w = pipout_r = NULL;
        writ = read = available = 0;

        bool ok1 = CreatePipe(&pipin_r, &pipin_w, &sats, 0);
        bool ok2 = CreatePipe(&pipout_r, &pipout_w, &sats, 0);

        sti.dwFlags = STARTF_USESTDHANDLES;
        sti.wShowWindow = SW_HIDE;
        sti.hStdInput = pipin_r; // redirect input do pipin_r
        sti.hStdError = pipout_w;
        sti.hStdOutput = pipout_w;  // redirect stdout do pipout_w

        wchar_t silnikBot[] = L"LaramieV3.exe";

        bool ok3 = CreateProcess(NULL, silnikBot, NULL, NULL, TRUE, /*CREATE_NEW_CONSOLE*/ 0, NULL, NULL, &sti, &pi); // Start the child process.
    }

    /**
    * Metoda inicjujaca poczatkowe komendy do poprawnego dzialania silnika (rozpoczecia gry na silniku)
    */
    void startBotNewGame() {
        WriteFile(pipin_w, "isready\n", 8, &writ, NULL); // wpisanie do pipin_w
        Sleep(200); // czekanie a¿ isready sie wykona
        WriteFile(pipin_w, "usinewgame\n", 11, &writ, NULL); // wpisanie do pipin_w
    }

    /**
    * Metoda umozliwiajaca komunikajce z silnikiem (USI) i zwaracajaca bestmove
    * @param position - komenda przekazana do silnika np.: "go depth 7", "position startpos moves"
    * @return - wyciete cztery pierwsze znaki po "bestmove " od silnika
    */
    std::string getNextMove(std::string position) {

        std::string str, tmp;
        size_t n = -1;

        bool tmpWrite = WriteFile(pipin_w, position.c_str(), position.length(), &writ, NULL); // wpisanie do pipin_w
        Sleep(200);

        bool tmp1 = PeekNamedPipe(pipout_r, NULL, 0, NULL, &available, NULL); // zagladanie do pipe pipout_r
        if (tmp1 && available <= sizeof(buffer) && available != 0) {
            ZeroMemory(buffer, sizeof(buffer));
            bool tm = ReadFile(pipout_r, &buffer, sizeof(buffer), &read, NULL);
            //puts(buffer); // aby zobaczyæ wynik co siê poda³o odp od bota
            buffer[read] = '\0';
            tmp += (char*)buffer;
            n = tmp.find("bestmove");
            if (n != -1) str = tmp.substr(n + 9, 5);
        }
        return str;
    }

    /**
    * Metoda uaktualnia silnik/program o pozycje w jakiej znadjuje sie rozgrywka (uzywane podczas normalnego ruchu).
    * @param wybor - tablica char[4] ktora przetrzymuje infomracje o ruchu ktory zostal wykonany
    * @param pozycja_startowa - pozycja startowa (nowa gra to startpos a z wczytanego to SFEN jakis)
    */
    void podaj_aktualna_pozycje(char wybor[4], std::string pozycja_startowa) {

        std::string ruch_z, ruch_na;
        ruch_z += wybor[0];
        ruch_z += wybor[1];
        ruch_na += wybor[2];
        ruch_na += wybor[3];
        std::string graczmov = ruch_z + ruch_na;
        std::string Graczmove = konwersjaRuchuGraUSISilnik(graczmov);
        ruchyUSI += Graczmove + " ";
        std::string ustawiniepozycji1 = getNextMove("position " + pozycja_startowa + " moves " + ruchyUSI + "\n");

    }

    /**
    * Metoda uaktualnia silnik/program o pozycje w jakiej znadjuje sie rozgrywka (uzywane podczas zrzutki).
    * @param wybor - tablica char[3] ktora przetrzymuje infomracje o ruchu ktory zostal wykonany
    * @param pozycja_startowa - pozycja startowa (nowa gra to startpos a z wczytanego to SFEN jakis)
    */
    void podaj_aktualna_pozycje_zrzutka(char wybor[3], std::string pozycja_startowa) {

        std::string ruch_z, ruch_na;
        ruch_z += wybor[0];
        ruch_z += "*";
        ruch_na += wybor[2];
        ruch_na += wybor[3];
        std::ranges::transform(ruch_z.begin(), ruch_z.end(), ruch_z.begin(), ::toupper);
        std::string graczmov = ruch_z + ruch_na;
        std::string Graczmove = konwersjaRuchuGraUSISilnik(graczmov);
        ruchyUSI += Graczmove + " ";
        std::string ustawiniepozycji1 = getNextMove("position " + pozycja_startowa + " moves " + ruchyUSI + "\n");

    }

};
