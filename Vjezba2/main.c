#include <stdio.h>
#include <stdlib.h>
#include "stl.h"

int main()
{
    Objekt3D *read_binary(FILE *fp);

    FILE *fp1 = fopen("primjerbin.stl", "rb");
    Objekt3D *objekt3d = read_binary(fp1);
    fclose(fp1);

    FILE *fp2 = fopen("primjerbin1.stl", "wb");
    write_binary(objekt3d, fp2);
    fclose(fp2);

    FILE *fp3 = fopen("primjertxt1.stl", "w+");
    write_txt(objekt3d, fp3);
    fclose(fp3);

    printf("Binary and text files created.");

    delete_obj(objekt3d);
    return 0;
}
