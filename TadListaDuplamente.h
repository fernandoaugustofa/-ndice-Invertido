#pragma once
#include"Bibliotecas.h"
struct SubLista {
	int info;
	int count;
	double relevancia;
	SubLista* proximo;
	SubLista* anterior;
};

struct no {
	SubLista* sublista;
	no* proximo;
	no* anterior;
	char info[15];
};

struct Lista {
	no* inicio;
};

void Imprimir(Lista *lista);
void bublesortsublista(SubLista *NO, no * l);
void bublesortlista(no *NO, Lista * l);
int adiciona(no* NO, int documento);
int adicionarsublista(Lista *lista, char documento[]);
int add(Lista *lista, char documento[]);
int carregar(char arquivo[], Lista* lista);
int PesquisaB(char N[][15], char termo[], int inicio, int fim);
no* PesquisaBinaria(Lista* lista, char termo[], int B);
int dist(Lista *lista, int doc);
int relevancia(no* NO, Lista * L, char palavras[]);
