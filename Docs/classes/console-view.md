# Classe ConsoleView

## Objetivo

Controlar a interação com o usuário pelo terminal.

Ela é a classe que conversa com o usuário, mas não deve conter a regra principal de irrigação.

## Responsabilidades

- Exibir menu.
- Ler opções do usuário.
- Pedir nova umidade.
- Chamar métodos do `SistemaIrrigacao`.
- Mostrar mensagens no terminal.

`ConsoleView` é o único lugar que deve usar `cin` e `cout` de forma direta.

## Objetos que a ConsoleView Usa

`ConsoleView` precisa conversar com o sistema principal e exibir mensagens.

Por isso, ela provavelmente terá objetos como:

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

## Métodos Previstos

```cpp
ConsoleView(SistemaIrrigacao sistema);

void iniciar();
void exibirMenu();
int lerOpcao();
void verificarSistema();
void exibirStatus();
void alterarUmidade();
```

Na versão atual, a `ConsoleView` recebe um `SistemaIrrigacao` já criado. O cadastro inicial completo ficará para uma etapa posterior.

## Menu Previsto

```
====================================
 SISTEMA DE IRRIGAÇÃO AUTOMATIZADO
====================================

1 - Verificar sistema
2 - Exibir status atual
3 - Alterar umidade do solo
0 - Sair

Escolha uma opção:
```

## Não Deve Fazer

- Não deve calcular água reforçada.
- Não deve decidir se a bomba liga.
- Não deve consumir água diretamente.
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

## Checklist de Implementação

- Criar loop principal.
- Criar menu.
- Criar leitura de opção.
- Criar chamadas para verificar sistema, exibir status e alterar umidade.
- Validar entrada da umidade.
- Encerrar quando o usuário escolher `0`.

## Links Relacionados

- [SistemaIrrigacao](sistema-irrigacao.md)
- [Alerta](alerta.md)
- [Padrões do projeto](../padroes/padroes-do-projeto.md)
