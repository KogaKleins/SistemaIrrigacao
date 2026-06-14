# Proposta de Projeto de Programação Orientada a Objetos

## Enunciado do Projeto

**Data Início:** 07/06/2026  
**Peso:** 10,0

## Avaliação de Projeto de Programação Orientada a Objetos

### Objetivo

O objetivo deste projeto é permitir que os alunos apliquem os princípios da Programação Orientada a Objetos (POO) para desenvolver um projeto prático e demonstrar as vantagens da POO em relação à programação estruturada.

### Instruções

1. **Formação de Equipes:** Forme equipes de 3 a 4 pessoas.
2. **Linguagem:** O projeto pode ser desenvolvido em C++, Tinkercad ou Wokwi.
3. **Projeto POO:** Cada equipe deve criar um projeto que faça uso dos conceitos de Programação Orientada a Objetos. O projeto deve ser significativo e resolver um problema do mundo real ou criar uma aplicação útil.
4. **Documentação:** Cada equipe deve fornecer documentação detalhada do projeto, incluindo diagramas de classes, descrição dos objetos e métodos, além de comentários explicativos no código.
5. **Apresentação:** Cada equipe terá até 15 minutos de apresentação do projeto e deve preparar slides para a apresentação. Não é necessário explicar todo o código, somente o mais relevante.
6. **Prazo de Entrega:** A apresentação, o projeto e a documentação devem ser entregues na data determinada no plano de ensino: 22/06/2026.

Exemplos de projetos:

- Estação meteorológica.
- Semáforo inteligente.
- Controle de reservatório.
- Sistema de irrigação.
- Monitor de temperatura.
- Controle de acesso.

### Critérios de Avaliação

| Critério | Peso | O que será avaliado |
| --- | --- | --- |
| Uso de POO | 1,0 | Extensividade e eficácia do uso dos conceitos de POO. |
| Qualidade do código | 2,0 | Organização, legibilidade, boas práticas e comentários explicativos. |
| Documentação | 2,0 | Diagramas de classes, descrição de objetos e métodos, e explicação clara da estrutura do projeto. |
| Apresentação | 4,0 | Clareza para explicar o projeto e as escolhas de design orientadas a objetos. |
| Inovação e criatividade | 1,0 | Originalidade da aplicação dos conceitos de POO. |

### Observações Finais

- Todos os membros devem participar ativamente do projeto e da apresentação.
- A colaboração e a comunicação entre os membros da equipe são essenciais.
- A documentação deverá estar em um repositório no GitHub.

## Proposta do Projeto

### Sistema de Irrigação Automatizado

O sistema tem como objetivo simular uma irrigação automatizada para plantas.

Ele lê a umidade do solo. Caso a umidade esteja abaixo de um limite definido, o sistema verifica se há água disponível no reservatório. Se houver água suficiente, a bomba de água é ligada para irrigar a planta. Caso não haja água no reservatório, o sistema emite um alerta informando que a irrigação não pode ser realizada.

Além disso, o sistema pode utilizar a temperatura ambiente como informação complementar para auxiliar a tomada de decisão, permitindo uma simulação mais próxima de um cenário real.

### Objetivo do Projeto

Criar uma aplicação prática utilizando os conceitos de Programação Orientada a Objetos, demonstrando a interação entre diferentes classes que representam componentes de um sistema real de irrigação.

### Classes Previstas

```cpp
class SensorUmidade;
class SensorTemperatura;
class Reservatorio;
class BombaAgua;
class Planta;
class SistemaIrrigacao;
class Alerta;
```
