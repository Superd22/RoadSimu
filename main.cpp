#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <ctime>

#include "voiture.h"
#include "route.h"
#include "voiture.cpp"
#include "route.cpp"
using namespace std;

#define H 80
#define W 80

char scr[H][W];
short int i, j;


// Class TIMER pour cross-plateform
// Au niveau du temps d'execution.
    class Timer {
        private:
            unsigned long startTime;
        public:
            void start() {
                startTime = clock();
            }

            unsigned long elapsedTime() {
                return ((unsigned long) clock() - startTime);
            }

            bool isTimeout(unsigned long seconds) {
                return seconds >= elapsedTime();
            }
    };

// Fonction qui remet le curseur en pos 0
    void clear_screen() {
      COORD coord = {0};
      HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
      SetConsoleCursorPosition ( h, coord );
    }

int main()
{
    Route PetiteRoute;

    char key;
    unsigned long dt = 1000; // en ms
    int acount=0;
    Timer ta;
    ta.start();
     while(true){
         if (ta.elapsedTime() > dt) {
                key='W';

                if(kbhit()) key = getch(); 	//Si on Appuis sur une touche

                    switch(key){
                        case '0': exit(0); break;

                        case 'N': PetiteRoute.add_car();break;
                        case 'n': PetiteRoute.remove_car();break;

                        case '+': dt = dt+100;break;
                        case '-': dt = dt-100;break;

                        case 'q': if(PetiteRoute.m_q>=10) PetiteRoute.m_q = PetiteRoute.m_q-10;break;
                        case 'Q': if(PetiteRoute.m_q<=90) PetiteRoute.m_q = PetiteRoute.m_q+10;break;

                        case 'p': if(PetiteRoute.m_luck>=10) PetiteRoute.m_luck = PetiteRoute.m_luck-10;break;
                        case 'P': if(PetiteRoute.m_luck<=90) PetiteRoute.m_luck = PetiteRoute.m_luck+10;break;

                        case 'm': PetiteRoute.change_type();break;
                    }

              //  clear_screen();
                clear_screen();

               // cout<<(unsigned long) ta.elapsedTime()<<endl;
               PetiteRoute.display();

                acount++;
                cout<<"\n DeltaT : "<<dt<<"ms";
                cout<<"\n "<<PetiteRoute.nmbr_car()<<" Voitures sur la route";

                // Si en version VDR
                if (PetiteRoute.m_type) {
                    cout<<"\n Type Freinage : VDR ";
                    cout<<"\n Probabilité redepart (q) :"<<PetiteRoute.m_q<<"%       ";
                }
                else {
                    cout<<"\n Type Freinage : NaSch ";
                }
                    cout<<"\n Probabilite Freinage (p) : "<<PetiteRoute.m_luck<<"%        ";

                // Remise en marche du timer.
                ta.start();
            }
        }

    return 0;
}
