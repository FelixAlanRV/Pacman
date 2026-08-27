#include "Fantasma.h"
#include <iostream>

Fantasma::Fantasma(int X, int Y, int dir)
{
    coord[0] = X;
    coord[1] = Y;
    direccion = dir;
}

Fantasma::~Fantasma()
{
    //dtor
}

float Fantasma::getX() {
    return coord[0];
}

float Fantasma::getY() {
    return coord[1];
}

void Fantasma::reset(int X, int Y, int dir) {
    coord[0] = X;
    coord[1] = Y;
    direccion = dir;
}


void Fantasma::cargarMatriz(int interseccion[10][11], float* X, float *Y)
{
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 11; j++) {
            matAdy[i][j] = interseccion[i][j];
        }
    }
    ejeX = X;
    ejeY = Y;
}

void Fantasma::draw( GLuint texture )
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

int Fantasma::dirOpuesta(int dirA){
    switch(dirA){
        case 0: return 2;
        case 1: return 3;
        case 2: return 0;
        case 3: return 1;
    }
}

void Fantasma::update()
{

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
    int centroX = coord[0];
    int centroY = coord[1];

    int y = ejeX[centroX];
    int x = ejeY[centroY];

    if(x != -1 && y != -1 && matAdy[x][y] != -1)
    {
        int random;

        switch(matAdy[x][y])
        {
            case 10:

                do{
                    random = rand() % 3;
                }while(random == 0  || random == dirOpuesta(direccion));
                direccion = random;
                break;
            case 20:

                do{
                    random = rand() % 2;
                }while(random == 2 || random == dirOpuesta(direccion));
                direccion = random;
                break;

            case 30:
                do{
                    random = rand() % 4;
                }while(random == 1 || random == 0  || random == dirOpuesta(direccion));
                direccion = random;
                break;

            case 40:
                do{
                    random = rand () % 4;
                }while(random == 2 || random == 1 || random == dirOpuesta(direccion));
                direccion = random;
                break;

            case 50:
                do{
                    random = rand() % 4;
                }while(random == 0 || random == dirOpuesta(direccion));
                direccion = random;
                break;

            case 60:
                do{
                    random = rand() % 4;
                }while(random == 1 || random == dirOpuesta(direccion));
                direccion = random;
                break;

            case 70:
                do{
                    random = rand() % 4;
                }while(random == 2 || random == dirOpuesta(direccion));
                direccion = random;
                break;

            case 80:
                do{
                    random = rand() % 3;
                }while(random == 3 || random == dirOpuesta(direccion));
                direccion = random;
                break;

            case 90:

                do{
                    random = rand() % 3;
                }while(random == dirOpuesta(direccion));
                direccion = random;
                break;

            case 5:

                do{
                    random = rand() %4 ;
                }while(random == 0 || random == 2 || random == dirOpuesta(direccion));
                direccion = random;
                break;

            case 6:

                direccion = 1;
                break;

            case 7:

                direccion = 0;
                break;

            case 8:

                direccion = 3;
                break;
            }
        }
    }


