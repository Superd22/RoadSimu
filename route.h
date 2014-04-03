#ifndef ROUTE_H_INCLUDED
#define ROUTE_H_INCLUDED
#include <string>
#include <vector>
#include "voiture.h"
using std::vector;

class Voiture;
class Route
{
    public:
    Route(int lenght, int type, int vmax);
    Route();

    // add_car()
    // Ajoute une voiture sur la route
    // (Ajoute une voiture au premier emplacement libre possible)
        void     add_car();

    // remove_car()
    // Supprime une voiture de la route.
    // (Suprime la voiture la plus ancienne)
        void     remove_car();

    // nmbr_car()
    // Compte le nombre de voitures présentes sur la route.
    // retourne (int) nombre de voitures.
        int      nmbr_car() const;

    // display()
    // Affiche la route a l'écran.
    // (Affichage PUIS mise-à-jour)
        void     display();

    // La longueur max de la route.
        int      m_lenght;
    // Le tableau de "voitures" sur la piste.
        vector< Voiture > m_road;
    // La vitesse maximale
        int      m_vmax;
    // La probabilité de freinage
        int      m_luck;
    // Le type de modélisation de freinage de la route.
        bool     m_type;

    private:

    // maj_route()
    // Effectue la mise à jour de toutes les voitures sur la route.
    // return void.
        void     maj_route();


};

#endif // ROUTE_H_INCLUDED
