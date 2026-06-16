# Especificação do Projeto

Este arquivo é o ponto de entrada da especificação. Ele não deve concentrar todos os detalhes do projeto; a documentação foi separada por tema para facilitar consulta durante a implementação.

## Resumo

**Nome:** Sistema de Irrigação Automatizado  
**Tipo:** Simulação em terminal  
**Linguagem:** C++  
**Paradigma:** Programação Orientada a Objetos  
**Contexto:** Trabalho acadêmico de POO

O sistema simula uma irrigação automatizada para uma planta. Ele usa umidade do solo, temperatura ambiente e água disponível no reservatório para decidir se deve irrigar.

Nesta entrega, os dados iniciais são criados no `main.cpp` e a interação acontece pelo menu do terminal.

## Mapa da Documentação

Documento de origem:

- [Proposta inicial](../propostaInicial.md)

### Projeto

- [Escopo](projeto/escopo.md)
- [Roteiro de implementação](projeto/roteiro-de-implementacao.md)

### Regras

- [Regras de negócio](regras/regras-de-negocio.md)

### Classes

- [Mapa das classes](classes/README.md)
- [Planta](classes/planta.md)
- [SensorUmidade](classes/sensor-umidade.md)
- [SensorTemperatura](classes/sensor-temperatura.md)
- [Reservatorio](classes/reservatorio.md)
- [BombaAgua](classes/bomba-agua.md)
- [SistemaIrrigacao](classes/sistema-irrigacao.md)
- [Alerta](classes/alerta.md)
- [ConsoleView](classes/console-view.md)

### Organização e Padrões

- [Estrutura de pastas](arquitetura/estrutura-de-pastas.md)
- [Diagrama de classes](arquitetura/diagrama-de-classes.md)
- [Padrões do projeto](padroes/padroes-do-projeto.md)

## Leitura Recomendada

Leitura mínima para entender o projeto:

1. Leia esta especificação.
2. Leia [Escopo](projeto/escopo.md).
3. Leia [Regras de negócio](regras/regras-de-negocio.md).
4. Leia [Mapa das classes](classes/README.md).

Para alterar ou revisar o código:

1. Leia [Padrões do projeto](padroes/padroes-do-projeto.md).
2. Siga o [Roteiro de implementação](projeto/roteiro-de-implementacao.md).

Não é necessário ler todos os arquivos. Os documentos de cada classe são consulta para entender ou alterar aquela parte.
