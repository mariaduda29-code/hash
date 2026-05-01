/* FUNÇÃO DE RECUPERAÇÃO 
    recuperaValor(chave):
    posicao <- calculaHash(chave); // chave vira posicao
    elemento <- tabela[posicao].busca(chave); // vai ate a posicao indicada e procura na lista a chave 
    se(elemento = NAOENCONTRADO){
        geraERRO("ITEM NAO ENCONTRADO");
    }senao{
    efetuaAcao(elemento.valor) // se foi encontrado, acessa o dado que estava junto com a chave e realiza o que for necessario 
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

    // FUNÇÃO RECUPERAR
    void recuperaValor(int chave){
        int posicao = calculaHash(chave);
        No* atual = tabela[posicao]; // percorre a lista daquela posicao
        while(atual!=nullptr){
            if(atual -> chave==chave){
                cout << "O valor da chave " << chave << " eh " << atual -> valor << endl;

            }
            atual = atual->proximo; // vai para o proximo 
        }
        cout << "ERRO: ITEM " << chave << " NAO ENCONTRADO!" << endl;
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
