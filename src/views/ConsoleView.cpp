#include "ConsoleView.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Guarda uma copia do sistema que sera controlado pela interface.
ConsoleView::ConsoleView(SistemaIrrigacao sistema) : sistema(sistema) {
}

// Loop principal: mostra menu, le opcao e executa a acao escolhida.
void ConsoleView::iniciar() {
    int opcao;

    do {
        exibirMenu();
        opcao = lerOpcao();

        cout << endl;

        switch (opcao) {
        case 1:
            verificarSistema();
            break;
        case 2:
            exibirStatus();
            break;
        case 3:
            alterarUmidade();
            break;
        case 4:
            alterarTemperatura();
            break;
        case 5:
            abastecerReservatorio();
            break;
        case 0:
            cout << "Encerrando o sistema." << endl;
            break;
        default:
            cout << "Opcao invalida." << endl;
            break;
        }

        cout << endl;
    } while (opcao != 0);
}

// Mostra apenas as opcoes disponiveis na versao atual.
void ConsoleView::exibirMenu() {
    cout << "====================================" << endl;
    cout << " SISTEMA DE IRRIGACAO AUTOMATIZADO" << endl;
    cout << "====================================" << endl;
    cout << "1 - Verificar sistema" << endl;
    cout << "2 - Exibir status atual" << endl;
    cout << "3 - Alterar umidade do solo" << endl;
    cout << "4 - Alterar temperatura" << endl;
    cout << "5 - Abastecer reservatorio" << endl;
    cout << "0 - Sair" << endl;
    cout << endl;
}

// Le uma opcao valida do menu.
int ConsoleView::lerOpcao() {
    return lerInteiroEntre("Escolha uma opcao: ", 0, 5);
}

// Aciona a verificacao completa no sistema e apenas exibe o resultado.
void ConsoleView::verificarSistema() {
    ResultadoVerificacao resultado = sistema.verificarSistema();
    exibirResultadoVerificacao(resultado);
}

// Mostra os dados que o sistema disponibiliza para a interface.
void ConsoleView::exibirStatus() {
    cout << alerta.mensagemStatus() << endl;
    cout << "Planta: " << sistema.getNomePlanta() << endl;
    cout << "Umidade atual: " << sistema.getUmidadeAtual() << "%" << endl;
    cout << "Umidade minima ideal: " << sistema.getUmidadeMinimaIdeal() << "%" << endl;
    cout << "Temperatura atual: " << sistema.getTemperaturaAtual() << " C" << endl;
    cout << "Agua por irrigacao: " << sistema.getAguaPorIrrigacaoMl() << " mL" << endl;
    cout << "Agua no reservatorio: " << sistema.getQuantidadeAguaReservatorioMl()
         << " mL de " << sistema.getCapacidadeReservatorioMl() << " mL" << endl;
    cout << "Espaco disponivel no reservatorio: "
         << sistema.getEspacoDisponivelReservatorioMl() << " mL" << endl;
    cout << "Bomba: " << (sistema.bombaEstaLigada() ? "Ligada" : "Desligada") << endl;
}

// Recebe uma nova leitura simulada e envia ao sistema.
void ConsoleView::alterarUmidade() {
    float novaUmidade = lerFloatEntre("Informe a nova umidade do solo (0 a 100): ", 0, 100);
    sistema.atualizarUmidade(novaUmidade);

    cout << "Umidade atualizada." << endl;
}

// Temperatura nao tem limite fixo no projeto; basta ser numerica.
void ConsoleView::alterarTemperatura() {
    float novaTemperatura = lerFloat("Informe a nova temperatura ambiente: ");
    sistema.atualizarTemperatura(novaTemperatura);

    cout << "Temperatura atualizada." << endl;
}

// A tela le o valor; o sistema abastece e devolve o excedente.
void ConsoleView::abastecerReservatorio() {
    float quantidadeMl = lerFloatMaiorQue("Informe a quantidade para abastecer em mL: ", 0);
    float excedenteMl = sistema.abastecerReservatorio(quantidadeMl);

    if (excedenteMl > 0) {
        cout << alerta.mensagemAbastecimentoComExcedente(excedenteMl) << endl;
    } else {
        cout << alerta.mensagemAbastecimentoRealizado() << endl;
    }
}

