#include "SensorUmidade.h"

// Guarda a umidade inicial recebida.
SensorUmidade::SensorUmidade(float umidadeAtual)
    : umidadeAtual(umidadeAtual)
{
}

// Retorna a leitura atual da umidade do solo.
float SensorUmidade::getUmidadeAtual() {
    return umidadeAtual;
}

// Atualiza a leitura simulada. Quem valida a entrada e a ConsoleView.
void SensorUmidade::setUmidadeAtual(float umidade) {
    umidadeAtual = umidade;
}

// A comparacao ja gera true ou false.
bool SensorUmidade::soloEstaSeco(float limiteMinimo) {
    return umidadeAtual < limiteMinimo;
}

// Acima de 70% o solo e considerado muito umido.
bool SensorUmidade::soloMuitoUmido() {
    return umidadeAtual > 70;
}
