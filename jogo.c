#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Biblioteca pra usar a função time no rand

int main() {

    int nivel, valorMaximo, numeroAleatorio, palpite, tentativas = 0;
    
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

        do {
        printf("Digite seu palpite (entre 1 e %d): ", valorMaximo);
        scanf("%d", &palpite);
        tentativas++;

        if(palpite < numeroAleatorio) {
            printf("Dica: é MAIOR!\n");
        } else if(palpite > numeroAleatorio) {
            printf("Dica: é MENOR!\n");
        } else {
            printf("Parabéns! você acertou em %d tentativas.\n", tentativas);
        }
    } while(palpite != numeroAleatorio);

    return 0;
}