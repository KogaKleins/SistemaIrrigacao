#include "SistemaIrrigacao.h"

// Inicializa os atributos com os objetos recebidos.
SistemaIrrigacao::SistemaIrrigacao(Planta planta, SensorUmidade sensorUmidade)
    : planta(planta), sensorUmidade(sensorUmidade) {
}

// A decisao principal usa dados da planta e do sensor.
bool SistemaIrrigacao::precisaIrrigar() {
    return sensorUmidade.soloEstaSeco(planta.getUmidadeMinimaIdeal());
}

// A interface informa a nova leitura; o sistema repassa ao sensor.
void SistemaIrrigacao::atualizarUmidade(float novaUmidade) {
    sensorUmidade.setUmidadeAtual(novaUmidade);
}

// Os getters abaixo entregam apenas o que a ConsoleView precisa mostrar.
string SistemaIrrigacao::getNomePlanta() {
    return planta.getNome();
}

float SistemaIrrigacao::getUmidadeAtual() {
    return sensorUmidade.getUmidadeAtual();
}

float SistemaIrrigacao::getUmidadeMinimaIdeal() {
    return planta.getUmidadeMinimaIdeal();
}

float SistemaIrrigacao::getAguaPorIrrigacaoMl() {
    return planta.getAguaPorIrrigacaoMl();
}
