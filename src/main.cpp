// Ponto de entrada do programa.
// Por enquanto os objetos iniciais sao criados aqui para testar o fluxo.
// Quando o cadastro inicial existir, essa montagem pode ir para a ConsoleView.
#include "models/Planta.h"
#include "models/Reservatorio.h"
#include "models/SensorTemperatura.h"
#include "models/SensorUmidade.h"
#include "services/SistemaIrrigacao.h"
#include "views/ConsoleView.h"

int main() {
    // Dados iniciais fixos apenas para testar a interacao atual.
    Planta planta("Manjericao", 40, 150);
    SensorUmidade sensorUmidade(25);
    SensorTemperatura sensorTemperatura(25);
    Reservatorio reservatorio(1000, 600);

    // O sistema recebe os models e passa a coordenar a regra principal.
    SistemaIrrigacao sistema(planta, sensorUmidade, sensorTemperatura, reservatorio);

    // A view conversa com o usuario e chama o sistema quando precisa.
    ConsoleView view(sistema);

    view.iniciar();

    return 0;
}
