#ifndef STL_H_INCLUDED
#define STL_H_INCLUDED
using namespace std;

template <typename T>
class List {
private:
    // Clase privada para los nodos de la lista
    class Node {
    public:
        T data;  // Dato almacenado en el nodo
        Node* prev;  // Puntero al nodo anterior
        Node* next;  // Puntero al siguiente nodo

        // Constructor del nodo
        Node(const T& value) {
            this->data = value;
            this->prev = NULL;
            this->next = NULL;
        }
    };

    Node* head;  // Puntero al primer elemento de la lista
    Node* tail;  // Puntero al último elemento de la lista
    size_t size;  // Tamaño de la lista

public:
    // Constructor de la lista
    List(){
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    // Destructor para liberar la memoria de los nodos
    ~List() {
        this->clear();
    }

    // Insertar al final de la lista (push_back)
        void push_back(const T& value) {
        Node* newNode = new Node(value);  // Aseguramos que la memoria sea asignada correctamente
        if (tail) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            head = tail = newNode;
        }
        ++size;  // Aumentamos el tamaño de la lista
        }

    // Insertar al inicio de la lista (push_front)
    void push_front(const T& value) {
        Node* newNode = new Node(value);
        if (head) {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        } else {
            head = tail = newNode;
        }
        ++size;
    }
    void insertarAlFinal(const T& value) {
        Node* newNode = new Node(value);  // Crear un nuevo nodo
        if (tail) {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            head = tail = newNode;  // Si la lista está vacía, el nuevo nodo es tanto el head como el tail
        }
        ++size;  // Incrementar el tamaño de la lista
    }

    // Eliminar el último elemento (pop_back)
    void pop_back() {
        if (!tail) return;

        Node* temp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = NULL;
        } else {
            head = NULL;
        }
        delete temp;
        --size;
    }

    // Eliminar el primer elemento (pop_front)
    void pop_front() {
        if (!head) return;

        Node* temp = head;
        head = head->next;
        if (head) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        delete temp;
        --size;
    }

    // Mostrar los elementos de la lista
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void clear() {
            Node* current = head;
            while (current != NULL) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
            head = tail = NULL;
            size = 0;
    }
    // Obtener el tamaño de la lista
    size_t get_size() {
        return size;
    }
     // Clase de iterador
    class Iterator {
    private:
        Node* current;

    public:
        // Constructor del iterador
        Iterator(Node* node) : current(node) {}

        // Operador de desreferencia (*)
        T& operator*()  {
            return current->data;
        }

        // Operador de incremento (++)
        Iterator& operator++() {
            if (current) current = current->next;
            return *this;
        }

        // Operador de comparación (== y !=)
        bool operator!=(const Iterator& other)  {
            return current != other.current;
        }
        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };


    // Métodos para obtener iteradores
    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(NULL);
    }
};


#endif // STL_H_INCLUDED
