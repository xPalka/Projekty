module;

#include <string>
#include <memory>

export module pion;

//import <string>;
//import <memory>;

export import pole;

/**
* Klasa pionka z shogi.
*/
export class Pion : public Figura {
public:

    /**
    * Destruktor
    */
    ~Pion() { }

    /**
    * Konstruktor jednoargumentowy (jak wczytujemy i dodajemy odrazu do figurGracza)
    * @param _gracz - gracz do jakiego bedzie nalezal Pion
    */
    Pion(Gracz _gracz) {
        pole = nullptr;
        gracz = _gracz;
        s1 = Promocja::bez_promocji;
        znak = "p";
    }

    /**
    * Konstruktor dwuargumentowy (jezeli dodajemy normalnie figure na plansze)
    * @param s - wskaŸnik na jakim polu bêdzie sta³ Pion
    * @param _gracz - gracz do jakiego bedzie nalezal Pion
    */
    Pion(Pole& s, Gracz _gracz) {
        pole = &s;
        pole->setStatusLong("Pionek");
        pole->setStatusShort("p");
        gracz = _gracz;
        s1 = Promocja::bez_promocji;
        znak = "p";
        pole->narysuj(znak, gracz);
    }

    /**
    * Konstruktor trójargumentowy (jezeli dodajemy odrazu zpromowana figure)
    * @param s - wskaŸnik na jakim polu bêdzie sta³ Pion
    * @param _gracz - gracz do jakiego bedzie nalezal Pion
    * @param prom - rodzaj promocji figury
    */
    Pion(Pole& s, Gracz _gracz, Promocja prom) {
        pole = &s;
        pole->setStatusLong("Pionek");
        pole->setStatusShort("p");
        gracz = _gracz;
        s1 = prom;
        znak = "P";
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
            if (s1 == Promocja::bez_promocji) { // jezeli pion nie promowany
                xx = x_na == x_z; // je¿eli x równe bo tylko do przodu idzie pionek to X true
                if (y_na - y_z == gracz) { // je¿eli y ró¿ne o 1 to Y jest true
                    yy = true;
                }
            }
            else { // jezeli pion promowany czyli z³oty genera³               
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
    * Metoda wykonuj¹ca ruch Pionem
    * @param p - referencja do pole na które chcemy siê poruszyæ
    * @param promocja_bot - pojedynczy znak okreslajacy czy jest promocja (dla silnika/bota). Znak '+' oznacz ¿e jest (wartoœæ ta zwracana jest przez slinik USI).
    * @return Boolowska wartoœæ czy ruch siê powiod³. True jezeli tak, a false w przeciwnym wypadku.
    */
    bool wykonajRuch(Pole& p, char promocja_bot) {
        int y_na = p.gety();
        int y_z = pole->gety();

        bool mozliwyRuch = sprawdzDostepnoscRuchu(p); // czy ruch jest prawid³owy w zasadach gry
        if (mozliwyRuch) {

            // dodaæ ¿e jak y_z to zapytaæ jak jeszcze nie jest po prostu?

            pole->narysuj(" ", gracz);
            pole = &p;
            if (gracz == gracz1 && s1 == Promocja::bez_promocji) {
                if (y_na == 8) {
                    // promocja i koniec
                    s1 = Promocja::promocja;
                    znak = "P";
                }
                else if (y_na >= 6 || y_z >= 6) {
                    // zadaj pytanie o promocje
                    if (promocja_bot == '\0') s1 = askIfPromotion();
                    if (s1 == Promocja::promocja || promocja_bot == '+')  znak = "P";
                }
            }
            if (gracz == gracz2 && s1 == Promocja::bez_promocji) {
                if (y_na == 0) {
                    // promocja i koniec
                    s1 = Promocja::promocja;
                    znak = "P";
                }
                else if (y_na <= 2 || y_z <= 2) {
                    // zadaj pytanie o promocje
                    if (promocja_bot == '\0') s1 = askIfPromotion();
                    if (s1 == Promocja::promocja || promocja_bot == '+')  znak = "P";
                }
            }
            pole->narysuj(znak, gracz);
            return true;
        }
        else return false;
    }

    /**
    * Metoda wykonaj¹ca zrzut(ponowne wystawienie piona) do gry
    * @param p - referencja do pole na które chcemy siê poruszyæ
    * @param tmp - wskaznik figury zrzutu
    */
    void wykonajRuchZrzut(Pole& p, std::shared_ptr<Pion> tmp) {

        // dodaj pion na plansze gdzie ma byc 
        pole = &p;
        pole->setStatusLong("Pionek");
        pole->setStatusShort("p");
        pole->setFigura(tmp);
        pole->narysuj(znak, gracz);
    }

};