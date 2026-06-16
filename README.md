# Sistema de Irrigação

Projeto acadêmico de Programação Orientada a Objetos em C++.

O sistema simula, via terminal, uma irrigação automatizada para uma planta. A aplicação usa dados simulados, como umidade do solo, temperatura ambiente e água disponível no reservatório, para decidir se a planta precisa de irrigação.

## Estado da Entrega

A entrega possui:

- cadastro inicial fixo de uma planta no `main.cpp`;
- leitura simulada de umidade do solo;
- leitura simulada de temperatura ambiente;
- reservatório com capacidade máxima, quantidade atual, consumo e abastecimento;
- bomba de água controlada pelo sistema;
- verificação se o solo está seco, adequado ou muito úmido;
- cálculo de irrigação normal ou reforçada;
- bloqueio da irrigação quando não há água suficiente;
- mensagens centralizadas em `Alerta`;
- menu de terminal com validação de entrada;
- alteração da umidade atual durante a execução;
- alteração da temperatura atual durante a execução;
- abastecimento do reservatório durante a execução;
- exibição de status atual.

## Fora do Escopo da Entrega

Os itens abaixo não são pendências desta entrega. Eles foram deixados fora do escopo para manter o projeto focado na simulação em terminal e nos conceitos de POO pedidos na proposta:

- cadastro de planta pelo menu;
- suporte a várias plantas;
- persistência em arquivo ou banco de dados;
- sensores ou hardware reais.

## Funcionalidades Disponíveis

Menu atual:

```
1 - Verificar sistema
2 - Exibir status atual
3 - Alterar umidade do solo
4 - Alterar temperatura
5 - Abastecer reservatorio
0 - Sair
```

Exemplos de decisão atual:

- se a umidade atual for menor que a umidade mínima ideal da planta, o sistema informa que a planta precisa de irrigação;
- se a umidade atual for maior ou igual à umidade mínima ideal, o sistema informa que não precisa irrigar no momento;
- se a temperatura estiver alta e o solo estiver seco, a irrigação usa 20% a mais de água;
- se o reservatório não tiver água suficiente, a bomba permanece desligada;
- se o solo estiver muito úmido, a irrigação é bloqueada.

## Arquitetura

O projeto está separado em camadas simples:

| Camada | Pasta | Responsabilidade |
| --- | --- | --- |
| Models | `src/models` | Guardam dados e respondem perguntas simples sobre seus próprios valores. |
| Services | `src/services` | Coordenam os models e aplicam regras de negócio. |
| Views | `src/views` | Fazem a interação com o usuário no terminal. |

Essa organização é próxima da ideia de **MVC**, mas no projeto ela funciona melhor como uma arquitetura em camadas:

- `models` fazem o papel de **Model**, guardando estado e comportamentos simples dos objetos do domínio.
- `views` fazem o papel de **View**, cuidando da entrada e saída no terminal.
- `services` fazem o papel de **Controller/Service**, coordenando os objetos e aplicando as regras de negócio.

Não é um MVC puro de aplicações gráficas ou web, porque não existe interface visual reagindo a eventos nem atualização automática de tela. Para este projeto em terminal, a separação `models`, `services` e `views` cumpre o mesmo objetivo principal: separar dados, regras e interação com o usuário.

Fluxo atual:

```
main.cpp
  cria Planta
  cria SensorUmidade
  cria SensorTemperatura
  cria Reservatorio
  cria SistemaIrrigacao
  inicia ConsoleView

ConsoleView
  lê entradas
  valida dados
  chama SistemaIrrigacao

SistemaIrrigacao
  consulta Planta, SensorUmidade, SensorTemperatura e Reservatorio
  controla BombaAgua
  decide se deve irrigar, bloquear ou apenas alertar
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
