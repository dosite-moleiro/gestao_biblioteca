#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 100 // Quantidade máxima de livros no sistema
#define MAX_NOME 50 // Tamanho máximo do nome do autor ou título

struct Livro {
    int codigo;
    char titulo[MAX_NOME];
    char autor[MAX_NOME];
    int ano_publicacao;
    int disponivel; // 1 = disponível, 0 = emprestado
};

struct Livro biblioteca[MAX_LIVROS]; // Array que guarda até 100 livros
int total_livros = 0; // Quantos livros foram cadastrados

void carregar_biblioteca(void);
void salvar_biblioteca(void);
void adicionar_livro(void);
void listar_livros(void);
int buscar_livro(int codigo);
void emprestar_livro(void);
void devolver_livro(void);
void menu_principal(void);

int main() {
    carregar_biblioteca(); // Lê os dados do arquivo, se existirem
    menu_principal(); // Mostra o menu interativo ao usuário
    salvar_biblioteca(); // Salva alterações feitas no programa
    return 0;
}

void carregar_biblioteca(void) {
    FILE *arquivo = fopen("biblioteca.txt", "r");
    
    if (arquivo == NULL) {
        printf("Arquivo de biblioteca não encontrado. Iniciando biblioteca vazia.\n");
        return;
    }
    
        while (total_livros < MAX_LIVROS &&
            fscanf(arquivo, "%d %49s %49s %d %d",
                  &biblioteca[total_livros].codigo,
                  biblioteca[total_livros].titulo,
                  biblioteca[total_livros].autor,
                  &biblioteca[total_livros].ano_publicacao,
                &biblioteca[total_livros].disponivel) == 5) {
        total_livros++;
    }
    
    fclose(arquivo);
    printf("Biblioteca carregada com %d livro(s).\n", total_livros);
}

void salvar_biblioteca(void) {
    FILE *arquivo = fopen("biblioteca.txt", "w");
    int i;

    if (arquivo == NULL) {
        printf("Erro ao salvar a biblioteca.\n");
        return;
    }
    for (i = 0; i < total_livros; i++) {
        fprintf(arquivo, "%d %s %s %d %d\n", biblioteca[i].codigo,
                biblioteca[i].titulo, biblioteca[i].autor,
                biblioteca[i].ano_publicacao, biblioteca[i].disponivel);
    }
    fclose(arquivo);
}

void adicionar_livro(void) {
    struct Livro livro;

    if (total_livros >= MAX_LIVROS) {
        printf("Limite de livros atingido.\n");
        return;
    }
    printf("Código: ");
    if (scanf("%d", &livro.codigo) != 1) return;
    if (buscar_livro(livro.codigo) != -1) {
        printf("Já existe um livro com esse código.\n");
        return;
    }
    printf("Título (sem espaços): ");
    if (scanf("%49s", livro.titulo) != 1) return;
    printf("Autor (sem espaços): ");
    if (scanf("%49s", livro.autor) != 1) return;
    printf("Ano de publicação: ");
    if (scanf("%d", &livro.ano_publicacao) != 1) return;
    livro.disponivel = 1;
    biblioteca[total_livros++] = livro;
    printf("Livro cadastrado.\n");
}

void listar_livros(void) {
    int i;

    if (total_livros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }
    for (i = 0; i < total_livros; i++) {
        printf("Código: %d | Título: %s | Autor: %s | Ano: %d | %s\n",
               biblioteca[i].codigo, biblioteca[i].titulo,
               biblioteca[i].autor, biblioteca[i].ano_publicacao,
               biblioteca[i].disponivel ? "Disponível" : "Emprestado");
    }
}

int buscar_livro(int codigo) {
    int i;

    for (i = 0; i < total_livros; i++) {
        if (biblioteca[i].codigo == codigo) return i;
    }
    return -1;
}

void emprestar_livro(void) {
    int codigo, indice;

    printf("Código do livro: ");
    if (scanf("%d", &codigo) != 1) return;
    indice = buscar_livro(codigo);
    if (indice == -1) printf("Livro não encontrado.\n");
    else if (!biblioteca[indice].disponivel) printf("O livro já está emprestado.\n");
    else {
        biblioteca[indice].disponivel = 0;
        printf("Empréstimo registrado.\n");
    }
}

void devolver_livro(void) {
    int codigo, indice;

    printf("Código do livro: ");
    if (scanf("%d", &codigo) != 1) return;
    indice = buscar_livro(codigo);
    if (indice == -1) printf("Livro não encontrado.\n");
    else if (biblioteca[indice].disponivel) printf("O livro já está disponível.\n");
    else {
        biblioteca[indice].disponivel = 1;
        printf("Devolução registrada.\n");
    }
}

void menu_principal(void) {
    int opcao;

    do {
        printf("\n1. Adicionar livro\n2. Listar livros\n3. Emprestar livro\n"
               "4. Devolver livro\n0. Sair\nOpção: ");
        if (scanf("%d", &opcao) != 1) return;
        switch (opcao) {
            case 1: adicionar_livro(); break;
            case 2: listar_livros(); break;
            case 3: emprestar_livro(); break;
            case 4: devolver_livro(); break;
            case 0: break;
            default: printf("Opção inválida.\n");
        }
    } while (opcao != 0);
}