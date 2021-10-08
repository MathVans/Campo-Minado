/************************************************************************/
/*                           Campo Minado                               */
/*											                            */
/*     Criado por:							                            */
/* Rog�rio Magnavita , Mateus Almeida, Gabriel Sena, Guilherme Andrade  */
/************************************************************************/



 //bibliotecas usadas
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <locale.h>
#include <conio.h>

int jogadas = 0;//unica v�riavel global utilizada para armazenar a quantidade de jogadas, e controlar a fun��o jogar. Vari�vel usada para saber se o jogador ganhou ou n�o.

//obs :COMPILADOR BUGOU ALGUMAS ACENTUA��ES NOS COMENT�RIOS.

//cabe�alho para o algor�timo

void gotoxy (int x, int y);	//FUN��O QUE ALTERA A LOCALIZACAO DO CURSOR
int menu (int c_bombas[8][8], int c_usuario[8][8]);	//FUN�AO MENU
int jogar (int c_bombas[8][8], int c_usuario[8][8]);	//FUNCAO QUE COMECA O JOGO
int criar_campos (int c_bombas[8][8], int c_usuario[8][8]);	//FUNCAO QUE IR� CRIAR O CAMPO
void imprimir_c_usuario (int c_bombas[8][8], int c_usuario[8][8]);	//FUNCAO QUE IMPRIMIR� O CAMPO
int coordenada (int c_bombas[8][8], int c_usuario[8][8], int *lin, int *col);	//~FUNCAO QUE RECEBE A S COORDENADAS DA JOGADA DO USUCRIO
int verificar (int c_bombas[8][8], int c_usuario[8][8], int lin, int col);	//FUN��O QUE IRA VERIFICAR A JOGADA DO USU�RIO




//fun��o que movimenta o cursor na tela


void
gotoxy (int x, int y)
{

COORD coord;

coord.X = x;

coord.Y = y;

SetConsoleCursorPosition (GetStdHandle (STD_OUTPUT_HANDLE), coord);

}







//fun��o principal, que criar� as matrizes e inicializar� o programa chamando as fun��es adjacentes.
//Criando um loop, com uma vari�vel de controle para receber o valor, que ser� retornado pela fun��o chamada no cas0:(MENU)

int main ()//FUN��O PRINCIPAL
{

int c_bombas[8][8];		// criando matriz que armazena as bombas

  int c_usuario[8][8];		// criando matriz que C) apresentada ao usuC!rio

  int start = 1;//VARI�VEL PARA O LOOP DO COME�O


setlocale (LC_ALL, "portuguese");	// definindo linguagem;

while (start!=0)//LOOOP PARA COME�AR O PROGRAMA E FAZER COM QUE MESMO QUE O USU�RIO DECIDA PARAR DE JOGAR, ELE VENHA PARA O MENU ANTES DE SAIR.
    {
        system("cls");//limpa a tela

        fflush(stdin);//limpa o buffer da mem�ria

start = menu (c_bombas, c_usuario);	//DECLARA QUE A VARIAVEL DO LOOP � IGUAL AO VALOR DE RETORNO DA FUN��O MENU

    }//CASO SEJA 0 ELE SAIR� DO LOOP, CASO SEJA 1 ELE ABRIR� O MENU NOVAMENTE.

    //FIM DA FUN��O MAIN

}






//FUN��O MENU FOI CRIADA PARA CONTROLAR O FUNCIONAMENTO DO JOGO.

//A fun��o fornece a ousu�rio as op��es de come�ar a jogar, e sair do jogo. disponibiliza tamb�m, em caso de derrota, a op��o de recome�ar o jogo.

//Caso a escolha do usu�rio sej� de jogar, o programa chamar� a fun��o que preenche as matrizes, logo ap�s entrar� em outro la�o de controle.
// Dessa vez chamando a fun��o jogar(obs:lembrando que as matrizes estar�o passando pelas pun�oes atrav�s de parametros)
// Se o jogador perder a partida, o programa sair� do la�o automaticamente, fornecendo ao mesmo as op��es de rejogar ou sair.



//caso a escolha do usu�rio seja sair do jogo, ele encerrar� sua execu��o.

//caso a escolha do usu�rio seja um valor aleat�rio, fora das op��es pedidas pelo programa, ele apresentar� uma mensagem de erro e reinicializar� o menu.

