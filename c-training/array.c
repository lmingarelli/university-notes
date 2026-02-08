#include <stdio.h>

int main() {
    // Si valorizzano con {}
    int a[5] = {10, 5, 50, 100, 7};
    printf("%d\n", a[2]);

    // Le stringhe in C sono array di char.
    // Il C sa che una stringa è terminata se incontra il valore nullo
    // ossia lo 0 (e non il carattere ASCII 0).
    char str[7] = {'h', 'e', 'l', 'l', '0', '!', 0};
    int i = 0;
    while (str[i] != 0){
        printf("%c", str[i]);
        i++;
    }
    printf("\n");

    // Le stringhe si possono inizializzare ovviamente anche cosi ma non 
    // inserendo la dimensione nelle [] andiamo a far fare al C un
    // allocazione automatica in base al valore iniziale.
    char str2[] = "hello";
    printf("%s of size %llu\n", str2, sizeof(str2));

    return 1;
}
