//Bibliotecas padrão
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

//Bibliotecas alternativas
#include "SahdoLib.h"
#include "Partidas.h"

//Ordem da matriz do tabuleiro de Sudoku
#define ORDEM 9

//Defines usados em funções com lógica booleana
#define VERDADEIRO 1
#define FALSO 0

//Defines utilizados para facilitar o entendimento do atributo "sinal" pertencente ao struct Matriz
#define LIVRE 2
#define USUARIO 1
#define AUTOMATICO 0

//Defines que auxiliam na seleção do tipo de jogo a ser executado
#define FACIL 0
#define MEDIO 1
#define DIFICIL 2
#define RESOLVIDO 3

//------------------------------------------------------------------------------
typedef struct Matriz
{
	int num; //valor de cada célula da matriz
	int lin,col; //linha e coluna da matriz
	int sinal; //AUTOMATICO - valores inseridos pelo programa | USUARIO - valores inseridos pelo usuario | LIVRE - valores livres
	struct Matriz* prox;

} matriz;


//Protótipos----------
void ImprimeMatriz(matriz *mat);
void ImprimeHistorico(matriz *l);
void Menu();
void IniciarJogo();
void Instrucoes();
void Nivel();
void IniciaBackUp(matriz* mat);
void ResolveSudokuEfazBackUp(matriz* mat, int lin, int col);
void FazBackUp(matriz* mat);
void InsereValor(matriz* mat, int num, int lin, int col);
void InsereValorUsuario(matriz* mat);
int getNumById(matriz* mat, int lin, int col);
int getSinalById (matriz* mat, int lin, int col);
int verificaSintaxe(int num);
int VerificaJogada(matriz* mat, int num, int lin, int col);
int VerificaSePerdeu();
int VerificaSeVenceu();
int ValorAleatorio();
matriz* Inicializa();
matriz* SalvaJogada(matriz* mat, int num, int lin, int col);

//Variáveis globais
int CoordX;
int CoordY;
int varNivel;
matriz* MatSudoku;
matriz* MatSudokuResolvidoBackUp;
matriz* HistoricoJogadas;

//------------------------------------------------------------------------------
int main()
{
   setTextMode(BOLD);
   setColor(GREEN,BLACK);
   clrscr();

   Menu();

   return 0;
}

//------------------------------------------------------------------------------
matriz* Inicializa()
{
   matriz* nova = (matriz*) malloc(sizeof(matriz));
   matriz* atual = nova;
   int lin,col,cont;
   int varPosicaoLinha;//Variavel que recebe a linha onde comeca atabea escolhida para o jogo
   int varAleatorio;//Variavel que recebe valor aleatório

   //varAleatorio seu valor
   varAleatorio = ValorAleatorio();

   //varPOsicaoLinharecebe seu valor
   varPosicaoLinha = (ORDEM*varAleatorio);

   //Inicializa variáveis globais
   CoordX = 30;
   CoordY = 3;
   HistoricoJogadas = NULL;

   //Seleciona o nível
   Nivel();

   //Laço for que percorre a lista e a matriz simultaneamente
   for(lin = 0; lin < ORDEM; lin++)
   {
        for(col = 0; col < ORDEM; col++)
        {
            //lista recebe seus valores------------------------
                //se o nivel for facil
                if(varNivel == FACIL)
                {
                    atual->num = SudokuFacil[lin+varPosicaoLinha][col];

                    //sinal recebe livre ser num for 0 e automatico caso diferente
                    if(SudokuFacil[lin+varPosicaoLinha][col] == 0)
                        atual->sinal = LIVRE;
                    else
                        atual->sinal = AUTOMATICO;
                }
                //se o nivel for medio
                if(varNivel == MEDIO)
                {
                    atual->num = SudokuMedio[lin+varPosicaoLinha][col];

                    //sinal recebe livre ser num for 0 e automatico caso diferente
                    if(SudokuMedio[lin+varPosicaoLinha][col] == 0)
                        atual->sinal = LIVRE;
                    else
                        atual->sinal = AUTOMATICO;
                }
                //se o nivel for dificil
                if(varNivel == DIFICIL)
                {
                    atual->num = SudokuDificil[lin+varPosicaoLinha][col];

                    //sinal recebe livre ser num for 0 e automatico caso diferente
                    if(SudokuDificil[lin+varPosicaoLinha][col] == 0)
                        atual->sinal = LIVRE;
                    else
                        atual->sinal = AUTOMATICO;
                }

                atual->lin = lin;
                atual->col = col;
            //fim recebimento-----------------------------

            //condicao para nao alocar memoria depois da posicao matriz[9][9]
            if((lin != ORDEM-1) || (col != ORDEM-1))
            {
                atual->prox = (matriz*) malloc(sizeof(matriz));
                atual = atual->prox;
            }
        }
   }

   atual->prox = NULL;

   return nova;
}

