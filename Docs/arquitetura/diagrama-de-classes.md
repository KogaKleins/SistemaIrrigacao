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
| `ResultadoVerificacao` | Enumera os resultados técnicos possíveis da verificação. |
| `SistemaIrrigacao` | Coordena as classes principais e aplica as regras de irrigação. |
| `Alerta` | Centraliza mensagens exibidas ao usuário. |
| `ConsoleView` | Lê dados, mostra menu e conversa com o usuário pelo terminal. |

## Relações Principais

- `SistemaIrrigacao` possui `Planta`, `SensorUmidade`, `SensorTemperatura`, `Reservatorio` e `BombaAgua`.
- `SistemaIrrigacao` retorna `ResultadoVerificacao` para indicar o que aconteceu.
- `ConsoleView` usa `SistemaIrrigacao` para executar as ações escolhidas pelo usuário.
- `ConsoleView` usa `Alerta` para exibir mensagens padronizadas.

## Diagrama Mermaid

```mermaid
classDiagram
    class Planta {
        - string nome
        - float umidadeMinimaIdeal
        - float aguaPorIrrigacaoMl
        + Planta(string nome, float umidadeMinimaIdeal, float aguaPorIrrigacaoMl)
        + string getNome()
        + float getUmidadeMinimaIdeal()
        + float getAguaPorIrrigacaoMl()
    }

    class SensorUmidade {
        - float umidadeAtual
        + SensorUmidade(float umidadeAtual)
        + float getUmidadeAtual()
        + void setUmidadeAtual(float umidade)
        + bool soloEstaSeco(float limiteMinimo)
        + bool soloMuitoUmido()
    }

    class SensorTemperatura {
        - float temperaturaAtual
        + SensorTemperatura(float temperaturaAtual)
        + float getTemperaturaAtual()
        + void setTemperaturaAtual(float temperatura)
        + bool temperaturaAlta()
        + bool temperaturaBaixa()
        + bool temperaturaNormal()
    }

    class Reservatorio {
        - float capacidadeMaximaMl
        - float quantidadeAtualMl
        + Reservatorio(float capacidadeMaximaMl, float quantidadeAtualMl)
        + float getCapacidadeMaximaMl()
        + float getQuantidadeAtualMl()
        + float getEspacoDisponivelMl()
        + bool temAguaSuficiente(float quantidadeNecessariaMl)
        + void consumirAgua(float quantidadeMl)
        + float abastecer(float quantidadeMl)
    }

    class BombaAgua {
        - bool ligada
        + BombaAgua()
        + BombaAgua(bool ligada)
        + void ligar()
        + void desligar()
        + bool estaLigada()
    }

    class ResultadoVerificacao {
        <<enumeration>>
        RESULTADO_SOLO_MUITO_UMIDO
        RESULTADO_SOLO_ADEQUADO
        RESULTADO_TEMPERATURA_ALTA_SEM_IRRIGACAO
        RESULTADO_AGUA_INSUFICIENTE
        RESULTADO_IRRIGACAO_REALIZADA
        RESULTADO_IRRIGACAO_REFORCADA
        RESULTADO_IRRIGACAO_COM_TEMPERATURA_BAIXA
    }

    class SistemaIrrigacao {
        - Planta planta
        - SensorUmidade sensorUmidade
        - SensorTemperatura sensorTemperatura
        - Reservatorio reservatorio
        - BombaAgua bomba
        - void irrigar()
        + SistemaIrrigacao(Planta planta, SensorUmidade sensorUmidade, SensorTemperatura sensorTemperatura, Reservatorio reservatorio)
        + bool precisaIrrigar()
        + float calcularAguaNecessariaMl()
        + ResultadoVerificacao verificarSistema()
        + void atualizarUmidade(float novaUmidade)
        + void atualizarTemperatura(float novaTemperatura)
        + float abastecerReservatorio(float quantidadeMl)
        + string getNomePlanta()
        + float getUmidadeAtual()
        + float getTemperaturaAtual()
        + float getUmidadeMinimaIdeal()
        + float getAguaPorIrrigacaoMl()
        + float getQuantidadeAguaReservatorioMl()
        + float getCapacidadeReservatorioMl()
        + float getEspacoDisponivelReservatorioMl()
        + bool bombaEstaLigada()
    }

    class Alerta {
        + string mensagemSoloSeco()
        + string mensagemSoloAdequado()
        + string mensagemSoloMuitoUmido()
        + string mensagemTemperaturaAlta()
        + string mensagemTemperaturaBaixa()
        + string mensagemAguaInsuficiente()
        + string mensagemAbastecimentoRealizado()
        + string mensagemAbastecimentoComExcedente(float quantidadeExcedenteMl)
        + string mensagemIrrigacaoRealizada()
        + string mensagemIrrigacaoReforcada()
        + string mensagemBombaLigada()
        + string mensagemBombaDesligada()
        + string mensagemStatus()
    }

    class ConsoleView {
        - SistemaIrrigacao sistema
        - Alerta alerta
        - float lerFloat(string mensagem)
        - int lerInteiroEntre(string mensagem, int minimo, int maximo)
        - float lerFloatEntre(string mensagem, float minimo, float maximo)
        - float lerFloatMaiorQue(string mensagem, float minimo)
        - void exibirResultadoVerificacao(ResultadoVerificacao resultado)
        + ConsoleView(SistemaIrrigacao sistema)
        + void iniciar()
        + void exibirMenu()
        + int lerOpcao()
        + void verificarSistema()
        + void exibirStatus()
        + void alterarUmidade()
        + void alterarTemperatura()
        + void abastecerReservatorio()
    }

    SistemaIrrigacao *-- Planta
    SistemaIrrigacao *-- SensorUmidade
    SistemaIrrigacao *-- SensorTemperatura
    SistemaIrrigacao *-- Reservatorio
    SistemaIrrigacao *-- BombaAgua
    SistemaIrrigacao --> ResultadoVerificacao
    ConsoleView --> SistemaIrrigacao
    ConsoleView --> Alerta
    ConsoleView --> ResultadoVerificacao
```
