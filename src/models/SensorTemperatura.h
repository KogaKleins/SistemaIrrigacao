#ifndef SENSORTEMPERATURA_H
#define SENSORTEMPERATURA_H

// Model que guarda a leitura simulada da temperatura.
// Ele apenas classifica a temperatura; nao decide irrigacao.
class SensorTemperatura {
private:
    float temperaturaAtual;

public:
    // Cria o sensor com a primeira leitura simulada.
    SensorTemperatura(float temperaturaAtual);

    // Consulta ou atualiza a leitura atual.
    float getTemperaturaAtual();
    void setTemperaturaAtual(float temperatura);

    // Classificacoes usadas pelo SistemaIrrigacao.
    bool temperaturaAlta();
    bool temperaturaBaixa();
    bool temperaturaNormal();
};

#endif