//------------------------------------------------------------------------------
void IniciaBackUp(matriz* mat)
{
    matriz* matResolvida = (matriz*) malloc(sizeof(matriz));
    matriz* atual1 = matResolvida;
    matriz* atual2 = mat;

    setColor(WHITE,BLACK);
    gotoxy(38,8);
    printf("Iniciando...\n");

    //copia MatSudoku para matResolvida
    while(atual2 != NULL)
    {
        atual1->num = atual2->num;
        atual1->lin = atual2->lin;
        atual1->col = atual2->col;
        atual1->sinal = atual2->sinal;

        if(atual2->prox == NULL)
            atual1->prox = NULL;
        else
            atual1->prox = (matriz*) malloc(sizeof(matriz));

        atual1 = atual1->prox;
        atual2 = atual2->prox;
    }

    ResolveSudokuEfazBackUp(matResolvida,0,0);
}

//------------------------------------------------------------------------------
void FazBackUp(matriz* mat)
{
    matriz* atual1;
    matriz* atual2 = mat;

    MatSudokuResolvidoBackUp = (matriz*) malloc(sizeof(matriz));
    atual1 = MatSudokuResolvidoBackUp;

    //copia Mat para MatSudokuResolvidoBackUp
    while(atual2 != NULL)
    {
        atual1->num = atual2->num;
        atual1->lin = atual2->lin;
        atual1->col = atual2->col;
        atual1->sinal = atual2->sinal;


        if(atual2->prox == NULL)
            atual1->prox = NULL;
        else
            atual1->prox = (matriz*) malloc(sizeof(matriz));

        atual1 = atual1->prox;
        atual2 = atual2->prox;
    }
}

//------------------------------------------------------------------------------
int getNumById (matriz* mat, int lin, int col)
{
    matriz* atual;

    //Laço que faz a busca na lista passada por parâmetro
    for (atual=mat; atual != NULL; atual=atual->prox)
    {

       if (atual->lin == lin && atual->col == col)
          return atual->num;
    }
}

//------------------------------------------------------------------------------
int getSinalById (matriz* mat, int lin, int col)
{
    matriz* atual;

    //Laço que faz a busca na lista passada por parâmetro
    for (atual=mat; atual != NULL; atual=atual->prox)
    {
       if (atual->lin == lin && atual->col == col)
          return atual->sinal;
    }
}

//------------------------------------------------------------------------------
void InsereValor(matriz* mat, int num, int lin, int col)
{
    matriz* atual;

    //Laço que faz a busca na lista passada por parâmetro
    for (atual=mat; atual != NULL; atual=atual->prox)
    {
       if (atual->lin == lin && atual->col == col)
       {
           atual->num = num;
           atual->sinal = USUARIO;
           return;
       }
    }
}

