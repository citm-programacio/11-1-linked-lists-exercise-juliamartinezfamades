#include <iostream>
using namespace std;

class DoublyLinkedList
{
private:
    // 1. Estructura del nodo
    struct Node
    {
        int value;
        Node* prev; //puntero al nodo anterior
        Node* next;//puntero al nodo siguiente
    };
    // 2. Atributos de la lista
    Node* first; // puntero al primer nodo
    Node* last;  // puntero al ultimo nodo
    unsigned int num_elems; // num de elementos de la lista

public:
    // 3. Constructor
    DoublyLinkedList() : first(nullptr), last(nullptr), num_elems(0) {} //la lista esta vacia, por eso es nullptr


    // Poner elemento al principio de la lista
    void push_front(const int& value)
    {
        if (num_elems == 0)  //si la lista esta vacia, se pone el elemento desde el main ( crea un nodo), y el anterior y el posterior estan vacios
        {
            first = last = new Node{ value, nullptr, nullptr };
        }
        else //si hay elementos, crea un nodo con el valor del main, el anterior esta vacio, porque llo pone al pprincipio y el posterior es el first
        {
            Node* node = new Node{ value, nullptr, first };
            first->prev = node; // el first pasa a ser el prev, el priemr elemento de la lisat
            first = node;
        }
        num_elems++; //se suam un elemento al numero
    }

    // lo mismo pero el elemento va al final
    void push_back(const int& value)
    {
        if (num_elems == 0)
        {
            first = last = new Node{ value, nullptr, nullptr };
        }
        else
        {
            Node* node = new Node{ value, last, nullptr };
            last->next = node;
            last = node;
        }
        num_elems++;
    }

    // insertat en una posicion especifica
    void insert(unsigned int position, const int& value)
    {
        if (position > num_elems)
        {
            cout << "Position out of range." << endl; //si la posicion supera la lista
            return;
        }

        if (position == 0) //si la quiere poner en la primera posicion llama a push_front
        {
            push_front(value);
            return;
        }
        else if (position == num_elems) //si la quiere poner en la ultima posicion llama a push_back
        {
            push_back(value);
            return;
        }

        Node* current = first;
        for (unsigned int i = 0; i < position - 1; i++)
        {
            current = current->next;
        }

        Node* node = new Node{ value, current, current->next }; //preguntar current
        current->next->prev = node;
        current->next = node;

        num_elems++;
    }

    // preguntar
    void print()
    {
        Node* current = first;
        while (current)
        {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    DoublyLinkedList list;

    // Insert elements and print the list after each operation
    cout << "Inserting 10 at the front:" << endl;
    list.push_front(10);
    list.print();

    cout << "Inserting 20 at the back:" << endl;
    list.push_back(20);
    list.print();

    cout << "Inserting 30 at position 1:" << endl;
    list.insert(1, 30);
    list.print();

    cout << "Inserting 40 at position 0 (front):" << endl;
    list.insert(0, 40);
    list.print();

    cout << "Inserting 50 at position 4 (back):" << endl;
    list.insert(4, 50);
    list.print();

    return 0;
}