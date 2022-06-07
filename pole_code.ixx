module;

#include <iostream>
#include <string>
#include <thread>
#include <future>
#include <memory>

export module pole_code;
/*
import <iostream>;
import <string>;
import <thread>;            
import <future>;
import <memory>;
*/
export import zasady_koniec_reszta;

void Pole::narysuj(std::string s, Gracz g) {
    std::string kolor;
    if (g == Gracz::gracz1) kolor = "Red";
    else if (g == Gracz::gracz2) kolor = "Blue";
    else kolor = "White";
    std::cout << "\033[48;2;40;40;40m";
    wstaw_tekst(x * 2 + 4, y * 2 + 4, s, kolor);
    std::cout << "\033[49m";
}

// git - thread - async
bool Pole::Ruch(Pole& pole, Pole** gra, char promocja_bot) {
    bool ruch = false;
    if (status == "Pionek") {
        ruch = p->wykonajRuch(pole, promocja_bot);
    }
    else if (status == "Lanca") {
        ruch = l->wykonajRuch(pole, gra, promocja_bot);
    }
    else if (status == "Skoczek") {
        ruch = n->wykonajRuch(pole, promocja_bot);
    }
    else if (status == "Srebrny Genera³") {
        ruch = s->wykonajRuch(pole, promocja_bot);
    }
    else if (status == "Z³oty Genera³") {
        ruch = g->wykonajRuch(pole);
    }
    else if (status == "Goniec") {
        ruch = b->wykonajRuch(pole, gra, promocja_bot);
    }
    else if (status == "Wie¿a") {
        ruch = r->wykonajRuch(pole, gra, promocja_bot);
    }
    else if (status == "Król") {
        ruch = k->wykonajRuch(pole);
    }
    return ruch;
}

// git - thread - async
bool Pole::ifBicie(Pole pole) {
    if (pole.status != "Pionek" && pole.status != "Lanca" && pole.status != "Skoczek" && pole.status != "Srebrny Genera³" && pole.status != "Z³oty Genera³" && pole.status != "Goniec" && pole.status != "Wie¿a" && pole.status != "Król") {
        return false;
    }
    else {
        return true;
    }
}

