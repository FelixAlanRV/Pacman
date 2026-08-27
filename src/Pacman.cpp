#include "Pacman.h"
#include <iostream>

Pacman::Pacman(int X, int Y, int dir)
{
    coord[0] = X;
    coord[1] = Y;
    direccion = dir;
    lastDireccion = 50;
    int contador = 0;
}

Pacman::~Pacman()
{
    // Destructor
}

int Pacman::obtenerDireccion() {
        return direccion;
    }


void Pacman::cargarMatriz(int interseccion[10][11], float* X, float*Y)
{
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 11; j++) {
            matAdy[i][j] = interseccion[i][j];
        }
    }
    ejeX = X;
    ejeY = Y;

}


void Pacman::draw(GLuint texture)
{
    glTranslatef(coord[0], coord[1], 0);
    glScalef(27, 27, 1);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);


    glBegin(GL_QUADS);

    glTexCoord2f(0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);  //Esquina inferior izquierda

    glTexCoord2f(0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);  //Esquina superior izquierda

    glTexCoord2f(1.0, 1.0);
    glVertex3f(1.0, 0.0, 0.0);  //Esquina superior derecha

    glTexCoord2f(1.0, 0.0);
    glVertex3f(1.0, 1.0, 0.0);  //Esquina inferior derecha

    glEnd();
    glDisable(GL_TEXTURE_2D);

}

void Pacman::guardarLastDireccion(int d){
    lastDireccion = d;
}

int Pacman::dirOpuesta(int dirA){
     switch(dirA){
        case 0: return 2;
        case 1: return 3;
        case 2: return 0;
        case 3: return 1;
        case 50: return 50;
    }

}

void Pacman::update()
{

    if(lastDireccion == dirOpuesta(direccion) ){
        direccion = lastDireccion;
    }

    int centroX = coord[0];
    int centroY = coord[1];

    int y = ejeX[centroX];
    int x = ejeY[centroY];


    if(y != -1 && x != -1 && matAdy[x][y] != -1)
    {

        switch(matAdy[x][y])
        {
            case 10:
                if(lastDireccion == 0  || lastDireccion == 3){
                direccion = 50;}else{
                direccion = lastDireccion;}
                break;

            case 20:
                if(lastDireccion == 2 || lastDireccion == 3){
                direccion = 50;}else{
                direccion = lastDireccion;}
                break;

            case 30:
                if(lastDireccion == 0 || lastDireccion == 1){
                direccion = 50;}else{
                direccion = lastDireccion;}
                break;

            case 40:
                if(lastDireccion == 1 || lastDireccion == 2){
                direccion = 50;}else{
                direccion = lastDireccion;}
                break;

            case 50:
                if(lastDireccion != 0){
                    direccion = lastDireccion;
                }else{
                    if(direccion == 0){
                        direccion = 50;}
                }
                break;

            case 60:
                if(lastDireccion != 1){
                    direccion = lastDireccion;
                }else{
                    if(direccion == 1){
                        direccion = 50;}
                }
                break;

            case 70:
                if(lastDireccion != 2){
                    direccion = lastDireccion;
                }else{
                    if(direccion == 2){
                        direccion = 50;}
                }
                break;

            case 80:
                if(lastDireccion != 3){
                    direccion = lastDireccion;
                }else{
                    if(direccion == 3){
                        direccion = 50;}
                }
                break;

            case 90:
                direccion = lastDireccion;
                break;

            case 99:

                if(contador == 0){
                        if(lastDireccion == 0  || lastDireccion == 2 || lastDireccion ==50){
                            direccion = 50;}else{
                                direccion = lastDireccion;
                contador = contador +1;}
                }


        }
    }

    switch(direccion)
    {

    case 0:

            coord[1] = coord[1]-1;
            break;

    case 1:
            coord[0] = coord[0]+1;
            break;

    case 2:
            coord[1] = coord[1]+1;
            break;

    case 3:
            coord[0] = coord[0]-1;
            break;

    default:
            break;
    }

}




