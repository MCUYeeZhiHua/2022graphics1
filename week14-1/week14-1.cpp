#include <stdio.h>
int main()
{///�ɮ׫��СA fout �}���ɮ�(�ɦW�Awrite�Ҧ�)
    FILE * fout = fopen("file.text", "w+");
     printf(     "Hellow World\n");
    fprintf(fout,"Hellow World\n");
    fclose(fout);///�����ɮ�
}
