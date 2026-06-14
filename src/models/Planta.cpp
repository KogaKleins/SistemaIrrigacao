#include "Planta.h"

using namespace std;

// A lista de inicializacao preenche os atributos assim que o objeto nasce.
Planta::Planta(string nome, float umidadeMinimaIdeal, float aguaPorIrrigacaoMl)
    : nome(nome), umidadeMinimaIdeal(umidadeMinimaIdeal), aguaPorIrrigacaoMl(aguaPorIrrigacaoMl)
{
}

// Retorna o nome guardado na planta.
string Planta::getNome() {
    return nome;
}

// Retorna a umidade minima que a planta precisa manter.
float Planta::getUmidadeMinimaIdeal() {
    return umidadeMinimaIdeal;
}

// Retorna a quantidade normal de agua em uma irrigacao.
float Planta::getAguaPorIrrigacaoMl() {
    return aguaPorIrrigacaoMl;
}
