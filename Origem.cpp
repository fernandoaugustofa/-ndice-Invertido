#include "Bibliotecas.h"
#include "TadListaDuplamente.h"
#include "TadListaSimplesmente.h"
int main(int argc, char** argv) {
	int A;
	int B = 0;
	char arquivo[20000];
	if (strcmp(argv[2], "Dupla") == 0) {
		cout << "Lista Duplamente" << endl;
		Lista* lista = (Lista*)(malloc(sizeof(Lista)));
		lista->inicio = NULL;
		B = B + carregar(argv[1], lista);
		do {
			arquivo[0] = 0;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "Opcoes:" << endl;
			cout << "1--- Carregar o arquivo;" << endl;
			cout << "2--- Imprimir a lista;" << endl;
			cout << "3--- Pesquisar documento;" << endl;
			cin >> A;
			if (A == 1) {
				cout << "Digite o caminho do arquivo:" << endl;
				cin >> arquivo;
				B = B + carregar(arquivo, lista);
			}
			else if (A == 2) {
				Imprimir(lista);
			}
			else if (A == 3) {
				cout << "Digite a palavra" << endl;
				cin >> arquivo;
				no* Y = PesquisaBinaria(lista, arquivo, B);
				if (Y != NULL) {
					relevancia(Y, lista, arquivo);
					bublesortsublista(Y->sublista, Y);
					SubLista* S = Y->sublista;
					cout << "Palavra : " << Y->info;
					int L = atoi(argv[3]);
					while (S != NULL && L != 0)
					{
						cout << ", (" << S->info << " : " << S->count << " : Relevancia " << S->relevancia << ")";
						S = S->proximo;
						L--;
					}
				}
				else {
					cout << "Nao Encontrado" << endl;
				}
			}
			else if (A == 4) {
				cout << "A lista tem " << B << " palavras" << endl;
			}
		} while (true);
	}
	else if (strcmp(argv[2], "Simples") == 0) {
		cout << "Lista Simplismente" << endl;
		ListaS* lista = (ListaS*)(malloc(sizeof(ListaS)));
		lista->inicio = NULL;
		B = B + carregarS(argv[1], lista);
		do {
			arquivo[0] = 0;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "Opcoes:" << endl;
			cout << "1--- Carregar o arquivo;" << endl;
			cout << "2--- Imprimir a lista;" << endl;
			cout << "3--- Pesquisar documento;" << endl;
			cin >> A;
			if (A == 1) {
				cout << "Digite o caminho do arquivo:" << endl;
				cin >> arquivo;
				B = B + carregarS(arquivo, lista);
			}
			else if (A == 2) {
				ImprimirS(lista);
			}
			else if (A == 3) {
				cout << "Digite a palavra" << endl;
				cin >> arquivo;
				noS* Y = PesquisaBinariaS(lista, arquivo, B);
				if (Y != NULL) {
					relevanciaS(Y, lista, arquivo);
					bublesortsublistaS(Y->sublista, Y);
					SubListaS* S = Y->sublista;
					cout << "Palavra : " << Y->info;
					int L = atoi(argv[3]);
					while (S != NULL && L != 0)
					{
						cout << ", (" << S->info << " : " << S->count << " : Relevancia " << S->Relevancia << ")";
						S = S->proximo;
						L--;
					}
				}
				else {
					cout << "Nao Encontrado" << endl;
				}
			}
			else if (A == 4) {
				cout << "A lista tem " << B << " palavras" << endl;
			}
		} while (true);
	}
	system("PAUSE");
}



