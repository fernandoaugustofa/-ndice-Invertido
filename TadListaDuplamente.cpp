#include "TadListaDuplamente.h"

int Documento;
int N = 0;

void Imprimir(Lista *lista) {
	no* N = lista->inicio;
	cout << "------------------------------------------------------------ " << endl;
	while (N != NULL) {
		SubLista* S = N->sublista;
		cout << "Palavra : " << N->info;
		while (S != NULL)
		{
			cout << ", (" << S->info << " : " << S->count << ")";
			S = S->proximo;
		}
		N = N->proximo;
		cout << endl;
	}
	system("PAUSE");
}


void bublesortsublista(SubLista *NO, no * l) {
	bool I = true;
	SubLista * N2 = NO->proximo;
	while (I) {
		I = false;
		NO = l->sublista;
		while (NO != NULL && NO->proximo != NULL) {

			if (NO->relevancia < NO->proximo->relevancia) {
				SubLista* N = NO->proximo;
				if (NO->anterior == NULL) {

					NO->anterior = NO->proximo;
					N->anterior = NULL;
					NO->proximo = N->proximo;
					N->proximo->anterior = NO;
					N->proximo = NO;
					l->sublista = N;

				}
				else {

					N->anterior = NO->anterior;
					NO->anterior = NO->proximo;
					N->anterior->proximo = N;
					NO->proximo = N->proximo;
					if (N->proximo != NULL) {
						N->proximo->anterior = NO;
						N->proximo = NO;
					}
					else {
						N->proximo = NO;
					}

				}
				I = true;
			}
			NO = NO->proximo;
		}
	}
}

void bublesortlista(no *NO, Lista * l) {
	bool I = true;
	no * N2 = NO->proximo;
	while (I) {
		I = false;
		NO = l->inicio;
		while (NO != NULL && NO->proximo != NULL) {

			if ((strcmp(NO->info, NO->proximo->info) > 0)) {
				no* N = NO->proximo;
				if (NO->anterior == NULL) {

					NO->anterior = NO->proximo;
					N->anterior = NULL;
					NO->proximo = N->proximo;
					N->proximo->anterior = NO;
					N->proximo = NO;
					l->inicio = N;

				}
				else {

					N->anterior = NO->anterior;
					NO->anterior = NO->proximo;
					N->anterior->proximo = N;
					NO->proximo = N->proximo;
					if (N->proximo != NULL) {
						N->proximo->anterior = NO;
						N->proximo = NO;
					}
					else {
						N->proximo = NO;
					}

				}
				I = true;
			}
			NO = NO->proximo;
		}
	}
}

int adiciona(no* NO, int documento) {
	if (NO->sublista == NULL) {
		SubLista* newno = (SubLista*)(malloc(sizeof(SubLista)));
		newno->proximo = NULL;
		newno->anterior = NULL;
		newno->count = 1;
		newno->info = documento;
		NO->sublista = newno;
	}
	else {
		SubLista* N = nullptr;
		SubLista* N2 = nullptr;
		N = NO->sublista;

		while (N != NULL)
		{
			N2 = N;
			N = N->proximo;
		}

		SubLista* L = (SubLista*)(malloc(sizeof(SubLista)));
		L->proximo = NULL;
		L->anterior = N2;
		N2->proximo = L;
		L->count = 1;
		L->info = documento;
	}
	return 0;
}

int adicionarsublista(Lista *lista, char documento[]) {
	no* N2 = lista->inicio;
	no* N3 = nullptr;
	while (N2 != NULL) {
		if (strcmp(N2->info, documento) == 0) {
			SubLista* S = N2->sublista;
			while (S != NULL) {
				if (Documento == S->info) {
					S->count = S->count + 1;
					return 0;
				}
				S = S->proximo;
			}
			adiciona(N2, Documento);
			return 0;
		}
		N3 = N2;
		N2 = N2->proximo;
	}
	if (lista->inicio == NULL) {
		no* N = (no*)(malloc(sizeof(no)));
		N->anterior = NULL;
		N->proximo = NULL;
		N->sublista = NULL;
		adiciona(N, Documento);
		strcpy(N->info, documento);
		lista->inicio = N;
		return 1;
	}
	else {
		no* N = (no*)(malloc(sizeof(no)));
		N->anterior = N3;
		N->proximo = NULL;
		N->sublista = NULL;
		adiciona(N, Documento);
		N3->proximo = N;
		strcpy(N->info, documento);
		return 1;
	}
	return 0;
}