// git - thread - async  
bool Pole::wykonajRuch(Pole& pole, FiguryGracza& figury, Gracz ruchGracza, Pole** gra, bool& krol_zbiry, char promocja_bot) {


    std::future<bool> fut1 = std::async(std::launch::async, [&] { return Ruch(pole, gra, promocja_bot); }); // thread 1 
    std::future<bool> fut2 = std::async(std::launch::async, [&] { return ifBicie(pole); }); // thread 2 
    bool ruch = fut1.get();
    bool czyJestBicie = fut2.get();

    // sprzatanie po ruchu
    // przenosi zbita figure do 'inventory' gracza aby mogl ja wysawic jak chce
    if (ruch && czyJestBicie) {

        if (pole.getStatusShort() == "p") {
            pole.p->setPromotion(Promocja::bez_promocji); // figura traci promocje po zbiciu 
            pole.p->setZnak("p");
            if (ruchGracza == gracz2) pole.p->setGracz(gracz2);
            else pole.p->setGracz(gracz1);
            pole.p->resetPoleFigura();
            figury.dodaj(pole.p);
        }
        else if (pole.getStatusShort() == "l") {
            pole.l->setPromotion(Promocja::bez_promocji);
            pole.l->setZnak("l");
            if (ruchGracza == gracz2) pole.l->setGracz(gracz2);
            else pole.l->setGracz(gracz1);
            pole.l->resetPoleFigura();
            figury.dodaj(pole.l);
        }
        else if (pole.getStatusShort() == "n") {
            pole.n->setPromotion(Promocja::bez_promocji);
            pole.n->setZnak("n");
            if (ruchGracza == gracz2)  pole.n->setGracz(gracz2);
            else  pole.n->setGracz(gracz1);
            pole.n->resetPoleFigura();
            figury.dodaj(pole.n);
        }
        else if (pole.getStatusShort() == "s") {
            pole.s->setPromotion(Promocja::bez_promocji);
            pole.s->setZnak("s");
            if (ruchGracza == gracz2)  pole.s->setGracz(gracz2);
            else  pole.s->setGracz(gracz1);
            pole.s->resetPoleFigura();
            figury.dodaj(pole.s);
        }
        else if (pole.getStatusShort() == "g") {
            pole.g->setPromotion(Promocja::bez_promocji);
            pole.g->setZnak("g");
            if (ruchGracza == gracz2)  pole.g->setGracz(gracz2);
            else  pole.g->setGracz(gracz1);
            pole.g->resetPoleFigura();
            figury.dodaj(pole.g);
        }
        else if (pole.getStatusShort() == "b") {
            pole.b->setPromotion(Promocja::bez_promocji);
            pole.b->setZnak("b");
            if (ruchGracza == gracz2)  pole.b->setGracz(gracz2);
            else  pole.b->setGracz(gracz1);
            pole.b->resetPoleFigura();
            figury.dodaj(pole.b);
        }
        else if (pole.getStatusShort() == "r") {
            pole.r->setPromotion(Promocja::bez_promocji);
            pole.r->setZnak("r");
            if (ruchGracza == gracz2)  pole.r->setGracz(gracz2);
            else  pole.r->setGracz(gracz1);
            pole.r->resetPoleFigura();
            figury.dodaj(pole.r);
        }
        else if (pole.getStatusShort() == "K") {
            krol_zbiry = true;
            // no jak zbijesz krola to koniec gry 
        }
    }

    // czsci pole z ktorego sie ruszala figura i ustawia na nowym 
    if (ruch) {
        if (status == "Pionek" || pole.status == "Pionek") {
            pole.p = p;
            p = nullptr;
        }
        if (status == "Lanca" || pole.status == "Lanca") {
            pole.l = l;
            l = nullptr;
        }
        if (status == "Skoczek" || pole.status == "Skoczek") {
            pole.n = n;
            n = nullptr;
        }
        if (status == "Srebrny Genera³" || pole.status == "Srebrny Genera³") {
            pole.s = s;
            s = nullptr;
        }
        if (status == "Z³oty Genera³" || pole.status == "Z³oty Genera³") {
            pole.g = g;
            g = nullptr;
        }
        if (status == "Goniec" || pole.status == "Goniec") {
            pole.b = b;
            b = nullptr;
        }
        if (status == "Wie¿a" || pole.status == "Wie¿a") {
            pole.r = r;
            r = nullptr;
        }
        if (status == "Król" || pole.status == "Król") {
            pole.k = k;
            k = nullptr;
        }
        pole.status_short = status_short;
        pole.status = status;
        status = "";
        status_short = "";
    }
    return ruch;
}

