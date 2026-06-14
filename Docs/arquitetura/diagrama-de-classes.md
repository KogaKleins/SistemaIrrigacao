# Diagrama de Classes

Este documento atende ao pedido de diagrama de classes da proposta do projeto.

Se o arquivo estiver aberto apenas como texto no VS Code, leia primeiro o resumo abaixo. O bloco Mermaid no final serve para renderizar o diagrama visual em ferramentas compatíveis, como preview Markdown com suporte a Mermaid ou GitHub.

## Legenda

- `-` indica atributo privado.
- `+` indica método público.
- `*--` indica composição: uma classe possui a outra.
- `-->` indica uso: uma classe chama ou depende da outra.

## Resumo das Classes

| Classe | Responsabilidade |
| --- | --- |
| `Planta` | Guarda os dados da planta cadastrada. |
| `SensorUmidade` | Guarda e classifica a umidade do solo. |
| `SensorTemperatura` | Guarda e classifica a temperatura ambiente. |
| `Reservatorio` | Controla capacidade, água disponível, consumo e abastecimento. |
| `BombaAgua` | Representa se a bomba está ligada ou desligada. |
| `SistemaIrrigacao` | Coordena as classes principais e aplica as regras de irrigação. |
| `Alerta` | Centraliza mensagens exibidas ao usuário. |
| `ConsoleView` | Lê dados, mostra menu e conversa com o usuário pelo terminal. |

## Relações Principais

- `SistemaIrrigacao` possui `Planta`, `SensorUmidade`, `SensorTemperatura`, `Reservatorio` e `BombaAgua`.
- `ConsoleView` usa `SistemaIrrigacao` para executar as ações escolhidas pelo usuário.
- `ConsoleView` usa `Alerta` para exibir mensagens padronizadas.

## Diagrama Mermaid

```mermaid
classDiagram
    class Planta {
        - string nome
        - float umidadeMinimaIdeal
        - float aguaPorIrrigacaoMl
        + string getNome()
        + float getUmidadeMinimaIdeal()
        + float getAguaPorIrrigacaoMl()
    }

    class SensorUmidade {
        - float umidadeAtual
        + float getUmidadeAtual()
        + void setUmidadeAtual(float umidade)
        + bool soloEstaSeco(float limiteMinimo)
        + bool soloMuitoUmido()
    }

    class SensorTemperatura {
        - float temperaturaAtual
        + float getTemperaturaAtual()
        + void setTemperaturaAtual(float temperatura)
        + bool temperaturaAlta()
        + bool temperaturaBaixa()
        + bool temperaturaNormal()
    }

    class Reservatorio {
        - float capacidadeMaximaMl
        - float quantidadeAtualMl
        + float getCapacidadeMaximaMl()
        + float getQuantidadeAtualMl()
        + float getEspacoDisponivelMl()
        + bool temAguaSuficiente(float quantidadeNecessariaMl)
        + void consumirAgua(float quantidadeMl)
        + float abastecer(float quantidadeMl)
    }

    class BombaAgua {
        - bool ligada
        + void ligar()
        + void desligar()
        + bool estaLigada()
    }

    class SistemaIrrigacao {
        - Planta planta
        - SensorUmidade sensorUmidade
        - SensorTemperatura sensorTemperatura
        - Reservatorio reservatorio
        - BombaAgua bomba
        + bool precisaIrrigar()
        + float calcularAguaNecessariaMl()
        + void irrigar()
        + void verificarSistema()
        + void exibirStatus()
        + void atualizarUmidade(float novaUmidade)
        + void atualizarTemperatura(float novaTemperatura)
        + void abastecerReservatorio(float quantidadeMl)
    }

    class Alerta {
        + string mensagemSoloAdequado()
        + string mensagemSoloMuitoUmido()
        + string mensagemTemperaturaAlta()
        + string mensagemTemperaturaBaixa()
        + string mensagemAguaInsuficiente()
        + string mensagemIrrigacaoRealizada()
        + string mensagemIrrigacaoReforcada()
        + string mensagemBombaLigada()
        + string mensagemBombaDesligada()
        + string mensagemStatus()
    }

    class ConsoleView {
        - SistemaIrrigacao sistema
        - Alerta alerta
        + void iniciar()
        + void exibirMenu()
        + int lerOpcao()
        + void cadastrarDadosIniciais()
        + void verificarSistema()
        + void alterarUmidade()
        + void alterarTemperatura()
        + void abastecerReservatorio()
        + void exibirStatus()
    }

    SistemaIrrigacao *-- Planta
    SistemaIrrigacao *-- SensorUmidade
    SistemaIrrigacao *-- SensorTemperatura
    SistemaIrrigacao *-- Reservatorio
    SistemaIrrigacao *-- BombaAgua
    ConsoleView --> SistemaIrrigacao
    ConsoleView --> Alerta
```
