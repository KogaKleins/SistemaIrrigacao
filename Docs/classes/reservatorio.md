# Classe Reservatorio

## Objetivo

Representar o reservatório de água disponível para irrigação.

## Responsabilidades

- Guardar a capacidade máxima.
- Guardar a quantidade atual de água.
- Informar se há água suficiente para uma irrigação.
- Consumir água quando a irrigação acontece.
- Permitir abastecimento por um valor recebido de fora.
- Impedir quantidade negativa.
- Impedir quantidade acima da capacidade máxima.

## Atributos

```cpp
float capacidadeMaximaMl;
float quantidadeAtualMl;
```

## Métodos Atuais

```cpp
Reservatorio(float capacidadeMaximaMl, float quantidadeAtualMl);

float getCapacidadeMaximaMl();
float getQuantidadeAtualMl();
float getEspacoDisponivelMl();
bool temAguaSuficiente(float quantidadeNecessariaMl);
void consumirAgua(float quantidadeMl);
float abastecer(float quantidadeMl);
```

`abastecer(float quantidadeMl)` não lê do teclado. Ele recebe a quantidade já lida pela interface e atualiza o reservatório.

Quem pede o valor ao usuário é `ConsoleView`.

## Observação Sobre `abastecer`

O método retorna quanto não coube no reservatório.

- Se tudo couber, retorna `0`.
- Se ultrapassar a capacidade, enche o reservatório até o máximo e retorna o excedente.

Exemplo:

| Item | Valor |
| --- | --- |
| Capacidade | 1000 mL |
| Quantidade atual | 900 mL |
| Tentativa de abastecimento | 300 mL |
| Quantidade realmente adicionada | 100 mL |
| Quantidade que não coube | 200 mL |
| Quantidade final | 1000 mL |

Assim, o `Reservatorio` protege o limite físico. O `SistemaIrrigacao` pode usar o valor retornado para avisar a `ConsoleView`, e a `ConsoleView` mostra a mensagem ao usuário.

## Validações

A validação amigável da entrada deve acontecer em `ConsoleView`, antes de criar ou atualizar o reservatório.

Regras esperadas:

- `capacidadeMaximaMl` deve ser maior que 0;
- `quantidadeAtualMl` deve estar entre 0 e `capacidadeMaximaMl`;
- `quantidadeMl` para consumo deve ser maior que 0;
- `quantidadeMl` para abastecimento deve ser maior que 0.

## Não Deve Fazer

- Não deve decidir se a planta precisa de água.
- Não deve ligar bomba.
- Não deve ler dados do terminal.
- Não deve exibir menu.

## Exemplo de Uso

```cpp
Reservatorio reservatorio(1000, 600);

if (reservatorio.temAguaSuficiente(150)) {
    reservatorio.consumirAgua(150);
}
```

## Conferência da Implementação Atual

- Atributos privados.
- Recebimento de valores iniciais válidos.
- Getters.
- Método `getEspacoDisponivelMl`.
- Método `temAguaSuficiente`.
- Método `consumirAgua`.
- Método `abastecer`.
- `abastecer` retorna o excedente quando a capacidade é ultrapassada.

## Links Relacionados

- [BombaAgua](bomba-agua.md)
- [SistemaIrrigacao](sistema-irrigacao.md)
- [Regras de negócio](../regras/regras-de-negocio.md)
