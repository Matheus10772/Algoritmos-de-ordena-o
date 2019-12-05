#include "algoritmos.h"


int* bubblesort(int* vetor, int tamanho) {
	int i = 0;
	int percorrer = 0;
	int Ciclo = 1;
	int tamanho2 = tamanho;
	int temp;
	for (percorrer; percorrer <= tamanho; percorrer++) {
		for (i; i < tamanho2; i++) {
			if (vetor[i + 1] < vetor[i]) {
				temp = vetor[i + 1];
				vetor[i + 1] = vetor[i];
				vetor[i] = temp;
			}
			printf("\nCiclo %d\n", Ciclo);
			Ciclo++;
			printf("\n");
		}
		tamanho2--;
		i = 0;
	}
	system("cls");
	imprimirtudo(vetor, tamanho);
	return vetor;
}



int* insertionsort(int* vetor, int tamanho) {
	int indice = 1;
	int atual;
	int ciclo = 1;
	if (tamanho > 1) {
		for (indice; indice < tamanho; indice++) {
			int aux = indice;
			for (aux; aux > 0; aux--) {
				atual = vetor[aux];
				if (atual < vetor[aux - 1]) {
					vetor[aux] = vetor[aux - 1];
					vetor[aux - 1] = atual;
				}
				else
				{
					break;
				}
				printf("\nCiclo %d\n", ciclo);
				ciclo++;
			}
		}
	}
	system("cls");
	imprimirtudo(vetor, tamanho);
	return vetor;
}



int* escrevervetor(int* vetor, int* ptamanho){
	*ptamanho = 0;
	int aux;
	vetor = (int*)malloc(sizeof(int)*5);
	int maxtam = 5;
	printf("\nDigite quantos números quiser. Pressione 0 quando quiser finalizar a inserção\n");
	scanf("%d", &vetor[*ptamanho]);
	(*ptamanho)++;
	while(1){
		scanf("%d", &aux);
		if (aux != 0) {
			if (*ptamanho > maxtam) {
				vetor = (int*)realloc(vetor, sizeof(int)*5);
			}
			vetor[*ptamanho] = aux;
			(*ptamanho)++;
		}
		else {
			break;
		}
	}
	system("cls");
	imprimirtudo(vetor, *ptamanho);
	return vetor;
}

int* randomvetor(int* vetor, int tamanho, int faixa)
{
	int aleatorio;
	vetor = (int*)malloc(sizeof(int) * tamanho);
	for (int i = 0; i < tamanho; i++) {
		aleatorio = rand() % faixa;
		vetor[i] = aleatorio;
	}
	system("cls");
	imprimirtudo(vetor, tamanho);
	return vetor;
}

int* casovetornull(int* ptamanho, int *vetor){
	int aux;
	printf("\nVetor ainda inexistente. Digite 1 para criar um novo ou qualquer outra tecla para cancelar.\n");
	scanf("%d", &aux);
	if (aux == 1) {
		int aux2;
		printf("\n1 escrever vetor. 2 gerar vetor aleatório. 3 cancelar");
		scanf("%d", &aux2);
		switch (aux2) {
		case 1:
			vetor = escrevervetor(vetor,ptamanho);
			return vetor;
			break;
		case 2:
			*ptamanho = 0;
			printf("\nDigite quantos numeros deseja alocar.\n");
			scanf("%d", ptamanho);
			printf("\nDigite a faixa de geracao. EX: 0 ate 100, digite 100.\n");
			int faixa1;
			scanf("%d", &faixa1);
			randomvetor(vetor, *ptamanho, faixa1);
			return vetor;
			break;
		default:
			system("cls");
			printf("\nOk\n");
			return NULL;
			break;
		}
	}
}

int* selectsort(int* vetor, int tamanho){
	int indice;
	int indafrente;
	int aux;
	int intemamovimentar;
	for (indice = 0; indice <= tamanho-1; indice++) {
		aux = indice;
		for (indafrente = indice + 1; indafrente <= tamanho; indafrente++) {
			if (vetor[indafrente] < vetor[aux])
				aux = indafrente;
		}
		intemamovimentar = vetor[indice];
		vetor[indice] = vetor[aux];
		vetor[aux] = intemamovimentar;
	}
	system("cls");
	imprimirtudo(vetor, tamanho);
	return vetor;
}

