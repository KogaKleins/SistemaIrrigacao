#ifndef CONSOLE_VIEW_H
#define CONSOLE_VIEW_H

#include <string>

#include "../services/SistemaIrrigacao.h"
#include "Alerta.h"

using namespace std;

// Camada de interface do terminal.
// Esta e a unica classe que deve usar cin/cout diretamente.
class ConsoleView {
private:
    SistemaIrrigacao sistema;
    Alerta alerta;

    // Helpers de leitura e exibicao usados pelas opcoes do menu.
    float lerFloat(string mensagem);
    int lerInteiroEntre(string mensagem, int minimo, int maximo);
    float lerFloatEntre(string mensagem, float minimo, float maximo);
    float lerFloatMaiorQue(string mensagem, float minimo);
    void exibirResultadoVerificacao(ResultadoVerificacao resultado);

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
    void alterarTemperatura();
    void abastecerReservatorio();
};

#endif