int add(Lista *lista, char documento[]) {
	int i = 0, i2 = 0;
	int B = 0;
	if (documento[0] == '.'  && documento[1] == 'I'  && documento[2] == ' ') {
		char D[100] = { 0 };
		int i = 3, i2 = 0;
		N++;
		while (i != strlen(documento)) {
			D[i2] = documento[i];
			i2++;
			i++;
		}
		Documento = atoi(D);
	}
	else
		if (documento[0] != '.'  && documento[1] != 'W' && documento[0] != '\n') {
			char documento2[16] = { 0 };
			int count = 0;
			int A = strlen(documento);
			while (i <= strlen(documento)) {
				if ((documento[i] == '\n') || (documento[i] == 32) || (i2 == 15)) {
					B = B + adicionarsublista(lista, documento2);
					while (i2 != 0) {
						documento2[i2] = 0;
						i2--;
					}
					i++;
				}
				documento2[i2] = documento[i];
				i2++;
				i++;
			}
		}
	return B;
}

int carregar(char arquivo[], Lista* lista) {
	try
	{
		FILE * pFile;
		int B = 0;
		char mystring[16000];
		pFile = fopen(arquivo, "r");
		if (pFile == NULL) cout << "Unable to open file";
		else {
			while (fgets(mystring, 5000, pFile) != NULL) {
				B = B + add(lista, mystring);
			}
			fclose(pFile);
			bublesortlista(lista->inicio, lista);

		}
		return B;
	}
	catch (int e)
	{
		cout << e << endl;
	}

}

int PesquisaB(char N[][15], char termo[], int inicio, int fim) {
	int i = (fim - inicio) / 2;
	i = inicio + i;
	if (inicio == fim || (inicio == fim - 1)) {
		if (strcmp(termo, N[i]) != 0) {
			return -1;
		}
	}
	if (strcmp(termo, N[i]) == 0) {
		return i;
	}
	if (strcmp(termo, N[i]) > 0) {
		return PesquisaB(N, termo, i, fim);
	}
	if (strcmp(termo, N[i]) < 0) {
		return PesquisaB(N, termo, inicio, i);
	}
	return NULL;
}

no* PesquisaBinaria(Lista* lista, char termo[], int B) {
	no* NO = (no*)malloc(sizeof(no));
	NO = lista->inicio;
	int i = 0;
	char A[50000][15];
	while (NO != NULL) {
		A[i][0] = 0;
		strcpy(A[i], NO->info);
		NO = NO->proximo;
		i++;
	}
	int Y = PesquisaB(A, termo, 0, i);
	if (Y != -1) {
		NO = lista->inicio;
		int T = 0;
		while (T != Y)
		{
			NO = NO->proximo;
			T++;
		}
		return NO;
	}
	return NULL;
}
int dist(Lista *lista, int doc) {
	no* N = lista->inicio;
	int A = 0;
	while (N != NULL) {
		SubLista* S = N->sublista;
		while (S != NULL)
		{
			if (doc == S->info) {
				A++;
				break;
			}
			S = S->proximo;
		}
		N = N->proximo;
	}
	return A;
}

int relevancia(no* NO, Lista * L, char palavras[]) {
	double i = 0;
	int A = 0;
	SubLista* N1 = NO->sublista;
	int S = 0, U = 0;
	while (N1 != NULL) {
		A = A + 1;
		U++;
		S = S + U;
		N1 = N1->proximo;
	}
	i = log(N) / A;
	N1 = NO->sublista;
	while (N1 != NULL) {
		int X = dist(L, N1->info);
		double F = (double)1 / (double)X;
		N1->relevancia = F * S * (N1->count * i);
		N1 = N1->proximo;
	}
	return 1;
}