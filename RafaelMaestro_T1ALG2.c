/** Trabalho 1 de Algoritmos 2

    Algoritmo de contagem de c�dulas, preenchimento por extenso de cheque e acesso por senha

/** SENHA: 123456 **/

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>




int acesso(){ // Inicio do programa + Fun��o que verifica a entrada da senha

	int acesso1Senha = 123456;
	int senha;
        printf("\n\n\n\t***BANCO DAS ILHAS WEBLANDS***");
        printf("\n\t------------------------------");
		printf("\n\n\tBem vindo!");
		printf("\n\n\tPara acessar o caixa,");
		printf("digite a sua senha de acesso!");
		printf("\n\n\tSenha: ");
		scanf("%d",&senha);

    if(senha == acesso1Senha){ // se a senha estiver correta

        system("cls");
        printf("\n\n\n\tUsu�rio Encontrado!");
        printf("\n\n\tREDIRECIONANDO...");
        Sleep(2000);
        system("cls");

        if(senha == acesso1Senha) return 1;
        else return 0;
}
    else{ // se estiver errada encerra a aplica��o

        printf("\n\n\n\t***Usu�rio N�o Encontrado e/ou Senha Incorreta!***");
        printf("\n\n\tCaso se trate de um erro, entre em contato com o SUPORTE pelo telefone +55 (11) 994229178");
        printf("\n\n\tTente novamente mais tarde!");
        Sleep(2000);
        printf("\n\n\tEncerrando aplica��o em: 3");
        Sleep(1000);
        printf("\n\n\tEncerrando aplica��o em: 2");
        Sleep(1000);
        printf("\n\n\tEncerrando aplica��o em: 1\n\n\n");
        Sleep(1000);
        exit(0);
}
}

int menu(int u){	//Fun��o do menu de sele��o de opera��es
	int op; // opera��es
    printf("\n\n\n\t***BANCO DAS ILHAS WEBLANDS***");
    printf("\n\t------------------------------");
    if(u == 1) {
        printf("\n\n\tCliente: Rafael");
		printf("\n\n\tEscolha uma das opera��es: ");
		printf("\n\n\t1 - Preenchimento de Cheque");
		printf("\n\n\t2 - Saque em Dinheiro");
		printf("\n\n\tOp��o: ");
            scanf("%d",&op);
		system("cls");

    if(op == 1 || op == 2){
		switch(op){
			case 1: 	return 1; // opera��o 1
						break;
            case 2:     return 0; // opera��o 2
                        break;
}
}
    if(op != 1 && op != 2){ // se selecionar uma opera��o que n�o existe
        printf("\n\n\n\tOpera��o INV�LIDA");
        printf("\n\n\tTente novamente mais tarde!");
        Sleep(1000);
        printf("\n\n\tEncerrando aplica��o em: 3");
        Sleep(1000);
        printf("\n\n\tEncerrando aplica��o em: 2");
        Sleep(1000);
        printf("\n\n\tEncerrando aplica��o em: 1\n\n\n");
        Sleep(1000);
        exit(0);}
}
}

void ler_str(char q[], int n){	//Fun��o para ler o valor digitado

	int i, a=0, flag = 0, cont = 0;
	fflush(stdin);
	printf("\n\n\n\t***BANCO DAS ILHAS WEBLANDS***\n");
    printf("\n\t----------------------------------------\n");
	printf("\n\n\tSAQUE: ");
    printf("\n\n\tPREENCHA O ESPA�O DE ACORDO COM O EXEMPLO,\n");
    printf("\n\tCOMPLETANDO COM 0 � FRENTE AT� QUE O VALOR INTEIRO SEJA MULTIPLO DE 3!\n");
    printf("\n\n\t(R$ 001600 mil e seiscentos reais)\n");
    printf("\n\n\tOU DA FORMA CONVENCIONAL R$ 20000,50 vinte mil e quinhentos reais e cinquenta centavos\n");
	printf("\n\n\tDigite a quantia desejada do saque em ");

	if(n == 0) printf("dinheiro");
	else printf("cheque");

	do{
		a = flag = cont = 0;
		fflush(stdin);
		printf("\n\n\tB$: ");
		gets(q);


		for(i=0;i<strlen(q);i++){ //Verifica se mais de uma virgula foi digitada e se foi digitado letra
			if(q[i] == '.' || q[i] == ',' || !isdigit(q[i])){
				a++;
				flag = 1;
}
            if(flag == 1)
				cont++;
}

		if(a > 1 || cont > 3)
			printf("\n\n\t\tValor INV�LIDO! Por favor digite NOVAMENTE"); // se sim retorna erro!
		} while(a > 1 || cont > 3);
}

