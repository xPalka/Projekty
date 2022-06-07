module;

#include <string>
#include <memory>

export module zlotyGeneral;

//import <string>;
//import <memory>;

export import srebrnyGeneral;

/**
* Klasa z³otego genera³a z shogi.
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
    * @param s - wskaŸnik na jakim polu bêdzie sta³ dGeneral
    * @param _gracz - gracz do jakiego bedzie nalezal dGeneral
    */
    dGeneral(Pole& s, Gracz _gracz) {
        pole = &s;
        pole->setStatusLong("Z³oty Genera³");
        pole->setStatusShort("g");
        gracz = _gracz;
        s1 = Promocja::bez_promocji;
        znak = "g";
        pole->narysuj(znak, gracz);
    }

    /**
    * Konstruktor trójargumentowy (jezeli dodajemy odrazu zpromowana figure)
    * @param s - wskaŸnik na jakim polu bêdzie sta³ dGeneral
    * @param _gracz - gracz do jakiego bedzie nalezal dGeneral
    * @param prom - rodzaj promocji figury
    */
    dGeneral(Pole& s, Gracz _gracz, Promocja prom) {
        pole = &s;
        pole->setStatusLong("Z³oty Genera³");
        pole->setStatusShort("g");
        gracz = _gracz;
        s1 = prom;
        znak = "G";
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
            if (s1 == Promocja::bez_promocji) { // jezeli z³Gen nie promowany
                if ((x_na >= x_z - 1) && (x_na <= x_z + 1) && (y_na - y_z == gracz)) { // ruch po przekontnej o 1 w przód i 1 w przód 
                    xx = true;
                    yy = true;
                }
                else if ((x_na == x_z) && (y_na - y_z == -gracz)) { // 1 w ty³
                    xx = true;
                    yy = true;
                }
                else if ((x_na == x_z - 1 || x_na == x_z + 1) && (y_na == y_z)) { // 1 w boki 
                    xx = true;
                    yy = true;
                }
            }
            else { // i tak jest z³oty genera³ bo on nie ma promocji    
                if ((x_na >= x_z - 1) && (x_na <= x_z + 1) && (y_na - y_z == gracz)) { // ruch po przekontnej o 1 w przód i 1 w przód 
                    xx = true;
                    yy = true;
                }
                else if ((x_na == x_z) && (y_na - y_z == -gracz)) { // 1 w ty³
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
    * Metoda wykonuj¹ca ruch z³otym genera³em
    * @param p - referencja do pole na które chcemy siê poruszyæ
    * @param promocja_bot - pojedynczy znak okreslajacy czy jest promocja (dla silnika/bota). Znak '+' oznacz ¿e jest (wartoœæ ta zwracana jest przez slinik USI).
    * @return Boolowska wartoœæ czy ruch siê powiod³. True jezeli tak, a false w przeciwnym wypadku.
    */
    bool wykonajRuch(Pole& p) {
        int y_na = p.gety();
        int y_z = pole->gety();

        bool mozliwyRuch = sprawdzDostepnoscRuchu(p); // czy ruch jest prawid³owy w zasadach gry
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
    * Metoda wykonaj¹ca zrzut(ponowne wystawienie z³otego genra³a) do gry
    * @param p - referencja do pole na które chcemy siê poruszyæ
    * @param tmp - wskaznik figury zrzutu
    */
    void wykonajRuchZrzut(Pole& p, std::shared_ptr<dGeneral> tmp) {

        // dodaj dGeneral na plansze gdzie ma byc 
        pole = &p;
        pole->setStatusLong("Z³oty Genera³");
        pole->setStatusShort("g");
        pole->setFigura(tmp);
        pole->narysuj(znak, gracz);
    }
};