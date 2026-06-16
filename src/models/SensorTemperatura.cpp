#include "SensorTemperatura.h"

// Guarda a temperatura inicial recebida.
SensorTemperatura::SensorTemperatura(float temperaturaAtual)
    : temperaturaAtual(temperaturaAtual)
{
}

// Retorna a leitura atual da temperatura.
float SensorTemperatura::getTemperaturaAtual() {
    return temperaturaAtual;
}

// Atualiza a leitura simulada. Quem valida a entrada e a ConsoleView.
void SensorTemperatura::setTemperaturaAtual(float temperatura) {
    temperaturaAtual = temperatura;
}

// Acima de 30 C a irrigacao pode ser reforcada se o solo estiver seco.
bool SensorTemperatura::temperaturaAlta() {
    return temperaturaAtual > 30;
}

// Abaixo de 15 C o sistema apenas mostra um alerta de cuidado.
bool SensorTemperatura::temperaturaBaixa() {
    return temperaturaAtual < 15;
}

// Entre 15 C e 30 C a temperatura e considerada normal.
bool SensorTemperatura::temperaturaNormal() {
    return temperaturaAtual >= 15 && temperaturaAtual <= 30;
}
