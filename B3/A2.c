#include <stdio.h>
#define MAX 15

void drucke_ganzzahl(int zahlen[], int anzahl_zahlen) {
    printf("[");
    for (int i = 0; i < anzahl_zahlen; i++)
    {
        if (i != 0) {
            printf(", ");
        }
        printf("%i", zahlen[i]);
    }
    printf("]\n");
    return;
}

void bubblesort(int zahlen[], int anzahl_zahlen) {
    int mem;
    for (int i = 0; i < anzahl_zahlen; i++)
    {
        for (int n = anzahl_zahlen; n > i; n--) 
        {
            if (zahlen[i] > zahlen[n]) {
                mem = zahlen[i];
                zahlen[i] = zahlen[n];
                zahlen[n] = mem;
                i = 0;
                n = anzahl_zahlen; 
            }
        }
    }
    drucke_ganzzahl(zahlen, anzahl_zahlen);
    return;
}

int main(int argc, char const *argv[])
{
    int zahlen[] = {24, 42, 15, 1337, 420, 1};
    int anzahl_zahlen = sizeof(zahlen) / sizeof(int);
    char buf[MAX];

    printf("Input:\n");
    drucke_ganzzahl(zahlen, anzahl_zahlen);
    printf("Output (Bubblesort):\n");
    bubblesort(zahlen, anzahl_zahlen);

    printf("Now say something:\n");
    fgets(buf, MAX, stdin);
    printf("You said: %s\n", buf);

    return 0;
}
