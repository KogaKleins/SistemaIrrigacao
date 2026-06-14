#ifndef PLANTA_H
#define PLANTA_H

#include <string>

using namespace std;

// Model que representa a planta cadastrada.
// Ela nao decide irrigacao; apenas guarda dados da planta.
class Planta {
private:
    string nome;
    float umidadeMinimaIdeal;
    float aguaPorIrrigacaoMl;

public:
    // Cria uma planta com os dados ja validados pela interface.
    Planta(string nome, float umidadeMinimaIdeal, float aguaPorIrrigacaoMl);

    // Getters: permitem consultar os atributos privados sem acessa-los direto.
    string getNome();
    float getUmidadeMinimaIdeal();
    float getAguaPorIrrigacaoMl();
};

#endif
