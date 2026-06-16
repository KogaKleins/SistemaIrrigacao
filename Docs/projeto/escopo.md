# Escopo

## O Sistema Entrega

- Usar dados iniciais fixos de uma planta no `main.cpp`.
- Armazenar a umidade atual do solo.
- Armazenar a temperatura ambiente atual.
- Armazenar a capacidade máxima do reservatório.
- Armazenar a quantidade atual de água no reservatório.
- Verificar se a planta precisa de irrigação.
- Calcular irrigação normal ou reforçada.
- Ligar e desligar a bomba durante uma irrigação válida.
- Consumir água do reservatório depois de irrigar.
- Exibir alertas e mensagens de status no terminal.
- Permitir alterar umidade e temperatura durante a execução.
- Permitir abastecer o reservatório durante a execução.

## Fora do Escopo da Entrega

- Não vai usar sensores físicos reais.
- Não vai controlar hardware real.
- Não vai salvar dados em arquivo ou banco de dados.
- Não vai trabalhar com várias plantas ao mesmo tempo.
- Não vai recalcular automaticamente a umidade do solo depois da irrigação.
- Não vai ter interface gráfica.
- Não vai cadastrar uma nova planta pelo menu.
- Não vai trocar a planta durante a execução.

Esses itens não são pendências. Eles ficam fora da entrega para manter o projeto coerente com a proposta acadêmica: demonstrar POO, separação de responsabilidades e interação entre classes em uma simulação de irrigação.

Para esta entrega, o sistema trabalha com uma planta criada no `main.cpp`. Isso já é suficiente para demonstrar POO e manter o foco na interação entre classes.

## Decisão Sobre Umidade Após Irrigação

Depois que uma irrigação acontece, a umidade do solo não muda automaticamente.

Motivo: como é uma simulação, a umidade representa uma leitura do sensor. O usuário poderá alterar a umidade pelo menu para simular uma nova leitura.

## Unidade Padrão

Todo volume de água é tratado em **mL**.

Isso evita misturar litros e mililitros no código e nos exemplos.
