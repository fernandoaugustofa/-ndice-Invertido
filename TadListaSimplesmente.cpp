#include "TadListaSimplesmente.h"

int DocumentoS;
int NS = 0;
void ImprimirS(ListaS *lista) {
	noS* N = lista->inicio;
	//system("CLS");
	cout << "------------------------------------------------------------ " << endl;
	while (N != NULL) {
		SubListaS* S = N->sublista;
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

void bublesortsublistaS(SubListaS *NO, noS * l) {
	bool I = true;
	SubListaS * N2 = NO->proximo;
	while (I) {
		I = false;
		NO = l->sublista;
		while (NO != NULL && NO->proximo != NULL) {
			if (NO->Relevancia < NO->proximo->Relevancia) {
				N2 = NO->proximo;
				int info;
				int count;
				double Relevancia;
				info = NO->info;
				count = NO->count;
				Relevancia = NO->Relevancia;
				NO->info = N2->info;
				NO->count = N2->count;
				NO->Relevancia = NO->Relevancia;
				N2->info = info;
				N2->count = count;
				N2->Relevancia = Relevancia;
				I = true;
			}
			NO = NO->proximo;
		}
	}
}

void bublesortlistaS(noS *NO, ListaS * l) {
	bool I = true;
	noS * N2 = NO->proximo;
	while (I) {
		I = false;
		NO = l->inicio;
		while (NO != NULL && NO->proximo != NULL) {

			if ((strcmp(NO->info, NO->proximo->info) > 0)) {
				char* A = (char*)malloc(15 * sizeof(char));
				N2 = NO->proximo;
				SubListaS * Sub = NO->sublista;
				A[0] = '0';
				strcpy(A, NO->info);
				NO->info[0] = '0';
				strcpy(NO->info, N2->info);
				N2->info[0] = '0';
				strcpy(N2->info, A);
				NO->sublista = N2->sublista;
				N2->sublista = Sub;
				I = true;
			}
			NO = NO->proximo;
		}
	}
}


int adicionaS(noS* NO, int documento) {
	if (NO->sublista == NULL) {
		SubListaS* newno = (SubListaS*)(malloc(sizeof(SubListaS)));
		newno->proximo = NULL;
		newno->count = 1;
		newno->info = documento;
		NO->sublista = newno;
	}
	else {
		SubListaS* N = nullptr, *N2 = nullptr;
		N = NO->sublista;

		while (N != NULL)
		{
			N2 = N;
			N = N->proximo;
		}

		SubListaS* L = (SubListaS*)(malloc(sizeof(SubListaS)));
		L->proximo = NULL;
		N2->proximo = L;
		L->count = 1;
		L->info = documento;
	}
	return 0;
}

int adicionarsublistaS(ListaS *lista, char documento[]) {
	noS* N2 = lista->inicio;
	noS* N3 = nullptr;
	while (N2 != NULL) {
		if (strcmp(N2->info, documento) == 0) {
			SubListaS* S = N2->sublista;
			while (S != NULL) {
				if (DocumentoS == S->info) {
					S->count = S->count + 1;
					return 0;
				}
				S = S->proximo;
			}
			adicionaS(N2, DocumentoS);
			return 0;
		}
		N3 = N2;
		N2 = N2->proximo;
	}
	if (lista->inicio == NULL) {
		noS* N = (noS*)(malloc(sizeof(noS)));
		N->proximo = NULL;
		N->sublista = NULL;
		adicionaS(N, DocumentoS);
		strcpy(N->info, documento);
		lista->inicio = N;
		return 1;
	}
	else {
		noS* N = (noS*)(malloc(sizeof(noS)));
		N->proximo = NULL;
		N->sublista = NULL;
		adicionaS(N, DocumentoS);
		N3->proximo = N;
		strcpy(N->info, documento);
		return 1;
	}
	return 0;
}



int addS(ListaS *lista, char documento[]) {
	int i = 0, i2 = 0;
	int B = 0;
	if (documento[0] == '.'  && documento[1] == 'I'  && documento[2] == ' ') {
		NS++;
		char D[100] = { 0 };
		int i = 3, i2 = 0;
		while (i != strlen(documento)) {
			D[i2] = documento[i];
			i2++;
			i++;
		}
		DocumentoS = atoi(D);
	}
	else
		if (documento[0] != '.'  && documento[1] != 'W' && documento[0] != '\n') {
			char documento2[16] = { 0 };
			int count = 0;
			int A = strlen(documento);
			while (i <= strlen(documento)) {
				if ((documento[i] == '\n') || (documento[i] == 32) || (i2 == 15)) {
					B = B + adicionarsublistaS(lista, documento2);
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

int carregarS(char arquivo[], ListaS* lista) {
	try
	{
		FILE * pFile;
		int B = 0;
		char mystring[16000];
		pFile = fopen(arquivo, "r");
		if (pFile == NULL) cout << "Unable to open file";
		else {
			int i = 0;
			while (fgets(mystring, 5000, pFile) != NULL) {
				B = B + addS(lista, mystring);
				i++;
			}
			fclose(pFile);
			bublesortlistaS(lista->inicio, lista);

		}
		return B;
	}
	catch (int e)
	{
		cout << e << endl;
	}

}

int PesquisaBS(char N[][15], char termo[], int inicio, int fim) {
	int i = (fim - inicio) / 2;
	i = inicio + i;
	if (inicio == fim) {
		if (strcmp(termo, N[i]) != 0) {
			return -1;
		}
	}
	if (strcmp(termo, N[i]) == 0) {
		return i;
	}
	if (strcmp(termo, N[i]) > 0) {
		return PesquisaBS(N, termo, i, fim);
	}
	if (strcmp(termo, N[i]) < 0) {
		return PesquisaBS(N, termo, inicio, i);
	}
	return NULL;
}

noS* PesquisaBinariaS(ListaS* lista, char termo[], int B) {
	noS* NO = (noS*)malloc(sizeof(noS));
	NO = lista->inicio;
	int i = 0;
	char A[50000][15];
	while (NO != NULL) {
		A[i][0] = 0;
		strcpy(A[i], NO->info);
		NO = NO->proximo;
		i++;
	}

	int Y = PesquisaBS(A, termo, 0, i);
	if (Y != -1) {
		cout << Y << endl;
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

int distS(ListaS *lista, int doc) {
	noS* N = lista->inicio;
	int A = 0;
	while (N != NULL) {
		SubListaS* S = N->sublista;
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

int relevanciaS(noS* NO, ListaS * L, char palavras[]) {
	double i = 0;
	int A = 0;
	SubListaS* N1 = NO->sublista;
	int S = 0, U = 0;
	while (N1 != NULL) {
		A = A + 1;
		U++;
		S = S + U;
		N1 = N1->proximo;
	}
	i = log(NS) / A;
	N1 = NO->sublista;
	while (N1 != NULL) {
		int X = distS(L, N1->info);
		double F = (double)1 / (double)X;
		N1->Relevancia = F * S * (N1->count * i);
		N1 = N1->proximo;
	}
	return 1;
}