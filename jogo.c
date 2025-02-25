#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Biblioteca pra usar a função time no rand

int main() {

    int nivel, valorMaximo, numeroAleatorio;
    
    printf("Qual o nivel de dificuldade ?\n");
    printf("1 - Facil\n");
    printf("2 - Medio\n");
    printf("3 - Dificil\n");
    printf("4 - Imposivel\n");
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

    srand(time(NULL));
    numeroAleatorio = rand() % valorMaximo + 1;

    printf("O valor maximo e: %d\n", valorMaximo);
    printf("O numero aleatorio e: %d\n", numeroAleatorio);

    return 0;
}