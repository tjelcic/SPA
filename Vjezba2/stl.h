#ifndef STL_H
#define STL_H
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float x,y,z;
}Vrh;

typedef struct
{
    float nor1,nor2,nor3;
    Vrh vrhovi[3];
    unsigned short nula;
}Trokut;

typedef struct
{
    Trokut *niz_trokuta;
    unsigned int broj_trokuta;
}Objekt3D;

Objekt3D *read_binary(FILE *fp);
void write_binary(Objekt3D *objekt3d, FILE *fp);
void write_txt(Objekt3D *objekt3d, FILE *fp);
void delete_obj(Objekt3D *objekt3d);

#endif