//------------------------------------------------------------------------------
void InsereValorUsuario(matriz* mat)
{
   int lin,col,num;
   matriz* atual = mat;

   //Usuario digita informações e a rotina checa se está no formato correto
   do
   {
	   ImprimeMatriz(mat);
	   setColor(YELLOW,BLACK);
	   printf("\n\nDigite o numero: ");
	   scanf("%d",&num);
   } while(verificaSintaxe(num) == FALSO);

   do
   {
	   ImprimeMatriz(mat);
	   setColor(YELLOW,BLACK);
	   printf("\n\nDigite a linha: ");
	   scanf("%d",&lin);
   } while(verificaSintaxe(lin) == FALSO);

   do
   {
	   ImprimeMatriz(mat);
	   setColor(YELLOW,BLACK);
	   printf("\n\nDigite a coluna: ");
	   scanf("%d",&col);
   } while(verificaSintaxe(col) == FALSO);


   //Matriz recebe valor inserido pelo usuário se for válido
   if(VerificaJogada(mat, num,lin-1,col-1) == VERDADEIRO && getSinalById(mat,lin-1,col-1) == LIVRE)
   {
       InsereValor(mat,num,lin-1,col-1);
       HistoricoJogadas = SalvaJogada(HistoricoJogadas,num,lin,col);
   }

   else
   {
       setColor(RED,BLACK);
       printf("\n\nJogada Inválida!!");
       __fpurge(stdin);
       getchar();
   }
}

//------------------------------------------------------------------------------
matriz* SalvaJogada(matriz* mat, int num, int lin, int col)
{
    matriz* novo = (matriz*) malloc(sizeof(matriz));
    matriz* atual = mat;

    novo->num = num;
    novo->lin = lin;
    novo->col = col;
    novo->prox = NULL;


    if(mat == NULL) mat = novo;

    else
    {
        while(atual->prox != NULL) atual = atual->prox;
        atual->prox = novo;
    }

    return mat;
}

//------------------------------------------------------------------------------
int VerificaJogada(matriz* mat, int num, int lin, int col)
{
    int l, c, lr, cr;

    //Verifica se o numero é o mesmo que eu digitei na mesma linha e coluna
    if (getNumById(mat,lin,col) == num) return VERDADEIRO;
    //Verifica se o numero na matriz é diferente de zero, ou seja, se ja tem um valor pre-inserido
    if (getNumById(mat,lin,col) != 0) return FALSO;

    //verifica se tem numero iguai na mesma coluna
    for (c = 0; c < ORDEM; c++){
        if (getNumById(mat,lin,c) == num) return FALSO;}

    //verifica se tem numero iguai na mesma linha
    for (l = 0; l < ORDEM; l++){
        if (getNumById(mat,l,col) == num) return FALSO;}

    lr = lin / 3;
    cr = col / 3;

    //verifica se tem numero iguai na mesma regiao (quadrante)
    for (l = lr * 3; l < (lr + 1) * 3; l++)
        for (c = cr * 3; c < (cr + 1) * 3; c++)
            if (getNumById(mat,l,c) == num) return FALSO;

    return VERDADEIRO;
}

//------------------------------------------------------------------------------
int VerificaSePerdeu()
{
    matriz* atual1 = MatSudoku;
    matriz* atual2 = MatSudokuResolvidoBackUp;
    int varVerifica = FALSO;

    //compara MatSudoku com MatSudokuResolvidoBackUp
    while(atual1 != NULL)
    {
        //verifica se valor é diferente
        if(atual1->sinal == USUARIO)
            if(atual1->num != atual2->num)
                varVerifica = VERDADEIRO;

        atual1 = atual1->prox;
        atual2 = atual2->prox;
    }

    return varVerifica;
}

//------------------------------------------------------------------------------
int VerificaSeVenceu()
{
    matriz* atual;

    //Laço que faz a busca na lista passada por parâmetro
    for (atual=MatSudoku; atual != NULL; atual=atual->prox)
    {
        if (atual->sinal == LIVRE) return FALSO;
    }

    return VERDADEIRO;
}

//------------------------------------------------------------------------------
void ResolveSudokuEfazBackUp(matriz* mat, int lin, int col)
{
    int n,aux;

    if (lin == ORDEM)
    {
        FazBackUp(mat);
    }

    else
    for (n = 1; n <= ORDEM; n++)
    {
        if (VerificaJogada(mat,n,lin,col) == VERDADEIRO)
        {
            aux = getNumById(mat,lin,col);
            InsereValor(mat,n,lin,col);

            if (col == ORDEM-1)
                ResolveSudokuEfazBackUp(mat,lin + 1, 0);
            else
                ResolveSudokuEfazBackUp(mat,lin, col + 1);

            InsereValor(mat,aux,lin,col);
        }
    }
}

