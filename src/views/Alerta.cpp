#include "Alerta.h"

#include <sstream>

// Cada metodo devolve texto, mas nao imprime nada.
// Quem imprime continua sendo a ConsoleView.
string Alerta::mensagemSoloSeco() {
    return "Solo seco. A planta precisa de irrigacao.";
}

string Alerta::mensagemSoloAdequado() {
    return "Solo adequado. Nao precisa irrigar agora.";
}

string Alerta::mensagemSoloMuitoUmido() {
    return "Solo muito umido. Irrigacao bloqueada no momento.";
}

string Alerta::mensagemTemperaturaAlta() {
    return "Temperatura alta. A planta pode precisar de mais agua.";
}

string Alerta::mensagemTemperaturaBaixa() {
    return "Temperatura baixa. Irrigue com cuidado.";
}

string Alerta::mensagemAguaInsuficiente() {
    return "Agua insuficiente no reservatorio.";
}

string Alerta::mensagemAbastecimentoRealizado() {
    return "Reservatorio abastecido com sucesso.";
}

// Usa stringstream para montar uma mensagem com numero no meio do texto.
string Alerta::mensagemAbastecimentoComExcedente(float quantidadeExcedenteMl) {
    ostringstream mensagem;
    mensagem << "Reservatorio abastecido. A quantidade excedente foi de "
             << quantidadeExcedenteMl << " mL.";

    return mensagem.str();
}

string Alerta::mensagemIrrigacaoRealizada() {
    return "Irrigacao realizada com sucesso.";
}

string Alerta::mensagemIrrigacaoReforcada() {
    return "Irrigacao reforcada realizada com sucesso.";
}

string Alerta::mensagemBombaLigada() {
    return "Bomba ligada.";
}

string Alerta::mensagemBombaDesligada() {
    return "Bomba desligada.";
}

string Alerta::mensagemStatus() {
    return "Status atual";
}
