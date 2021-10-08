/************************************************************************/
/*                           Campo Minado                               */
/*											                            */
/*     Criado por:							                            */
/* Rogério Magnavita , Mateus Almeida, Gabriel Sena, Guilherme Andrade  */
/************************************************************************/



 //bibliotecas usadas
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#include <conio.h>

int jogadas = 0;//unica váriavel global utilizada para armazenar a quantidade de jogadas, e controlar a função jogar. Variável usada para saber se o jogador ganhou ou não.

//obs :COMPILADOR BUGOU ALGUMAS ACENTUAÇÕES NOS COMENTÁRIOS.

//cabeçalho para o algorítimo

void gotoxy (int x, int y);	//FUNÇÃO QUE ALTERA A LOCALIZACAO DO CURSOR
int menu (int c_bombas[8][8], int c_usuario[8][8]);	//FUNçAO MENU
int jogar (int c_bombas[8][8], int c_usuario[8][8]);	//FUNCAO QUE COMECA O JOGO
int criar_campos (int c_bombas[8][8], int c_usuario[8][8]);	//FUNCAO QUE IRÁ CRIAR O CAMPO
void imprimir_c_usuario (int c_bombas[8][8], int c_usuario[8][8]);	//FUNCAO QUE IMPRIMIRÁ O CAMPO
int coordenada (int c_bombas[8][8], int c_usuario[8][8], int *lin, int *col);	//~FUNCAO QUE RECEBE A S COORDENADAS DA JOGADA DO USUCRIO
int verificar (int c_bombas[8][8], int c_usuario[8][8], int lin, int col);	//FUNÇÃO QUE IRA VERIFICAR A JOGADA DO USUÁRIO




//função que movimenta o cursor na tela


void
gotoxy (int x, int y)
{

COORD coord;

coord.X = x;

coord.Y = y;

SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), coord);

}







//função principal, que criará as matrizes e inicializará o programa chamando as funções adjacentes.
//Criando um loop, com uma variável de controle para receber o valor, que será retornado pela função chamada no cas0:(MENU)

int main ()//FUNÇÃO PRINCIPAL
{

int c_bombas[8][8];		// criando matriz que armazena as bombas

  int c_usuario[8][8];		// criando matriz que C) apresentada ao usuC!rio

  int start = 1;//VARIÁVEL PARA O LOOP DO COMEÇO


setlocale (LC_ALL, "portuguese");	// definindo linguagem;

while (start!=0)//LOOOP PARA COMEÇAR O PROGRAMA E FAZER COM QUE MESMO QUE O USUÁRIO DECIDA PARAR DE JOGAR, ELE VENHA PARA O MENU ANTES DE SAIR.
    {
        system("cls");//limpa a tela

        fflush(stdin);//limpa o buffer da memória

start = menu (c_bombas, c_usuario);	//DECLARA QUE A VARIAVEL DO LOOP É IGUAL AO VALOR DE RETORNO DA FUNÇÃO MENU

    }//CASO SEJA 0 ELE SAIRÁ DO LOOP, CASO SEJA 1 ELE ABRIRÁ O MENU NOVAMENTE.

    //FIM DA FUNÇÃO MAIN

}






//FUNÇÃO MENU FOI CRIADA PARA CONTROLAR O FUNCIONAMENTO DO JOGO.

//A função fornece a ousuário as opções de começar a jogar, e sair do jogo. disponibiliza também, em caso de derrota, a opção de recomeçar o jogo.

//Caso a escolha do usuário sejá de jogar, o programa chamará a função que preenche as matrizes, logo após entrará em outro laço de controle.
// Dessa vez chamando a função jogar(obs:lembrando que as matrizes estarão passando pelas punçoes através de parametros)
// Se o jogador perder a partida, o programa sairá do laço automaticamente, fornecendo ao mesmo as opções de rejogar ou sair.



//caso a escolha do usuário seja sair do jogo, ele encerrará sua execução.

//caso a escolha do usuário seja um valor aleatório, fora das opções pedidas pelo programa, ele apresentará uma mensagem de erro e reinicializará o menu.

int
menu (int c_bombas[8][8], int c_usuario[8][8])//FUNÇÃO MENU

