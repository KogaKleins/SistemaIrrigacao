# Roteiro de Implementação

Este roteiro define uma ordem segura para começar a codar sem misturar responsabilidades.

## Etapa 1 - Modelos Simples

Implementar primeiro as classes que quase não dependem de outras:

1. `Planta`
2. `SensorUmidade`
3. `SensorTemperatura`
4. `Reservatorio`
5. `BombaAgua`

Essas classes devem ter atributos privados, construtores e métodos simples.

## Etapa 2 - Controlador Principal

Implementar `SistemaIrrigacao`.

Ele deve receber ou criar os objetos principais e aplicar as regras:

- verificar umidade;
- verificar temperatura;
- calcular água necessária;
- validar reservatório;
- ligar e desligar bomba;
- consumir água.

## Etapa 3 - Mensagens

Implementar `Alerta`.

Ele deve concentrar mensagens usadas pela interface, sem conter regra de negócio.

## Etapa 4 - Interface de Terminal

Implementar `ConsoleView`.

Ela deve:

- pedir dados ao usuário;
- exibir menu;
- ler opções;
- chamar métodos do `SistemaIrrigacao`;
- mostrar mensagens.

## Etapa 5 - Main

Implementar `main.cpp`.

O arquivo deve ser simples:

```cpp
#include "views/ConsoleView.h"

int main() {
    ConsoleView view;
    view.iniciar();

    return 0;
}
```

## Etapa 6 - Validação Manual

Executar manualmente os cenários principais:

- solo seco com água suficiente;
- solo seco com temperatura alta;
- solo seco sem água suficiente;
- solo adequado;
- solo muito úmido;
- abastecimento do reservatório.
