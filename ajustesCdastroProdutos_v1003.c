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
    char desc [100]; //Descri��o com 100 caracteres.
    int quant_estoque;
    float preco_prod;

}Produto; //Tipo de dados 'Produto' criado.

//Fun��o para troca de cor das sa�das.
void textColor(int color_name){

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_name);

}

//Fun��o para calcular o VALOR TOTAL em estoque.
float valorTotal_estoque(float total_prec, float quant_est){

    float v_tot_estoq; //Valor total estoque
    v_tot_estoq = total_prec * quant_est;

    return v_tot_estoq;

}

//Fun��o para mostrar os produtos cadastrados.
void imprimirProdutos(Produto p){

        textColor(2);
        printf("  C�digo   :   %d\n",   p.codigo);
        printf("  Nome     :   %s\n",   p.nome);
        printf("  Descri��o:   %s\n",   p.desc);
        printf("  Estoque  :   %d\n",   p.quant_estoque);
        printf("  Pre�o Un.:   %.2f\n", p.preco_prod);

}

//Fun��o principal.
int main(){
setlocale(LC_ALL,"Portuguese_Brazil"); //Define o idioma do c�digo.

SetConsoleTitle(" Sistema de Cadastro para Produtos"); //Define nome da janela do programa

    float estoque [quant_prod]; //Vari�vel recebe o resultado da fun��o valorTotal_estoque
    int prod_cadastrados = 0; //Vari�vel controla a 'linha' em que os produtos ficam cadastrados

    Produto produtos[quant_prod]; //Cria��o de uma vari�vel do tipo Produto chamada ' produtos '

        textColor(3);
        printf("  -----------------------------\n");
        printf("       CADASTRO DE PRODUTOS    \n");
        printf("  -----------------------------\n");

        printf("     (M�ximo de 100 produtos)\n");
        printf("  -----------------------------\n");
    //Repeti��o dos dados que ser�o cadastrados a cada produto novo.
    for (int i = 0; i < quant_prod; i++){
        
        //Vari�vel controla quantidade de produtos cadastrados

        textColor(7);
        printf("  Digite o c�digo do produto: ");
        scanf("%d", &produtos[i].codigo); //Usu�rio insere c�digo do produto.
        getchar();

            while (produtos[i].codigo < 0){ //Enquanto o c�digo for menor que 0, o usu�rio deve colocar outro n�mero.
                textColor(4);
                printf("  C�digo inv�lido, tente novamente com um n�mero positivo...\n\n");

                textColor(7);
                printf("  Digite o c�digo do produto: ");
                scanf("%d", &produtos[i].codigo);
                getchar();
            }

        printf("  Digite o nome do produto: ");
        gets(produtos[i].nome); //Usu�rio insere nome do produto.

        printf("  Digite uma descri��o para o produto: ");
        gets(produtos[i].desc); //Usu�rio insere descri��o do produto.

        printf("  Digite a quantidade em estoque do produto: ");
        scanf("%d", &produtos[i].quant_estoque); //Usu�rio insere a quantidade de estoque do produto.

            while (produtos[i].quant_estoque < 0){ //Enquanto a quantidade de estoque for menor que 0, o usu�rio deve colocar outro n�mero.
                textColor(4);
                printf("  Quantidade de estoque inv�lida, tente novamente com uma quantidade positiva...\n\n");

                textColor(7);
                printf("  Digite a quantidade em estoque do produto: ");
                scanf("%d", &produtos[i].quant_estoque);
                getchar();
            }

        printf("  Digite o pre�o do produto: ");
        scanf("%f", &produtos[i].preco_prod); //Usu�rio insere o pre�o do produto.

            while (produtos[i].preco_prod < 0){ //Enquanto o pre�o for menor que 0, o usu�rio deve colocar outro pre�o.
                textColor(4);
                printf("  Pre�o inv�lido, tente novamente com um pre�o positivo...\n\n");

                textColor(7);
                printf("  Digite o pre�o do produto: ");
                scanf("%f", &produtos[i].preco_prod);
                getchar();
            }

        estoque[i] = valorTotal_estoque(produtos[i].preco_prod, produtos[i].quant_estoque); //Chamada da fun��o VALORTOTAL_ESTOQUE
                                                                  /*pega os valores que foram armazenados nas vari�veis PRECO_PROD (da struct PRODUTO)
                                                                  e QUANT_ESTOQUE (da struct PRODUTO) e as joga na fun��o valorTotal_estoque
                                                                  nas vari�veis TOTAL_PREC e QUANT_EST, em ordem.*/

        printf("  Cadastrando..."); //Apenas visual, n�o interfere nas contas e fun��es do sistema.
        sleep(1);

        textColor(2);
        printf("  Cadastro Conclu�do!\n");
        
        prod_cadastrados++; //Vari�vel avan�a para o proximo produto a ser cadastrado

        int decisao; //Vari�vel para decis�o do usu�rio (continuar ou parar)
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

                            for (int i = 0; i < prod_cadastrados; i++){ //Repete a fun��o imprimirProdutos de acordo com a quantidade de produtos cadastrados.
                                
                                imprimirProdutos(produtos[i]);
                                textColor(6);
                                printf("  Valor total estoque: %.2f\n", estoque[i]); //Mostra o valor total de estoque (conta feita na fun��o valotTotal_estoque).
                                textColor(3);
                                printf("  -----------------------------\n");
                                printf("\n");
                            }
                            break;
                        }//else if
                            else {
                                while (decisao != 1 && decisao != 2){
                                    printf("\n O n�mero que voc� digitou n�o coincide com as op��es dadas, tente novamente: ");
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

                                                for (int i = 0; i < prod_cadastrados; i++){ //Repete a fun��o imprimirProdutos de acordo com a quantidade de produtos cadastrados.
                                                    
                                                    imprimirProdutos(produtos[i]);
                                                    textColor(6);
                                                    printf("  Valor total estoque: %.2f\n", estoque[i]); //Mostra o valor total de estoque (conta feita na fun��o valotTotal_estoque).
                                                    
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