// Traduz o codigo tecnico do sistema para mensagens de usuario.
void ConsoleView::exibirResultadoVerificacao(ResultadoVerificacao resultado) {
    switch (resultado) {
    case RESULTADO_SOLO_MUITO_UMIDO:
        cout << alerta.mensagemSoloMuitoUmido() << endl;
        break;
    case RESULTADO_SOLO_ADEQUADO:
        cout << alerta.mensagemSoloAdequado() << endl;
        break;
    case RESULTADO_TEMPERATURA_ALTA_SEM_IRRIGACAO:
        cout << alerta.mensagemSoloAdequado() << endl;
        cout << alerta.mensagemTemperaturaAlta() << endl;
        break;
    case RESULTADO_AGUA_INSUFICIENTE:
        cout << alerta.mensagemSoloSeco() << endl;
        cout << alerta.mensagemAguaInsuficiente() << endl;
        break;
    case RESULTADO_IRRIGACAO_REALIZADA:
        cout << alerta.mensagemBombaLigada() << endl;
        cout << alerta.mensagemIrrigacaoRealizada() << endl;
        cout << alerta.mensagemBombaDesligada() << endl;
        break;
    case RESULTADO_IRRIGACAO_REFORCADA:
        cout << alerta.mensagemBombaLigada() << endl;
        cout << alerta.mensagemIrrigacaoReforcada() << endl;
        cout << alerta.mensagemBombaDesligada() << endl;
        break;
    case RESULTADO_IRRIGACAO_COM_TEMPERATURA_BAIXA:
        cout << alerta.mensagemTemperaturaBaixa() << endl;
        cout << alerta.mensagemBombaLigada() << endl;
        cout << alerta.mensagemIrrigacaoRealizada() << endl;
        cout << alerta.mensagemBombaDesligada() << endl;
        break;
    }
}

// Le qualquer numero real. Regras de intervalo ficam em outros metodos.
float ConsoleView::lerFloat(string mensagem) {
    string entrada;
    float valor;

    while (true) {
        cout << mensagem;
        getline(cin, entrada);

        stringstream fluxoEntrada(entrada);

        if (!(fluxoEntrada >> valor)) {
            cout << "Valor invalido. Digite apenas numeros." << endl;
            continue;
        }

        if (!fluxoEntrada.eof()) {
            cout << "Valor invalido. Nao misture numeros com letras." << endl;
            continue;
        }

        return valor;
    }
}

// Reaproveita lerFloat e aplica apenas a regra de minimo aberto.
float ConsoleView::lerFloatMaiorQue(string mensagem, float minimo) {
    float valor;

    while (true) {
        valor = lerFloat(mensagem);

        if (valor <= minimo) {
            cout << "Valor invalido. Digite um numero maior que " << minimo << "." << endl;
            continue;
        }

        return valor;
    }
}

// Le texto e tenta converter para float.
// Usar getline evita o estado de erro do cin quando o usuario digita letras.
float ConsoleView::lerFloatEntre(string mensagem, float minimo, float maximo) {
    float valor;

    while (true) {
        valor = lerFloat(mensagem);

        if (valor < minimo || valor > maximo) {
            cout << "Valor invalido. Digite um numero entre " << minimo << " e " << maximo << "." << endl;
            continue;
        }

        return valor;
    }
}

// Mesma ideia de lerFloatEntre, mas para numeros inteiros.
int ConsoleView::lerInteiroEntre(string mensagem, int minimo, int maximo) {
    string entrada;
    int valor;

    while (true) {
        cout << mensagem;
        getline(cin, entrada);

        // stringstream permite tentar ler um int a partir do texto digitado.
        stringstream fluxoEntrada(entrada);

        if (!(fluxoEntrada >> valor)) {
            cout << "Opcao invalida. Digite apenas numeros." << endl;
            continue;
        }

        if (!fluxoEntrada.eof()) {
            cout << "Opcao invalida. Nao misture numeros com letras." << endl;
            continue;
        }

        if (valor < minimo || valor > maximo) {
            cout << "Opcao invalida. Digite um numero entre " << minimo << " e " << maximo << "." << endl;
            continue;
        }

        return valor;
    }
}
