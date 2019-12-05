#include "algoritmos.h"

int opcao;
int *vetor = NULL;
int tamanho;
int* ptamanho = &tamanho;

void main() {

	while (1) {
		printf("Selecione uma das opções\n");
		printf("1- Escrever um novo vetor.\n"
			"2- Gerar um vetor aleatorio\n"
			"3- Imprimir vetor\n"
			"4- Ordenar usando bubblesort\n"
			"5- Ordenar usando insertsort\n"
			"6- Ordenar usando selectsort \n"
			"7- Ordenar usando shellsort\n"
			"8- Ordenar usando quicksort\n"
			"9- Ordenar usando heapsort\n"
			"10- Sair \n"
			);

		scanf("%d", &opcao);

		switch (opcao) {
		case 1:
			free(vetor);
			vetor = escrevervetor(vetor,ptamanho);
			break;
		case 2:
			free(vetor);
			printf("\nDigite quantos numeros deseja alocar.\n");
			scanf("%d", &tamanho);
			printf("\nDigite a faixa de geracao. EX: 0 ate 100, digite 100.\n");
			int faixa;
			scanf("%d", &faixa);
			vetor = randomvetor(vetor, tamanho, faixa);
			break;
		case 3:
			if (vetor != NULL)
				imprimirtudo(vetor, tamanho);
			else {
				vetor = casovetornull(ptamanho, vetor);
			}
			break;
		case 4:
			if (vetor != NULL)
				vetor = bubblesort(vetor, tamanho);
			else
			{
				vetor = casovetornull(ptamanho, vetor);
			}
			break;
		case 5:
			if (vetor != NULL)
				vetor = insertionsort(vetor, tamanho);
			else
			{
				vetor = casovetornull(ptamanho, vetor);
			}
			break;
		case 6:
			if (vetor != NULL)
				vetor = selectsort(vetor, tamanho);
			else
			{
				vetor = casovetornull(ptamanho, vetor);
			}
			break;
		case 7:
			if (vetor != NULL)
				vetor = shellsort(vetor, tamanho);
			else
			{
				vetor = casovetornull(ptamanho, vetor);
			}
			break;
		case 8:
			if (vetor != NULL) {
				int esq = 0;
				int dir = tamanho;
				vetor = quicksort(vetor, esq, dir);
			}
			else
			{
				vetor = casovetornull(ptamanho, vetor);
			}
			break;
		case 9:
			if (vetor != NULL)
				vetor = heapsort(vetor, tamanho);
			else
			{
				vetor = casovetornull(ptamanho, vetor);
			}
			break;
		case 10:
			free(vetor);
			free(ptamanho);
			exit(1);
			break;
		default:
			system("cls");
			printf("\nInvaliso\n");
		}
	}
}