int* shellsort(int* vetor, int tamanho){
	double x = (((tamanho + 1) / 2) + 1);
	double h = ceil(x);
	int inicio = 0;
	int final = (int)h;
	int aux;
	while (h >= 1) {
		for (final; final <= tamanho; final++) {
			if (vetor[inicio] > vetor[final]) {
				aux = vetor[inicio];
				vetor[inicio] = vetor[final];
				vetor[final] = aux;
			}
			inicio++;
		}
		h = ceil(h / 2);
		final = h;
		inicio = 0;
	}
	system("cls");
	imprimirtudo(vetor, tamanho);
	return vetor;
}

int* quicksort(int* vetor, int esq, int dir){
	if (esq < dir) {
		int pivo = separar(vetor, esq, dir);
		quicksort(vetor, esq, pivo - 1);
		quicksort(vetor, pivo + 1, dir); 
	}
	return vetor;
}

int separar(int* vetor, int esq, int dir){
	int i = esq;
	int j = dir;
	int aux;
	int pivo = vetor[esq];
	while (i < j)
	{
		while (vetor[i] <= pivo) i++;
		while (vetor[j] > pivo) j--;
		if (i < j) {
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
		}
	}
	vetor[esq] = vetor[j];
	vetor[j] = pivo;
	return j;
	
}

/*algoritmo tudo em um. Constroi e arranja a heap. */int* heapmanutecaotudoemum(int* vetor, int tamanho) {
	int filhodireito;
	int filhoesquerdo;
	int aux;
	int intemamovimentar;
	int i = 0;
	int ir = 0;
	while (i < tamanho) {
		if ((i * 2) <= tamanho && ((i * 2) + 1) <= tamanho) {
			filhodireito = (i * 2) + 1;
			filhoesquerdo = i * 2;
			aux = filhodireito;
			if (vetor[filhoesquerdo] > vetor[aux])
				aux = filhoesquerdo;
			while ((i * 2) <= tamanho && ((i * 2) + 1) <= tamanho) {
			if (vetor[i] < vetor[aux]) {
				intemamovimentar = vetor[i];
				vetor[i] = vetor[aux];
				vetor[aux] = intemamovimentar;
				filhoesquerdo = aux * 2;
				filhodireito = (aux * 2) + 1;
				i = aux;
				aux = filhodireito;
				if (vetor[filhoesquerdo] > vetor[filhodireito])
					aux = filhoesquerdo;
			}

			else { break; }
		}
		ir++;
		i = ir;
		}
		else
		{
			break;
		}
	}
	return vetor;
}

int* heapmanutecao(int* vetor, int indice, int tamamho)
{
	int filhodireito;
	int filhoesquerdo;
	int aux;
	int intemamovimentar;
	if ((filhodireito = (indice * 2) + 1) > tamamho && (filhoesquerdo = (indice * 2)) <= tamamho) {
		filhoesquerdo = indice * 2;
		if (vetor[filhoesquerdo] > vetor[indice]) {
			intemamovimentar = vetor[indice];
			vetor[indice] = vetor[filhoesquerdo];
			vetor[filhoesquerdo] = intemamovimentar;
		}
		return vetor;
	}
	else if ((filhodireito = (indice * 2) + 1) > tamamho && (filhoesquerdo = (indice * 2)) > tamamho)
		return vetor;

	else{
		filhoesquerdo = indice * 2;
		filhodireito = (indice * 2) + 1;
		if (vetor[filhoesquerdo] < vetor[filhodireito])
			aux = filhodireito;
		else
		{
			aux = filhoesquerdo;
		}
		if (vetor[indice] < vetor[aux]) {
			intemamovimentar = vetor[indice];
			vetor[indice] = vetor[aux];
			vetor[aux] = intemamovimentar;
		}
		return vetor;
	}

}

int* heapconstruir(int* vetor, int tamanho, int esq)
{
	for (esq; esq < tamanho; esq++) {
		vetor = heapmanutecao(vetor, esq, tamanho);
		esq++;
	}
	return vetor;
}

int* heapsort(int* vetor, int tamanho)
{
	int i = 0;
	vetor = heapconstruir(vetor, tamanho, i);
	int tamanho2 = tamanho;
	int aux;
	while (i <= tamanho) {
		aux = vetor[i];
		vetor[i] = vetor[tamanho2];
		vetor[tamanho2] = aux;
		tamanho2--;
		i++;
		vetor = heapconstruir(vetor, tamanho2, i);
	}
	system("cls");
	imprimirtudo(vetor, tamanho);
	return vetor;
}

void imprimirtudo(int* vetor, int tamanho) {
	system("cls");
	for (int i = 0; i < tamanho; i++) {
		printf("%d ", vetor[i]);
	}
}