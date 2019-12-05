#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<math.h>
/*#define typeof(var) _Generic( (var),\
char: "Char",\
int: "Integer",\
float: "Float",\
char *: "String",\
void *: "Pointer",\
default: "Undefined")
*/

void imprimirtudo(int* vetor, int tamanho);
int* bubblesort(int* vetor, int tamanho);
int* insertionsort(int* vetor, int tamanho);
int* escrevervetor(int* vetor, int* ptamanho);
int* randomvetor(int* vetor, int tamanho, int faixa);
int* casovetornull(int* ptamanho,int *vetor);
int* selectsort(int* vetor, int tamanho);
int* shellsort(int* vetor, int tamanho);
int* quicksort(int* vetor, int esq, int dir);
int separar(int* vetor, int esq, int dir);
int* heapmanutecaotudoemum(int* vetor, int tamanho);
int* heapmanutecao(int* vetor, int indice, int tamanho);
int* heapconstruir(int* vetor, int tamanho, int esq);
int* heapsort(int* vetor, int tamanho);
