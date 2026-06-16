#include "BombaAgua.h"

// A bomba comeca desligada para proteger o sistema.
BombaAgua::BombaAgua()
    : ligada(false)
{
}

BombaAgua::BombaAgua(bool ligada)
    : ligada(ligada)
{
}

void BombaAgua::ligar() {
    ligada = true;
}

void BombaAgua::desligar() {
    ligada = false;
}

bool BombaAgua::estaLigada() {
    return ligada;
}
