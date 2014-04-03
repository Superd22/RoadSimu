#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <ctime>
#include <conio.h>
#include <queue>
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
                return ((unsigned long) clock() - startTime) / CLOCKS_PER_SEC;
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
    unsigned long dt = 10; //in seconds
    int acount=0;
    Timer ta;
    ta.start();
     while(true){

         if (ta.elapsedTime() > dt/1000) {
         //  if (true) {
                key='W';

                if(kbhit()) key = getch(); 	//Si on Appuis sur une touche

                    switch(key){
                        case '0': exit(0); break;
                        case 'n': PetiteRoute.add_car();break;
                        case 'b': PetiteRoute.remove_car();break;
                        case '+': dt = dt+100;break;
                        case '-': dt = dt-100;break;
                    }

                clear_screen();
                clear_screen();
                PetiteRoute.display();

                acount++;
                cout<<acount;
                cout<<"\n DeltaT : "<<dt<<" secondes";
                cout<<"\n "<<PetiteRoute.nmbr_car()<<" Voitures sur la route";
                // Remise en marche du timer.
                ta.start();
            }
        }

    return 0;
}
