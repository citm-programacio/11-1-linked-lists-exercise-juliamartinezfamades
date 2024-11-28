#include <iostream>
using namespace std;

class List {
public:
    List();
    ~List();

    void push_front(const int& value);
    void push_back(const int& value);
    void insert(unsigned int position, const int& value);
    void pop_front();
    void pop_back();
    void erase(unsigned int position);
    void clear();

    void print() const;

    int& front();
    int& back();
    int& value_at(unsigned int position);
    bool empty() const;
    unsigned int size() const;

private:
    struct Node {
        int value;
        Node* next;
        Node* prev;
    };

    Node* first = nullptr;
    Node* last = nullptr;
    unsigned int num_elems = 0;
};

List::List() : first(nullptr), last(nullptr), num_elems(0) {}

List::~List() {
    clear();
}

void List::push_front(const int& value) {
    Node* new_node = new Node{ value, first, nullptr };
    if (first) {
        first->prev = new_node;
    }
    else {
        last = new_node;  
    }
    first = new_node;
    num_elems++;
}

void List::push_back(const int& value) {
    Node* new_node = new Node{ value, nullptr, last };
    if (last) {
        last->next = new_node;
    }
    else {
        first = new_node; 
    }
    last = new_node;
    num_elems++;
}

void List::insert(unsigned int position, const int& value) {
    if (position == 0) {
        push_front(value);
    }
    else if (position >= num_elems) {
        push_back(value);
    }
    else {
        Node* new_node = new Node{ value, nullptr, nullptr };
        Node* current = first;
        for (unsigned int i = 0; i < position; i++) {
            current = current->next;
        }
        new_node->next = current;
        new_node->prev = current->prev;
        if (current->prev) {
            current->prev->next = new_node;
        }
        current->prev = new_node;
        num_elems++;
    }
}

void List::pop_front() {
    if (first) {
        Node* temp = first;
        first = first->next;
        if (first) {
            first->prev = nullptr;
        }
        else {
            last = nullptr;  
        }
        delete temp;
        num_elems--;
    }
}

void List::pop_back() {
    if (last) {
        Node* temp = last;
        last = last->prev;
        if (last) {
            last->next = nullptr;
        }
        else {
            first = nullptr;  
        }
        delete temp;
        num_elems--;
    }
}

void List::erase(unsigned int position) {
    if (position < num_elems) {
        Node* current = first;
        for (unsigned int i = 0; i < position; i++) {
            current = current->next;
        }
        if (current->prev) {
            current->prev->next = current->next;
        }
        else {
            first = current->next;  
        }
        if (current->next) {
            current->next->prev = current->prev;
        }
        else {
            last = current->prev;  
        }
        delete current;
        num_elems--;
    }
}

void List::clear() {
    while (first) {
        pop_front();
    }
}

void List::print() const {
    Node* current = first;
    while (current) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

int& List::front() {
    return first->value;
}

int& List::back() {
    return last->value;
}

int& List::value_at(unsigned int position) {
    Node* current = first;
    for (unsigned int i = 0; i < position; i++) {
        current = current->next;
    }
    return current->value;
}

bool List::empty() const {
    return first == nullptr;
}

unsigned int List::size() const {
    return num_elems;
}

int main() {
    List lista;

    lista.insert(0, 10);  
    lista.print();

    lista.insert(1, 20);  
    lista.print();

    lista.insert(1, 15);  
    lista.print();

    lista.insert(2, 25);  
    lista.print();

    lista.insert(0, 5);   
    lista.print();

}
