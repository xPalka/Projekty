module;

#include <string>
#include <memory>

export module wieza;

//import <string>;
//import <memory>;

export import goniec;

/**
* Klasa wiezy z shogi.
*/
export class Wieza : public Figura {
public:

    /**
    * Destruktor
    */
    ~Wieza() { }

    /**
    * Konstruktor jednoargumentowy (jak wczytujemy i dodajemy odrazu do figurGracza)
    * @param _gracz - gracz do jakiego bedzie nalezal Wieza
    */
    Wieza(Gracz _gracz) {
        pole = nullptr;
        gracz = _gracz;
        s1 = Promocja::bez_promocji;
        znak = "r";
    }

    /**
    * Konstruktor dwuargumentowy (jezeli dodajemy normalnie figure na plansze)
    * @param s - wskaŸnik na jakim polu bêdzie sta³ Wieza
    * @param _gracz - gracz do jakiego bedzie nalezal Wieza
    */
    Wieza(Pole& s, Gracz _gracz) {
        pole = &s;
        pole->setStatusLong("Wie¿a");
        pole->setStatusShort("r");
        gracz = _gracz;
        s1 = Promocja::bez_promocji;
        znak = "r";
        pole->narysuj(znak, gracz);
    }

    /**
    * Konstruktor trójargumentowy (jezeli dodajemy odrazu zpromowana figure)
    * @param s - wskaŸnik na jakim polu bêdzie sta³ Wieza
    * @param _gracz - gracz do jakiego bedzie nalezal Wieza
    * @param prom - rodzaj promocji figury
    */
    Wieza(Pole& s, Gracz _gracz, Promocja prom) {
        pole = &s;
        pole->setStatusLong("Wie¿a");
        pole->setStatusShort("r");
        gracz = _gracz;
        s1 = prom;
        znak = "R";
        pole->narysuj(znak, gracz);
    }

    /**
    * Metoda sprawdza czy ruch jest mozliwy do wykonania.
    * @param p - pole na które chcemy siê poruszyæ
    * @param gra - ca³a dwuwymiarowa tablica pól (czyli nasza szachownica na której rozgrywa siê rozgrywka).
    * @return Boolowska wartoœæ czy ruch jest mo¿liwy do wykonania. True jezeli tak, a false w przeciwnym wypadku.
    */
    bool sprawdzDostepnoscRuchu(Pole p, Pole** gra) {
        bool xx = false;
        bool yy = false;
        int x_na = p.getx();
        int y_na = p.gety();
        int x_z = pole->getx();
        int y_z = pole->gety();

        if (x_na >= 0 && x_na <= 8 && y_na >= 0 && y_na <= 8) {
            if (s1 == Promocja::bez_promocji) { // jezeli wieza nie promowany

                // ruch przodu i ty³
                if (x_na == x_z && y_na != y_z) {
                    // spradzenie w dol
                    if (y_na > y_z) { // je¿eli y_na wiêksze od pocz¹tkowego 
                        for (int i = y_z + 1; i < y_na; i++) {
                            if (!gra[x_na][i].isEmptyPole()) {
                                // nie jest puste jakies pole wiec nie mozna zrobic ruchu
                                return false;
                            }
                        }
                    }
                    // sprawdzenie w gore
                    else if (y_na < y_z) {
                        for (int i = y_z - 1; i > y_na; i--) {
                            if (!gra[x_na][i].isEmptyPole()) {
                                // nie jest puste jakies pole wiec nie mozna zrobic ruchu
                                return false;
                            }
                        }
                    }
                    xx = true;
                    yy = true;
                }
                // ruch na boki
                else if (x_na != x_z && y_na == y_z) {
                    // spradzenie w prawo
                    if (x_na > x_z) { // je¿eli y_na wiêksze od pocz¹tkowego 
                        for (int i = x_z + 1; i < x_na; i++) {
                            if (!gra[i][y_na].isEmptyPole()) {
                                // nie jest puste jakies pole wiec nie mozna zrobic ruchu
                                return false;
                            }
                        }
                    }
                    // sprawdzenie w lewo
                    else if (x_na < x_z) {
                        for (int i = x_z - 1; i > x_na; i--) {
                            if (!gra[i][y_na].isEmptyPole()) {
                                // nie jest puste jakies pole wiec nie mozna zrobic ruchu
                                return false;
                            }
                        }
                    }
                    xx = true;
                    yy = true;
                }
            }
            else { // promowany wieza - smok
                 // ruch przodu i ty³
                if (x_na == x_z && y_na != y_z) {
                    // spradzenie w dol
                    if (y_na > y_z) { // je¿eli y_na wiêksze od pocz¹tkowego 
                        for (int i = y_z + 1; i < y_na; i++) {
                            if (!gra[x_na][i].isEmptyPole()) {
                                // nie jest puste jakies pole wiec nie mozna zrobic ruchu
                                return false;
                            }
                        }
                    }
                    // sprawdzenie w gore
                    else if (y_na < y_z) {
                        for (int i = y_z - 1; i > y_na; i--) {
                            if (!gra[x_na][i].isEmptyPole()) {
                                // nie jest puste jakies pole wiec nie mozna zrobic ruchu
                                return false;
                            }
                        }
                    }
                    xx = true;
                    yy = true;
                }
                // ruch na boki
                else if (x_na != x_z && y_na == y_z) {
                    // spradzenie w prawo
                    if (x_na > x_z) { // je¿eli y_na wiêksze od pocz¹tkowego 
                        for (int i = x_z + 1; i < x_na; i++) {
                            if (!gra[i][y_na].isEmptyPole()) {
                                // nie jest puste jakies pole wiec nie mozna zrobic ruchu
                                return false;
                            }
                        }
                    }
                    // sprawdzenie w lewo
                    else if (x_na < x_z) {
                        for (int i = x_z - 1; i > x_na; i--) {
                            if (!gra[i][y_na].isEmptyPole()) {
                                // nie jest puste jakies pole wiec nie mozna zrobic ruchu
                                return false;
                            }
                        }
                    }
                    xx = true;
                    yy = true;
                }
                //prwao lewo dó³ boki i skosy o 1
                else if ((x_na == x_z - 1 || x_na == x_z + 1) && (y_na == y_z - 1 || y_na == y_z + 1)) {
                    xx = true;
                    yy = true;
                }
            }
        }
        return xx && yy;
    }

