# Estrutura de Pastas

## Estrutura Prevista

```
Sistema_Irrigacao/
|-- README.md
|-- propostaInicial.md
|-- Docs/
|   |-- ESPECIFICACAO.md
|   |-- projeto/
|   |   |-- escopo.md
|   |   `-- roteiro-de-implementacao.md
|   |-- regras/
|   |   `-- regras-de-negocio.md
|   |-- classes/
|   |   |-- README.md
|   |   |-- alerta.md
|   |   |-- bomba-agua.md
|   |   |-- console-view.md
|   |   |-- planta.md
|   |   |-- reservatorio.md
|   |   |-- sensor-temperatura.md
|   |   |-- sensor-umidade.md
|   |   `-- sistema-irrigacao.md
|   |-- arquitetura/
|   |   |-- diagrama-de-classes.md
|   |   `-- estrutura-de-pastas.md
|   |-- padroes/
|   |   `-- padroes-do-projeto.md
`-- src/
    |-- main.cpp
    |-- models/
    |   |-- Planta.h
    |   |-- Planta.cpp
    |   |-- SensorUmidade.h
    |   |-- SensorUmidade.cpp
    |   |-- SensorTemperatura.h
    |   |-- SensorTemperatura.cpp
    |   |-- Reservatorio.h
    |   |-- Reservatorio.cpp
    |   |-- BombaAgua.h
    |   `-- BombaAgua.cpp
    |-- services/
    |   |-- SistemaIrrigacao.h
    |   `-- SistemaIrrigacao.cpp
    `-- views/
        |-- Alerta.h
        |-- Alerta.cpp
        |-- ConsoleView.h
        `-- ConsoleView.cpp
```

## Responsabilidade das Pastas

### `src/models`

Classes que representam objetos principais do sistema.

Exemplos:

- `Planta`;
- `SensorUmidade`;
- `SensorTemperatura`;
- `Reservatorio`;
- `BombaAgua`.

### `src/services`

Classes que coordenam regras de negócio.

Exemplo:

- `SistemaIrrigacao`.

### `src/views`

Classes relacionadas à interação com o usuário.

Exemplos:

- `ConsoleView`;
- `Alerta`.

### `Docs`

Documentação do projeto.

## Regra de Organização

NÃO colocar regra de negócio em `main.cpp` ou em `ConsoleView`.

`main.cpp` deve iniciar o programa.  
`ConsoleView` deve conversar com o usuário.  
`SistemaIrrigacao` deve decidir o funcionamento.
