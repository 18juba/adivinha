#include <gtk/gtk.h>
#include <stdlib.h>
#include <time.h>

GtkWidget *entrada, *label_resultado;
int numeroAleatorio, tentativas = 0, valorMaximo = 100;

void verificar_palpite(GtkWidget *widget, gpointer data) {
    const char *palpite_str = gtk_entry_get_text(GTK_ENTRY(entrada));
    int palpite = atoi(palpite_str);
    tentativas++;

    char mensagem[100];
    if (palpite < numeroAleatorio) {
        sprintf(mensagem, "📈 Dica: é MAIOR!");
    } else if (palpite > numeroAleatorio) {
        sprintf(mensagem, "📉 Dica: é MENOR!");
    } else {
        sprintf(mensagem, "🎉 Parabéns! Acertou em %d tentativas!", tentativas);
    }

    gtk_label_set_text(GTK_LABEL(label_resultado), mensagem);
}

void definir_dificuldade(GtkWidget *widget, gpointer data) {
    int nivel = GPOINTER_TO_INT(data);

    switch(nivel) {
        case 1: valorMaximo = 10; break;
        case 2: valorMaximo = 100; break;
        case 3: valorMaximo = 1000; break;
        case 4: valorMaximo = 10000; break;
        default: valorMaximo = 100;
    }

    srand(time(NULL));
    numeroAleatorio = rand() % valorMaximo + 1;
    tentativas = 0;

    char mensagem[100];
    sprintf(mensagem, "🔎 Digite um número entre 1 e %d:", valorMaximo);
    gtk_label_set_text(GTK_LABEL(label_resultado), mensagem);
    gtk_entry_set_text(GTK_ENTRY(entrada), "");
}

void reiniciar_jogo(GtkWidget *widget, gpointer data) {
    definir_dificuldade(widget, data);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *janela, *caixa, *botao, *botao_reiniciar, *botao_facil, *botao_medio, *botao_dificil, *botao_impossivel;

    janela = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(janela), "Jogo da Adivinhação");
    gtk_container_set_border_width(GTK_CONTAINER(janela), 20);
    gtk_window_set_default_size(GTK_WINDOW(janela), 300, 300);

    caixa = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(janela), caixa);

    label_resultado = gtk_label_new("Escolha a dificuldade para começar:");
    gtk_box_pack_start(GTK_BOX(caixa), label_resultado, FALSE, FALSE, 0);

    botao_facil = gtk_button_new_with_label("😀 Fácil (1-10)");
    g_signal_connect(botao_facil, "clicked", G_CALLBACK(definir_dificuldade), GINT_TO_POINTER(1));
    gtk_box_pack_start(GTK_BOX(caixa), botao_facil, FALSE, FALSE, 0);

    botao_medio = gtk_button_new_with_label("😃 Médio (1-100)");
    g_signal_connect(botao_medio, "clicked", G_CALLBACK(definir_dificuldade), GINT_TO_POINTER(2));
    gtk_box_pack_start(GTK_BOX(caixa), botao_medio, FALSE, FALSE, 0);

    botao_dificil = gtk_button_new_with_label("😨 Difícil (1-1000)");
    g_signal_connect(botao_dificil, "clicked", G_CALLBACK(definir_dificuldade), GINT_TO_POINTER(3));
    gtk_box_pack_start(GTK_BOX(caixa), botao_dificil, FALSE, FALSE, 0);

    botao_impossivel = gtk_button_new_with_label("😱 Impossível (1-10000)");
    g_signal_connect(botao_impossivel, "clicked", G_CALLBACK(definir_dificuldade), GINT_TO_POINTER(4));
    gtk_box_pack_start(GTK_BOX(caixa), botao_impossivel, FALSE, FALSE, 0);

    entrada = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(caixa), entrada, FALSE, FALSE, 0);

    g_signal_connect(entrada, "activate", G_CALLBACK(verificar_palpite), NULL);

    botao = gtk_button_new_with_label("Verificar");
    g_signal_connect(botao, "clicked", G_CALLBACK(verificar_palpite), NULL);
    gtk_box_pack_start(GTK_BOX(caixa), botao, FALSE, FALSE, 0);

    botao_reiniciar = gtk_button_new_with_label("🔄 Jogar Novamente");
    g_signal_connect(botao_reiniciar, "clicked", G_CALLBACK(reiniciar_jogo), NULL);
    gtk_box_pack_start(GTK_BOX(caixa), botao_reiniciar, FALSE, FALSE, 0);

    g_signal_connect(janela, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(janela);
    gtk_main();

    return 0;
}
