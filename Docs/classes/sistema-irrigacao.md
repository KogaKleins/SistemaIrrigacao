# Classe SistemaIrrigacao

## Objetivo

Coordenar os objetos do sistema e aplicar as regras de negócio da irrigação.

Esta é a classe mais importante da lógica. Ela não representa uma peça física; representa o controlador do sistema.

## Responsabilidades

- Consultar umidade.
- Consultar temperatura.
- Consultar reservatório.
- Decidir se a planta precisa de irrigação.
- Calcular a quantidade de água necessária.
- Impedir bomba ligada sem água suficiente.
- Controlar a bomba.
- Consumir água do reservatório.
- Atualizar sensores simulados.

## Atributos

```cpp
Planta planta;
SensorUmidade sensorUmidade;
SensorTemperatura sensorTemperatura;
Reservatorio reservatorio;
BombaAgua bomba;
```

## Métodos Previstos

```cpp
SistemaIrrigacao(
    Planta planta,
    SensorUmidade sensorUmidade,
    SensorTemperatura sensorTemperatura,
    Reservatorio reservatorio
);

bool precisaIrrigar();
float calcularAguaNecessariaMl();
void verificarSistema();
void irrigar();
void exibirStatus();
void atualizarUmidade(float novaUmidade);
void atualizarTemperatura(float novaTemperatura);
void abastecerReservatorio(float quantidadeMl);
string getNomePlanta();
float getUmidadeAtual();
float getUmidadeMinimaIdeal();
float getAguaPorIrrigacaoMl();
```

Esses métodos não leem dados do teclado. Eles recebem valores já tratados pela `ConsoleView`.

Métodos como `precisaIrrigar()` retornam `true` ou `false`. A `ConsoleView` usa esse resultado para mostrar a mensagem adequada.

Os getters específicos existem para a `ConsoleView` montar telas de status sem acessar os objetos internos diretamente.

## Regra Principal

1. Verificar se o solo está seco.
2. Se o solo não estiver seco, não irrigar.
3. Se o solo estiver seco, calcular a água necessária.
4. Verificar se o reservatório tem água suficiente.
5. Se houver água suficiente, ligar a bomba, consumir água e desligar a bomba.
6. Se não houver água suficiente, manter a bomba desligada.

## Cálculo de Água

| Temperatura | Água necessária |
| --- | --- |
| Menor ou igual a 30°C | Água normal da planta |
| Maior que 30°C | Água normal da planta + 20% |

## Não Deve Fazer

- Não deve ler `cin`.
- Não deve montar menu.
- Não deve depender de interface gráfica.
- Não deve imprimir mensagens diretamente se existir `Alerta` ou `ConsoleView` para isso.

## Forma de Implementar

Para começar de forma incremental, `SistemaIrrigacao` pode nascer apenas com `Planta`, `SensorUmidade` e um método `precisaIrrigar()`.

Depois que `SensorTemperatura`, `Reservatorio` e `BombaAgua` existirem, o construtor e os métodos serão ampliados para usar esses objetos.

## Checklist de Implementação

- Criar atributos principais.
- Criar construtor.
- Criar `precisaIrrigar`.
- Criar `calcularAguaNecessariaMl`.
- Criar `irrigar`.
- Criar `verificarSistema`.
- Criar métodos de atualização.
- Criar getters específicos para exibir status.
- Garantir que bomba desligue após irrigação.
- Garantir que bomba não ligue sem água suficiente.

## Links Relacionados

- [Regras de negócio](../regras/regras-de-negocio.md)
- [ConsoleView](console-view.md)
- [Alerta](alerta.md)

