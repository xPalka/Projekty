module;

#include <string>
#include <memory>

export module krol;

//import <string>;
//import <memory>;

export import wieza;

/**
* Klasa króla z shogi.
*/
export class Krol : public Figura {
public:

    /**
    * Destruktor
    */
    Krol() { }

    /**
    * Konstruktor dwuargumentowy
    * @param s - wskaŸnik na jakim polu bêdzie sta³ Krol
    * @param _gracz - gracz do jakiego bedzie nalezal Krol
    */
    Krol(Pole& s, Gracz _gracz) {
        pole = &s;
        pole->setStatusLong("Król");
        pole->setStatusShort("K");
        gracz = _gracz;
        s1 = Promocja::bez_promocji;
        znak = "K";
        pole->narysuj(znak, gracz);
    }

    /**
    * Metoda sprawdza czy ruch jest mozliwy do wykonania.
    * @param p - pole na które chcemy siê poruszyæ
    * @return Boolowska wartoœæ czy ruch jest mo¿liwy do wykonania. True jezeli tak, a false w przeciwnym wypadku.
    */
    bool sprawdzDostepnoscRuchu(Pole p) {
        bool xx = false;
        bool yy = false;
        int x_na = p.getx();
        int y_na = p.gety();
        int x_z = pole->getx();
        int y_z = pole->gety();

        if (x_na >= 0 && x_na <= 8 && y_na >= 0 && y_na <= 8) {
            if (s1 == Promocja::bez_promocji) { // jezeli krol nie promowany        

                //prwao lewo dó³ boki o 1
                if ((x_na == x_z && (y_na == y_z - 1 || y_na == y_z + 1)) || (y_na == y_z && (x_na == x_z - 1 || x_na == x_z + 1))) {
                    xx = true;
                    yy = true;
                }
                //prwao lewo dó³ boki i skosy o 1
                else if ((x_na == x_z - 1 || x_na == x_z + 1) && (y_na == y_z - 1 || y_na == y_z + 1)) {
                    xx = true;
                    yy = true;
                }
            }
            else {
                // promowany krol czyli krol no jak krole beda promowane to liczymy pkt

                //prwao lewo dó³ boki o 1
                if ((x_na == x_z && (y_na == y_z - 1 || y_na == y_z + 1)) || (y_na == y_z && (x_na == x_z - 1 || x_na == x_z + 1))) {
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
    * Metoda wykonuj¹ca ruch krolem
    * @param p - referencja do pole na które chcemy siê poruszyæ
    * @return Boolowska wartoœæ czy ruch siê powiod³. True jezeli tak, a false w przeciwnym wypadku.
    */
    bool wykonajRuch(Pole& p) {
        int y_na = p.gety();

        bool mozliwyRuch = sprawdzDostepnoscRuchu(p); // czy ruch jest prawid³owy w zasadach gry
        if (mozliwyRuch) { // if czy przekroczy³ ten ruch promocje 
            pole->narysuj(" ", gracz);
            pole = &p;
            if (gracz == gracz1 && y_na >= 6) {
                s1 = Promocja::promocja; // JEZELI JEST PROMOWANY TO KONIEC GRY BO DOSZEDL DO POLA PROMOCJI PRZECIWNIKA LICZ PKT
                znak = "K";
            }
            if (gracz == gracz2 && y_na <= 2) {
                s1 = Promocja::promocja; // JEZELI JEST PROMOWANY TO KONIEC GRY BO DOSZEDL DO POLA PROMOCJI PRZECIWNIKA LICZ PKT
                znak = "K";
            }
            pole->narysuj(znak, gracz);
            return true;
        }
        else return false;
    }
};

