#ifndef PACMAN_H
#define PACMAN_H

#include <GL/glut.h>

class Pacman
{
     public:
        Pacman(int, int, int);
        ~Pacman();
        void cargarMatriz( int[10][11], float*, float*);
        void draw(GLuint);
        void update();
        void guardarLastDireccion(int);
        int dirOpuesta(int);
        int obtenerDireccion();
        float getX();
        float getY();
        void reset(int X, int Y, int dir);

    protected:

        private:
        int matAdy[10][11];
        float* ejeX;
        float* ejeY;
        float coord[2];
        int direccion;
        int lastDireccion;
        int contador;

};

#endif // PACMAN_H