{

int op;			//VARIÁVEL PARA OPÇÃO ESCOLHIDA

gotoxy (30, 0);		//chama funcao gotoxy, que realoca o cursor na parte desejada.

printf ("<><>||||*****CAMPO MINADO*****||||<><>");	//TITULO DO JOGO

gotoxy (43, 2);		//chama funcao gotoxy, que realoca o cursor na parte desejada.


printf ("|1-JOGAR");	//OPÇÃO JOGAR

gotoxy (36, 3);		//chama funcao gotoxy, que realoca o cursor na parte desejada.


printf ("========================");


gotoxy (43, 4);		//chama funcao gotoxy, que realoca o cursor na parte desejada.


printf ("|2-SAIR");		//OPÇÃO SAIR

gotoxy (43, 6);		//chama funcao gotoxy, que realoca o cursor na parte desejada.


printf ("|ESCOLHA :");	//OPÇÃO :

 scanf("%i", &op);		//obtem o valor da variável

 //COMEÇO DO SWITCH

switch (op)
    {


case 1:	//CASO JOGADOR QUEIRA JOGAR
      {

system ("cls");	//limpa a tela
	criar_campos (c_bombas, c_usuario);		// chama a função que irá preencher o campo de bombas e dicas, e o campo que será impresso ao usuário.



	int isRunning = 1;	//cria a variável de controle para o loop

while (isRunning!=0)	//novamente entra em loop, o while automaticamente entende que se a variavel for igual a 1 ele continuará em funcionamento.

	  {

system ("cls");		//limpa a tela



isRunning = jogar (c_bombas, c_usuario);//chama a função int jogar(passando as matrizes), retornando o valor de retorno dela para a variável de controle do loop.
																	//("IR PARA FUNÇÃO JOGAR")


if (jogadas >=52){	//verifica se o jogador realizou a quantidade de jogadas necessárias para ganhar.

	printf ("Você venceu!");	//caso seja verdadeira, a condição o jogador recebe a mensagem

	Sleep(3000);	//pausa o sistema por 3 segundos para ver a mensagem

	isRunning = 0;	// zera a variavel, para sair do loop

}
	  }

printf ("\nDeseja jogar novamente\n1-SIM\n2-NãoO\nESCOLHA:");	//pergunta se o usuário que jogar novamente.


scanf ("%i", &op);	//variável de escolha


if (op == 1)	//caso seja sim.
	    {

system ("cls");	//limpar a tela

return 1;	//retorna 1 para o main, informando que o menu deverá ser chamado novamente gerando novas configurações.

	    }

if(op==2){	//caso não

    return 0;// retorna 0 para o main, encerrando o laço do main.

}

    break;

}


case 2:	// caso o usuário decida sair do jogo, ao invés de iniciar uma partida
      {


system ("cls");	//limpa a tela

return 0;

break;

}

default:
      {
	printf ("\nERRO digito inválido :%d\n", op);	//caso o usuário digite um valor invalido

printf ("reiniciando...");	//avisa que está! reiniciando

Sleep (1000);		//timer para reiniciar e o usuário visualizar a mensagem de erro

system ("cls");	//limpa a tela

 return 1;	//retorna 1 para o laço no main, chamando a funcao menu novamente para o usuario


break;

}
//FIM DO SWITCH
}

return 0;
//FIM DA FUNÇÃO MENU
}




//FUNÇÃO QUE IRÁ PREENCHER AS MATRIZES GERADAS NO MAIN.

// Utilizando de laços as matrizes serão preenchidas respectivamente por suas informações

//**matriz # C_BOMBAS : Será primeiramente preenchida por zeros, logo após utilizando a função srand, e rand que darão valores aleatórios para serem usados como
//coordenadas para colocara a posição das bombas(OBS:o valor (-1).
//que será reconhecido como bomba no algorítimo). Em seguida, umas sequencia de laços e condições que irão verificar as posiçoes da matriz atribuindo a elas
//o valor de um contador, que será incrementado toda vez que a posição ao redor contiver a bomba.

//**matriz # C_USUÁRIO :Já essa matriz será preenchida completamente por ('88'), que é o valor de conversão na tabela ascii em inteiro do CHAR ('X').
//Na função imprimir será utilizada a ("%c") para que a conversão seja realizada.