    /**
    * Metoda wykonuj¹ca ruch wie¿y
    * @param p - referencja do pole na które chcemy siê poruszyæ
    * @param promocja_bot - pojedynczy znak okreslajacy czy jest promocja (dla silnika/bota). Znak '+' oznacz ¿e jest (wartoœæ ta zwracana jest przez slinik USI).
    * @return Boolowska wartoœæ czy ruch siê powiod³. True jezeli tak, a false w przeciwnym wypadku.
    */
    bool wykonajRuch(Pole& p, Pole** s, char promocja_bot) {
        int y_na = p.gety();
        int y_z = pole->gety();

        bool mozliwyRuch = sprawdzDostepnoscRuchu(p, s); // czy ruch jest prawid³owy w zasadach gry
        if (mozliwyRuch) {
            pole->narysuj(" ", gracz);
            pole = &p;
            if (gracz == gracz1 && (y_na >= 6 || y_z >= 6) && s1 == Promocja::bez_promocji) {
                // zadaj pytanie o promocje
                if (promocja_bot == '\0') s1 = askIfPromotion();
                if (s1 == Promocja::promocja || promocja_bot == '+')  znak = "R";
            }
            if (gracz == gracz2 && (y_na <= 2 || y_z <= 2) && s1 == Promocja::bez_promocji) {
                // zadaj pytanie o promocje
                if (promocja_bot == '\0') s1 = askIfPromotion();
                if (s1 == Promocja::promocja || promocja_bot == '+')  znak = "R";
            }
            pole->narysuj(znak, gracz);
            return true;
        }
        else return false;
    }

    /**
    * Metoda wykonaj¹ca zrzut(ponowne wystawienie wie¿¹) do gry
    * @param p - referencja do pole na które chcemy siê poruszyæ
    * @param tmp - wskaznik figury zrzutu
    */
    void wykonajRuchZrzut(Pole& p, std::shared_ptr<Wieza> tmp) {

        // dodaj goniec na plansze gdzie ma byc 
        pole = &p;
        pole->setStatusLong("Wie¿a");
        pole->setStatusShort("r");
        pole->setFigura(tmp);
        pole->narysuj(znak, gracz);
    }
};