#include <iostream>
#include <fstream>
#include <cmath>
#include "biblio_fonctions.h"

#define M_PI 3.14159265358979323846

using namespace std;

void ecrire_image_PGM(unsigned char image[dim_x][dim_z], const char* nom_fichier) { // Cette fonction va écrire une image en niveaux de gris dans un fichier PGM
    ofstream fichier(nom_fichier);

    fichier << "P2\n";
    fichier << dim_x << " " << dim_z << "\n";
    fichier << "255\n";

    for(int j = dim_z - 1; j >= 0; j--) {
        for(int i = 0; i < dim_x; i++) {
            fichier << (int)image[i][j] << " ";
        }
        fichier << endl;
    }

    fichier.close();
}

void initialiser_image(unsigned char image[dim_x][dim_z]) {
    for (int i = 0; i < dim_x; i++)
        for (int j = 0; j < dim_z; j++)
            image[i][j] = 0;
}

float deg_en_rad(float deg) {
    return deg * M_PI / 180.0;
}

float projection_axe_x(float vitesse, float angle) {
    return vitesse * cos(deg_en_rad(angle));
}

float projection_axe_z(float vitesse, float angle) {
    return vitesse * sin(deg_en_rad(angle));
}

int conv_metre_pixel_x(float x) {
    int px = (int)(x + 0.5);
    if (px < 0) return 0;
    if (px >= dim_x) return dim_x - 1;
    return px;
}

int conv_metre_pixel_z(float z) {
    int pz = (int)(z + 0.5);
    if (pz < 0) return 0;
    if (pz >= dim_z) return dim_z - 1;
    return pz;
}

float tracer_trajectoire(unsigned char image[dim_x][dim_z],float vx0, float vz0,float x0, float z0,float &vitesse_finale) {// Tracer cette trajectoire dans une image (visualisation).


    float g = 9.81;
    float t = 0;
    float dt = 0.05;

    float x, z;
    float vz;

    while (true) {

        x = x0 + vx0 * t;
        z = z0 + vz0 * t - 0.5 * g * t * t;
        vz = vz0 - g * t;

        if (z < 0) break;

        int px = conv_metre_pixel_x(x);
        int pz = conv_metre_pixel_z(z);

        if (px >= 0 && px < dim_x && pz >= 0 && pz < dim_z)
            image[px][pz] = 255;

        t += dt;

        if (x < 0 || x >= dim_x) break;
    }

    vitesse_finale = sqrt(vx0 * vx0 + vz * vz);

    return x;
}

void tracer_trajectoire_chocs_elastiques(unsigned char image[dim_x][dim_z],float vx0, float vz0,float x0, float z0) {

    float vitesse_finale;
    float x_impact = tracer_trajectoire(image, vx0, vz0, x0, z0, vitesse_finale);

    while (x_impact >= 0 && x_impact < dim_x) {
        vz0 = -vz0;
        x_impact = tracer_trajectoire(image, vx0, vz0, x_impact, 0, vitesse_finale);
    }
}


void tracer_trajectoire_chocs_inelastiques(unsigned char image[dim_x][dim_z],float vx0, float vz0,float x0, float z0,float coeff) {

    float vitesse_finale;
    float x_impact = tracer_trajectoire(image, vx0, vz0, x0, z0, vitesse_finale);

    while (x_impact >= 0 && x_impact < dim_x) {
        vz0 = -vz0 * coeff;

        if (fabs(vz0) < 0.1) break;

        x_impact = tracer_trajectoire(image, vx0, vz0, x_impact, 0, vitesse_finale);
    }
}