void trata_string(char q[]){	//Preenche a string com 0 � 15 caracteres, e inverte ela no final.

	char aux2[20];
	int i, tam, flag = 0, aux;
	tam = strlen(q) ;

	for(i=0; i<tam; i++)
		if(q[i] == '.' || q[i] == ',')
			flag = 1;

	if(flag == 1){
		for(i=0; i<tam; i++)
			if(q[i] == '.' || q[i] == ',')
				q[i] = '0';
	}else strcat(q, "000");
	tam = strlen(q);
	aux = 15 - strlen(q);
	for(i=0; i<aux; i++)
		aux2[i] = '0';
	strcat(aux2, q);
	strcpy(q, aux2);
	strrev(q);
	return(aux2);
    printf("q: %s\n", q);
    printf("%s\n", aux2);
}

void extenso(char q[], int n,char f[], long *ant){   /*Fun��o para escrever por extenso at� 999,
                                                n � a ordem de grandeza do numero*/
	int un, dez, cent, soma, flag;

	un = q[0] - 48;						//VALOR DE UNIDADE - ascii
	dez = q[1] - 48;					//VALOR DA DEZENA - ascii
	cent = q[2] - 48;		            //VALOR DA CENTENA - ascii

	switch(cent){ // centenas

			case 1: if(dez == 0 && un == 0) strcat(f," Cem ");
					else strcat(f," Cento ");
					break;
			case 2: strcat(f," Duzentos "); break;
			case 3: strcat(f," Trezentos "); break;
			case 4: strcat(f," Quatrocentos "); break;
			case 5: strcat(f," Quinhentos "); break;
			case 6: strcat(f," Seiscentos "); break;
			case 7: strcat(f," Setecentos "); break;
			case 8: strcat(f," Oitocentos "); break;
			case 9: strcat(f," Novecentos "); break;
}

	if(cent > 0 && (dez != 0 || un != 0)) strcat(f,"e");

	switch(dez){

		case 1: switch(un){
					case 0:  strcat(f," Dez "); break;
					case 1:  strcat(f," Onze "); break;
					case 2:  strcat(f," Doze "); break;
					case 3:  strcat(f," Treze "); break;
					case 4:  strcat(f," Quatorze "); break;
					case 5:  strcat(f," Quinze "); break;
					case 6:  strcat(f," Dezeseis "); break;
					case 7:  strcat(f," Dezesete "); break;
					case 8:  strcat(f," Dezoito "); break;
					case 9:  strcat(f," Dezenove "); break;
}
				break;

		case 2: strcat(f," Vinte "); break;
		case 3: strcat(f," Trinta "); break;
		case 4: strcat(f," Quarenta "); break;
		case 5: strcat(f," Cinquenta "); break;
		case 6: strcat(f," Sessenta "); break;
		case 7: strcat(f," Setenta "); break;
		case 8: strcat(f," Oitenta "); break;
		case 9: strcat(f," Noventa "); break;
}

	if(dez > 1) strcat(f,"e");

	if(dez != 1){

		switch (un){
				//case 0:  if(centena == 0 && dezena == 0) printf("Zero"); break;
				case 1:  if(n != 2) strcat(f," Um "); break;
				case 2:  strcat(f," Dois "); break;
				case 3:  strcat(f," Tres "); break;
				case 4:  strcat(f," Quatro "); break;
				case 5:  strcat(f," Cinco "); break;
				case 6:  strcat(f," Seis "); break;
				case 7:  strcat(f," Sete "); break;
				case 8:  strcat(f," Oito "); break;
				case 9:  strcat(f," Nove "); break;
}
}
}

