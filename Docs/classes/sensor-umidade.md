# Classe SensorUmidade

## Objetivo

Representar a leitura simulada da umidade do solo.

O sensor não mede nada fisicamente. Ele guarda o valor informado pelo usuário e permite que o sistema consulte esse valor.

## Responsabilidades

- Guardar a umidade atual do solo.
- Permitir atualização da umidade por um valor recebido de fora.
- Informar se o solo está seco em relação ao limite da planta.
- Informar se o solo está muito úmido.

## Atributos

```cpp
float umidadeAtual;
```

## Métodos Previstos

```cpp
SensorUmidade(float umidadeAtual);

float getUmidadeAtual();
void setUmidadeAtual(float umidade);
bool soloEstaSeco(float limiteMinimo);
bool soloMuitoUmido();
```

`setUmidadeAtual(float umidade)` não lê do teclado. Ele apenas recebe um número e atualiza o atributo `umidadeAtual`.

Quem lê o valor digitado pelo usuário é `ConsoleView`.

## Regras Usadas

| Condição | Classificação |
| --- | --- |
| `umidadeAtual < limiteMinimo` | Solo seco |
| `umidadeAtual >= limiteMinimo` e `umidadeAtual <= 70` | Solo adequado |
| `umidadeAtual > 70` | Solo muito úmido |

## Validações

A validação amigável da entrada deve acontecer em `ConsoleView`, antes de chamar `setUmidadeAtual`.

Regra esperada:

- a umidade não pode ser menor que 0;
- a umidade não pode ser maior que 100.

## Não Deve Fazer

- Não deve decidir sozinho se haverá irrigação.
- Não deve ligar ou desligar bomba.
- Não deve calcular quantidade de água.
- Não deve exibir menu.
- Não deve ler `cin`.

## Exemplo de Uso

```cpp
SensorUmidade sensor(25);

if (sensor.soloEstaSeco(40)) {
    // SistemaIrrigacao decide o próximo passo.
}
```

## Checklist de Implementação

- Criar atributo privado `umidadeAtual`.
- Criar construtor.
- Criar getter.
- Criar setter para atualizar o valor recebido.
- Criar método `soloEstaSeco`.
- Criar método `soloMuitoUmido`.

## Links Relacionados

- [Planta](planta.md)
- [SistemaIrrigacao](sistema-irrigacao.md)
- [Regras de negócio](../regras/regras-de-negocio.md)

