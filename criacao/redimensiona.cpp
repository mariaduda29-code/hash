/* FUNÇÃO DE REDIMENSIONAMENTO 
    redimensiona(novaCapacidade):
        tabelaAux ← alocaVetorDeListas(novaCapacidade); // cria uma nova tabela 
        para (cada elemento em tabela) {
        // percorre cada elemento da tabela antiga, entra na lista e reinsere cada item na nova 
	        insereElementoNaTabela(elemento,tabelaAux);
        }       
    capacidade ← novaCapacidade; // atualiza a capacidade
    apaga(tabela); // apaga a antiga 
    // redireciona a tabela para a com nova capacidade
    tabela ← tabelaAux; // tabela aponta para o novo endereço da tabelaAuc
*/
#include <iostream>
using namespace std;
struct No{ // cada no da lista encadeada 
    int chave;
    int valor;
    No* proximo;
};

struct Hash{
    int capacidade;
    No** tabela; // um vetor de ponteiros para os nos
    // FUNÇÃO CRIAR 
    Hash(int cap){
        capacidade = cap;
        tabela = new No*[capacidade]; 
        for (int i =0; i < capacidade; i++){
            tabela[i] = nullptr;
        }
    } 

    // FUNÇÃO AUXILIAR QUE CALCULA A CHAVE 
    int calculaHash(int chave){ 
        // h(k) = k mod m, h(k) e a posiça, k chave, m capacidade
        return chave%capacidade; // retorna posição 
    }

void redimensiona (int novaCapacidade){
    No** tabelaAux = new No*[novaCapacidade];
    for(int i=0; i < novaCapacidade; i++){
        tabelaAux[i]=nullptr;
    }

    int capacidadeAntiga = capacidade;

    for(int i=0; i < capacidadeAntiga; i++){
        No* atual = tabela[i];
        while(atual != nullptr){
            int chave = atual -> chave;
            int valor = atual -> valor;

            int novaPos = chave%capacidade;
            No* novoNo = new No{chave, valor, tabelaAux[novaPos]};
            tabelaAux[novaPos] = novoNo;

            No* temp = atual;
            atual= atual -> proximo;
            delete temp;

        }
    }
    delete[] tabela;
    tabela = tabelaAux ;
    capacidade = novaCapacidade;
}
// FUNÇÃO INSERIR 
    void insereElementos(int valor, int chave){
        int posicao = calculaHash(chave);
        No* lista = tabela[posicao];

        // verificar se ja existe, buscar aquela chave 
        No* atual = lista;
        while(atual != nullptr){
            if(atual -> chave = chave){
                cout << "ERRO: ITEM " << chave << " JA ESTA NA TABELA" << endl;
                return;
            }
            atual= atual -> proximo;
        }
        // criar e colocar no inicio
        No* novo = new No;
        novo -> chave;
        novo -> valor;
        novo -> proximo = tabela[posicao];
        tabela[posicao] = novo;

        cout << "INSERIDO " << chave << " NA POSICAO " << posicao << endl;
    }

    // FUNÇAO DESTRUIR 
    ~Hash(){
        for(int i=0; i < capacidade; i++){
            No* atual = tabela[i];
            while(atual = nullptr){
                No* aux = atual;
                atual = atual -> proximo;
                delete aux;
            }
        }
        delete[]tabela;
        cout << "MEMORIA LIBERADA" << endl;
    }
};
int main (){
    Hash* minhaHash = new Hash(5);

    minhaHash -> insereElementos(100, 10); // 10%5 = 0, 100 na posicao 0;
    minhaHash -> insereElementos(200, 15); // 10%5 =0, colisão abre lista 
    minhaHash -> insereElementos(300, 10); // chave repetida

    delete minhaHash;

    return 0;
}
