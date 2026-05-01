/*  FUNÇÃO CONSTRUTORA DA ESTRUTURA 
    criarHash(cap):
        //tamanho da tabela, guarda o valor de entradas que o vetor tera
        capacidade <- cap; 
        // vetor cada posição é o ponteiro para uma lista 
        tabela <- alocaVetordeListas(capacidade)

    FUNÇÃO DESTRUTORA DA ESTRUTURA
    destruirHash():
        // percorre o vetor, libera a memoria (nó por nó) e libera o vetor
        desalocaVetordeListas();  
*/
#include <iostream>
using namespace std;

class Hash{
public:
    int capacidade;
    int *tabela;

    Hash(int cap){
        capacidade = cap;
        tabela = new int[capacidade];

        cout << "Hash criada com a capacidade" << capacidade << endl;
    }

    ~Hash(){
        delete[]tabela;
        cout << "Memoria da tabela deletada" << endl;
    }
};
int main (){
    Hash* minhaHash = new Hash(10);

    cout << "Capacidade acessada via seta: " << minhaHash->capacidade << endl;

    delete minhaHash;

    return 0;
}
        