int
menu (int c_bombas[8][8], int c_usuario[8][8])//FUN��O MENU

{

int op;			//VARI�VEL PARA OP��O ESCOLHIDA

gotoxy (30, 0);		//chama funcao gotoxy, que realoca o cursor na parte desejada.

printf ("<><>||||*****CAMPO MINADO*****||||<><>");	//TITULO DO JOGO

gotoxy (43, 2);		//chama funcao gotoxy, que realoca o cursor na parte desejada.


printf ("|1-JOGAR");	//OP��O JOGAR

gotoxy (36, 3);		//chama funcao gotoxy, que realoca o cursor na parte desejada.


printf ("========================");


gotoxy (43, 4);		//chama funcao gotoxy, que realoca o cursor na parte desejada.


printf ("|2-SAIR");		//OP��O SAIR

gotoxy (43, 6);		//chama funcao gotoxy, que realoca o cursor na parte desejada.


printf ("|ESCOLHA :");	//OP��O :

 scanf("%i", &op);		//obtem o valor da vari�vel

 //COME�O DO SWITCH

switch (op)
    {


case 1:	//CASO JOGADOR QUEIRA JOGAR
      {

system ("cls");	//limpa a tela
	criar_campos (c_bombas, c_usuario);		// chama a fun��o que ir� preencher o campo de bombas e dicas, e o campo que ser� impresso ao usu�rio.



	int isRunning = 1;	//cria a vari�vel de controle para o loop

while (isRunning!=0)	//novamente entra em loop, o while automaticamente entende que se a variavel for igual a 1 ele continuar� em funcionamento.

	  {

system ("cls");		//limpa a tela



isRunning = jogar (c_bombas, c_usuario);//chama a fun��o int jogar(passando as matrizes), retornando o valor de retorno dela para a vari�vel de controle do loop.
																	//("IR PARA FUN��O JOGAR")


if (jogadas >=52){	//verifica se o jogador realizou a quantidade de jogadas necess�rias para ganhar.

	printf ("Voc� venceu!");	//caso seja verdadeira, a condi��o o jogador recebe a mensagem

	Sleep(3000);	//pausa o sistema por 3 segundos para ver a mensagem

	isRunning = 0;	// zera a variavel, para sair do loop

}
	  }

printf ("\nDeseja jogar novamente\n1-SIM\n2-N�oO\nESCOLHA:");	//pergunta se o usu�rio que jogar novamente.


scanf ("%i", &op);	//vari�vel de escolha


if (op == 1)	//caso seja sim.
	    {

system ("cls");	//limpar a tela

return 1;	//retorna 1 para o main, informando que o menu dever� ser chamado novamente gerando novas configura��es.

	    }

if(op==2){	//caso n�o

    return 0;// retorna 0 para o main, encerrando o la�o do main.

}

    break;

}


case 2:	// caso o usu�rio decida sair do jogo, ao inv�s de iniciar uma partida
      {


system ("cls");	//limpa a tela

return 0;

break;

}

default:
      {
	printf ("\nERRO digito inv�lido :%d\n", op);	//caso o usu�rio digite um valor invalido

printf ("reiniciando...");	//avisa que est�! reiniciando

Sleep (1000);		//timer para reiniciar e o usu�rio visualizar a mensagem de erro

system ("cls");	//limpa a tela

 return 1;	//retorna 1 para o la�o no main, chamando a funcao menu novamente para o usuario


break;

}
//FIM DO SWITCH
}

return 0;
//FIM DA FUN��O MENU
}




//FUN��O QUE IR� PREENCHER AS MATRIZES GERADAS NO MAIN.

// Utilizando de la�os as matrizes ser�o preenchidas respectivamente por suas informa��es

//**matriz # C_BOMBAS : Ser� primeiramente preenchida por zeros, logo ap�s utilizando a fun��o srand, e rand que dar�o valores aleat�rios para serem usados como
//coordenadas para colocara a posi��o das bombas(OBS:o valor (-1).
//que ser� reconhecido como bomba no algor�timo). Em seguida, umas sequencia de la�os e condi��es que ir�o verificar as posi�oes da matriz atribuindo a elas
//o valor de um contador, que ser� incrementado toda vez que a posi��o ao redor contiver a bomba.

//**matriz # C_USU�RIO :J� essa matriz ser� preenchida completamente por ('88'), que � o valor de convers�o na tabela ascii em inteiro do CHAR ('X').
//Na fun��o imprimir ser� utilizada a ("%c") para que a convers�o seja realizada.


