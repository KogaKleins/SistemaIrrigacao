# Classe Planta

## Objetivo

Representar a planta ativa do sistema e guardar suas necessidades básicas de irrigação.

## Responsabilidades

- Guardar o nome da planta.
- Guardar a umidade mínima ideal.
- Guardar a quantidade normal de água por irrigação.
- Fornecer esses dados para o `SistemaIrrigacao`.

## Papel no Fluxo

A `Planta` não decide nada sozinha. Ela apenas guarda os dados que representam a necessidade da planta.

Exemplo:

| Objeto | Dado ou ação |
| --- | --- |
| `Planta` | Umidade mínima ideal = 40% |
| `SensorUmidade` | Umidade atual = 25% |
| `SistemaIrrigacao` | Compara 25% < 40% e decide irrigar. |

O `ConsoleView` pode impedir que o usuário cadastre uma umidade mínima inválida, mas quem usa essa umidade para decidir a irrigação é o `SistemaIrrigacao`.

## Atributos

```cpp
string nome;
float umidadeMinimaIdeal;
float aguaPorIrrigacaoMl;
```

## Métodos Atuais

```cpp
Planta(string nome, float umidadeMinimaIdeal, float aguaPorIrrigacaoMl);

string getNome();
float getUmidadeMinimaIdeal();
float getAguaPorIrrigacaoMl();
```

## Validações

Esses valores devem chegar válidos para a `Planta`.

Nesta entrega, os dados iniciais da planta são fixos no `main.cpp`, então esses valores devem ser mantidos válidos na própria montagem inicial:

- `nome` não deve ser vazio.
- `umidadeMinimaIdeal` deve estar entre 1 e 70.
- `aguaPorIrrigacaoMl` deve ser maior que 0.

Assim, a `Planta` continua simples: ela guarda os dados e fornece getters.

## Não Deve Fazer

- Não deve ler dados do terminal.
- Não deve decidir se a bomba liga.
- Não deve consumir água do reservatório.
- Não deve alterar sensores.

## Exemplo de Uso

```cpp
Planta planta("Manjericão", 40, 150);
```

## Links Relacionados

- [SistemaIrrigacao](sistema-irrigacao.md)
- [Regras de negócio](../regras/regras-de-negocio.md)

