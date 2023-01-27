#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <windows.h>


#define quant_prod 100 //Define a quantidade de produtos a serem cadastrados.


//Estrutura com todos os dados de cadastro dos PRODUTOS.
typedef struct{
    int codigo;
    char nome [30]; //Nome com 30 caracteres.
    char desc [100]; //Descrição com 100 caracteres.
    int quant_estoque;
    float preco_prod;

}Produto; //Tipo de dados 'Produto' criado.

//Função para troca de cor das saídas.
void textColor(int color_name){

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_name);

}

//Função para calcular o VALOR TOTAL em estoque.
float valorTotal_estoque(float total_prec, float quant_est){

    float v_tot_estoq; //Valor total estoque
    v_tot_estoq = total_prec * quant_est;

    return v_tot_estoq;

}

//Função para mostrar os produtos cadastrados.
void imprimirProdutos(Produto p){

        textColor(2);
        printf("  Código   :   %d\n",   p.codigo);
        printf("  Nome     :   %s\n",   p.nome);
        printf("  Descrição:   %s\n",   p.desc);
        printf("  Estoque  :   %d\n",   p.quant_estoque);
        printf("  Preço Un.:   %.2f\n", p.preco_prod);

}

//Função principal.
int main(){
setlocale(LC_ALL,"Portuguese_Brazil"); //Define o idioma do código.

SetConsoleTitle(" Sistema de Cadastro para Produtos"); //Define nome da janela do programa

    float estoque [quant_prod]; //Variável recebe o resultado da função valorTotal_estoque
    int prod_cadastrados = 0; //Variável controla a 'linha' em que os produtos ficam cadastrados

    Produto produtos[quant_prod]; //Criação de uma variável do tipo Produto chamada ' produtos '

        textColor(3);
        printf("  -----------------------------\n");
        printf("       CADASTRO DE PRODUTOS    \n");
        printf("  -----------------------------\n");

        printf("     (Máximo de 100 produtos)\n");
        printf("  -----------------------------\n");
    //Repetição dos dados que serão cadastrados a cada produto novo.
    for (int i = 0; i < quant_prod; i++){
        
        //Variável controla quantidade de produtos cadastrados

        textColor(7);
        printf("  Digite o código do produto: ");
        scanf("%d", &produtos[i].codigo); //Usuário insere código do produto.
        getchar();

            while (produtos[i].codigo < 0){ //Enquanto o código for menor que 0, o usuário deve colocar outro número.
                textColor(4);
                printf("  Código inválido, tente novamente com um número positivo...\n\n");

                textColor(7);
                printf("  Digite o código do produto: ");
                scanf("%d", &produtos[i].codigo);
                getchar();
            }

        printf("  Digite o nome do produto: ");
        gets(produtos[i].nome); //Usuário insere nome do produto.

        printf("  Digite uma descrição para o produto: ");
        gets(produtos[i].desc); //Usuário insere descrição do produto.

        printf("  Digite a quantidade em estoque do produto: ");
        scanf("%d", &produtos[i].quant_estoque); //Usuário insere a quantidade de estoque do produto.

            while (produtos[i].quant_estoque < 0){ //Enquanto a quantidade de estoque for menor que 0, o usuário deve colocar outro número.
                textColor(4);
                printf("  Quantidade de estoque inválida, tente novamente com uma quantidade positiva...\n\n");

                textColor(7);
                printf("  Digite a quantidade em estoque do produto: ");
                scanf("%d", &produtos[i].quant_estoque);
                getchar();
            }

        printf("  Digite o preço do produto: ");
        scanf("%f", &produtos[i].preco_prod); //Usuário insere o preço do produto.

            while (produtos[i].preco_prod < 0){ //Enquanto o preço for menor que 0, o usuário deve colocar outro preço.
                textColor(4);
                printf("  Preço inválido, tente novamente com um preço positivo...\n\n");

                textColor(7);
                printf("  Digite o preço do produto: ");
                scanf("%f", &produtos[i].preco_prod);
                getchar();
            }

        estoque[i] = valorTotal_estoque(produtos[i].preco_prod, produtos[i].quant_estoque); //Chamada da função VALORTOTAL_ESTOQUE
                                                                  /*pega os valores que foram armazenados nas variáveis PRECO_PROD (da struct PRODUTO)
                                                                  e QUANT_ESTOQUE (da struct PRODUTO) e as joga na função valorTotal_estoque
                                                                  nas variáveis TOTAL_PREC e QUANT_EST, em ordem.*/

        printf("  Cadastrando..."); //Apenas visual, não interfere nas contas e funções do sistema.
        sleep(1);

        textColor(2);
        printf("  Cadastro Concluído!\n");
        
        prod_cadastrados++; //Variável avança para o proximo produto a ser cadastrado

        int decisao; //Variável para decisão do usuário (continuar ou parar)
        textColor(7);
        printf("\n  Tecle '1' caso deseje continuar com o cadastro de produtos.");
        printf("\n  Tecle '2' caso deseje mostrar a lista de produtos cadastrados.\n");
        scanf("%d", &decisao);
        system("cls");

                    if (decisao == 1){//if
                        
                        textColor(2);
                        printf("\n  Cadastro de um novo produto iniciado...\n");
                        printf("\n\n");
                    }//fim if
                        else if (decisao == 2){
                                textColor(3);
                                printf("  -----------------------------\n");
                                printf("       PRODUTOS CADASTRADOS    \n");
                                printf("  -----------------------------\n");

                            for (int i = 0; i < prod_cadastrados; i++){ //Repete a função imprimirProdutos de acordo com a quantidade de produtos cadastrados.
                                
                                imprimirProdutos(produtos[i]);
                                textColor(6);
                                printf("  Valor total estoque: %.2f\n", estoque[i]); //Mostra o valor total de estoque (conta feita na função valotTotal_estoque).
                                textColor(3);
                                printf("  -----------------------------\n");
                                printf("\n");
                            }
                            break;
                        }//else if
                            else {
                                while (decisao != 1 && decisao != 2){
                                    printf("\n O número que você digitou não coincide com as opções dadas, tente novamente: ");
                                    scanf("%d", &decisao);
                                    system("cls");
                                    }//while
                                        if (decisao == 1){
                                            textColor(8);
                                            printf("\nCadastro de um novo produto iniciado...\n");
                                        }//if
                                            else if (decisao == 2){

                                                textColor(3);
                                                printf("  -----------------------------\n");
                                                printf("       PRODUTOS CADASTRADOS    \n");
                                                printf("  -----------------------------\n");

                                                for (int i = 0; i < prod_cadastrados; i++){ //Repete a função imprimirProdutos de acordo com a quantidade de produtos cadastrados.
                                                    
                                                    imprimirProdutos(produtos[i]);
                                                    textColor(6);
                                                    printf("  Valor total estoque: %.2f\n", estoque[i]); //Mostra o valor total de estoque (conta feita na função valotTotal_estoque).
                                                    
                                                    textColor(3);
                                                    printf("  -----------------------------\n");
                                                    printf("\n\n");
                                                    
                                                }//for
                                                break;
                                            }//else if
                                
                            }//else
    }//for

    getch();

    return 0;
}