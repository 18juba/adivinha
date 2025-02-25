#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Biblioteca pra usar a função time no rand

int main() {

    int nivel, valorMaximo;
    
    print("Qual o nivel de dificuldade ?\n");
    print("1 - Facil\n");
    print("2 - Medio\n");
    print("3 - Dificil\n");
    print("4 - Imposivel\n");
    scanf("%d", &nivel);

    switch(nivel) {
        case 1:
            valorMaximo = 10;
            break;
        case 2:
            valorMaximo = 100;
            break;
        case 3:
            valorMaximo = 1000;
            break;
        case 4:
            valorMaximo = 10000;
            break;
        default:
            printf("Nível inválido. Definindo como Medio.\n");
            valorMaximo = 100;
    }

    return 0;
}