int criar_campos (int c_bombas[8][8], int c_usuario[8][8])
{				//funcao que preenche os campos para o usuario
  srand (time (NULL));		// criando a semente randomica

for (int i = 0; i < 8; i++)
    {

for (int j = 0; j < 8; j++)
	{

c_bombas[i][j] = 0;

}			// criando a matriz, conferindo 0 C  todas as posiçoes

}

for (int k = 0; k < 12; k++)
    {

int s = rand () % 8;

int t = rand () % 8;	// criando valores aleatórios de 1 a 8, de forma a encontrar uma posicionamento aleatório na matriz.
      if (c_bombas[s][t] == -1)

k -= 1;

      else

c_bombas[s][t] = -1;

}


int cont_bomba = 0, x = 0, z = 0;	// declarando mais variC!veis, que seriam usadas em outra funcão.
  for (int i = 0; i < 8; i++)
    {

for (int j = 0; j < 8; j++)
	{

	    // loop da matriz para colocar as bomas e as dicas para os usuarios
	    x = i - 1;

z = j - 1;

	    // posicionamento diagonal superior esquerda.
	    // declarando as posicçoes ao redor antes, pois se fizesse: "campo1[i-1][j-1]" ficaria mais dificil de manipular.

if (c_bombas[x][z] == -1
		 && ((x >= 00 && x <= 7) && (z >= 0 && z <= 7)))
	    {

		// SE "posição" = bomba, e se X e Z estiverem entre 0 e 4 (for uma posição que exista na matriz), aumentar o contador de bomba.
		cont_bomba++;

}

x = i - 1;

z = j;		// posicionamento acima.
	  if (c_bombas[x][z] == -1
	      && ((x >= 00 && x <= 7) && (z >= 0 && z <= 7)))
	    {

cont_bomba++;

}

x = i - 1;

z = j + 1;		// posicionamento diagonal superior direita.
	  if (c_bombas[x][z] == -1
	      && ((x >= 00 && x <= 7) && (z >= 0 && z <= 7)))
	    {

cont_bomba++;

}


x = i;

z = j - 1;		// posicionamento  esquerda
	  if (c_bombas[x][z] == -1
	      && ((x >= 00 && x <= 7) && (z >= 0 && z <= 7)))
	    {

cont_bomba++;

}

x = i;

z = j + 1;		// posicionamento  direita.
	  if (c_bombas[x][z] == -1
	      && ((x >= 00 && x <= 7) && (z >= 0 && z <= 7)))
	    {			// "  "  "
	      cont_bomba++;

}


x = i + 1;

z = j - 1;		// posicionamento diagonal inferior esquerda.
	  if (c_bombas[x][z] == -1
	      && ((x >= 00 && x <= 7) && (z >= 0 && z <= 7)))
	    {

cont_bomba++;

}

x = i + 1;

z = j;		// posicionamento abaixo
	  if (c_bombas[x][z] == -1
	      && ((x >= 00 && x <= 7) && (z >= 0 && z <= 7)))
	    {

cont_bomba++;

}


x = i + 1;

z = j + 1;		// posicionamento diagonal inferior direita.

if (c_bombas[x][z] == -1
	       && ((x >= 00 && x <= 7) && (z >= 0 && z <= 7)))
	    {

cont_bomba++;

}


if (c_bombas[i][j] != -1)
	    {			// se a posicionamento for uma bomba

c_bombas[i][j] = cont_bomba++;	// C) dado o valor do contador de bombas ao redor.
	    }

cont_bomba = 0;


}

}


for (int i = 0; i < 8; i++)//cria a matriz que sera impressa a o usuário
    {

for (int j = 0; j < 8; j++)
	{

c_usuario[i][j] = 88;

}
}
//(RETORNAR PARA MENU, CASE 1.)
}



