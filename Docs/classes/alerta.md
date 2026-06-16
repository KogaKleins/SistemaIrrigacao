# Classe Alerta

## Objetivo

Padronizar mensagens exibidas ao usuário.

Essa classe ajuda a evitar vários textos espalhados pelo código.

## Responsabilidades

- Fornecer mensagens de solo adequado.
- Fornecer mensagens de solo seco.
- Fornecer mensagens de solo muito úmido.
- Fornecer mensagens de temperatura alta.
- Fornecer mensagens de temperatura baixa.
- Fornecer mensagens de água insuficiente.
- Fornecer mensagens de abastecimento realizado.
- Fornecer mensagens de abastecimento com excedente.
- Fornecer mensagens de irrigação realizada.
- Fornecer mensagens de bomba ligada e desligada.
- Fornecer mensagens de status.

## Métodos Atuais

```cpp
string mensagemSoloSeco();
string mensagemSoloAdequado();
string mensagemSoloMuitoUmido();
string mensagemTemperaturaAlta();
string mensagemTemperaturaBaixa();
string mensagemAguaInsuficiente();
string mensagemAbastecimentoRealizado();
string mensagemAbastecimentoComExcedente(float quantidadeExcedenteMl);
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

Quando a mensagem precisar de um valor, esse valor deve vir pronto de outra classe:

```cpp
string mensagem = alerta.mensagemAbastecimentoComExcedente(200);
```

Quem imprime a mensagem com `cout` é `ConsoleView`.

## Conferência da Implementação Atual

- Métodos de mensagens.
- Textos centralizados e claros.
- Mensagens de usuário evitam repetição em várias classes.

## Links Relacionados

- [ConsoleView](console-view.md)
- [SistemaIrrigacao](sistema-irrigacao.md)

