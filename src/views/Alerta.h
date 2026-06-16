#ifndef ALERTA_H
#define ALERTA_H

#include <string>

using namespace std;

// Centraliza textos exibidos pela interface.
// Nao decide regras de irrigacao e nao imprime no terminal.
class Alerta {
public:
    string mensagemSoloSeco();
    string mensagemSoloAdequado();
    string mensagemSoloMuitoUmido();
    string mensagemTemperaturaAlta();
    string mensagemTemperaturaBaixa();
    string mensagemAguaInsuficiente();
    string mensagemAbastecimentoRealizado();

    // Recebe o valor calculado fora daqui; Alerta so monta o texto.
    string mensagemAbastecimentoComExcedente(float quantidadeExcedenteMl);

    string mensagemIrrigacaoRealizada();
    string mensagemIrrigacaoReforcada();
    string mensagemBombaLigada();
    string mensagemBombaDesligada();
    string mensagemStatus();
};

#endif
