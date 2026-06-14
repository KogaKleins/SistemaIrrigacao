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
    cout << "0 - Sair" << endl;
    cout << endl;
}

// Le uma opcao valida do menu.
int ConsoleView::lerOpcao() {
    return lerInteiroEntre("Escolha uma opcao: ", 0, 3);
}

// Pergunta ao sistema se a planta precisa de irrigacao.
void ConsoleView::verificarSistema() {
    if (sistema.precisaIrrigar()) {
        cout << "Solo seco. A planta precisa de irrigacao." << endl;
    } else {
        cout << "Solo adequado. Nao precisa irrigar agora." << endl;
    }
}

// Mostra os dados que o sistema disponibiliza para a interface.
void ConsoleView::exibirStatus() {
    cout << "Status atual" << endl;
    cout << "Planta: " << sistema.getNomePlanta() << endl;
    cout << "Umidade atual: " << sistema.getUmidadeAtual() << "%" << endl;
    cout << "Umidade minima ideal: " << sistema.getUmidadeMinimaIdeal() << "%" << endl;
    cout << "Agua por irrigacao: " << sistema.getAguaPorIrrigacaoMl() << " mL" << endl;
}

// Recebe uma nova leitura simulada e envia ao sistema.
void ConsoleView::alterarUmidade() {
    float novaUmidade = lerFloatEntre("Informe a nova umidade do solo (0 a 100): ", 0, 100);
    sistema.atualizarUmidade(novaUmidade);

    cout << "Umidade atualizada." << endl;
}

// Le texto e tenta converter para float.
// Usar getline evita o estado de erro do cin quando o usuario digita letras.
float ConsoleView::lerFloatEntre(string mensagem, float minimo, float maximo) {
    string entrada;
    float valor;

    while (true) {
        cout << mensagem;
        getline(cin, entrada);

        // stringstream transforma a string em um "mini cin" para extrair numero.
        stringstream fluxoEntrada(entrada);

        if (!(fluxoEntrada >> valor)) {
            cout << "Valor invalido. Digite apenas numeros." << endl;
            continue;
        }

        if (!fluxoEntrada.eof()) {
            cout << "Valor invalido. Nao misture numeros com letras." << endl;
            continue;
        }

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
