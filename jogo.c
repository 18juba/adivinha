#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Biblioteca para usar a função time no rand

int main() {
    int nivel, valorMaximo, numeroAleatorio, palpite, tentativas;
    char jogarNovamente;

    do {
        tentativas = 0;

        printf("\n===============================\n");
        printf("    🎯 JOGO DA ADIVINHAÇÃO 🎯    \n");
        printf("===============================\n\n");
        
        printf("\nQual o nivel de dificuldade ?\n");
        printf("1 - Facil\n");
        printf("2 - Medio\n");
        printf("3 - Dificil\n");
        printf("4 - Impossivel\n");
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
                printf("Dica: é MAIOR! 📈\n");
            } else if(palpite > numeroAleatorio) {
                printf("Dica: é MENOR! 📉\n");
            } else {
                if (tentativas == 1) {
                    printf("😲 CRAQUE! você acertou de primeira!\n");
                } else if (tentativas <= 5) {
                    printf("🔥 Jogou muito! você acertou em apenas %d tentativas!\n", tentativas);
                } else if (tentativas <= 10) {
                    printf("👍 Bom jogo! você conseguiu em apenas %d tentativas!\n", tentativas);
                } else {
                    printf("🎉Parabéns! você acertou em %d tentativas.\n", tentativas);
                }
            }
        } while(palpite != numeroAleatorio);

        printf("\nDeseja jogar novamente? (s/n): ");
        scanf(" %c", &jogarNovamente);

    } while(jogarNovamente == 's' || jogarNovamente == 'S');

    printf("Obrigado por jogar! 👋\n");

    return 0;
}