void bilhao(char q[],int n,char f[]){//Fun��o que escreve os bilh�o, bilh�es, milh�o, milh�es, etc...

	int un, dez, cent, soma;
	int soma1, soma2, soma3, soma4, soma5;

	un = q[0] - 48;						//VALOR DE UNIDADE - ascii
	dez = q[1] - 48;					//VALOR DA DEZENA - ascii
	cent = q[2] - 48;					//VALOR DA CENTENA - ascii

	soma = (cent * 100) + (dez * 10) + un;

	switch(n){

		case 0:		soma1 = soma;
					if(soma == 1) strcat(f,"Bilh�o");
					else if(soma != 0) strcat(f,"Bilh�es");
					break;
		case 1:		soma2 = soma;
					if(soma == 1) strcat(f,"Milh�o");
					else if(soma != 0) strcat(f,"Milh�es");
					break;
		case 2:		soma3 = soma;
					if(soma != 0) strcat(f,"Mil");
					break;
		case 3:		soma4 = soma;
					if(strlen(f) > 2)
						if(soma1 == 0 && soma2 == 0 && soma3 == 0 && soma4 == 1) strcat(f,"Bit");
						else strcat(f," Bits");
					break;
		case 4:		soma5 = soma;
					if(soma != 0 )	strcat(f,"CentBits");
					break;
}
}

void cheque(char q[]){   //Fun��o de controle da escrita por extenso

	int i, cont = 14;
	int dia, mes, ano;
	long anterior = 0;
	char a[3], fim[250] = " ";

	printf("\n\t*-EXEMPLO DE PREENCHIMENTO DE DATA : (22 11 2021)-*\n");
    printf("\n\tDigite a data do preenchimento: ");
		scanf("%d %d %d",&dia,&mes,&ano);


	if((dia < 0 || dia > 31) || (mes < 0 || mes > 12) || (ano < 2021 || ano > 2050)){
        printf("Data INV�LIDA");
        Sleep(2000);
        exit(0);
}
	system("cls");
	printf("\n\n\t***PREENCHIMENTO DE CHEQUE*** ");
	printf("\n\t---------------------------------------------------------------------------");
	printf("\n\tQuantia:");

	for(i = 0; i < 5; i++){
		a[0] = q[cont - 2];
		a[1] = q[cont - 1];
		a[2] = q[cont];
		cont-=3;

		extenso(a,i,fim,&anterior);
		bilhao(a,i,fim);
}

	if(strlen(fim) > 1)	puts(fim);
	else printf("\n\n\tQuantia digitada igual a zero!");
	Sleep(2000);

	printf("\n\n\tData do cheque: %d / %d / %d ",dia, mes, ano);
	printf("\n\n\n\t***Banco das Ilhas Weblands***");
	printf("\n\t***Agradecemos a prefer�ncia!***\n");
	printf("\t---------------------------------------------------------------------------");
}

