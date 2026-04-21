#ifndef BIBLIO_FONCTIONS_H_INCLUDED
#define BIBLIO_FONCTIONS_H_INCLUDED

#define dim_x 2000
#define dim_z 250
void ecrire_image_PGM(unsigned char image[dim_x][dim_z], const char* nom_fichier);
void initialiser_image(unsigned char image[dim_x][dim_z]);

float projection_axe_x(float vitesse, float angle);
float projection_axe_z(float vitesse, float angle);
float deg_en_rad(float deg);

float tracer_trajectoire(unsigned char image[dim_x][dim_z],float vx0, float vz0,float x0, float z0,float &vitesse_finale);

int conv_metre_pixel_x(float x);
int conv_metre_pixel_z(float z);

void tracer_trajectoire_chocs_elastiques(unsigned char image[dim_x][dim_z],float vx0, float vz0, float x0, float z0);

void tracer_trajectoire_chocs_inelastiques(unsigned char image[dim_x][dim_z],float vx0, float vz0, float x0, float z0, float coeff);

#endif
