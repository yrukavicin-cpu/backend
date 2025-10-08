#include <stdio.h>
#include <string.h>

int main() {
    char a[10][256];
    int i, minlen = 1000000000;

    for(i=0;i<10;i++){
        if(!fgets(a[i], sizeof(a[i]), stdin)) return 0;
        size_t L = strlen(a[i]);
        if(L>0 && a[i][L-1]=='\n'){ a[i][L-1]=0; L--; }
        if((int)L < minlen) minlen = (int)L;
    }

    for(i=0;i<10;i++){
        int L = (int)strlen(a[i]);
        if(L == minlen){
            printf("Елемент: %s | Номер: %d | Довжина: %d\n", a[i], i+1, L);
        }
    }
    return 0;
}