module;

#include <string>
#include <memory>

export module lanca;

//import <string>;
//import <memory>;

export import pion;

/**
* Klasa lancy z shogi.
*/
export class Lanca : public Figura {
public:

    /**
    * Destruktor
    */
    ~Lanca() { }

    /**
    * Konstruktor jednoargumentowy (jak wczytujemy i dodajemy odrazu do figurGracza)
    * @param _gracz - gracz do jakiego bedzie nalezal Lanca
    */
    Lanca(Gracz _gracz) {
        pole = nullptr;
        gracz = _gracz;
        s1 = Promocja::bez_promocji;
        znak = "l";
    }

    /**
    * Konstruktor dwuargumentowy (jezeli dodajemy normalnie figure na plansze)
    * @param s - wskaŸnik na jakim polu bêdzie sta³ Lanca
    * @param _gracz - gracz do jakiego bedzie nalezal Lanca
    */
    Lanca(Pole& s, Gracz _gracz) {
        pole = &s;
        pole->setStatusLong("Lanca");
        pole->setStatusShort("l");
        gracz = _gracz;
        s1 = Promocja::bez_promocji;
        znak = "l";
        pole->narysuj(znak, gracz);
    }

    /**
    * Konstruktor trójargumentowy (jezeli dodajemy odrazu zpromowana figure)
    * @param s - wskaŸnik na jakim polu bêdzie sta³ Lanca
    * @param _gracz - gracz do jakiego bedzie nalezal Lanca
    * @param prom - rodzaj promocji figury
    */
    Lanca(Pole& s, Gracz _gracz, Promocja prom) {
        pole = &s;
        pole->setStatusLong("Lanca");
        pole->setStatusShort("l");
        gracz = _gracz;
        s1 = prom;
        znak = "L";
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
            if (s1 == Promocja::bez_promocji) { // jezeli lanca nie promowany


                // ruch jest tylko do przodu wiec to ponizej GIT jest
                xx = x_na == x_z; // je¿eli x równe bo tylko do przodu idzie pionek to X true
                if (gracz == gracz1) {
                    if (y_na > y_z) { // je¿eli y wiêksze od pocz¹tkowego 
                        yy = true;
                        // wspolrzedne git to teraz przegladnij czy po drodze czegos nie ma 
                        for (int i = y_z + 1; i < y_na; i++) {
                            if (!gra[x_na][i].isEmptyPole()) {
                                // nie jest puste jakies pole wiec nie mozna zrobic ruchu
                                return false;
                            }
                        }
                    }
                }
                else if (gracz == gracz2) {
                    if (y_na < y_z) {
                        yy = true;
                        // wspolrzedne git to teraz przegladnij czy po drodze czegos nie ma 
                        for (int i = y_z - 1; i > y_na; i--) {
                            if (!gra[x_na][i].isEmptyPole()) {
                                // nie jest puste jakies pole wiec nie mozna zrobic ruchu
                                return false;
                            }
                        }

                    }
                }
            }
            else { // jezeli lanca promowany czyli z³oty genera³               
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
    * Metoda wykonuj¹ca ruch lanc¹
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
            if (gracz == gracz1 && s1 == Promocja::bez_promocji) {
                if (y_na == 8) {
                    // promocja i koniec
                    s1 = Promocja::promocja;
                    znak = "L";
                }
                else if (y_na >= 6 || y_z >= 6) {
                    // zadaj pytanie o promocje
                    if (promocja_bot == '\0') s1 = askIfPromotion();
                    if (s1 == Promocja::promocja || promocja_bot == '+')  znak = "L";
                }
            }
            if (gracz == gracz2 && s1 == Promocja::bez_promocji) {
                if (y_na == 0) {
                    // promocja i koniec
                    s1 = Promocja::promocja;
                    znak = "L";
                }
                else if (y_na <= 2 || y_z <= 2) {
                    // zadaj pytanie o promocje
                    if (promocja_bot == '\0') s1 = askIfPromotion();
                    if (s1 == Promocja::promocja || promocja_bot == '+')  znak = "L";
                }
            }
            pole->narysuj(znak, gracz);
            return true;
        }
        else return false;
    }

    /**
    * Metoda wykonaj¹ca zrzut(ponowne wystawienie lancy) do gry
    * @param p - referencja do pole na które chcemy siê poruszyæ
    * @param tmp - wskaznik figury zrzutu
    */
    void wykonajRuchZrzut(Pole& p, std::shared_ptr<Lanca> tmp) {

        // dodaj lanca na plansze gdzie ma byc 
        pole = &p;
        pole->setStatusLong("Lanca");
        pole->setStatusShort("l");
        pole->setFigura(tmp);
        pole->narysuj(znak, gracz);
    }
};