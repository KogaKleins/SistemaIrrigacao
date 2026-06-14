# Regras de Negócio

## RN01 - Umidade é o Fator Principal

A umidade do solo é o principal fator de decisão.

| Condição | Estado do solo | Decisão |
| --- | --- | --- |
| Umidade atual menor que a umidade mínima ideal | Seco | A planta precisa de irrigação. |
| Umidade atual maior ou igual à umidade mínima ideal | Adequado ou muito úmido | A planta não precisa de irrigação. |

## RN02 - Temperatura Não Liga a Bomba Sozinha

A temperatura apenas influencia mensagens e quantidade de água quando o solo já está seco.

| Situação | Resultado |
| --- | --- |
| Temperatura alta e solo seco | Irrigação reforçada. |
| Temperatura alta e solo adequado | Alerta informativo, sem irrigação. |
| Temperatura normal e solo seco | Irrigação normal. |
| Temperatura baixa e solo seco | Irrigação normal com alerta de cuidado. |

## RN03 - Classificação da Temperatura

| Temperatura | Classificação |
| --- | --- |
| Menor que 15°C | Ambiente frio |
| Entre 15°C e 30°C | Ambiente normal |
| Maior que 30°C | Ambiente quente |

## RN04 - Classificação da Umidade

| Umidade | Classificação |
| --- | --- |
| Menor que a umidade mínima ideal da planta | Solo seco |
| Maior ou igual à umidade mínima ideal e menor ou igual a 70% | Solo adequado |
| Maior que 70% | Solo muito úmido |

Solo muito úmido nunca gera irrigação. O sistema apenas informa o estado.

## RN05 - Cálculo da Água Necessária

| Condição | Cálculo |
| --- | --- |
| Solo seco e temperatura menor ou igual a 30°C | Água necessária = água por irrigação da planta |
| Solo seco e temperatura maior que 30°C | Água necessária = água por irrigação da planta + 20% |

Exemplo:

| Item | Valor |
| --- | --- |
| Água por irrigação | 150 mL |
| Temperatura | 34°C |
| Cálculo | 150 mL + 20% |
| Água necessária | 180 mL |

## RN06 - Reservatório Protege a Bomba

Antes de ligar a bomba, o sistema deve verificar se existe água suficiente.

| Condição | Resultado |
| --- | --- |
| Água atual maior ou igual à água necessária | Pode irrigar. |
| Água atual menor que a água necessária | Não pode irrigar; a bomba permanece desligada e o sistema exibe alerta de água insuficiente. |

## RN07 - Consumo de Água

Quando uma irrigação acontece:

1. A bomba liga.
2. O reservatório consome a quantidade calculada.
3. A bomba desliga.
4. O sistema informa o resultado.

O reservatório nunca pode ficar com quantidade negativa.

## RN08 - Abastecimento do Reservatório

Ao abastecer:

| Condição | Resultado |
| --- | --- |
| A quantidade adicionada cabe no reservatório | Soma normalmente. |
| A quantidade adicionada ultrapassa a capacidade máxima | O reservatório fica cheio e o sistema informa que parte da água não coube. |

## RN09 - Entradas Inválidas

O sistema deve rejeitar entradas fora dos limites definidos.

Exemplos:

- umidade menor que 0%;
- umidade maior que 100%;
- água por irrigação menor ou igual a 0;
- reservatório com quantidade atual maior que a capacidade máxima;
- abastecimento com valor menor ou igual a 0.

## Resumo do Fluxo

Quando o usuário escolher **Verificar sistema**:

1. Ler a umidade atual.
2. Comparar a umidade atual com a umidade mínima ideal da planta.
3. Se o solo não estiver seco, não ligar a bomba e exibir o estado do solo.
4. Se o solo estiver seco, calcular a água necessária.
5. Verificar se o reservatório tem água suficiente.
6. Se houver água suficiente, ligar a bomba, consumir água e desligar a bomba.
7. Se não houver água suficiente, manter a bomba desligada e exibir alerta.

## Situações Esperadas

| Umidade | Temperatura | Reservatório | Resultado |
| --- | --- | --- | --- |
| Baixa | Normal | Suficiente | Irrigação normal |
| Baixa | Alta | Suficiente | Irrigação reforçada |
| Baixa | Qualquer | Insuficiente | Não irriga |
| Adequada | Alta | Qualquer | Alerta, sem irrigação |
| Muito úmida | Qualquer | Qualquer | Não irriga |
