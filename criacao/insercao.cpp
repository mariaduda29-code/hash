/* FUNÇÃO INSERÇÃO
    // o valor é o dado e a chave é o identificador dele 
    // a chave determinada onde o dado vai estar na tabela 
    insereElemento(valor,chave):
        posicao <- calculaHash(chave); // a chave vira uma posição  
        lista <- tabela[posicao]; // acessa o vetor na posição calculada e pega a lista encadeada que esta la 
        se (lista.busca(chave) = NAOENCONTRADO){
            lista.insereNoFim(valor,chave);
        }senao{
            geraErro("ITEM JÁ ESTA NA TABELA");
        }
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