bool Pole::czySzach(Pole** pole, Gracz gracz) {

    // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------    
    // sprawdzanie w dol GIT
    if (8 >= (y + 1)) {
        for (int i = y + 1; i < 9; i++) {
            if (!pole[x][i].isEmptyPole()) {
                if (pole[x][i].getStatusShort() == "l") {
                    if (pole[x][i].isEmptyLanca()->getGracz() == gracz2) {
                        if (pole[x][i].isEmptyLanca()->getPromotion() == Promocja::bez_promocji) {
                            if (pole[x][i].isEmptyLanca()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                            else break; // jest tam lanca ale twojego gracza wiec git nie ma szacha stad
                        }
                    }
                }
                else if (pole[x][i].getStatusShort() == "r") {
                    if (pole[x][i].isEmptyWieza()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                    else break; // jest tam wieza/promowana wieza ale twojego gracza wiec git nie ma szacha stad                   
                }
                else break; // stoi cos po drodze ale nie jest to cos co atakuje krola 
            }
        }
    }

    // sprawdzanie w gora GIT
    if ((y - 1) >= 0) {
        for (int i = y - 1; i >= 0; i--) {
            if (!pole[x][i].isEmptyPole()) {
                if (pole[x][i].getStatusShort() == "l") {
                    if (pole[x][i].isEmptyLanca()->getGracz() == gracz1) {
                        if (pole[x][i].isEmptyLanca()->getPromotion() == Promocja::bez_promocji) {
                            if (pole[x][i].isEmptyLanca()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                            else break;
                        }
                    }
                }
                else if (pole[x][i].getStatusShort() == "r") {
                    if (pole[x][i].isEmptyWieza()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                    else break; // jest tam wieza/promowana wieza ale twojego gracza wiec git nie ma szacha stad                   
                }
                else break; // stoi cos po drodze ale nie jest to cos co atakuje krola 
            }
        }
    }

    // sprawdzanie w prawo GIT
    if (8 >= (x + 1)) {
        for (int i = x + 1; i < 0; i++) {
            if (!pole[i][y].isEmptyPole()) {
                // nie jest puste       
                if (pole[i][y].getStatusShort() == "r") {
                    if (pole[i][y].isEmptyWieza()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                    else break; // jest tam wieza/promowana wieza ale twojego gracza wiec git nie ma szacha stad                   
                }
                else break; // stoi cos po drodze ale nie jest to cos co atakuje krola            
            }
        }
    }

    // sprawdzanie w lewo GIT
    if ((x - 1) >= 0) {
        for (int i = x - 1; i >= 0; i--) {
            if (!pole[i][y].isEmptyPole()) {
                // nie jest puste       
                if (pole[i][y].getStatusShort() == "r") {
                    if (pole[i][y].isEmptyWieza()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                    else break; // jest tam wieza/promowana wieza ale twojego gracza wiec git nie ma szacha stad                   
                }
                else break; // stoi cos po drodze ale nie jest to cos co atakuje krola            
            }
        }
    }
    // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------    
    // skosy po d³ugoœci GIT
    for (int i = 1; i < 9; i++) {
        if (((x - i) <= 0) || ((y - i) <= 0)) break; // je¿eli index poni¿ej 0
        else if (!pole[x - i][y - i].isEmptyPole()) {
            // nie jest puste
            if (pole[x - i][y - i].getStatusShort() == "b") {
                if (pole[x - i][y - i].isEmptyGoniec()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                else break; // jest tam wieza/promowana goniec ale twojego gracza wiec git nie ma szacha stad                   
            }
            else break; // stoi cos po drodze ale nie jest to cos co atakuje krola 
        }
    }

    // skosy po d³ugoœci GIT
    for (int i = 1; i < 9; i++) {
        if (((x - i) <= 0) || ((y + i) >= 8)) break; // je¿eli index poni¿ej 0
        else if (!pole[x - i][y + i].isEmptyPole()) {
            // nie jest puste
            if (pole[x - i][y + i].getStatusShort() == "b") {
                if (pole[x - i][y + i].isEmptyGoniec()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                else break; // jest tam wieza/promowana goniec ale twojego gracza wiec git nie ma szacha stad                   
            }
            else break; // stoi cos po drodze ale nie jest to cos co atakuje krola         
        }
    }

    // skosy po d³ugoœci GIT
    for (int i = 1; i < 9; i++) {
        if (((x + i) >= 8) || ((y - i) <= 0)) break; // je¿eli index poni¿ej 0
        else if (!pole[x + i][y - i].isEmptyPole()) {
            // nie jest puste       
            if (pole[x + i][y - i].getStatusShort() == "b") {
                if (pole[x + i][y - i].isEmptyGoniec()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                else break; // jest tam wieza/promowana goniec ale twojego gracza wiec git nie ma szacha stad                   
            }
            else break; // stoi cos po drodze ale nie jest to cos co atakuje krola   
        }
    }

    // skosy po d³ugoœci GIT
    for (int i = 1; i < 9; i++) {
        if (((x + i) >= 8) || ((y + i) >= 8)) break; // je¿eli index poni¿ej 0
        else if (!pole[x + i][y + i].isEmptyPole()) {
            // nie jest puste
            if (pole[x + i][y + i].getStatusShort() == "b") {
                if (pole[x + i][y + i].isEmptyGoniec()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                else break; // jest tam wieza/promowana goniec ale twojego gracza wiec git nie ma szacha stad                   
            }
            else break; // stoi cos po drodze ale nie jest to cos co atakuje krola                        
        }
    }
    // -----------------------------------------------------     
     // 1 pole do przodu (z do³u) GIT
    if (8 >= (y + gracz) && (y + gracz) >= 0) {
        if (!pole[x][y + gracz].isEmptyPole()) {
            // jezeli tu stoi figura przeciwnika: p, dGen+(P,L,N,S), mGen
            if (pole[x][y + gracz].getStatusShort() == "p") {
                if (pole[x][y + gracz].isEmptyPion()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
            }
            else if (pole[x][y + gracz].getStatusShort() == "l") {
                if (pole[x][y + gracz].isEmptyLanca()->getPromotion() == Promocja::promocja) {
                    if (pole[x][y + gracz].isEmptyLanca()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
            else if (pole[x][y + gracz].getStatusShort() == "n") {
                if (pole[x][y + gracz].isEmptySkoczek()->getPromotion() == Promocja::promocja) {
                    if (pole[x][y + gracz].isEmptySkoczek()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
            else if (pole[x][y + gracz].getStatusShort() == "s") {
                if (pole[x][y + gracz].isEmptymGeneral()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
            }
            else if (pole[x][y + gracz].getStatusShort() == "g") {
                if (pole[x][y + gracz].isEmptydGeneral()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
            }
            else if (pole[x][y + gracz].getStatusShort() == "K") {
                if (pole[x][y + gracz].isEmptyKrol()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
            }
            else if (pole[x][y + gracz].getStatusShort() == "g") {
                if (pole[x][y + gracz].isEmptyGoniec()->getPromotion() == Promocja::promocja) {
                    if (pole[x][y + gracz].isEmptyGoniec()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
        }
    }

    // w ty³ jeden GIT
    if (8 >= (y - gracz) && (y - gracz) >= 0) {
        if (!pole[x][y - gracz].isEmptyPole()) {
            if (pole[x][y - gracz].getStatusShort() == "g") {
                if (pole[x][y - gracz].isEmptydGeneral()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
            }
            else if (pole[x][y - gracz].getStatusShort() == "K") {
                if (pole[x][y - gracz].isEmptyKrol()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
            }
            else if (pole[x][y - gracz].getStatusShort() == "p") {
                if (pole[x][y - gracz].isEmptyPion()->getPromotion() == Promocja::promocja) {
                    if (pole[x][y - gracz].isEmptyPion()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
            else if (pole[x][y - gracz].getStatusShort() == "n") {
                if (pole[x][y - gracz].isEmptySkoczek()->getPromotion() == Promocja::promocja) {
                    if (pole[x][y - gracz].isEmptySkoczek()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
            else if (pole[x][y - gracz].getStatusShort() == "s") {
                if (pole[x][y - gracz].isEmptymGeneral()->getPromotion() == Promocja::promocja) {
                    if (pole[x][y - gracz].isEmptymGeneral()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
            else if (pole[x][y - gracz].getStatusShort() == "l") {
                if (pole[x][y - gracz].isEmptyLanca()->getPromotion() == Promocja::promocja) {
                    if (pole[x][y - gracz].isEmptyLanca()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
            else if (pole[x][y - gracz].getStatusShort() == "g") {
                if (pole[x][y - gracz].isEmptyGoniec()->getPromotion() == Promocja::promocja) {
                    if (pole[x][y - gracz].isEmptyGoniec()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
        }
    }
    // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // skos prawy-dol (figura atakuje z lewej-gory) GIT
    if ((8 >= (x + gracz) && (x + gracz) >= 0) && (8 >= (y + gracz) && (y + gracz) >= 0)) {
        // K,mGen,
        if (!pole[x + gracz][y + gracz].isEmptyPole()) {
            if (pole[x + gracz][y + gracz].getStatusShort() == "g") {
                if (pole[x + gracz][y + gracz].isEmptydGeneral()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
            }
            else if (pole[x + gracz][y + gracz].getStatusShort() == "s") {
                if (pole[x + gracz][y + gracz].isEmptymGeneral()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
            }
            else if (pole[x + gracz][y + gracz].getStatusShort() == "K") {
                if (pole[x + gracz][y + gracz].isEmptyKrol()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
            }

            else if (pole[x + gracz][y + gracz].getStatusShort() == "p") {
                if (pole[x + gracz][y + gracz].isEmptyPion()->getPromotion() == Promocja::promocja) {
                    if (pole[x + gracz][y + gracz].isEmptyPion()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
            else if (pole[x + gracz][y + gracz].getStatusShort() == "n") {
                if (pole[x + gracz][y + gracz].isEmptySkoczek()->getPromotion() == Promocja::promocja) {
                    if (pole[x + gracz][y + gracz].isEmptySkoczek()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
            else if (pole[x + gracz][y + gracz].getStatusShort() == "l") {
                if (pole[x + gracz][y + gracz].isEmptyLanca()->getPromotion() == Promocja::promocja) {
                    if (pole[x + gracz][y + gracz].isEmptyLanca()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
            else if (pole[x + gracz][y + gracz].getStatusShort() == "b") {
                if (pole[x + gracz][y + gracz].isEmptyWieza()->getPromotion() == Promocja::promocja) {
                    if (pole[x + gracz][y + gracz].isEmptyWieza()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
        }
    }

    // skos lewa-dol (figura atakuje z prawej-gory) GIT
    if ((8 >= (x - gracz) && (x - gracz) >= 0) && (8 >= (y + gracz) && (y + gracz) >= 0)) {
        // K,mGen,
        if (!pole[x - gracz][y + gracz].isEmptyPole()) {
            if (pole[x - gracz][y + gracz].getStatusShort() == "g") {
                if (pole[x - gracz][y + gracz].isEmptydGeneral()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
            }
            else if (pole[x - gracz][y + gracz].getStatusShort() == "s") {
                if (pole[x - gracz][y + gracz].isEmptymGeneral()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
            }
            else if (pole[x - gracz][y + gracz].getStatusShort() == "K") {
                if (pole[x - gracz][y + gracz].isEmptyKrol()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
            }

            else if (pole[x - gracz][y + gracz].getStatusShort() == "p") {
                if (pole[x - gracz][y + gracz].isEmptyPion()->getPromotion() == Promocja::promocja) {
                    if (pole[x - gracz][y + gracz].isEmptyPion()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
            else if (pole[x - gracz][y + gracz].getStatusShort() == "n") {
                if (pole[x - gracz][y + gracz].isEmptySkoczek()->getPromotion() == Promocja::promocja) {
                    if (pole[x - gracz][y + gracz].isEmptySkoczek()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
            else if (pole[x - gracz][y + gracz].getStatusShort() == "l") {
                if (pole[x - gracz][y + gracz].isEmptyLanca()->getPromotion() == Promocja::promocja) {
                    if (pole[x - gracz][y + gracz].isEmptyLanca()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
            else if (pole[x - gracz][y + gracz].getStatusShort() == "b") {
                if (pole[x - gracz][y + gracz].isEmptyWieza()->getPromotion() == Promocja::promocja) {
                    if (pole[x - gracz][y + gracz].isEmptyWieza()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
        }
    }

    // skos prawy-gora (figura atakuje z lewej-dolu) GIT
    if ((8 >= (x + gracz) && (x + gracz) >= 0) && (8 >= (y - gracz) && (y - gracz) >= 0)) {
        // K,mGen,
        if (!pole[x + gracz][y - gracz].isEmptyPole()) {
            if (pole[x + gracz][y - gracz].getStatusShort() == "K") {
                if (pole[x + gracz][y - gracz].isEmptyKrol()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
            }
            else if (pole[x + gracz][y - gracz].getStatusShort() == "s") {
                if (pole[x + gracz][y - gracz].isEmptymGeneral()->getPromotion() == Promocja::bez_promocji) {
                    if (pole[x + gracz][y - gracz].isEmptymGeneral()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
            else if (pole[x + gracz][y - gracz].getStatusShort() == "b") {
                if (pole[x + gracz][y - gracz].isEmptyWieza()->getPromotion() == Promocja::promocja) {
                    if (pole[x + gracz][y - gracz].isEmptyWieza()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
        }
    }

    // skos lewy-gora (figura atakuje z prawego-dolu) GIT
    if ((8 >= (x - gracz) && (x - gracz) >= 0) && (8 >= (y - gracz) && (y - gracz) >= 0)) {
        // K,mGen,
        if (!pole[x - gracz][y - gracz].isEmptyPole()) {
            if (pole[x - gracz][y - gracz].getStatusShort() == "K") {
                if (pole[x - gracz][y - gracz].isEmptyKrol()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
            }
            else if (pole[x - gracz][y - gracz].getStatusShort() == "s") {
                if (pole[x - gracz][y - gracz].isEmptymGeneral()->getPromotion() == Promocja::bez_promocji) {
                    if (pole[x - gracz][y - gracz].isEmptymGeneral()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
            else if (pole[x - gracz][y - gracz].getStatusShort() == "b") {
                if (pole[x - gracz][y - gracz].isEmptyWieza()->getPromotion() == Promocja::promocja) {
                    if (pole[x - gracz][y - gracz].isEmptyWieza()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
        }
    }
    // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    // skoczek
    if ((x - 1 > 0) && (8 >= (y + (2 * gracz)) && (y + (2 * gracz)) >= 0)) {
        if (!pole[x - 1][y + (2 * gracz)].isEmptyPole()) {
            if (pole[x - 1][y + (2 * gracz)].getStatusShort() == "n") {
                if (pole[x - 1][y + (2 * gracz)].isEmptySkoczek()->getPromotion() == Promocja::bez_promocji) {
                    if (pole[x - 1][y + (2 * gracz)].isEmptySkoczek()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
        }
    }

    if ((x + 1 < 9) && (8 >= (y + (2 * gracz)) && (y + (2 * gracz)) >= 0)) {
        if (!pole[x + 1][y + (2 * gracz)].isEmptyPole()) {
            if (pole[x + 1][y + (2 * gracz)].getStatusShort() == "n") {
                if (pole[x + 1][y + (2 * gracz)].isEmptySkoczek()->getPromotion() == Promocja::bez_promocji) {
                    if (pole[x + 1][y + (2 * gracz)].isEmptySkoczek()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
        }
    }
    // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------    
    // w prawy bok GIT
    if (x + 1 <= 8) {
        if (!pole[x + 1][y].isEmptyPole()) {
            if (pole[x + 1][y].getStatusShort() == "g") {
                if (pole[x + 1][y].isEmptydGeneral()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
            }
            else if (pole[x + 1][y].getStatusShort() == "K") {
                if (pole[x + 1][y].isEmptyKrol()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
            }
            else if (pole[x + 1][y].getStatusShort() == "p") {
                if (pole[x + 1][y].isEmptyPion()->getPromotion() == Promocja::promocja) {
                    if (pole[x + 1][y].isEmptyPion()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
            else if (pole[x + 1][y].getStatusShort() == "n") {
                if (pole[x + 1][y].isEmptySkoczek()->getPromotion() == Promocja::promocja) {
                    if (pole[x + 1][y].isEmptySkoczek()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
            else if (pole[x + 1][y].getStatusShort() == "s") {
                if (pole[x + 1][y].isEmptymGeneral()->getPromotion() == Promocja::promocja) {
                    if (pole[x + 1][y].isEmptymGeneral()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
            else if (pole[x + 1][y].getStatusShort() == "l") {
                if (pole[x + 1][y].isEmptyLanca()->getPromotion() == Promocja::promocja) {
                    if (pole[x + 1][y].isEmptyLanca()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
            else if (pole[x + 1][y].getStatusShort() == "g") {
                if (pole[x + 1][y].isEmptyGoniec()->getPromotion() == Promocja::promocja) {
                    if (pole[x + 1][y].isEmptyGoniec()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
        }
    }

    // w lewy bok GIT
    if (x - 1 >= 0) {
        if (!pole[x - 1][y].isEmptyPole()) {
            if (pole[x - 1][y].getStatusShort() == "g") {
                if (pole[x - 1][y].isEmptydGeneral()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
            }
            else if (pole[x - 1][y].getStatusShort() == "K") {
                if (pole[x - 1][y].isEmptyKrol()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
            }
            else if (pole[x - 1][y].getStatusShort() == "p") {
                if (pole[x - 1][y].isEmptyPion()->getPromotion() == Promocja::promocja) {
                    if (pole[x - 1][y].isEmptyPion()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
            else if (pole[x - 1][y].getStatusShort() == "n") {
                if (pole[x - 1][y].isEmptySkoczek()->getPromotion() == Promocja::promocja) {
                    if (pole[x - 1][y].isEmptySkoczek()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
            else if (pole[x - 1][y].getStatusShort() == "s") {
                if (pole[x - 1][y].isEmptymGeneral()->getPromotion() == Promocja::promocja) {
                    if (pole[x - 1][y].isEmptymGeneral()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
            else if (pole[x - 1][y].getStatusShort() == "l") {
                if (pole[x - 1][y].isEmptyLanca()->getPromotion() == Promocja::promocja) {
                    if (pole[x - 1][y].isEmptyLanca()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
            else if (pole[x - 1][y].getStatusShort() == "g") {
                if (pole[x - 1][y].isEmptyGoniec()->getPromotion() == Promocja::promocja) {
                    if (pole[x - 1][y].isEmptyGoniec()->getGracz() != gracz) return true; // figura jest rozna od gracza pola
                }
            }
        }
    }
    // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------    
    return false;

}

