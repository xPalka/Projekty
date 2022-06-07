module;

#include <iostream>
#include <string>
#include <regex>
#include <ranges>
#include <fstream>
#include <filesystem>
#include <thread>
#include <future>

export module SFEN_USI_gra;

export import interfejs_urzytkowinka;


#pragma region grupa_SFEN-USI

/**
* Funkcja konwertujaca figury do zrzutki do formatu SFEN.
* @param fig_gracz - string konwertownaych figur gracza
* @return string przekonwertowanych figur gracza na SFEN
*/
export std::string sumFigury(std::string fig_gracz) {
    int count_ilosc = 0;
    std::string temep = "";
    if (fig_gracz.empty()) return "";
    else if (fig_gracz.length() == 1) return fig_gracz;

    fig_gracz += " ";

    for (int i = 1; i < fig_gracz.length(); i++) {
        char tmp = fig_gracz[i - 1];
        char tmp2 = fig_gracz[i];
        count_ilosc++;
        if (tmp != tmp2) {
            if (count_ilosc > 1) {
                temep += std::to_string(count_ilosc);
                temep += tmp;
            }
            else {
                temep += tmp;
            }
            count_ilosc = 0;
        }
        else {
            if (i == fig_gracz.length() - 1) count_ilosc++;
            if (count_ilosc > 1 && i == fig_gracz.length() - 1) {
                temep += std::to_string(count_ilosc);
                temep += tmp2;
            }
        }
    }

    return temep;
}

/**
* Funkcja konwertujaca na SFEN foramt plansze gey.
* @param odcz - ifstream odczytu pliku
* @return string przekonwartowanej planszy na SFEN
*/
export std::string planszaToSFEN(std::ifstream& odcz) {

    std::string wynik_lini[9] = { "" };
    std::string linia;
    int m = 8;
    for (int i = 0; i < 9; i++) {
        std::getline(odcz, linia);

        reverse(linia.begin(), linia.end()); // obrot bo zmiana z formatu eu na jap
        for (int k = 0; k < 18; k += 2) {
            int z = (k + 2);
            reverse(linia.begin() + k, linia.begin() + z);
        }

        int ilosc_pustych = 0;
        for (int j = 0; j < 18; j++) {
            if (linia[j] == ' ') {
                ilosc_pustych++;
                j++;
                if (j == 17) wynik_lini[m] += std::to_string(ilosc_pustych);// dodaj do string te puste
            }
            else if (linia[j] == '1') {
                // czarne czyli duze
                if (ilosc_pustych != 0) {
                    wynik_lini[m] += std::to_string(ilosc_pustych);// dodaj do string te puste
                    ilosc_pustych = 0;
                }
                j++;
                if (isupper(linia[j]) && linia[j] != 'K') wynik_lini[m] += "+";
                wynik_lini[m] += toupper(linia[j]);

            }
            else if (linia[j] == '2') {
                // biale czyli male
                if (ilosc_pustych != 0) {
                    wynik_lini[m] += std::to_string(ilosc_pustych);// dodaj do string te puste
                    ilosc_pustych = 0;
                }
                j++;
                if (isupper(linia[j]) && linia[j] != 'K') wynik_lini[m] += "+";
                wynik_lini[m] += tolower(linia[j]);
            }
        }

        m--;
    }

    std::string wynik = wynik_lini[0] + "/" + wynik_lini[1] + "/" + wynik_lini[2] + "/" + wynik_lini[3] + "/" + wynik_lini[4] + "/" + wynik_lini[5] + "/" + wynik_lini[6] + "/" + wynik_lini[7] + "/" + wynik_lini[8];
    return wynik;
}

/**
* Funkcja konwertujaca figury do zrzutki do formatu SFEN.
* @param odcz - ifstream odczytu pliku
* @return string przekonwertowanych figur gracza na SFEN
*/
export std::string figuryGraczyToSFEN(std::ifstream& odcz) {

    std::string fig_gracz1 = "";
    std::string fig_gracz2 = "";
    std::getline(odcz, fig_gracz1);
    std::getline(odcz, fig_gracz2);

    if (!fig_gracz1.empty()) {
        std::ranges::transform(fig_gracz1.begin(), fig_gracz1.end(), fig_gracz1.begin(), ::toupper);
        sortByPattern(fig_gracz1, "RBGSNLP"); // posortowanie wed³ug formatu SFEN
    }
    if (!fig_gracz2.empty()) {
        sortByPattern(fig_gracz2, "rbgsnlp"); // posortowanie wed³ug formatu SFEN
    }

    if (fig_gracz1.empty() && fig_gracz2.empty()) {
        fig_gracz1 = "-";
    }
    else {
        fig_gracz1 = sumFigury(fig_gracz1);
        fig_gracz2 = sumFigury(fig_gracz2);
        // jezeli jest kilka takich samych to dodac przed liczbe tej ilosci  
    }

    std::string figury_graczSFEN = fig_gracz1 + fig_gracz2; // gotowy string figurgraczy w formacie SFEN
    return figury_graczSFEN;
}

/**
* Funkcja skladajace czesci konwertujaych funkcji do jednego calego formatu SFEN.
* @param siezka - path pliku z jakiego odczytujemy
* @return string calej sciezki SFEN gotowy do podania do programu
*/
export std::string graToSFEN(std::filesystem::path siezka) {

    std::ifstream odcz(siezka);

    std::string figuryGraczow = "";
    std::string planszaSFEN = "";
    std::string player = "";

    figuryGraczow = figuryGraczyToSFEN(odcz);
    planszaSFEN = planszaToSFEN(odcz);

    std::getline(odcz, player);
    if (player == "1") player = "b"; // czarne
    else if (player == "2") player = "w"; // biale

    std::string tmp = "sfen " + planszaSFEN + " " + player + " " + figuryGraczow;

    odcz.close();
    return tmp;
}

#pragma endregion grupa_SFEN-USI