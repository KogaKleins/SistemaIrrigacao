# Classe Alerta

## Objetivo

Padronizar mensagens exibidas ao usuário.

Essa classe ajuda a evitar vários textos espalhados pelo código.

## Responsabilidades

- Fornecer mensagens de solo adequado.
- Fornecer mensagens de solo muito úmido.
- Fornecer mensagens de temperatura alta.
- Fornecer mensagens de temperatura baixa.
- Fornecer mensagens de água insuficiente.
- Fornecer mensagens de irrigação realizada.
- Fornecer mensagens de bomba ligada e desligada.
- Fornecer mensagens de status.

## Métodos Previstos

```cpp
string mensagemSoloAdequado();
string mensagemSoloMuitoUmido();
string mensagemTemperaturaAlta();
string mensagemTemperaturaBaixa();
string mensagemAguaInsuficiente();
string mensagemIrrigacaoRealizada();
string mensagemIrrigacaoReforcada();
string mensagemBombaLigada();
string mensagemBombaDesligada();
string mensagemStatus();
```

## Decisão de Arquitetura

`Alerta` não deve decidir nada.

Ele apenas centraliza textos. A decisão de irrigar continua em `SistemaIrrigacao`.

## Não Deve Fazer

- Não deve consultar sensor.
- Não deve consultar reservatório.
- Não deve ligar bomba.
- Não deve calcular água.
- Não deve conter regra de negócio.

## Exemplo de Uso

```cpp
Alerta alerta;
string mensagem = alerta.mensagemAguaInsuficiente();
```

Quem imprime a mensagem com `cout` é `ConsoleView`.

## Checklist de Implementação

- Criar métodos de mensagens.
- Manter textos claros.
- Evitar repetir mensagens em várias classes.

## Links Relacionados

- [ConsoleView](console-view.md)
- [SistemaIrrigacao](sistema-irrigacao.md)

