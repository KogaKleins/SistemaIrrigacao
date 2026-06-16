#include "Reservatorio.h"

Reservatorio::Reservatorio(float capacidadeMaximaMl, float quantidadeAtualMl)
    : capacidadeMaximaMl(capacidadeMaximaMl), quantidadeAtualMl(quantidadeAtualMl)
{
}

float Reservatorio::getCapacidadeMaximaMl() {
    return capacidadeMaximaMl;
}

float Reservatorio::getQuantidadeAtualMl() {
    return quantidadeAtualMl;
}

float Reservatorio::getEspacoDisponivelMl() {
    return capacidadeMaximaMl - quantidadeAtualMl;
}

// Quantidades invalidas nao devem liberar consumo de agua.
bool Reservatorio::temAguaSuficiente(float quantidadeNecessariaMl) {
    if (quantidadeNecessariaMl <= 0)
        return false;

    return quantidadeAtualMl >= quantidadeNecessariaMl;
}

// Consome apenas quando existe agua suficiente para nao ficar negativo.
void Reservatorio::consumirAgua(float quantidadeMl) {
    if (quantidadeMl > 0 && temAguaSuficiente(quantidadeMl))
        quantidadeAtualMl -= quantidadeMl;
}

// Enche ate o limite e devolve quanto nao coube no reservatorio.
float Reservatorio::abastecer(float quantidadeMl) {
    if (quantidadeMl <= 0)
        return 0;

    float espacoDisponivelMl = getEspacoDisponivelMl();

    if (quantidadeMl <= espacoDisponivelMl) {
        quantidadeAtualMl += quantidadeMl;
        return 0;
    }

    float sobrepujaMl = quantidadeMl - espacoDisponivelMl;
    quantidadeAtualMl = capacidadeMaximaMl;

    return sobrepujaMl;
}