void dinheiro(char q[]){	//Fun��o para calcular a quantidade de c�dulas

	int i, cont = 14, valor;
	double total = 0, soma = 0;  //Quantidade de notas de cem
	int nota100, nota50, nota20, nota10, nota5, nota2, nota1, md5, md25, md10, md1;
	//Variavel para as notas de $50, $20, $10, $5, $2, $1, moedas de $0,50, $0,25, $0,10, $0,01
	nota100 = nota50 = nota20 = nota10 = nota5 = nota2 = nota1 = md5 = md25 = md10 = md1 = 0;
	char a[3];

	for(i = 0; i < 5; i++){
		a[2] = q[cont - 2];
		a[1] = q[cont - 1];
		a[0] = q[cont];
		cont-=3;

		valor = atoi(a);

		switch(i){		//Switch para contar as notas e moedas

			case 0:    total = total + valor * 1000000;
					   break;
			case 1:    total = total + valor * 10000;
					   break;
			case 2:    total = total + valor * 10;
					   break;
			case 3:    while(valor >= 100) {
							nota100++;
							valor-=100;
					   }
					   while(valor >= 50)  {
					   		nota50++;
					   		valor-=50;
					   }
					   while(valor >= 20)  {
					   		nota20++;
					   		valor-=20;
					   }
					   while(valor >= 10)  {
					   		nota10++;
					   		valor-=10;
					   }
					   while(valor >= 5)   {
					   		nota5++;
					   		valor-=5;
					   }
					   while(valor >= 2)   {
					   		nota2++;
					   		valor-=2;
					   }
					   while(valor >= 1)   {
					   		nota1++;
					   		valor--;
					   }
					   break;

			case 4:    while(valor >= 50) {
					   		md5++;
					   		valor-=50;
					   }
					   while(valor >= 25) {
					   		md25++;
					   		valor-=25;
					   }
					   while(valor >= 10) {
					   		md10++;
					   		valor-=10;
					   }
					   while(valor >= 1)  {
					   		md1++;
					   		valor--;
					   }
					   break;}
}

	printf("\n\n");

	if(total > 0 || nota100 > 0){
		total = total + nota100;
		printf("\n\tNotas de $100 bits: %.0lf",total);
}
	if(nota50 > 0)	printf("\n\tNotas de $50 bits: %d",nota50);
	if(nota20 > 0)  printf("\n\tNotas de $20 bits: %d",nota20);
	if(nota10 > 0)  printf("\n\tNotas de $10 bits: %d",nota10);
	if(nota5 > 0)   printf("\n\tNotas de $5 bits: %d",nota5);
	if(nota2 > 0)	printf("\n\tNotas de $2 bits: %d",nota2);
	if(nota1 > 0)   printf("\n\tMoedas de $1 bits: %d",nota1);
	if(md5 > 0)	    printf("\n\tMoedas de $0,50 centbits: %d",md5);
	if(md25 > 0)	printf("\n\tMoedas de $0,25 centbits: %d",md25);
	if(md10 > 0)	printf("\n\tMoedas de $0,10 centbits: %d",md10);
	if(md1 > 0)		printf("\n\tMoedas de $0,01 centbits: %d",md1);
	printf("\n\t------------------------------------------------------");

	printf("\n\n");

	soma = total + nota50 + nota20 + nota10 + nota5 + nota2 + nota1 + md5 + md25 + md10 + md1;

	if(total >= 30) printf("\n\n\tQUANTIAS MAIORES QUE *B$3000* DEVEM SER RETIRADAS COM O ATENDENTE NO CAIXA INTERNO!");
	else if(soma == 0)	 printf("\n\tQuantia digitada igual a ZERO!");
		else {
				printf("\n\n\t***Retire o dinheiro...***");
				Sleep(2000);
}
}

int main(){

	int saque, user;
	char quantia[20], e;
	setlocale(LC_ALL, "Portuguese");

	do{
		user = acesso();
		do{
			saque = menu(user);
			ler_str(quantia,saque);
			trata_string(quantia);

			if(!saque) dinheiro(quantia);
			else cheque(quantia);



			printf("\n\n\t\tDeseja realizar outra opera��o?: ");
        do{
            scanf("%c",&e);
            e = toupper(e);
        } while(e != 'S' && e != 'N');
        if(e != 'N') system("cls");
        fflush(stdin);
		} while(e != 'N');

	} while(e != 'N');


	printf("\n\tOpera��o finalizada!");
	printf("\n\tObrigado por usar o banco das ilhas Weblands");
	printf("\n\tVolte sempre!");
    printf("\n\t---------------------------------------------------------\n\n");
	return 0;
}
