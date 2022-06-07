module;

#include <string>
#include <memory>

export module zlotyGeneral;

//import <string>;
//import <memory>;

export import srebrnyGeneral;

/**
* Klasa z�otego genera�a z shogi.
*/
export class dGeneral : public Figura {
public:

    /**
    * Destruktor
    */
    ~dGeneral() { }

    /**
    * Konstruktor jednoargumentowy (jak wczytujemy i dodajemy odrazu do figurGracza)
    * @param _gracz - gracz do jakiego bedzie nalezal dGeneral
    */
    dGeneral(Gracz _gracz) {
        pole = nullptr;
        gracz = _gracz;
        s1 = Promocja::bez_promocji;
        znak = "g";
    }

    /**
    * Konstruktor dwuargumentowy (jezeli dodajemy normalnie figure na plansze)
    * @param s - wska�nik na jakim polu b�dzie sta� dGeneral
    * @param _gracz - gracz do jakiego bedzie nalezal dGeneral
    */
    dGeneral(Pole& s, Gracz _gracz) {
        pole = &s;
        pole->setStatusLong("Z�oty Genera�");
        pole->setStatusShort("g");
        gracz = _gracz;
        s1 = Promocja::bez_promocji;
        znak = "g";
        pole->narysuj(znak, gracz);
    }

    /**
    * Konstruktor tr�jargumentowy (jezeli dodajemy odrazu zpromowana figure)
    * @param s - wska�nik na jakim polu b�dzie sta� dGeneral
    * @param _gracz - gracz do jakiego bedzie nalezal dGeneral
    * @param prom - rodzaj promocji figury
    */
    dGeneral(Pole& s, Gracz _gracz, Promocja prom) {
        pole = &s;
        pole->setStatusLong("Z�oty Genera�");
        pole->setStatusShort("g");
        gracz = _gracz;
        s1 = prom;
        znak = "G";
        pole->narysuj(znak, gracz);
    }

    /**
    * Metoda sprawdza czy ruch jest mozliwy do wykonania.
    * @param p - pole na kt�re chcemy si� poruszy�
    * @return Boolowska warto�� czy ruch jest mo�liwy do wykonania. True jezeli tak, a false w przeciwnym wypadku.
    */
    bool sprawdzDostepnoscRuchu(Pole p) {
        bool xx = false;
        bool yy = false;
        int x_na = p.getx();
        int y_na = p.gety();
        int x_z = pole->getx();
        int y_z = pole->gety();

        if (x_na >= 0 && x_na <= 8 && y_na >= 0 && y_na <= 8) {
            if (s1 == Promocja::bez_promocji) { // jezeli z�Gen nie promowany
                if ((x_na >= x_z - 1) && (x_na <= x_z + 1) && (y_na - y_z == gracz)) { // ruch po przekontnej o 1 w prz�d i 1 w prz�d 
                    xx = true;
                    yy = true;
                }
                else if ((x_na == x_z) && (y_na - y_z == -gracz)) { // 1 w ty�
                    xx = true;
                    yy = true;
                }
                else if ((x_na == x_z - 1 || x_na == x_z + 1) && (y_na == y_z)) { // 1 w boki 
                    xx = true;
                    yy = true;
                }
            }
            else { // i tak jest z�oty genera� bo on nie ma promocji    
                if ((x_na >= x_z - 1) && (x_na <= x_z + 1) && (y_na - y_z == gracz)) { // ruch po przekontnej o 1 w prz�d i 1 w prz�d 
                    xx = true;
                    yy = true;
                }
                else if ((x_na == x_z) && (y_na - y_z == -gracz)) { // 1 w ty�
                    xx = true;
                    yy = true;
                }
                else if ((x_na == x_z - 1 || x_na == x_z + 1) && (y_na == y_z)) { // 1 w boki 
                    xx = true;
                    yy = true;
                }
            }
        }
        return xx && yy;
    }

    /**
    * Metoda wykonuj�ca ruch z�otym genera�em
    * @param p - referencja do pole na kt�re chcemy si� poruszy�
    * @param promocja_bot - pojedynczy znak okreslajacy czy jest promocja (dla silnika/bota). Znak '+' oznacz �e jest (warto�� ta zwracana jest przez slinik USI).
    * @return Boolowska warto�� czy ruch si� powiod�. True jezeli tak, a false w przeciwnym wypadku.
    */
    bool wykonajRuch(Pole& p) {
        int y_na = p.gety();
        int y_z = pole->gety();

        bool mozliwyRuch = sprawdzDostepnoscRuchu(p); // czy ruch jest prawid�owy w zasadach gry
        if (mozliwyRuch) {
            pole->narysuj(" ", gracz);
            pole = &p;
            if (gracz == gracz1 && (y_na >= 6 || y_z >= 6) && s1 == Promocja::bez_promocji) {
                // zadaj pytanie o promocje
                s1 = Promocja::promocja;
                znak = "g";
            }
            if (gracz == gracz2 && (y_na <= 2 || y_z <= 2) && s1 == Promocja::bez_promocji) {
                // zadaj pytanie o promocje
                s1 = Promocja::promocja;
                znak = "g";
            }
            pole->narysuj(znak, gracz);
            return true;
        }
        else return false;
    }

    /**
    * Metoda wykonaj�ca zrzut(ponowne wystawienie z�otego genra�a) do gry
    * @param p - referencja do pole na kt�re chcemy si� poruszy�
    * @param tmp - wskaznik figury zrzutu
    */
    void wykonajRuchZrzut(Pole& p, std::shared_ptr<dGeneral> tmp) {

        // dodaj dGeneral na plansze gdzie ma byc 
        pole = &p;
        pole->setStatusLong("Z�oty Genera�");
        pole->setStatusShort("g");
        pole->setFigura(tmp);
        pole->narysuj(znak, gracz);
    }
};