//------------------------------------------------------------------------------
int verificaSintaxe(int num)
{
    int varVerifica;

    switch(num)
	{
           case 1: varVerifica = VERDADEIRO; break;
	   case 2: varVerifica = VERDADEIRO; break;
	   case 3: varVerifica = VERDADEIRO; break;
	   case 4: varVerifica = VERDADEIRO; break;
	   case 5: varVerifica = VERDADEIRO; break;
	   case 6: varVerifica = VERDADEIRO; break;
	   case 7: varVerifica = VERDADEIRO; break;
	   case 8: varVerifica = VERDADEIRO; break;
	   case 9: varVerifica = VERDADEIRO; break;
	   default:
               varVerifica = FALSO;
               setColor(RED,BLACK);
               printf("\n\nErro de sintaxe\n\n");
               __fpurge(stdin);
               getchar();
               break;
	}

	return varVerifica;
}

//------------------------------------------------------------------------------
void ImprimeMatriz(matriz *mat)
{
   int i;
   int x,y;

   //coordenada da tela don shell
   x = CoordX;
   y = CoordY;

   //limpa a tela
   clrscr();

   //--------------------------------------------
   if(mat == NULL) printf("Lista Vazia");
   //--------------------------------------------

   //Imprime título e modo-----------------
   gotoxy(x,y-2);
   switch(varNivel)
   {
        case FACIL: setColor(GREEN,BLACK);     printf("          SUDOKU FACIL"); break;
        case MEDIO: setColor(YELLOW,BLACK);    printf("          SUDOKU MEDIO"); break;
        case DIFICIL: setColor(RED,BLACK);     printf("         SUDOKU DIFICIL"); break;
        case RESOLVIDO: setColor(WHITE,BLACK); printf("        SUDOKU RESOLVIDO"); break;

   }
   //----------------------------------------

   //vai para a posição xy da tela para imprimir a tabela
   gotoxy(x,y);

   //i é a variável contadora para a impressa dos indices de 1 a 9 na lateral direita da tabela
   i = 1;

   //ImprimeHistorico os dados da tabela-------------------------------
   while(mat != NULL)
   {

      //Seleciona a cor da célula e ImprimeHistorico valor da célula
      if((mat->col+mat->lin)%2 == 0)
      {
            switch(mat->sinal)
            {
                 case AUTOMATICO:
                    setColor(BLACK,GREEN);
                    printf(" %d ",mat->num);
                    break;
                 case USUARIO:
                    setColor(RED,GREEN);
                    printf(" %d ",mat->num);
                    break;
                 case LIVRE:
                    setColor(GREEN,GREEN);
                    printf("   ");
                    break;
            }
      }

      else
      {
            switch(mat->sinal)
            {
                 case AUTOMATICO:
                    setColor(BLACK,WHITE);
                    printf(" %d ",mat->num);
                    break;
                 case USUARIO:
                    setColor(RED,WHITE);
                    printf(" %d ",mat->num);
                    break;
                 case LIVRE:
                    setColor(WHITE,WHITE);
                    printf("   ");
                    break;
            }
      }
      //Fim seleciona a cor


      //Espaço entre uma região e outra------------------------------------
      if((mat->col + 1) % 3 == 0)
      {
        setColor(BLACK,BLACK);
        printf("  ");
      }

      //Pula uma linha ao final de cada linha e duas entre as regioes de cima e as de baixo. Esse trecho também ImprimeHistorico o indice lateral esquerdo de 1 a 9. Além disso esta rotina faz com que a tabela volte a posicao exata para impressao atraves da funcao gotoxy
      if(mat->col == ORDEM-1)
      {
            if((mat->lin + 1) % 3 == 0)
            {
                //ImprimeHistorico indice lateral esquerdo de 1 a 9
                setColor(WHITE,BLACK);
                printf("%d",i++);

                //pula duas linhas
                y = y+2;
                gotoxy(x,y);
            }

            else
            {
                //ImprimeHistorico indice lateral esquerdo de 1 a 9
                setColor(WHITE,BLACK);
                printf("%d",i++);

                //pula apenas uma linha
                y = y+1;
                gotoxy(x,y);
            }
      }

      //Percorre a lista da matriz
      mat = mat->prox;
   }
   //---------------------------------

   //ImprimeHistorico índices de 1 a 9 em baixo da tabela
   setColor(WHITE,BLACK);
   gotoxy(x,y);
   for(i=1; i<=ORDEM; i++)
   {
      if(i%3 == 0)
	printf(" %d   ",i);
      else
	printf(" %d ",i);
   }

   //retorna a cor normal do programa
   setColor(GREEN,BLACK);
}

