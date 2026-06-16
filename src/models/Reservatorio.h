#ifndef RESERVATORIO_H
#define RESERVATORIO_H

// Model que controla a agua disponivel para irrigacao.
// Ele protege seus limites fisicos: nao fica negativo nem passa da capacidade.
class Reservatorio {
private:
    float capacidadeMaximaMl;
    float quantidadeAtualMl;

public:
    // Recebe valores ja validados pela interface ou pela montagem inicial.
    Reservatorio(float capacidadeMaximaMl, float quantidadeAtualMl);

    float getCapacidadeMaximaMl();
    float getQuantidadeAtualMl();
    float getEspacoDisponivelMl();

    // Perguntas e alteracoes simples sobre a agua guardada.
    bool temAguaSuficiente(float quantidadeNecessariaMl);
    void consumirAgua(float quantidadeMl);

    // Retorna 0 se couber tudo, ou o excedente que nao coube.
    float abastecer(float quantidadeMl);
};

#endif