void imprimir_c_usuario (int c_bombas[8][8], int c_usuario[8][8])
{

char index = 'A';	//variável char para o index lateral do campo minado.

for (int i = 0; i < 8; i++)	//laço que foi utilizado para imprimir o campo minado
    {

if (i == 0)
	{

printf ("   1 2 3 4 5 6 7 8\n=====================\n");

}


printf ("%c ", index++);


for (int j = 0; j < 8; j++)
	{


printf (" %c", c_usuario[i][j]);

}
printf ("\n");

}
printf ("\n");
/*

for (int i = 0; i < 8; i++)
    {

for (int j = 0; j < 8; j++)  							//retirar a para visualizar a matriz de bombas e dicas
	{

printf (" %d", c_bombas[i][j]);

}
printf ("\n");

}*/
}


			//FUNÇÃO COORDENADA
// Nela o usuário realizará a sua jogada, e as coordenadas receberão tratamento para serem traduzidas a lógica do algorítimo
//ressaltar que houveram muitos bugs nessa, mas todos resolvidos.
//atribuindo os valores obtidos ao ponteiro das variavés após o tratamentos
//e retorna para jogar o valor, que será obtido dentro da próxima função ("FUNÇÃO VERIFICAR")


int coordenada (int c_bombas[8][8], int c_usuario[8][8], int *lin, int *col)

{				//recebe as cordenadas do usuC!rio, econverte os valores da tabela ascii
  printf ("Informe a linha: ");


*lin = getch ();		//pega o char
  printf ("%c\n", *lin);	//

printf ("Informe a coluna: ");

int c;

scanf ("%d", &c);		//pega  o int
  *col = c - 1;			//passa o int para  avairavel col.

if (*lin >= 65 && *lin <= 72)
    {

*lin -= 65;//para letraminuscula

}
  else
    {

*lin -= 97;//para letra maiuscula

}



    return verificar (c_bombas, c_usuario, *lin, *col);	//chama a função verificar.
}



						//FUNÇÃO VERIFICAR
		//Nela será analisada a validez da jogada do usuário.
//caso seja inválida seu retorno será 0, caindo dentro do laço na função jogar.(IR PARA FUNÇÃO JOGAR LINHA :

//caso seja uam jogada válida, seu retorno será 1, e o jogo retorna para jogar sem entrar no laço de tratamento de erros, ou jogadas inválidas.


int verificar (int c_bombas[8][8], int c_usuario[8][8], int lin, int col)

{				//verifica se a jogada valida e transforma o char da jogada em int, atravC)s da conversC#o de valores pela tabela ascii
  // 65=A, 72=H,,,,, 97=a, 104=h

  if ((lin >= 0 && lin < 8) && (col >= 0 && col < 8) && (c_usuario[lin][col] == 88))
    {

jogadas++;

return 1;

}

  else
    {

return 0;

}

}



// FUNÇÃO JOGAR
//nela fora criada variáveis que irão armazenar as coordenadas

//função onde começa a partida do campo minado, primeiro chamando a função imprimir campo usuário.
//("IR PARA FUNÇÃO IMPRIMIR USUÁRIO")

//E novamente usando de uma variável para o controle de retorno, é chamada pela primeira vez a jogada do usuário que sera realizada dentro da função "coordenada"
//(obs: IR PARA COORDENADA)

int jogar (int c_bombas[8][8], int c_usuario[8][8])
{				// função que contem a parte lógica do funcionamento do jogo

  int lin, col;	//variaveis para armazenar as coordenadas

    imprimir_c_usuario (c_bombas, c_usuario);//chama a funçã o imprimir usuário

int isValid = coordenada (c_bombas, c_usuario, &lin, &col);	// chamando as jogadas

while (isValid != 1)
    {				//caso o retorno da verificaC'C#o seja 0, a jogada serC! invalida.
fflush(stdin);
printf ("Erro! Coordenada inválida.");	//informa ao usuC!rio

Sleep (1000);		//timer para que ele veja a mensagem

system ("cls");		//limpa a tela

return 1;		//retorna 1 para o loop do menu.

}



while (isValid == 1)
    {

if (c_bombas[lin][col] == -1)//caso a jogada, esteja com uma bomba
	{


printf ("\nVOCE PERDEU!!!!!!!\n");	//mensagem de derrota

return 0;	//retorna 0 para o loop menu


}

if (c_bombas[lin][col] != -1){

    c_usuario[lin][col]=c_bombas[lin][col]+48;// caso a jogada não seja uma bomba, iguala a coordenada escolhida ao valor da dica na matriz das bombas e dicas.
    return 1; //return 1
}


}


}
