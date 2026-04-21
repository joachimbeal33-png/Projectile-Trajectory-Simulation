#include <iostream>
#include "biblio_fonctions.h"

using namespace std;

int main() {
    unsigned char image[dim_x][dim_z];
    initialiser_image(image);

    int choix;
    float v0, angle;
    float x0, z0;
    float coeff = 1.0;

    float vitesse_finale = 0;
    float distance = 0;

    cout << "--- Menu Simulation ---" << endl;
    cout << "1. Depart origine" << endl;
    cout << "2. Depart position et hauteur" << endl;
    cout << "3. Chocs elastiques" << endl;
    cout << "4. Chocs inelastiques" << endl;
    cout << "Votre choix : ";
    cin >> choix;

    cout << "Position initiale x0 (m) : ";
    cin >> x0;

    cout << "Hauteur initiale z0 (m) : ";
    cin >> z0;

    cout << "Vitesse initiale (m/s) : ";
    cin >> v0;

    cout << "Angle (degres) : ";
    cin >> angle;

    float vx = projection_axe_x(v0, angle);
    float vz = projection_axe_z(v0, angle);

    switch(choix) { // Ici on va mettre le choix que l'on souhaite

        case 1:// Ici on va tracer un seul rebond avec une position initiale de 0 et une hauteur initiale à 0
            x0 = 0;
            z0 = 0;
            distance = tracer_trajectoire(image, vx, vz, x0, z0, vitesse_finale);//lance le calcul de trajectoire, dessine la trajectoire dans l’image et va récupérer la valeur envoyée
            break;

        case 2:// Ici on va tracer un seul rebond avec une position initiale de 0 mais avec  une hauteur initiale saisie par l'utilisateur
            distance = tracer_trajectoire(image, vx, vz, x0, z0, vitesse_finale);
            break;

        case 3:// Ici on va tracer le même rebond jusqu'à l'infini avec une position initiale qui peut varier selon l'utilisateur et de même pour la hauteur initiale
            tracer_trajectoire_chocs_elastiques(image, vx, vz, x0, z0);
            cout << "Simulation avec rebonds elastiques." << endl;
            break;

        case 4:// Ici on va tracer différent rebond qui vu diminuer comme ici il y a un coefficient directeur, toujours avec une position initiale qui peut varier selon l'utilisateur et de même pour la hauteur initiale
            cout << "Coefficient de restitution (0 a 1) : ";
            cin >> coeff;
            tracer_trajectoire_chocs_inelastiques(image, vx, vz, x0, z0, coeff);
            cout << "Simulation avec rebonds inelastiques." << endl;
            break;

        default:// Si l'utilisateur entre un nombre au supérieur à 4, ce message s'affichera
            cout << "Choix invalide !" << endl;
            return 1;
    }

    // Affichage résultats
    if (choix == 1 || choix == 2) {
        cout << "Distance parcourue : " << distance << " m" << endl;
        cout << "Vitesse a l'impact : " << vitesse_finale << " m/s" << endl;
    }

    ecrire_image_PGM(image, "trajectoire.pgm");

    cout << "Image generee : trajectoire.pgm" << endl;

    return 0;
}
