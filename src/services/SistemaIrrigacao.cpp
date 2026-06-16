#include "SistemaIrrigacao.h"

// Inicializa os models recebidos e cria a bomba desligada.
// A bomba fica dentro do sistema porque quem decide ligar/desligar e o controlador.
SistemaIrrigacao::SistemaIrrigacao(
    Planta planta,
    SensorUmidade sensorUmidade,
    SensorTemperatura sensorTemperatura,
    Reservatorio reservatorio
) : planta(planta),
    sensorUmidade(sensorUmidade),
    sensorTemperatura(sensorTemperatura),
    reservatorio(reservatorio),
    bomba() {
}

// A umidade é o primeiro criterio para decidir se existe chance de irrigar.
bool SistemaIrrigacao::precisaIrrigar() {
    return sensorUmidade.soloEstaSeco(planta.getUmidadeMinimaIdeal()) && !sensorUmidade.soloMuitoUmido();
}

// Temperatura alta reforca a irrigacao apenas quando o solo ja esta seco.
float SistemaIrrigacao::calcularAguaNecessariaMl() {
    float aguaNecessariaMl = planta.getAguaPorIrrigacaoMl();

    if (sensorTemperatura.temperaturaAlta())
        aguaNecessariaMl += aguaNecessariaMl * 0.2f;

    return aguaNecessariaMl;
}

ResultadoVerificacao SistemaIrrigacao::verificarSistema() {
    // Solo muito umido bloqueia qualquer irrigacao.
    if (sensorUmidade.soloMuitoUmido())
        return RESULTADO_SOLO_MUITO_UMIDO;

    // Solo adequado nao irriga; temperatura alta vira apenas alerta informativo.
    if (!precisaIrrigar()) {
        if (sensorTemperatura.temperaturaAlta())
            return RESULTADO_TEMPERATURA_ALTA_SEM_IRRIGACAO;

        return RESULTADO_SOLO_ADEQUADO;
    }

    float aguaNecessariaMl = calcularAguaNecessariaMl();

    // A bomba nao liga se o reservatorio nao tiver agua suficiente.
    if (!reservatorio.temAguaSuficiente(aguaNecessariaMl)) {
        bomba.desligar();
        return RESULTADO_AGUA_INSUFICIENTE;
    }

    irrigar();

    if (sensorTemperatura.temperaturaAlta())
        return RESULTADO_IRRIGACAO_REFORCADA;

    // Temperatura baixa nao muda a quantidade, mas gera alerta.
    if (sensorTemperatura.temperaturaBaixa())
        return RESULTADO_IRRIGACAO_COM_TEMPERATURA_BAIXA;

    return RESULTADO_IRRIGACAO_REALIZADA;
}

// Executa a irrigacao depois das validacoes feitas pelo controlador.
void SistemaIrrigacao::irrigar() {
    float aguaNecessariaMl = calcularAguaNecessariaMl();

    if (!reservatorio.temAguaSuficiente(aguaNecessariaMl))
        return;

    bomba.ligar();
    reservatorio.consumirAgua(aguaNecessariaMl);
    bomba.desligar();
}

// A interface informa a nova leitura; o sistema repassa ao sensor.
void SistemaIrrigacao::atualizarUmidade(float novaUmidade) {
    sensorUmidade.setUmidadeAtual(novaUmidade);
}

void SistemaIrrigacao::atualizarTemperatura(float novaTemperatura) {
    sensorTemperatura.setTemperaturaAtual(novaTemperatura);
}

float SistemaIrrigacao::abastecerReservatorio(float quantidadeMl) {
    return reservatorio.abastecer(quantidadeMl);
}

// Os getters abaixo entregam apenas o que a ConsoleView precisa mostrar.
string SistemaIrrigacao::getNomePlanta() {
    return planta.getNome();
}

float SistemaIrrigacao::getUmidadeAtual() {
    return sensorUmidade.getUmidadeAtual();
}

float SistemaIrrigacao::getTemperaturaAtual() {
    return sensorTemperatura.getTemperaturaAtual();
}

float SistemaIrrigacao::getUmidadeMinimaIdeal() {
    return planta.getUmidadeMinimaIdeal();
}

float SistemaIrrigacao::getAguaPorIrrigacaoMl() {
    return planta.getAguaPorIrrigacaoMl();
}

float SistemaIrrigacao::getQuantidadeAguaReservatorioMl() {
    return reservatorio.getQuantidadeAtualMl();
}

float SistemaIrrigacao::getCapacidadeReservatorioMl() {
    return reservatorio.getCapacidadeMaximaMl();
}

float SistemaIrrigacao::getEspacoDisponivelReservatorioMl() {
    return reservatorio.getEspacoDisponivelMl();
}

bool SistemaIrrigacao::bombaEstaLigada() {
    return bomba.estaLigada();
}