//Função Menu-------------------------------------------------------------------
void Menu()
{
   char op;

   //apaga tudo
   clrscr();

   //ImprimeHistorico título do jogo
   setColor(GREEN,BLACK);
   nicePrint("SUDOKU",24,4);

   //limpa o buffer
   __fpurge(stdin);

   setColor(WHITE,BLACK);//branco

   gotoxy(29,10);
   printf("************************");
   gotoxy(29,11);
   printf("*                      *");
   gotoxy(29,12);
   printf("*                      *");
   gotoxy(29,13);
   printf("*                      *");
   gotoxy(29,14);
   printf("*                      *");
   gotoxy(29,15);
   printf("*                      *");
   gotoxy(29,16);
   printf("*                      *");
   gotoxy(29,17);
   printf("*                      *");
   gotoxy(29,18);
   printf("*                      *");
   gotoxy(29,19);
   printf("*                      *");
   gotoxy(29,20);
   printf("************************");

   setColor(RED,BLACK);//vermelho
   gotoxy(22,24);
   printf("  By Lucas Rocha Sahdo & Antonio Cesar");

   setColor(YELLOW,BLACK);//amarelo

   gotoxy(39,11);
   printf("Menu");
   gotoxy(36,13);
   printf("1. Iniciar");
   gotoxy(36,14);
   printf("2. Instrucoes");
   gotoxy(36,15);
   printf("3. Sair");
   gotoxy(36,17);

   setColor(WHITE,BLACK);//branco
   printf("opcao: ");
   __fpurge(stdin);
   op = getchar();

   setColor(WHITE,BLACK);

   switch(op)
   {
         case '1': clrscr(); IniciarJogo(); break;

         case '2': Instrucoes(); break;

         case '3':
             clrscr();
             gotoxy(36,12);
             printf("FIM DO PROGRAMA!!!");
	     __fpurge(stdin);
	     getchar();
	     setTextMode(NORMAL);
	     clrscr();
             exit(1);break;

         default:
             gotoxy(34,19);
             printf("opcao invalida!");
	     __fpurge(stdin);
	     getchar();
             Menu();
   }
}

//--------------------------------------------------------
void IniciarJogo()
{
	//Inicializa a lista principal com uma tabela de sudoku de acordo com o nível escolhido
	MatSudoku = Inicializa();

    //Resolve o sudoku atual e faz backup
	IniciaBackUp(MatSudoku);

	//Laço infinito
	while(1)
	{

        //Usuario insere valor
		InsereValorUsuario(MatSudoku);

        //Imprime Matriz principal
	    ImprimeMatriz(MatSudoku);

		//Verifica se perdeu
		if(VerificaSePerdeu(MatSudoku))
		{
		    setColor(RED,BLACK);

		    printf("\n\nFim de jogo...");
		    __fpurge(stdin);
		    getchar();

		    clrscr();

		    gotoxy(30,10);
		    printf("Voce perdeu!! :(");
		    __fpurge(stdin);
		    getchar();

		    varNivel = RESOLVIDO;
		    ImprimeMatriz(MatSudokuResolvidoBackUp);
		    __fpurge(stdin);
		    getchar();

		    ImprimeHistorico(HistoricoJogadas);
		    Menu();
		}

		//Verifica se ganhou
		if(VerificaSeVenceu(MatSudoku))
		{
		    setColor(YELLOW,BLACK);
		    printf("\n\nVoce Venceu!!!");
		    __fpurge(stdin);
		    getchar();

		    clrscr();

		    gotoxy(30,10);
		    printf("Parabens!!!! =D");
		    __fpurge(stdin);
		    getchar();

		    ImprimeHistorico(HistoricoJogadas);
		    Menu();
		}

	}
}

