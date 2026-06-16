# Estrutura de Pastas

## Estrutura Atual

```
Sistema_Irrigacao/
|-- README.md
|-- propostaInicial.md
|-- build/
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

`build/` guarda arquivos gerados pela compilação. Não colocar código-fonte nessa pasta.

## Responsabilidade das Pastas

## Arquitetura Usada

O projeto usa uma arquitetura em camadas simples, próxima da ideia de MVC:

| Camada do projeto | Relação com MVC | Responsabilidade |
| --- | --- | --- |
| `src/models` | Model | Representa os objetos do domínio, como planta, sensores, reservatório e bomba. |
| `src/services` | Controller/Service | Coordena os models e aplica as regras de negócio. |
| `src/views` | View | Faz a interação com o usuário pelo terminal. |

Não é um MVC puro de aplicações web ou gráficas. Como o sistema é de terminal, não existe uma tela visual atualizada automaticamente. Mesmo assim, a separação segue o princípio central do MVC: cada parte tem uma responsabilidade clara.

Essa divisão facilita explicar o projeto:

- dados e comportamentos simples ficam nos models;
- regras de irrigação ficam no serviço principal;
- leitura e impressão no terminal ficam na view;
- `main.cpp` apenas monta os objetos e inicia o programa.

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

### `build`

Arquivos gerados pelo compilador, como executáveis e objetos. Essa pasta fica fora de `src` para não misturar código-fonte com resultado de compilação.

## Regra de Organização

NÃO colocar regra de negócio em `main.cpp` ou em `ConsoleView`.

`main.cpp` deve iniciar o programa.  
`ConsoleView` deve conversar com o usuário.  
`SistemaIrrigacao` deve decidir o funcionamento.
