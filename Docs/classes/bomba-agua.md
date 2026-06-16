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

## Métodos Atuais

```cpp
BombaAgua();
BombaAgua(bool ligada);

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

O construtor com `bool` pode ser usado em testes ou simulações específicas, mas o uso normal cria a bomba desligada.

## Conferência da Implementação Atual

- Atributo privado `ligada`.
- Inicialização padrão como `false`.
- Método `ligar`.
- Método `desligar`.
- Método `estaLigada`.

## Links Relacionados

- [Reservatorio](reservatorio.md)
- [SistemaIrrigacao](sistema-irrigacao.md)
- [Regras de negócio](../regras/regras-de-negocio.md)
