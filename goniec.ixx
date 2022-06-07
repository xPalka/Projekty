module;

#include <string>
#include <memory>

export module goniec;

//import <string>;
//import <memory>;

export import zlotyGeneral;

/**
* Klasa gonca z shogi.
*/
export class Goniec : public Figura {
public:

    /**
    * Destruktor
    */
    ~Goniec() { }

    /**
    * Konstruktor jednoargumentowy (jak wczytujemy i dodajemy odrazu do figurGracza)
    * @param _gracz - gracz do jakiego bedzie nalezal Goniec
    */
    Goniec(Gracz _gracz) {
        pole = nullptr;
        gracz = _gracz;
        s1 = Promocja::bez_promocji;
        znak = "b";
    }

    /**
    * Konstruktor dwuargumentowy (jezeli dodajemy normalnie figure na plansze)
    * @param s - wskaŸnik na jakim polu bêdzie sta³ Goniec
    * @param _gracz - gracz do jakiego bedzie nalezal Goniec
    */
    Goniec(Pole& s, Gracz _gracz) {
        pole = &s;
        pole->setStatusLong("Goniec");
        pole->setStatusShort("b");
        gracz = _gracz;
        s1 = Promocja::bez_promocji;
        znak = "b";
        pole->narysuj(znak, gracz);
    }

    /**
    * Konstruktor trójargumentowy (jezeli dodajemy odrazu zpromowana figure)
    * @param s - wskaŸnik na jakim polu bêdzie sta³ Goniec
    * @param _gracz - gracz do jakiego bedzie nalezal Goniec
    * @param prom - rodzaj promocji figury
    */
    Goniec(Pole& s, Gracz _gracz, Promocja prom) {
        pole = &s;
        pole->setStatusLong("Goniec");
        pole->setStatusShort("b");
        gracz = _gracz;
        s1 = prom;
        znak = "B";
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
            // jezeli goniec nie promowany
            if (s1 == Promocja::bez_promocji) {

                // prawa-gora i lewy-dol GIT
                if (x_na - x_z == -(y_na - y_z)) {

                    //prawa gora sprawdzenie
                    if ((x_na - x_z) > 0) {
                        for (int ix = x_z + 1, iy = y_z - 1; ; ix++, iy--) {
                            if ((x_na - ix) == 0 && (y_na - iy) == 0) break;
                            else if (!gra[ix][iy].isEmptyPole()) {
                                // nie jest puste jakies pole wiec nie mozna zrobic ruchu
                                return false;
                            }
                        }
                    }
                    //lewy dol sprawdzenie
                    else if ((x_na - x_z) < 0) {
                        for (int ix = x_z - 1, iy = y_z + 1; ; ix--, iy++) {
                            if ((x_na - ix) == 0 && (y_na - iy) == 0) break;
                            else if (!gra[ix][iy].isEmptyPole()) {
                                // nie jest puste jakies pole wiec nie mozna zrobic ruchu
                                return false;
                            }
                        }
                    }
                    xx = true;
                    yy = true;
                }
                // prawy-dol i lewa-gora
                else if (x_na - x_z == y_na - y_z) {

                    //lewy gora sprawdzenie
                    if ((x_na - x_z) < 0) {
                        for (int ix = x_z - 1, iy = y_z - 1; ; ix--, iy--) {
                            if ((x_na - ix) == 0 && (y_na - iy) == 0) break;
                            else if (!gra[ix][iy].isEmptyPole()) {
                                // nie jest puste jakies pole wiec nie mozna zrobic ruchu
                                return false;
                            }
                        }
                    }
                    //prawa dol sprawdzenie
                    else if ((x_na - x_z) > 0) {
                        for (int ix = x_z + 1, iy = y_z + 1; ; ix++, iy++) {
                            if ((x_na - ix) == 0 && (y_na - iy) == 0) break;
                            else if (!gra[ix][iy].isEmptyPole()) {
                                // nie jest puste jakies pole wiec nie mozna zrobic ruchu
                                return false;
                            }
                        }
                    }
                    xx = true;
                    yy = true;
                }
            }
            else { // promowany goniec - koñ
                // prawa-gora i lewy-dol GIT
                if (x_na - x_z == -(y_na - y_z)) {

                    //prawa gora sprawdzenie
                    if ((x_na - x_z) > 0) {
                        for (int ix = x_z + 1, iy = y_z - 1; ; ix++, iy--) {
                            if ((x_na - ix) == 0 && (y_na - iy) == 0) break;
                            else if (!gra[ix][iy].isEmptyPole()) {
                                // nie jest puste jakies pole wiec nie mozna zrobic ruchu
                                return false;
                            }
                        }
                    }
                    //lewy dol sprawdzenie
                    else if ((x_na - x_z) < 0) {
                        for (int ix = x_z - 1, iy = y_z + 1; ; ix--, iy++) {
                            if ((x_na - ix) == 0 && (y_na - iy) == 0) break;
                            else if (!gra[ix][iy].isEmptyPole()) {
                                // nie jest puste jakies pole wiec nie mozna zrobic ruchu
                                return false;
                            }
                        }
                    }
                    xx = true;
                    yy = true;
                }
                // prawy-dol i lewa-gora
                else if (x_na - x_z == y_na - y_z) {

                    //lewy gora sprawdzenie
                    if ((x_na - x_z) < 0) {
                        for (int ix = x_z - 1, iy = y_z - 1; ; ix--, iy--) {
                            if ((x_na - ix) == 0 && (y_na - iy) == 0) break;
                            else if (!gra[ix][iy].isEmptyPole()) {
                                // nie jest puste jakies pole wiec nie mozna zrobic ruchu
                                return false;
                            }
                        }
                    }
                    //prawa dol sprawdzenie
                    else if ((x_na - x_z) > 0) {
                        for (int ix = x_z + 1, iy = y_z + 1; ; ix++, iy++) {
                            if ((x_na - ix) == 0 && (y_na - iy) == 0) break;
                            else if (!gra[ix][iy].isEmptyPole()) {
                                // nie jest puste jakies pole wiec nie mozna zrobic ruchu
                                return false;
                            }
                        }
                    }
                    xx = true;
                    yy = true;
                }
                //prwao lewo dó³ boki o 1
                else if ((x_na == x_z && (y_na == y_z - 1 || y_na == y_z + 1)) || (y_na == y_z && (x_na == x_z - 1 || x_na == x_z + 1))) {
                    xx = true;
                    yy = true;
                }
            }
        }
        return xx && yy;
    }

    /**
    * Metoda wykonuj¹ca ruch goñcem
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
                if (s1 == Promocja::promocja || promocja_bot == '+')  znak = "B";
            }
            if (gracz == gracz2 && (y_na <= 2 || y_z <= 2) && s1 == Promocja::bez_promocji) {
                // zadaj pytanie o promocje
                if (promocja_bot == '\0') s1 = askIfPromotion();
                if (s1 == Promocja::promocja || promocja_bot == '+')  znak = "B";
            }
            pole->narysuj(znak, gracz);
            return true;
        }
        else return false;
    }

    /**
    * Metoda wykonaj¹ca zrzut(ponowne wystawienie goñca) do gry
    * @param p - referencja do pole na które chcemy siê poruszyæ
    * @param tmp - wskaznik figury zrzutu
    */
    void wykonajRuchZrzut(Pole& p, std::shared_ptr<Goniec> tmp) {

        // dodaj goniec na plansze gdzie ma byc 
        pole = &p;
        pole->setStatusLong("Goniec");
        pole->setStatusShort("b");
        pole->setFigura(tmp);
        pole->narysuj(znak, gracz);
    }
};