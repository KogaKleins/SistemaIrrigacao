#ifndef SENSORUMIDADE_H
#define SENSORUMIDADE_H

// Model que representa a leitura simulada da umidade do solo.
// Ele nao le teclado e nao decide irrigacao sozinho.
class SensorUmidade {
private:
    float umidadeAtual;

public:
    // Cria o sensor com a primeira leitura simulada.
    SensorUmidade(float umidadeAtual);

    // Consulta ou atualiza a leitura atual do sensor.
    float getUmidadeAtual();
    void setUmidadeAtual(float umidade);

    // Perguntas simples sobre a umidade guardada.
    bool soloEstaSeco(float limiteMinimo);
    bool soloMuitoUmido();
};

#endif