int criar_campos (int c_bombas[8][8], int c_usuario[8][8])
{				//funcao que preenche os campos para o usuario
  srand (time (NULL));		// criando a semente randomica

for (int i = 0; i < 8; i++)
    {

for (int j = 0; j < 8; j++)
	{

c_bombas[i][j] = 0;

}			// criando a matriz, conferindo 0 C  todas as posi�oes

}

for (int k = 0; k < 12; k++)
    {

int s = rand () % 8;

int t = rand () % 8;	// criando valores aleat�rios de 1 a 8, de forma a encontrar uma posicionamento aleat�rio na matriz.
      if (c_bombas[s][t] == -1)

k -= 1;

      else

c_bombas[s][t] = -1;

}


int cont_bomba = 0, x = 0, z = 0;	// declarando mais variC!veis, que seriam usadas em outra func�o.
  for (int i = 0; i < 8; i++)
    {

for (int j = 0; j < 8; j++)
	{

	    // loop da matriz para colocar as bomas e as dicas para os usuarios
	    x = i - 1;

z = j - 1;

	    // posicionamento diagonal superior esquerda.
	    // declarando as posic�oes ao redor antes, pois se fizesse: "campo1[i-1][j-1]" ficaria mais dificil de manipular.

if (c_bombas[x][z] == -1
		 && ((x >= 00 && x <= 7) && (z >= 0 && z <= 7)))
	    {

		// SE "posi��o" = bomba, e se X e Z estiverem entre 0 e 4 (for uma posi��o que exista na matriz), aumentar o contador de bomba.
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


for (int i = 0; i < 8; i++)//cria a matriz que sera impressa a o usu�rio
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

char index = 'A';	//vari�vel char para o index lateral do campo minado.

for (int i = 0; i < 8; i++)	//la�o que foi utilizado para imprimir o campo minado
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


			//FUN��O COORDENADA
// Nela o usu�rio realizar� a sua jogada, e as coordenadas receber�o tratamento para serem traduzidas a l�gica do algor�timo
//ressaltar que houveram muitos bugs nessa, mas todos resolvidos.
//atribuindo os valores obtidos ao ponteiro das variav�s ap�s o tratamentos
//e retorna para jogar o valor, que ser� obtido dentro da pr�xima fun��o ("FUN��O VERIFICAR")


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



    return verificar (c_bombas, c_usuario, *lin, *col);	//chama a fun��o verificar.
}



						//FUN��O VERIFICAR
		//Nela ser� analisada a validez da jogada do usu�rio.
//caso seja inv�lida seu retorno ser� 0, caindo dentro do la�o na fun��o jogar.(IR PARA FUN��O JOGAR LINHA :

//caso seja uam jogada v�lida, seu retorno ser� 1, e o jogo retorna para jogar sem entrar no la�o de tratamento de erros, ou jogadas inv�lidas.


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



// FUN��O JOGAR
//nela fora criada vari�veis que ir�o armazenar as coordenadas

//fun��o onde come�a a partida do campo minado, primeiro chamando a fun��o imprimir campo usu�rio.
//("IR PARA FUN��O IMPRIMIR USU�RIO")

//E novamente usando de uma vari�vel para o controle de retorno, � chamada pela primeira vez a jogada do usu�rio que sera realizada dentro da fun��o "coordenada"
//(obs: IR PARA COORDENADA)

int jogar (int c_bombas[8][8], int c_usuario[8][8])
{				// fun��o que contem a parte l�gica do funcionamento do jogo

  int lin, col;	//variaveis para armazenar as coordenadas

    imprimir_c_usuario (c_bombas, c_usuario);//chama a fun�� o imprimir usu�rio

int isValid = coordenada (c_bombas, c_usuario, &lin, &col);	// chamando as jogadas

while (isValid != 1)
    {				//caso o retorno da verificaC'C#o seja 0, a jogada serC! invalida.
fflush(stdin);
printf ("Erro! Coordenada inv�lida.");	//informa ao usuC!rio

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

    c_usuario[lin][col]=c_bombas[lin][col]+48;// caso a jogada n�o seja uma bomba, iguala a coordenada escolhida ao valor da dica na matriz das bombas e dicas.
    return 1; //return 1
}


}


}
