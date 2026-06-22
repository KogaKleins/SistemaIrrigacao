#ifndef SISTEMA_IRRIGACAO_H
#define SISTEMA_IRRIGACAO_H

#include <string>

#include "../models/BombaAgua.h"
#include "../models/Planta.h"
#include "../models/Reservatorio.h"
#include "../models/SensorTemperatura.h"
#include "../models/SensorUmidade.h"

using namespace std;

// enum cria um tipo com valores fixos.
// Aqui ele funciona como um "codigo de resultado": o sistema diz o que aconteceu,
// mas nao devolve texto pronto. A ConsoleView usa esse codigo para escolher a mensagem.
enum ResultadoVerificacao {
    RESULTADO_SOLO_MUITO_UMIDO,
    RESULTADO_SOLO_ADEQUADO,
    RESULTADO_TEMPERATURA_ALTA_SEM_IRRIGACAO,
    RESULTADO_AGUA_INSUFICIENTE,
    RESULTADO_IRRIGACAO_REALIZADA,
    RESULTADO_IRRIGACAO_REFORCADA,
    RESULTADO_IRRIGACAO_COM_TEMPERATURA_BAIXA
};

// Classe de servico/controlador.
// Ela junta os models e aplica a regra de negocio principal.
class SistemaIrrigacao {
private:
    Planta planta;
    SensorUmidade sensorUmidade;
    SensorTemperatura sensorTemperatura;
    Reservatorio reservatorio;
    BombaAgua bomba;

    // Acao interna: so deve acontecer depois das validacoes do sistema.
    void irrigar();

public:
    // Construtor:
    // Recebe os models criados no main ou na tela.
    // e passa a ser controlada pelo proprio SistemaIrrigacao.
    SistemaIrrigacao(
        Planta planta,
        SensorUmidade sensorUmidade,
        SensorTemperatura sensorTemperatura,
        Reservatorio reservatorio
    );

    // Decisoes e alteracoes usadas pela interface.
    bool precisaIrrigar();
    float calcularAguaNecessariaMl();
    ResultadoVerificacao verificarSistema();
    void atualizarUmidade(float novaUmidade);
    void atualizarTemperatura(float novaTemperatura);
    float abastecerReservatorio(float quantidadeMl);

    // Getters especificos para a tela exibir status sem acessar os models direto.
    string getNomePlanta();
    float getUmidadeAtual();
    float getTemperaturaAtual();
    float getUmidadeMinimaIdeal();
    float getAguaPorIrrigacaoMl();
    float getQuantidadeAguaReservatorioMl();
    float getCapacidadeReservatorioMl();
    float getEspacoDisponivelReservatorioMl();
    bool bombaEstaLigada();
};

#endif
