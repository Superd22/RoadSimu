#include "voiture.h"
using namespace std;


   Voiture::Voiture() : m_p(0) ,m_a(0) {}
   Voiture::Voiture(int pos) : m_p(pos) ,m_a(0)  {}

   void Voiture::change_velocity(int vmax, int deltaV) {
        if(m_a+deltaV > vmax) {m_a = vmax;}
            else {m_a = m_a+deltaV;}
   }

   int Voiture::distance_to_nearest(Route road) const {
            int distance = road.m_lenght;
            for(int i=0;i<=road.m_road.size();i++) {
                int distance_abs = abs(m_p - road.m_road[i].m_p);
                    if( distance_abs < distance  )
                        distance = distance_abs;
            }

    return distance;
   }

    double Voiture::rand_value() {
        return(double)rand() / RAND_MAX;
    }

    void Voiture::maj_step_one(Route road) {
        change_velocity(road.m_vmax,1);
    }

    void Voiture::maj_step_two(Route road) {
        int d = distance_to_nearest(road);
        if(m_a <= d) {m_a = d-1;}
    }

    void Voiture::maj_step_three(Route road) {
       if (rand_value() <= 0.5) m_a--;
    }

    void Voiture::maj_step_four(Route road) {
        int distance = m_p + m_a;
        if (distance > road.m_lenght) { distance = (distance%road.m_lenght)-1; }

        m_p = distance;
    }

    void Voiture::maj_voiture(Route road) {
        maj_step_one(road);
        maj_step_two(road);
        maj_step_three(road);
        maj_step_four(road);
    }
