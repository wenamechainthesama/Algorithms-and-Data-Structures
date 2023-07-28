#include <iostream>
using namespace std;

template<typename T1>
class Stack {

    private:

        template<typename T2>
        class Node {

            public:

                T2 data;
                Node<T2> *pPrev;

                Node(T2 data = T2(), Node<T2> *pPrev = nullptr) {
                    this->data = data;
                    this->pPrev = pPrev;
                }

                ~Node() {
                    if (pPrev != nullptr) {
                        delete pPrev;
                        pPrev == nullptr;
                    }
                }
        };

        Node<T1> *_lastNode;

    public:

        Stack();
        ~Stack();

        void pop();
        void push(T1 value);

        T1 getLast();
};

template<typename T1>
Stack<T1>::Stack() {
    _lastNode = nullptr;
}

template<typename T1>
Stack<T1>::~Stack() {
    while (_lastNode != nullptr) {
        pop();
    }
}

template<typename T1>
T1 Stack<T1>::getLast() {
    return _lastNode->data;
}

template<typename T1>
void Stack<T1>::push(T1 value) {
    _lastNode = new Node<T1>(value, _lastNode);
}

template<typename T1>
void Stack<T1>::pop() {
    _lastNode = _lastNode->pPrev;
}

int main() {

}