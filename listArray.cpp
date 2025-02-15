#include <iostream>
using namespace std;

// Trabalhamos com uma lista para manipular diversos tipos de dados abstratos.
// Construir a lista: O(1)
// Inserção:
// Pior caso O(n), quando o cursor está no começo da lista e todos os elementos tem que ser deslocados para a direita.
// Melhor caso: O(1), quando o cursor está no final da lista.
// caso médio: O(n), quando o cursos está numa posição intermédiaria.
// Remoção:
// Pior caso O(n), quando o cursor está no começo da lista e todos os elementos tem que ser deslocados para a direita.
// Melhor caso: O(1), quando o cursor está no final da lista.
// caso médio: O(n), quando o cursos está numa posição intermédiaria.


template <typename E> // Alocação dinamica de tipos, seja float, int, string, deixando a necessidade de definir o tipo de lado.
class List {
private:

    int maxSize; // Tamanho máximo da lista
    int listSize; // Número atual de elementos na lista.
    int current; // Cursor da lista, pra manter o controle
    E* listArray; // Ponteiro pra um array de elementos.
public:
    List(int size){
        maxSize = size;
        listSize = current = 0;
        listArray = new E[size];
    }

    ~List() {
        delete[] listArray;
    }

    // retorna o tamanho da lista.
    void length(){
        cout << listSize << endl;
    }

    // Retorna o indice que o cursor está
    void currentPos(){
        cout << current << endl;
    }
    void clear(){
        delete[] listArray;
    }

    // Insere um elemento no início da lista. É sempre no início.
    void insert(const E& item){
        // Checa se a lista está cheia.
        if (listSize >= maxSize) {
            cout << "vai rolar nao, padrinho" << endl;
        }

        // Move os elementos atuais do array para a direita, começando do fim.
        for (int i = listSize; i > current; i--) {
            listArray[i] = listArray[i-1];
        }
        // Insere o item na posição atual e aumenta o tamanho atual da lista.
        listArray[current] = item;
        listSize++;
    }

    // Insere um elemento no final da lista.
    void append(const E& item){
        if (listSize >= maxSize){
            cout << "Tu tem burro?" << endl;
        }
        listArray[listSize++] = item;
    }


    // Irá remover o elemento que o cursor está apontando.
    E remove() {
        if (current < 0 || current >=listSize) {
            cout << "vai rolar nao, padrinho" << endl;
        }

        E it = listArray[current];

        for (int i = current; i < listSize - 1; i++) {
            listArray[i] = listArray[i + 1];
        }
        listSize--;
        return it;
    }

    // "Bloco" de movimentações para o cursor.
    void moveToStart() {
        current = 0;
    }

    void moveToEnd() {
        current = listSize;
    }

    // Move o cursos pra um indice desejado.
    void moveToPos(int pos){
        if (pos < 0 || pos > listSize){
            cout << "tu sois burrinho em?" << endl;
        }
        current = pos;
    }

    void previous() {
        if (current != 0) {
            current --;
        }
    }
    void next() {
        if (current < listSize) {
            current++;
        }
    }

    void display() {
        for (int i = 0; i < listSize; i++){
            cout << listArray[i] << " ";
        }
        cout << endl;
    }
};

int main(){

    List<int> minhaLista(5);

    // Teste de inserção de elementos:
    minhaLista.insert(1);
    minhaLista.insert(5);
    minhaLista.append(6);
    minhaLista.append(3);
    minhaLista.insert(2);
    minhaLista.display();

    // Teste de remoção de elementos:
    // Nesse ponto, o cursor está no início, então removerá o primeiro elemento.
    minhaLista.remove();
    minhaLista.display();
    minhaLista.moveToEnd();
    minhaLista.moveToPos(1);
    minhaLista.remove();
    minhaLista.display();
    minhaLista.moveToStart();
    minhaLista.remove();
    minhaLista.display();

    return 0;
}