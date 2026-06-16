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

A bomba aparece como atributo, mas não entra no construtor porque ela não depende de dado digitado pelo usuário. Ela sempre começa desligada e passa a ser controlada pelo `SistemaIrrigacao`.

## Resultado da Verificação

`ResultadoVerificacao` é um `enum`, ou seja, uma lista fechada de resultados possíveis.

Ele evita que o `SistemaIrrigacao` devolva textos prontos. Assim:

1. `SistemaIrrigacao` decide o que aconteceu.
2. `ConsoleView` recebe o resultado.
3. `ConsoleView` usa `Alerta` para mostrar a mensagem correta.

Valores atuais:

```cpp
RESULTADO_SOLO_MUITO_UMIDO
RESULTADO_SOLO_ADEQUADO
RESULTADO_TEMPERATURA_ALTA_SEM_IRRIGACAO
RESULTADO_AGUA_INSUFICIENTE
RESULTADO_IRRIGACAO_REALIZADA
RESULTADO_IRRIGACAO_REFORCADA
RESULTADO_IRRIGACAO_COM_TEMPERATURA_BAIXA
```

Esses nomes não são mensagens para o usuário. Eles são códigos claros para o programa.

## Métodos Atuais

### Públicos

```cpp
SistemaIrrigacao(
    Planta planta,
    SensorUmidade sensorUmidade,
    SensorTemperatura sensorTemperatura,
    Reservatorio reservatorio
);

bool precisaIrrigar();
float calcularAguaNecessariaMl();
ResultadoVerificacao verificarSistema();
void atualizarUmidade(float novaUmidade);
void atualizarTemperatura(float novaTemperatura);
float abastecerReservatorio(float quantidadeMl);
string getNomePlanta();
float getUmidadeAtual();
float getTemperaturaAtual();
float getUmidadeMinimaIdeal();
float getAguaPorIrrigacaoMl();
float getQuantidadeAguaReservatorioMl();
float getCapacidadeReservatorioMl();
float getEspacoDisponivelReservatorioMl();
bool bombaEstaLigada();
```

### Interno

```cpp
void irrigar();
```

`irrigar()` fica interno porque só deve ser chamado depois que o próprio sistema verificar solo, temperatura e reservatório.

Esses métodos não leem dados do teclado. Eles recebem valores já tratados pela `ConsoleView`.

Métodos como `precisaIrrigar()` retornam `true` ou `false`. A `ConsoleView` usa esse resultado para mostrar a mensagem adequada.

Os getters específicos existem para a `ConsoleView` montar telas de status sem acessar os objetos internos diretamente.

`verificarSistema()` executa o fluxo principal e retorna um resultado técnico, sem imprimir no terminal. A `ConsoleView` transforma esse resultado em mensagens usando `Alerta`.

`abastecerReservatorio(float quantidadeMl)` deve devolver o excedente informado pelo `Reservatorio`. Se retornar `0`, toda a água coube; se retornar um valor maior que `0`, o reservatório foi preenchido até a capacidade máxima e esse valor representa a água que sobrou.

## Regra Principal

1. Verificar se o solo está muito úmido.
2. Se o solo estiver muito úmido, bloquear a irrigação.
3. Se o solo não estiver seco, não irrigar. Caso a temperatura esteja alta, retornar apenas um alerta informativo.
4. Se o solo estiver seco, calcular a água necessária.
5. Verificar se o reservatório tem água suficiente.
6. Se não houver água suficiente, manter a bomba desligada.
7. Se houver água suficiente, ligar a bomba, consumir água e desligar a bomba.
8. Retornar o resultado técnico para a `ConsoleView` exibir a mensagem correta.

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

## Estado Atual

Nesta entrega, `SensorTemperatura` e `Reservatorio` entram pelo construtor. `BombaAgua` é criada pelo próprio sistema porque seu estado inicial padrão é sempre desligado.

O sistema retorna um `ResultadoVerificacao` em vez de imprimir mensagens diretamente. A `ConsoleView` interpreta esse resultado e usa `Alerta` para mostrar os textos ao usuário.

## Conferência da Implementação Atual

- Atributos principais.
- Construtor com os models recebidos do `main.cpp`.
- Método `precisaIrrigar`.
- Método `calcularAguaNecessariaMl`.
- Método interno `irrigar`.
- Método `verificarSistema`.
- Métodos de atualização.
- Getters específicos para exibir status.
- `abastecerReservatorio` retorna o excedente do reservatório.
- A bomba desliga após irrigação.
- A bomba não liga sem água suficiente.

## Links Relacionados

- [Regras de negócio](../regras/regras-de-negocio.md)
- [ConsoleView](console-view.md)
- [Alerta](alerta.md)

