# Classe SensorTemperatura

## Objetivo

Representar a leitura simulada da temperatura ambiente.

O sensor não deve decidir se a irrigação acontece. Ele apenas guarda e classifica a temperatura.

## Responsabilidades

- Guardar a temperatura atual.
- Permitir atualização da temperatura por um valor recebido de fora.
- Informar se a temperatura está baixa, normal ou alta.

## Atributos

```cpp
float temperaturaAtual;
```

## Métodos Previstos

```cpp
SensorTemperatura(float temperaturaAtual);

float getTemperaturaAtual();
void setTemperaturaAtual(float temperatura);
bool temperaturaAlta();
bool temperaturaBaixa();
bool temperaturaNormal();
```

`setTemperaturaAtual(float temperatura)` não lê do teclado. Ele apenas recebe um número e atualiza o atributo `temperaturaAtual`.

Quem lê o valor digitado pelo usuário é `ConsoleView`.

## Regras Usadas

| Condição | Classificação |
| --- | --- |
| `temperaturaAtual < 15` | Temperatura baixa |
| `temperaturaAtual >= 15` e `temperaturaAtual <= 30` | Temperatura normal |
| `temperaturaAtual > 30` | Temperatura alta |

## Validações

A temperatura será aceita como valor numérico real.

Não haverá limite rígido mínimo ou máximo, porque temperaturas podem variar bastante. A validação principal é impedir entrada não numérica na interface.

## Não Deve Fazer

- Não deve ligar bomba.
- Não deve consumir água.
- Não deve decidir irrigação sozinho.
- Não deve exibir menu.

## Exemplo de Uso

```cpp
SensorTemperatura sensor(34);

if (sensor.temperaturaAlta()) {
    // SistemaIrrigacao pode reforçar a irrigação se o solo estiver seco.
}
```

## Checklist de Implementação

- Criar atributo privado `temperaturaAtual`.
- Criar construtor.
- Criar getter.
- Criar setter para atualizar o valor recebido.
- Criar métodos de classificação.

## Links Relacionados

- [SistemaIrrigacao](sistema-irrigacao.md)
- [Regras de negócio](../regras/regras-de-negocio.md)

