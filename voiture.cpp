#include "voiture.h"
using namespace std;


   Voiture::Voiture() : m_p(0) ,m_a(0) {}
   Voiture::Voiture(int pos) : m_p(pos) ,m_a(0)  {}

   void Voiture::change_velocity(int vmax, int deltaV) {
        if(m_a+deltaV > vmax) {m_a = vmax;}
            else {m_a = m_a+deltaV;}
   }

   int Voiture::distance_to_nearest(Route road) const {
    int distance = road.m_lenght+1;
    int pos = m_p;
    bool found=false;
       for(int i=1;i<=m_a;i++)
       {
           if(!found){
                int searchpos = m_p+i;
                if(m_p+i > road.m_lenght+1) {
                    searchpos = (searchpos)%(road.m_lenght+1)-1;
                }
               for (int car=0;car<road.m_road.size();car++) {
                    if(searchpos == road.m_road[car].m_p) {
                        distance = i;
                        found = true;
                        break;
                    }
               }
           }
           else break;
       }
    return distance;
   }

    double Voiture::rand_value() {
        return(double)rand() / RAND_MAX;
    }

    void Voiture::maj_step_one(Route road) {
        m_was_stopped = false;


            if (road.m_type && m_a == 0) {
                // Nous sommes en VDR.
                // La voiture était immobile
                m_was_stopped = true;
                if (rand_value() <= (double)road.m_q/100) m_a++;
            }
            else {
            if(m_a < road.m_vmax) m_a++;
            }
    }

    void Voiture::maj_step_two(Route road) {
        int d = distance_to_nearest(road);
        if(m_a >= d) {m_a = d-1;}
    }

    void Voiture::maj_step_three(Route road) {
        if (!m_was_stopped) {
            if (rand_value() <= (double)road.m_luck/100 && m_a>0) m_a--;
        }
    }

    void Voiture::maj_step_four(Route road) {
        int distance = m_p + m_a;
        if (distance > road.m_lenght) { distance = (distance%road.m_lenght+1)-2; }
        m_p = distance;
    }

    void Voiture::maj_voiture(Route road) {
        maj_step_one(road);
        maj_step_two(road);
        maj_step_three(road);
        maj_step_four(road);
    }
