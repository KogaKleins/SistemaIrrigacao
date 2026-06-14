#ifndef SISTEMA_IRRIGACAO_H
#define SISTEMA_IRRIGACAO_H

#include <string>

#include "../models/Planta.h"
#include "../models/SensorUmidade.h"

using namespace std;

// Classe de servico/controlador.
// Ela junta os models e aplica a regra de negocio principal.
class SistemaIrrigacao {
private:
    Planta planta;
    SensorUmidade sensorUmidade;

public:
    // Recebe os models ja criados e passa a coordenar o funcionamento.
    SistemaIrrigacao(Planta planta, SensorUmidade sensorUmidade);

    // Decisoes e alteracoes usadas pela interface.
    bool precisaIrrigar();
    void atualizarUmidade(float novaUmidade);

    // Getters especificos para a tela exibir status sem acessar os models direto.
    string getNomePlanta();
    float getUmidadeAtual();
    float getUmidadeMinimaIdeal();
    float getAguaPorIrrigacaoMl();
};

#endif
