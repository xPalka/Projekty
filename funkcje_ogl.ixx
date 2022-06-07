module;

#include <iostream>
#include <string>
#include <regex>

export module funkcje_ogl;


export import krol;

#pragma region funkcje_ogl

/**
* Funkcja zmieniajaca znak char na intereger.
* @param x - zmieniany char
* @return intereger zmienienego znaku char
*/
export int char_to_int(char x) {
    int tmp = -1;
    if (x >= '1' && x <= '9')
        tmp = x - '1';
    else if (x >= 'A' && x <= 'I')
        tmp = x - 'A';
    else if (x >= 'a' && x <= 'i')
        tmp = x - 'a';
    return tmp;
}

/**
* Funkcja czyszczaca ekran konsoli.
*/
export void clear_screan() {
    for (int i = 0; i <= 60; i++) {
        wstaw_tekst(0, i, "                                                                                                                              ");
    }
}

/**
* Funkcja rysujaca szachownice shogi.
*/
export void rysuj_szachownice() {

    for (int i = 0; i < 9; i++) {
        if (i == 0)
            wstaw_tekst(2 * i + 4, 3, "1", "Yellow");
        else if (i == 1)
            wstaw_tekst(2 * i + 4, 3, "2", "Yellow");
        else if (i == 2)
            wstaw_tekst(2 * i + 4, 3, "3", "Yellow");
        else if (i == 3)
            wstaw_tekst(2 * i + 4, 3, "4", "Yellow");
        else if (i == 4)
            wstaw_tekst(2 * i + 4, 3, "5", "Yellow");
        else if (i == 5)
            wstaw_tekst(2 * i + 4, 3, "6", "Yellow");
        else if (i == 6)
            wstaw_tekst(2 * i + 4, 3, "7", "Yellow");
        else if (i == 7)
            wstaw_tekst(2 * i + 4, 3, "8", "Yellow");
        else if (i == 8)
            wstaw_tekst(2 * i + 4, 3, "9", "Yellow");
    }
    for (int i = 0; i < 9; i++) {
        if (i == 0)
            wstaw_tekst(2, 2 * i + 4, "A", "Yellow");
        else if (i == 1)
            wstaw_tekst(2, 2 * i + 4, "B", "Yellow");
        else if (i == 2)
            wstaw_tekst(2, 2 * i + 4, "C", "Yellow");
        else if (i == 3)
            wstaw_tekst(2, 2 * i + 4, "D", "Yellow");
        else if (i == 4)
            wstaw_tekst(2, 2 * i + 4, "E", "Yellow");
        else if (i == 5)
            wstaw_tekst(2, 2 * i + 4, "F", "Yellow");
        else if (i == 6)
            wstaw_tekst(2, 2 * i + 4, "G", "Yellow");
        else if (i == 7)
            wstaw_tekst(2, 2 * i + 4, "H", "Yellow");
        else if (i == 8)
            wstaw_tekst(2, 2 * i + 4, "I", "Yellow");
    }

    std::cout << "\033[48;2;40;40;40m";
    for (int i = 4; i <= 20; i++) {
        wstaw_tekst(4, i, "                 ");
    }
    for (int i = 1; i < 18; i++)
        for (int j = 1; j < 18; j++) {
            if (j % 2 == 0) wstaw_tekst(i + 3, j + 3, "-", "Black");
            else if (i % 2 == 0) wstaw_tekst(i + 3, j + 3, "|", "Black");
        }
    std::cout << "\033[49m";
}

/**
* Funkcja sortujaca strung wed³ug podanego paternu string.
* @param str - sortowany string
* @param pat - string paternu wed³ug jakieg ma byc postorowany string
*/
export void sortByPattern(std::string& str, std::string pat) {
    const int MAX_CHAR = 26; // 26 znaków bez znaków specjalnych 
    int count[MAX_CHAR] = { 0 }; // tablica z iloœci¹ ka¿dego z znaków

    // Count number of occurrences of each character in str.
    for (int i = 0; i < str.length(); i++)
        count[str[i] - 'a']++;

    // Traverse the pattern and print every characters
    // same number of times as it appears in str. This
    // loop takes O(m + n) time where m is length of
    // pattern and n is length of str.
    int index = 0;
    for (int i = 0; i < pat.length(); i++)
        for (int j = 0; j < count[pat[i] - 'a']; j++)
            str[index++] = pat[i];
}

#pragma endregion funkcje_ogl