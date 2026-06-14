#ifndef CONSOLE_VIEW_H
#define CONSOLE_VIEW_H

#include <string>

#include "../services/SistemaIrrigacao.h"

using namespace std;

// Camada de interface do terminal.
// Esta e a unica classe que deve usar cin/cout diretamente.
class ConsoleView {
private:
    SistemaIrrigacao sistema;

    // Le entradas numericas com validacao basica de intervalo.
    int lerInteiroEntre(string mensagem, int minimo, int maximo);
    float lerFloatEntre(string mensagem, float minimo, float maximo);

public:
    // Recebe um sistema pronto para controlar pela tela.
    ConsoleView(SistemaIrrigacao sistema);

    // Fluxo principal da interface.
    void iniciar();
    void exibirMenu();
    int lerOpcao();

    // Acoes do menu atual.
    void verificarSistema();
    void exibirStatus();
    void alterarUmidade();
};

#endif
