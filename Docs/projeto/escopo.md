# Escopo

## O Sistema Vai Fazer

- Cadastrar os dados iniciais de uma planta.
- Armazenar a umidade atual do solo.
- Armazenar a temperatura ambiente atual.
- Armazenar a capacidade máxima do reservatório.
- Armazenar a quantidade atual de água no reservatório.
- Verificar se a planta precisa de irrigação.
- Calcular irrigação normal ou reforçada.
- Ligar e desligar a bomba durante uma irrigação válida.
- Consumir água do reservatório depois de irrigar.
- Exibir alertas e mensagens de status no terminal.
- Permitir alterar umidade, temperatura e água do reservatório durante a execução.

## O Sistema Não Vai Fazer

- Não vai usar sensores físicos reais.
- Não vai controlar hardware real.
- Não vai salvar dados em arquivo ou banco de dados.
- Não vai trabalhar com várias plantas ao mesmo tempo.
- Não vai recalcular automaticamente a umidade do solo depois da irrigação.
- Não vai ter interface gráfica.

## Melhoria Opcional

- Permitir trocar a planta durante a execução.

Para a primeira versão, o sistema pode trabalhar com uma planta cadastrada no início. Isso já é suficiente para demonstrar POO.

## Decisão Sobre Umidade Após Irrigação

Depois que uma irrigação acontece, a umidade do solo não muda automaticamente.

Motivo: como é uma simulação, a umidade representa uma leitura do sensor. O usuário poderá alterar a umidade pelo menu para simular uma nova leitura.

## Unidade Padrão

Todo volume de água será tratado em **mL**.

Isso evita misturar litros e mililitros no código e nos exemplos.
