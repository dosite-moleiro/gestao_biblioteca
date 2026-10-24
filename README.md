# 📚 Sistema de Gestão de Biblioteca em C

Projeto acadêmico desenvolvido em linguagem C durante a disciplina de **Algoritmos e Pensamento Computacional**, no curso de Análise e Desenvolvimento de Sistemas.

## 🎯 Objetivo

Desenvolver um sistema de console para gerenciar livros de uma biblioteca, praticando os fundamentos da lógica de programação e a organização de dados por meio da linguagem C.

## ⚙️ Funcionalidades

- 📖 Cadastro de livros com código, título, autor e ano de publicação
- 📋 Listagem dos livros cadastrados
- 🔎 Busca de livros pelo código
- 📤 Registro de empréstimos
- 📥 Registro de devoluções
- ✅ Verificação da disponibilidade dos livros
- 💾 Salvamento e carregamento dos dados em arquivo de texto
- 🚫 Validação de códigos duplicados e limite de livros cadastrados

## 🛠️ Tecnologias e conceitos praticados

- Linguagem C
- Estruturas (`struct`)
- Vetores
- Funções
- Estruturas condicionais (`if/else` e `switch`)
- Estruturas de repetição (`do/while` e `for`)
- Manipulação de arquivos (`fopen`, `fscanf` e `fprintf`)
- Entrada e saída de dados

## ▶️ Como executar

### Pré-requisitos

- Compilador C, como o GCC
- Terminal ou ambiente de desenvolvimento compatível

### Compilação

No terminal, acesse a pasta do projeto e execute:

```bash
gcc SistemaDeGestaoDeBiblioteca.c -o biblioteca
```

### Execução

No Linux ou macOS:

```bash
./biblioteca
```

No Windows:

```bash
biblioteca.exe
```

O programa utiliza o arquivo `biblioteca.txt` para armazenar os dados. Caso o arquivo não exista, a biblioteca começa vazia e o arquivo é criado ao salvar os dados ao sair do programa.

## 📌 Observações

- O sistema permite cadastrar até 100 livros.
- Para a entrada de títulos e nomes de autores, a versão atual aceita palavras sem espaços.
- O projeto tem finalidade acadêmica e foi desenvolvido para praticar conceitos fundamentais de programação em C.

## 👨‍💻 Autor

**Dosité Moleiro**

Estudante de Análise e Desenvolvimento de Sistemas.

🔗 [GitHub](https://github.com/dosite-moleiro)

## 📂 Repositório

[github.com/dosite-moleiro/gestao_biblioteca](https://github.com/dosite-moleiro/gestao_biblioteca)
