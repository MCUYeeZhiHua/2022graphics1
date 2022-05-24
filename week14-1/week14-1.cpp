#include <stdio.h>
int main()
{///檔案指標， fout 開啟檔案(檔名，write模式)
    FILE * fout = fopen("file.text", "w+");
     printf(     "Hellow World\n");
    fprintf(fout,"Hellow World\n");
    fclose(fout);///關閉檔案
}
