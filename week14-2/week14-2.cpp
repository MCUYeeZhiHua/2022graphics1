#include <stdio.h>
int main()
{///�ɮ׫��СA fout �}���ɮ�(�ɦW�Awrite�Ҧ�)
    FILE * fout = fopen("file.text", "w+");
    fprintf(fout,"3.1415926\n");
    fclose(fout);///�����ɮ�

    float angle=0;
    FILE * fin = fopen("file.text", "r");
    fscanf(fin,"%f",&angle);///�S�[&�|��
    printf("Ū��F����:%f",angle);
    fclose(fin);
}
