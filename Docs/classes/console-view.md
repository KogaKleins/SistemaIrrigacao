# Classe ConsoleView

## Objetivo

Controlar a interação com o usuário pelo terminal.

Ela é a classe que conversa com o usuário, mas não deve conter a regra principal de irrigação.

## Responsabilidades

- Exibir menu.
- Ler opções do usuário.
- Pedir nova umidade.
- Pedir nova temperatura.
- Pedir quantidade para abastecer o reservatório.
- Chamar métodos do `SistemaIrrigacao`.
- Mostrar mensagens no terminal.

`ConsoleView` é o único lugar que deve usar `cin` e `cout` de forma direta.

## Objetos que a ConsoleView Usa

`ConsoleView` precisa conversar com o sistema principal e exibir mensagens.

Por isso, ela tem estes objetos:

```cpp
SistemaIrrigacao sistema;
Alerta alerta;
```

Esses objetos não são os dados digitados pelo usuário. Eles são ferramentas que a tela usa.

O fluxo é:

1. `ConsoleView` recebe dados do usuário.
2. `ConsoleView` valida entradas básicas.
3. `ConsoleView` chama métodos do `SistemaIrrigacao`.
4. `SistemaIrrigacao` manipula os objetos e aplica as regras.
5. `ConsoleView` mostra o resultado.

## Métodos Atuais

```cpp
ConsoleView(SistemaIrrigacao sistema);

void iniciar();
void exibirMenu();
int lerOpcao();
void verificarSistema();
void exibirStatus();
void alterarUmidade();
void alterarTemperatura();
void abastecerReservatorio();
```

Helpers internos usados pela própria `ConsoleView`:

```cpp
float lerFloat(string mensagem);
int lerInteiroEntre(string mensagem, int minimo, int maximo);
float lerFloatEntre(string mensagem, float minimo, float maximo);
float lerFloatMaiorQue(string mensagem, float minimo);
void exibirResultadoVerificacao(ResultadoVerificacao resultado);
```

Nesta entrega, a `ConsoleView` recebe um `SistemaIrrigacao` já criado. Os dados iniciais são montados no `main.cpp`; a tela controla apenas as ações disponíveis no menu.

`verificarSistema()` na `ConsoleView` representa a opção do menu. Ele deve apenas chamar `SistemaIrrigacao::verificarSistema()` e exibir a mensagem adequada. A regra completa continua no `SistemaIrrigacao`.

## Menu Atual

```
====================================
 SISTEMA DE IRRIGAÇÃO AUTOMATIZADO
====================================

1 - Verificar sistema
2 - Exibir status atual
3 - Alterar umidade do solo
4 - Alterar temperatura
5 - Abastecer reservatorio
0 - Sair

Escolha uma opção:
```

## Não Deve Fazer

- Não deve calcular água reforçada.
- Não deve decidir se a bomba liga.
- Não deve consumir água diretamente.
- Não deve abastecer o reservatório diretamente.
- Não deve acessar atributos privados das classes.

## Conferência de Entrada

A interface deve tentar impedir entradas inválidas.

Essa conferência é básica. Ela verifica se o usuário digitou algo aceitável.

Depois de validar, a interface envia o valor para o objeto correto. Exemplo: lê a nova umidade, confere se está entre 0 e 100, e só então chama um método do sistema para atualizar a umidade.

Para facilitar o tratamento de erro, a leitura pode usar `getline` e converter a entrada para número. Assim a interface consegue rejeitar letras, entrada vazia e valores fora do intervalo sem travar o programa.

A decisão de irrigar continua sendo responsabilidade do `SistemaIrrigacao`.

Exemplos:

- opção de menu fora do intervalo;
- umidade menor que 0 ou maior que 100;
- entrada não numérica onde o sistema espera número.

## Conferência da Implementação Atual

- Loop principal.
- Menu.
- Leitura de opção.
- Chamadas para verificar sistema, exibir status e alterar umidade.
- Chamadas para alterar temperatura e abastecer reservatório.
- Validação da entrada da umidade.
- Validação da entrada do abastecimento.
- Encerramento quando o usuário escolhe `0`.

## Links Relacionados

- [SistemaIrrigacao](sistema-irrigacao.md)
- [Alerta](alerta.md)
- [Padrões do projeto](../padroes/padroes-do-projeto.md)
