#pragma once
#include"Bibliotecas.h"

struct SubListaS {
	int info;
	int count;
	double Relevancia;
	SubListaS* proximo;
};

struct noS {
	SubListaS* sublista;
	noS* proximo;
	char info[15];
};

struct ListaS {
	noS* inicio;
};

void ImprimirS(ListaS *lista);
void bublesortsublistaS(SubListaS *NO, noS * l);
void bublesortlistaS(noS *NO, ListaS * l);
int adicionaS(noS* NO, int documento);
int adicionarsublistaS(ListaS *lista, char documento[]);
int addS(ListaS *lista, char documento[]);
int carregarS(char arquivo[], ListaS* lista);
int PesquisaBS(char N[][15], char termo[], int inicio, int fim);
noS* PesquisaBinariaS(ListaS* lista, char termo[], int B);
int distS(ListaS *lista, int doc);
int relevanciaS(noS* NO, ListaS * L, char palavras[]);