//-------------------------------------------------------
void Instrucoes()
{
   clrscr();

   setColor(GREEN,BLACK);//branco

   gotoxy(35,1);
   printf("Instrucoes");
   gotoxy(35,2);
   printf("__________");

   setColor(GREEN,BLACK);//verde


   setColor(YELLOW,BLACK);//amarelo
   gotoxy(12,8);
   printf("Apos iniciar o jogo:");

   setColor(GREEN,BLACK);//verde
   gotoxy(12,10);
   printf("- Escolha o nivel de dificuldade");

   setColor(GREEN,BLACK);//verde
   gotoxy(12,11);
   printf("- Digite um numero de 1 a 9 para inserir na tabela de sudoku");

   setColor(GREEN,BLACK);//verde
   gotoxy(12,12);
   printf("- Digite um numero de 1 a 9 para escolher a coluna da coordenada");

   gotoxy(12,13);
   printf("- Digite um numero de 1 a 9 para escolher a linha da coordenada");

   setColor(YELLOW,BLACK);//amarelo
   gotoxy(25,15);
   printf("Ex:");

   setColor(GREEN,BLACK);//branco
   gotoxy(30,17);
   printf("numero: 5");

   gotoxy(30,18);
   printf("coluna: 2");

   gotoxy(30,19);
   printf("linha: 7\n\n");

   __fpurge(stdin);
   getchar();
   Menu();
}

//Função Nível------------------------------------------------------------------
void Nivel()
{
   char op;

   //apaga tudo
   clrscr();

   //limpa o buffer
   __fpurge(stdin);

   setColor(BLUE,BLACK);//Azul

   gotoxy(31,10);
   printf("************************");
   gotoxy(31,11);
   printf("*                      *");
   gotoxy(31,12);
   printf("*                      *");
   gotoxy(31,13);
   printf("*                      *");
   gotoxy(31,14);
   printf("*                      *");
   gotoxy(31,15);
   printf("*                      *");
   gotoxy(31,16);
   printf("*                      *");
   gotoxy(31,17);
   printf("************************");

   setColor(GREEN,BLACK);//verde
   gotoxy(38,12);
   printf("1. Facil");

   setColor(YELLOW,BLACK);//amarelo
   gotoxy(38,13);
   printf("2. Medio");

   setColor(RED,BLACK);//vermelho
   gotoxy(38,14);
   printf("3. Dificil");

   setColor(WHITE,BLACK);//branco
   gotoxy(38,16);
   printf("opcao: ");


   setColor(YELLOW,BLACK);//amarelo

   op = getchar();

   switch(op)
   {
         case '1': varNivel = FACIL; break;

         case '2': varNivel = MEDIO; break;

         case '3': varNivel = DIFICIL; break;


         default:
             gotoxy(34,19);
             printf("opcao invalida!");
             __fpurge(stdin);
             getchar();
             Nivel();
   }
}

//------------------------------------------------------------------------------
void ImprimeHistorico(matriz *l)
{
   int cont = 1;

   clrscr();

   gotoxy(30,0);
   setColor(WHITE,BLACK);
   printf("Historico de Jogadas\n\n");

   setColor(GREEN,BLACK);
   while(l != NULL)
   {
      printf("\n%d: num: %d | lin: %d | col: %d",cont++, l->num, l->lin, l->col);
      l = l->prox;
   }

   __fpurge(stdin);
   getchar();
}

//------------------------------------------------------------------------------
int ValorAleatorio()
{
     int i;
     int var;


     for (i = 1; i <= 6; i++)
     {
           /* gerando valores aleatórios entre zero e 3 (0,1,2) */
           var = rand() % 3;
     }


     return var;
}
