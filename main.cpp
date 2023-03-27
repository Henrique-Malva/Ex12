#include <iostream>
#include <string.h>
#include <cstdlib>
#include <iomanip>

using namespace std;

#define size 15

typedef struct{
    int nr;
    float alt;
    string nac;
    char nome[51];
}ficha;

void init(ficha* tab);
int compareSTR(const void* a,const void* b);
int compareCC(const void* a, const void* b);
int pesquisaBinaria(ficha val[], int tab[], int comp, int valor);
void ordenacaoInsercao(ficha v[], int index[], int n);
void printSTR(ficha *tab);
void printSTR2(ficha *tab, int *ind);

int main()
{
    cout << "Exercicio 12\n\n" << endl;

    ficha tab[size]={};
    int index[size]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    int pesq, res;

    cout <<endl<<endl;
    init(tab);
    qsort(tab,size,sizeof(ficha),compareSTR);
    ordenacaoInsercao(tab,index, 15);


    printSTR(tab);
    printSTR2(tab,index);

//    cout << tab[0].nr << endl; //somente para apresentar um nr que existe (para testar)
//    do {
//        cout << "nr de CC a pesquisar (0 para terminar): ";
//        cin>>pesq;
//        if(pesq!=0){ // só executa a pesquisa se numero recebido não for 0
//            res=pesquisaBinaria(tab,index,size,pesq);
//            if (res==-1) {
//                cout << "\nNao ha ninguem com esse numero\n" << endl;
//            }
//            else{
//                int i=0;
//                while(tab[res].nome[i]!=0){ //encontra o tamanho do nome para poder dar o espaçamento certo na apresentação
//                    i++;
//                }
//                cout << "\nnumero: " << left << setw(6) << tab[res].nr << "nome: " << setw(i+2) << tab[res].nome << "altura: " << setw(6) << tab[res].alt << "nacionalidade: " << tab[res].nac << endl << endl;
//            }
//        }
//    } while (pesq!=0);
    return 0;
}

void printSTR(ficha *tab){ //something wrong ain't right
    for (int i = 0; i < size; ++i) {
            cout <<i<<"  "<<tab[i].nome;

            cout << endl;
    }
}

void printSTR2(ficha *tab, int *ind){ //something wrong ain't right

    for (int k = 0; k < size; ++k) {
        cout <<ind[k] <<" "<< tab[ind[k]].nr<< endl;
    }
}

void init(ficha *tab){ // inicialização dos campos da struct
    char nomes[][12] = {"Joao", "Maria", "Alberto", "Josefina", "Zacarias", "Malato", "Mauricia", "Josefa", "Malaquias", "Tome" };
    int k;
    for (int i = 0; i < size; i++) {

        tab[i].nr = (rand() % 1001) + 9000; //numero de cc (de 9 a 10 mil)
        tab[i].alt = (rand() % 121 + 100)/100.0; //altura
        //inicialização dos nomes
        k = (rand() % 9); //escolhe indice do nome na lista nomes
        for (int j = 0; j < 12; ++j) {
            tab[i].nome[j]= nomes[k][j];
        }

        tab[i].nac = "pt"; //tudo nacional, pq nacional é bom
    }
}

int compareSTR(const void* a,const void* b){ //comparação das strings de nome para ter a tabela por ordem alfabética
    return strcmp(((ficha *)a)->nome,((ficha *)b)->nome);
}

void ordenacaoInsercao(ficha v[], int index[], int n) {
 for (int i = 1; i < n; i++) { // n-1 iterações
 ficha aux = v[index[i]]; // elemento a inserir copiado para var temporaria
 int j; // vai conter índice onde inserir
 for (j = i; (j > 0) && (aux.nr < v[index[j-1]].nr); j--) // desloca elementos para direita
 index[j] = index[j-1]; // ate’ chegar à posição de insercao
 index[j] = i; // insere elemento no índice j
 }
}

int pesquisaBinaria(ficha val[],int tab[], int comp, int valor){ //pesquisa binaria pela tabela de indices
    int inicio = 0;
    int fim = comp - 1;
    while (inicio <= fim){
        int meio = (inicio+fim)/2;
        if (valor == val[tab[meio]].nr) return tab[meio]; // pesquisa o elemento da tab de structs de indice guardado na posição meio do array de indices
        else
            if (valor > val[tab[meio]].nr)
                inicio = meio + 1;
            else
                fim = meio - 1;
    }
    return -1;
}
