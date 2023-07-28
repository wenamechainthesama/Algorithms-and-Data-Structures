#include <iostream>
using namespace std;

template<typename T1>
class List {

    private:

        template<typename T2>
        class Node {

            public:

                Node<T2> *pNext;
                T2 data;

                Node<T2> assignNodeInstance(Node<T2> &otherNodeInstance){ 
                    this->data = otherNodeInstance.data;
                    this->pNext = otherNodeInstance.pNext;
                }

                Node(T2 data = T2(), Node *pNext = nullptr) {
                    this->data = data;
                    this->pNext = pNext;
                }

                Node(Node<T2>& otherNodeInstance) {
                    assingNode(otherNodeInstance);
                }

                ~Node() {
                    if (pNext != nullptr) {
                        delete pNext;
                        pNext = nullptr;
                    }
                }

                Node<T2>& operator=(Node<T2> &otherNodeInstance) {
                    assingNode(otherNodeInstance);

                    return *this;
                }

                bool operator==(Node<T2> &nodeInstance) {
                    return this->data == nodeInstance.data && this->pNext == nodeInstance.pNext;
                }
                
                bool  operator!=(Node<T2> &nodeInstance) {
                    return !Node<T2>::operator==(nodeInstance);
                }
        };

        Node<T1> *_head;
        int _size;

    public:

        List();
        ~List();
        List(List &otherListInstance); 

        void clear();
        void pop_back();
        void pop_front();
        void removeAt(int index);
        void push_back(T1 value);
        void push_front(T1 value);
        void insert(T1 value, int index);

        int getIndex(int value);
        int getSize() { return _size; }

        void assignListInstance(List<T1> &otherListInstance);

        T1& operator[](int index);
        bool operator==(List<T1> &otherListInstance);
        bool operator!=(List<T1> &otherListInstance);
        List<T1>& operator=(List<T1> &otherListInstance);
};

template<typename T1>
List<T1>::List() {
    _size = 0;
    _head = nullptr;
}

template<typename T1>
List<T1>::~List() {
    clear();
}

template<typename T1>
void List<T1>::assignListInstance(List<T1> &otherListInstance) {
    this->_size = otherListInstance._size;
    this->_head = otherListInstance._head;
}

template<typename T1>
List<T1>::List(List &otherListInstance) {
    assignListInstance(otherListInstance);
}

template<typename T1>
void List<T1>::insert(T1 value, int index) {
    if (index == 0) {
        push_front(value);
    } else if (index < 0) {
        throw runtime_error("Given index is less than zero. "
                            "There is no element with such index");
    } else if (index > _size) {
        throw runtime_error("Given index is bigger than size of list. "
                            "There is no element with such index");
    } else {
        Node<T1> *current = _head;
        int currentIndex = 0;
        while (true) {
            if (index == currentIndex + 1) {
                current->pNext = new Node<T1>(value, current->pNext);
                break;
            }
            current = current->pNext;
            currentIndex++;
        }
        _size++;
    }
}

template<typename T1>
void List<T1>::removeAt(int index) {
    if (index == 0) {
        this->pop_front();
    } else if (index < 0) {
        throw runtime_error("Index is less than zero. "
                            "There is no element with such index");
    } else if (index >= _size) {
        throw runtime_error("Index is bigger (or equal) than size of list. "
                            "There is no element with such index");
    } else {
        Node<T1> *current = _head;
        int currentIndex = 0;
        while (currentIndex + 1 != index) {
            current = current->pNext;
            currentIndex++;
        }

        Node<T1> *linkToNextNode = current->pNext->pNext;
        current->pNext = linkToNextNode;

        _size--;
    }

}

template<typename T1>
void List<T1>::pop_back() {
    removeAt(_size - 1);
}

template<typename T1>
int List<T1>::getIndex(int value) {
    Node<T1> *current = _head;
    int index = 0;

    while (current->data != value) {
        if (index + 1 == _size) {
            return -1;
        }

        current = current->pNext;
        index++;
    }

    return index;
}

template<typename T1>
void List<T1>::pop_front() {
    if (_head != nullptr) {
        Node<T1> *tempHead = _head;
        _head = _head->pNext;
        _size--;
    } else {
        throw runtime_error("There are no elements in list");
    }
}

template<typename T1>
void List<T1>::clear() {
    while (_size) {
        pop_front();
    }
}

template<typename T1>
void List<T1>::push_back(T1 value) {
    if (_head == nullptr) {
        _head = new Node<T1>(value);
    } else {
        Node<T1> *current = _head;

        while (current->pNext != nullptr) {
            current = current->pNext;
        }

        current->pNext = new Node<T1>(value);
    }

    _size++;
}

template<typename T1>
void List<T1>::push_front(T1 value) {
    _head = new Node<T1>(value, _head);
    _size++;
}

template<typename T1>
T1& List<T1>::operator[](int index) {
    if (index >= _size) {
        throw runtime_error("There is no element in list with such index. "
                            "Given index is bigger (or equal) than list size");
    } else if (index < 0) {
        throw runtime_error("There is no element in list with such index. "
                            "Given index is less than zero");
    }

    Node<T1> *current = _head;
    int nodesPassed = 0;
    while (nodesPassed != index) {
        current = current->pNext;
        nodesPassed++;
    }

    return current->data;
}

template<typename T1>
List<T1>& List<T1>::operator=(List<T1> &otherListInstance) {
    assignListInstance(otherListInstance);
    return *this;
}

template<typename T1>
bool List<T1>::operator==(List<T1> &otherListInstance) {
    if (_size != otherListInstance._size) {
        return false;
    }

    for (int i = 0; i < _size; i++) {
        if ((*this)[i] != otherListInstance[i]) {
            return false;
        }
    }

    return true;
}

template<typename T1>
bool List<T1>::operator!=(List<T1> &otherListInstance) {
    return !operator==(otherListInstance);
}


int main() {

}


/*
Code With C++:
1) Programming Language
2) Browser
3) Operating System
4) Compiler
5) Game engine
6) Libriry
7) Server
*/
