# Padrões do Projeto

Combinados simples para o código ficar consistente.

## Linguagem

- Usar C++.
- Usar terminal.
- Usar `float` para números com casas decimais.
- Usar `string` para textos.
- Usar `using namespace std;` para simplificar o primeiro projeto.

## Arquivos

Cada classe tem um arquivo `.h` e um arquivo `.cpp`.

Exemplo:

- `SensorUmidade.h`
- `SensorUmidade.cpp`

## Nomes

Classes começam com letra maiúscula:

- `Planta`
- `SensorUmidade`
- `SensorTemperatura`
- `Reservatorio`
- `BombaAgua`
- `SistemaIrrigacao`
- `ConsoleView`
- `Alerta`

Atributos e métodos começam com letra minúscula:

- `umidadeAtual`
- `aguaPorIrrigacaoMl`
- `calcularAguaNecessariaMl`
- `temAguaSuficiente`

## Encapsulamento

Para praticar POO, os atributos ficam `private`.

Exemplo:

```cpp
class BombaAgua {
private:
    bool ligada;

public:
    void ligar();
    void desligar();
    bool estaLigada();
};
```

## Responsabilidade de Cada Classe

Cada classe deve cuidar de uma parte. O resumo das responsabilidades fica no [mapa das classes](../classes/README.md), e o detalhe de cada classe fica no arquivo próprio dela.

Regra prática: se um método começa a fazer coisa demais, ele provavelmente pertence a outra classe.

## Entrada e Saída no Terminal

Para simplificar:

- `ConsoleView` usa `cin` e `cout`;
- as outras classes evitam `cin`;
- a regra principal fica em `SistemaIrrigacao`.

Fluxo esperado:

1. `ConsoleView` lê dados.
2. `SistemaIrrigacao` aplica as regras.
3. `ConsoleView` mostra o resultado.

## Organização dos Arquivos

- Classes de domínio ficam em `src/models`.
- O controlador principal fica em `src/services`.
- Classes ligadas à interface de terminal ficam em `src/views`.
- `main.cpp` deve apenas iniciar a aplicação.

Regras do sistema ficam em [Regras de negócio](../regras/regras-de-negocio.md). O que entra ou não entra na entrega fica em [Escopo](../projeto/escopo.md).

## Comentários

Comentários devem ajudar a entender decisões importantes. Não precisa comentar o óbvio.

Bom:

```cpp
// A temperatura só aumenta a água se o solo estiver seco.
```

Desnecessário:

```cpp
// Soma 1.
x++;
```

## Main

`main.cpp` deve ser pequeno:

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
