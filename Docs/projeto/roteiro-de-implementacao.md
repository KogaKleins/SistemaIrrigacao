# Roteiro de Implementação

Este roteiro registra uma ordem segura de implementação e o estado atual do projeto, sem misturar responsabilidades.

## Etapa 1 - Modelos Simples

Status: implementada.

As classes que quase não dependem de outras já estão em `src/models`:

1. `Planta`
2. `SensorUmidade`
3. `SensorTemperatura`
4. `Reservatorio`
5. `BombaAgua`

Essas classes têm atributos privados, construtores e métodos simples.

## Etapa 2 - Controlador Principal

Status: implementada.

`SistemaIrrigacao` coordena os objetos principais e aplica as regras:

- verificar umidade;
- verificar temperatura;
- calcular água necessária;
- validar reservatório;
- ligar e desligar bomba;
- consumir água.

## Etapa 3 - Mensagens

Status: implementada.

`Alerta` concentra mensagens usadas pela interface, sem conter regra de negócio.

## Etapa 4 - Interface de Terminal

Status: implementada.

A `ConsoleView`:

- pedir dados ao usuário;
- exibir menu;
- ler opções;
- chamar métodos do `SistemaIrrigacao`;
- mostrar mensagens.

## Etapa 5 - Main

Status: implementada com dados fixos.

O arquivo deve ser simples:

```cpp
#include "models/Planta.h"
#include "models/Reservatorio.h"
#include "models/SensorTemperatura.h"
#include "models/SensorUmidade.h"
#include "services/SistemaIrrigacao.h"
#include "views/ConsoleView.h"

int main() {
    Planta planta("Manjericao", 40, 150);
    SensorUmidade sensorUmidade(25);
    SensorTemperatura sensorTemperatura(25);
    Reservatorio reservatorio(1000, 600);

    SistemaIrrigacao sistema(planta, sensorUmidade, sensorTemperatura, reservatorio);
    ConsoleView view(sistema);

    view.iniciar();

    return 0;
}
```

Como a entrega não inclui cadastro inicial pelo terminal, o `main.cpp` cria dados fixos para iniciar o fluxo. Mesmo assim, ele não aplica regra de negócio.

## Etapa 6 - Validação Manual

Status: deve ser executada após mudanças no código.

Executar manualmente os cenários principais:

- solo seco com água suficiente;
- solo seco com temperatura alta;
- solo seco sem água suficiente;
- solo adequado;
- solo muito úmido;
- abastecimento do reservatório.

## Itens Fora do Escopo da Entrega

- Cadastro inicial da planta pelo terminal.
- Troca da planta durante a execução.
- Persistência em arquivo ou banco de dados.
- Sensores ou hardware reais.

Esses itens não são necessários para atender à proposta inicial. A entrega se concentra na simulação em terminal e na aplicação de POO.
