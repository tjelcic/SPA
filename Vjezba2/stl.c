#include <stdio.h>
#include <stdlib.h>
#include "stl.h"

Objekt3D *read_binary(FILE *fp)
{
    Objekt3D *objekt3d = (Objekt3D *)malloc(sizeof(Objekt3D));
    fseek(fp, 80, SEEK_SET);
    fread(&(objekt3d->broj_trokuta), sizeof(unsigned int), 1, fp);
    objekt3d->niz_trokuta = (Trokut *)malloc(sizeof(Trokut) * objekt3d->broj_trokuta);
    int i = 0;
    while (!feof(fp))
    {
        fread(&(objekt3d->niz_trokuta[i++]), 50, 1, fp);
    }
    return objekt3d;
}

void write_binary(Objekt3D *objekt3d, FILE *fp)
{
    int nula[20] = {0};
    fwrite(nula, sizeof(int), 20, fp);
    fwrite(&objekt3d->broj_trokuta, sizeof(unsigned int), 1, fp);
    for (int i = 0; i < objekt3d->broj_trokuta; i++)
    {
        fwrite(&objekt3d->niz_trokuta[i], 50, 1, fp);
    }
}
void write_txt(Objekt3D *objekt3d, FILE *fp)
{
    fprintf(fp, "solid OpenSCAD_Model\n");
    for (int i = 0; i < objekt3d->broj_trokuta; i++)
    {
        fprintf(fp, "  facet normal %f %f %f \n", objekt3d->niz_trokuta[i].nor1, objekt3d->niz_trokuta[i].nor2, objekt3d->niz_trokuta[i].nor3);
        fprintf(fp, "    outer loop \n");

        for (int j = 0; j < 3; j++)
        {
            fprintf(fp, "      vertex %f %f %f\n", objekt3d->niz_trokuta[i].vrhovi[j].x, objekt3d->niz_trokuta[i].vrhovi[j].y, objekt3d->niz_trokuta[i].vrhovi[j].z);
        }
        fprintf(fp, "    endloop \n");
        fprintf(fp, "  endfacet \n");
    }
    fprintf(fp, "endsolid OpenSCAD_Model");
}

void delete_obj(Objekt3D *objekt3d)
{
    free(objekt3d->niz_trokuta);
    free(objekt3d);
}
