# Sistema de Irrigação

Projeto acadêmico de Programação Orientada a Objetos em C++.

O sistema simula, via terminal, uma irrigação automatizada para uma planta. A aplicação usa dados simulados, como umidade do solo e necessidade da planta, para decidir se a planta precisa de irrigação.

## Estado Atual

A implementação está incremental. Nesta etapa, o projeto já possui:

- cadastro inicial fixo de uma planta no `main.cpp`;
- leitura simulada de umidade do solo;
- verificação se o solo está abaixo da umidade mínima ideal;
- menu de terminal com validação de entrada;
- alteração da umidade atual durante a execução;
- exibição de status atual.

Ainda serão implementados:

- sensor de temperatura;
- reservatório;
- bomba de água;
- mensagens centralizadas em `Alerta`;
- cálculo de irrigação normal ou reforçada;
- verificação de água disponível antes de irrigar.

## Funcionalidades Disponíveis

Menu atual:

```
1 - Verificar sistema
2 - Exibir status atual
3 - Alterar umidade do solo
0 - Sair
```

Exemplo de decisão atual:

- se a umidade atual for menor que a umidade mínima ideal da planta, o sistema informa que a planta precisa de irrigação;
- se a umidade atual for maior ou igual à umidade mínima ideal, o sistema informa que não precisa irrigar no momento.

## Arquitetura

O projeto está separado em camadas simples:

| Camada | Pasta | Responsabilidade |
| --- | --- | --- |
| Models | `src/models` | Guardam dados e respondem perguntas simples sobre seus próprios valores. |
| Services | `src/services` | Coordenam os models e aplicam regras de negócio. |
| Views | `src/views` | Fazem a interação com o usuário no terminal. |

Fluxo atual:

```
main.cpp
  cria Planta
  cria SensorUmidade
  cria SistemaIrrigacao
  inicia ConsoleView

ConsoleView
  lê entradas
  valida dados
  chama SistemaIrrigacao

SistemaIrrigacao
  consulta Planta e SensorUmidade
  decide se precisa irrigar
```

## Como Executar

No VS Code, use:

1. `Terminal > Run Task...`
2. `C++: build and run`

Ou execute pelo PowerShell:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File scripts\build.ps1 -Run
```

O script compila todos os arquivos `.cpp` dentro de `src/` e gera:

```
build/sistema_irrigacao.exe
```

## Requisitos

- Windows com PowerShell.
- Compilador C++ compatível com `g++`.

O script tenta localizar automaticamente:

- `g++`;
- `clang++`;
- `c++`;
- `mingw32-g++`;
- `C:\Program Files (x86)\Dev-Cpp\MinGW64\bin\g++.exe`.

## Estrutura Principal

```
Sistema_Irrigacao/
|-- README.md
|-- propostaInicial.md
|-- Docs/
|-- scripts/
|   `-- build.ps1
`-- src/
    |-- main.cpp
    |-- models/
    |-- services/
    `-- views/
```

## Documentação

- [Especificação do projeto](Docs/ESPECIFICACAO.md)
- [Escopo](Docs/projeto/escopo.md)
- [Roteiro de implementação](Docs/projeto/roteiro-de-implementacao.md)
- [Regras de negócio](Docs/regras/regras-de-negocio.md)
- [Mapa das classes](Docs/classes/README.md)
- [Diagrama de classes](Docs/arquitetura/diagrama-de-classes.md)
- [Padrões do projeto](Docs/padroes/padroes-do-projeto.md)

## Objetivo Acadêmico

O projeto foi criado para praticar:

- classes e objetos;
- encapsulamento;
- construtores;
- separação de responsabilidades;
- interação entre objetos;
- organização de um projeto C++ em múltiplos arquivos.
