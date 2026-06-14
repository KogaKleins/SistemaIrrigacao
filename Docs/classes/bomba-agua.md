# Classe BombaAgua

## Objetivo

Representar o estado da bomba de água.

A bomba é simples: ela só sabe se está ligada ou desligada.

## Responsabilidades

- Ligar.
- Desligar.
- Informar se está ligada.

## Atributos

```cpp
bool ligada;
```

## Métodos Previstos

```cpp
BombaAgua();

void ligar();
void desligar();
bool estaLigada();
```

## Estado Inicial

A bomba deve começar desligada.

Valor inicial do atributo: `ligada = false`.

## Regra Importante

A bomba não decide quando deve ligar.

Quem decide é o `SistemaIrrigacao`, depois de verificar:

- umidade do solo;
- temperatura;
- quantidade de água necessária;
- água disponível no reservatório.

## Não Deve Fazer

- Não deve verificar reservatório.
- Não deve consumir água.
- Não deve calcular irrigação.
- Não deve ler dados do terminal.
- Não deve exibir menu.

## Exemplo de Uso

```cpp
BombaAgua bomba;

bomba.ligar();
bomba.desligar();
```

## Checklist de Implementação

- Criar atributo privado `ligada`.
- Inicializar como `false`.
- Criar método `ligar`.
- Criar método `desligar`.
- Criar método `estaLigada`.

## Links Relacionados

- [Reservatorio](reservatorio.md)
- [SistemaIrrigacao](sistema-irrigacao.md)
- [Regras de negócio](../regras/regras-de-negocio.md)
