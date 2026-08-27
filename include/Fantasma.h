#ifndef FANTASMA_H
#define FANTASMA_H

#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Fantasma
{
    public:
        Fantasma(int, int, int);
        ~Fantasma();
        void cargarMatriz( int[10][11], float*, float*);
        void draw( GLuint );
        void update();
        int dirOpuesta(int);
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

};

#endif // FANTASMA_H
