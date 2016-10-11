#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef struct Fila{
	int valor;
	struct Fila *prox; 
}No;

int tam, opc, cont = TRUE;
int inicia(No *inicio);
int menu(void);
No *aloca();
int remove(No *inicio);

int main(){
	char espera;
	No *inicio = (No *) malloc(sizeof(No));
	inicia(inicio);
	while(cont){
		cont = menu();
		printf("Aperte ENTER para continuar... \n");
		fflush(stdin);	
		espera = getchar();
		fflush(stdin);
	}
	printf("\nPrograma finalizado com sucesso!");
}

int menu(void){
	printf("Escolha a opcao desejada:\n");
	printf("0 - Sair\n");
	printf("1 - Zerar fila\n");
	printf("2 - Exibir fila\n");
	printf("3 - Adicionar elementos na fila\n");
	printf("4 - Retirar elemento da fila\n");
	printf("Opcao: ");
	scanf("%d", &opc);
	
	switch(opc){
		case 0:
			
			return opc;
		case 1:
			break;
		case 2:
			
			break;
		case 3:
			adiciona(inicio);
			break;
		case 4:
			break;
		default:
			printf("Comando invalido!\n");
			return opc;
	}
}
void inicia(No *inicio){
	inicio->prox = NULL;
	tam = 0;
}

int vazia(No *inicio){
	if(inicio->prox == NULL){
		printf("Fila vazia!\n");
		return TRUE;
	}else{
		return FALSE;
	}
}

No *aloca(){
	No *novo = (No *) malloc(No);
	novo->prox = NULL;
	return novo;
}

int adiciona(No *inicio){
	No *novo = aloca();
	if(vazia(inicio)){
		inicio->prox = novo;
		printf("Qual valor deseja guardar?: ");
		scanf("%d", novo->valor);
		printf("Valor adicionado!\n");
		tam++;
		return TRUE;
	}else{
		No *tmp = inicio->prox;
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		tmp->prox = novo;
		printf("Qual valor deseja guardar?: ");
		scanf("%d", novo->valor);
		printf("Valor adicionado!\n");
		tam++;
		return TRUE;
	}
}

int remove(No *inicio){
	if(inicio->prox == NULL)
		printf("Fila Vazia!\n");
	else
		No *tmp = inicio->prox;
		inicio->prox = tmp->prox;
		free(tmp);
		return TRUE;
}




