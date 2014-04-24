#ifndef VOITURE_H_INCLUDED
#define VOITURE_H_INCLUDED
#include "route.h"
class Voiture
{
    public:

    Voiture();
    Voiture(int pos);
    // Position de la voiture sur la route

    // @m_p : la position de la voiture sur la piste.
        int m_p;
    // @m_a : la vitesse de la voiture
        int m_a;

    // maj_voiture
    // Fonction publique, met à jour l'ensemble des paramètres de la voiture.
    // @param : (route) road -> La route sur laquelle la voiture circule.
    // return void.
        void maj_voiture(Route road);

    private:

    // distance_to_nearest
    // Calcule la distance a la plus proche voiture suivante.
    // @param : (route) road -> La route sur laquelle la voiture circule.
    // Retourne le nombre de case jusqu'a la prochaine voiture (INCLUSE)
        int distance_to_nearest(Route road) const;

    // change_velocity
    // Change la vitesse d'une voiture en tenant compte de la vitesse max.
    // @param : (int) vmax -> La vitesse maximale autorisée.
    // (int) deltaV -> Le changement de vitesse désiré.
    // return void.
        void change_velocity(int vmax, int deltaV);

    // rand_value
    // Génére une valeur aléatoire entre 0 et 1.
    // Retourne ladite valeur.
        double rand_value();

    // maj_step_one
    // Effectue la première étape de la mise à jour d'une voiture
    // (Acceleration d'une unité)
    // @param : (route) road -> La route sur laquelle la voiture circule.
    // return void.
        void maj_step_one(Route road);


    // maj_step_two
    // Effectue la deuxiéme étape de la mise à jour d'une voiture
    // (Freinage de sécurité)
    // @param : (route) road -> La route sur laquelle la voiture circule.
    // return void.
        void maj_step_two(Route road);

     // maj_step_three
     // Effectue la troisiéme étape de la mise à jour d'une voiture
     // (Freinage random)
     // @param : (route) road -> La route sur laquelle la voiture circule.
     // return void.
        void maj_step_three(Route road);

     // maj_step_four
     // Effectue la quatrième étape de la mise à jour d'une voiture
     // Met en mouvement la voiture (= la déplaçe de case)
     // @param : (route) road -> La route sur laquelle la voiture circule.
     // return void.
        void maj_step_four(Route road);

        bool m_was_stopped;
};

#endif // VOITURE_H_INCLUDED
