# Mapa das Classes

Esta pasta serve para consultar cada classe isoladamente.

Não precisa ler todos esses arquivos antes de começar. Leia o mapa abaixo e depois abra apenas a classe que você for consultar ou alterar.

## Classes de Modelo

| Classe | Responsabilidade principal |
| --- | --- |
| [Planta](planta.md) | Guardar as necessidades da planta. |
| [SensorUmidade](sensor-umidade.md) | Guardar e classificar a umidade do solo. |
| [SensorTemperatura](sensor-temperatura.md) | Guardar e classificar a temperatura ambiente. |
| [Reservatorio](reservatorio.md) | Controlar a água disponível. |
| [BombaAgua](bomba-agua.md) | Representar o estado ligado/desligado da bomba. |

## Classe de Serviço

| Classe | Responsabilidade principal |
| --- | --- |
| [SistemaIrrigacao](sistema-irrigacao.md) | Coordenar objetos e aplicar regras de negócio. |

## Classes de Interface

| Classe | Responsabilidade principal |
| --- | --- |
| [Alerta](alerta.md) | Padronizar mensagens exibidas ao usuário. |
| [ConsoleView](console-view.md) | Interagir com o usuário pelo terminal. |

## Regra de Ouro

Cada classe deve ter uma responsabilidade clara.

A bomba não decide quando liga. O sensor não controla reservatório. A tela não calcula regra de irrigação. O controlador é quem coordena tudo.

## Como os Dados Caminham

Fluxo resumido: `ConsoleView` -> `SistemaIrrigacao` -> classes de modelo.

`ConsoleView` recebe dados do usuário.

`SistemaIrrigacao` aplica a lógica.

As classes de modelo guardam os dados e oferecem métodos simples.
