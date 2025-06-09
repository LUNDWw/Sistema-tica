# 📋 Sistema de Cadastro - Ótica da Família

Este projeto é um programa simples escrito em **C** que simula o atendimento em uma ótica. Ele permite ao usuário selecionar tipos de produtos, cadastrar clientes com orçamento e buscar clientes já cadastrados.

## 🚀 Funcionalidades

- Apresenta um menu com opções de atendimento:
  - Óculos de grau
  - Óculos de sol
  - Lentes de contato
  - Finalizar sistema
  - Buscar cliente (somente após cadastro)
- Cadastro de cliente com nome e valor de orçamento
- Busca de clientes pelo nome (ignorando diferenças de maiúsculas/minúsculas)
- Limite de até 100 clientes

## 🧾 Estrutura dos Dados

- Estrutura `Cliente` com os campos:
  - `nome`: nome do cliente (string)
  - `orcamento`: valor do orçamento (float)
- Vetor `clientes[MAX_CLIENTES]` para armazenar os registros

## 🛠️ Como funciona

1. Ao iniciar, o sistema exibe um menu.
2. O usuário escolhe o tipo de produto desejado.
3. É oferecida a opção de continuar com o cadastro.
4. Caso o usuário aceite, ele informa o orçamento e o nome.
5. Os dados são armazenados no vetor de clientes.
6. Após o primeiro cadastro, é possível buscar clientes por nome.
7. O sistema permanece em loop até que o usuário escolha a opção "Finalizar".

## 🎞 Prints
  
  ![cap 1](https://github.com/user-attachments/assets/3be36ec6-6f52-404a-9752-f8b421084095)
  
  ![cap 2](https://github.com/user-attachments/assets/61554871-d5b8-4049-90b8-8eb4da84f840)
  
  ![cap 3](https://github.com/user-attachments/assets/a36a33b8-bf75-4e27-b3e9-746c1f30e0e1)
  

## 💡 Sugestões de melhoria

- Armazenar os dados em um arquivo para persistência
- Implementar validação de entrada mais robusta
- Adicionar opções de remover ou editar cliente

## 📌 Compilação

Para compilar:

```bash
gcc cod.c -o otica
```

Para executar:

```bash
./otica
```
##👨‍🎓 Descrição
Aluno: Lucas Eduardo Ribeiro Porto
Curso: Sistema de informações

