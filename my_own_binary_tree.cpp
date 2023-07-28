#include <iostream>
#include <string>
using namespace std;

template<typename T1, typename T2>
class BinaryTree {

    private:

        template<typename T3, typename T4>
        class Node {

            public:

                /*
                Node:
                index - pointer to node data (key)
                data - value to which index points (value)
                left - pointer to children (left) node
                right - pointer to children (right) node
                */

                T3 index;
                T4 data;
                Node<T3, T4> *left;
                Node<T3, T4> *right;
                Node<T3, T4> *parent;

                Node(T3 index = T3(), T4 data = T4(), Node<T3, T4> *left = nullptr, Node<T3, T4> *right = nullptr, Node<T3, T4> *parent = nullptr) {
                    this->index = index;
                    this->data = data;
                    this->left = left;
                    this->right = right;
                    this->parent = parent;
                }

                void assingNodeInstance(Node<T3, T4> &otherNodeInstance) {
                    index = otherNodeInstance.index;
                    data = otherNodeInstance.data;
                    left = otherNodeInstance.left;
                    right = otherNodeInstance.right;
                    parent = otherNodeInstance.parent;
                }

                Node(Node<T3, T4> &otherNodeInstance) {
                    assingNodeInstance(otherNodeInstance);
                }

                ~Node() {
                    if (left != nullptr) {
                        delete left;
                        left = nullptr;
                    }

                    if (right != nullptr) {
                        delete right;
                        right = nullptr;
                    }
                }

                Node<T3, T4>& operator=(Node<T3, T4> &otherNodeInstance) {
                    assingNodeInstance(otherNodeInstance);
                    return *this;
                }

                bool operator==(Node<T3, T4> &otherNodeInstance) {
                    return index == otherNodeInstance.index;
                }

                bool operator!=(Node<T3, T4> &otherNodeInstance) {
                    return !operator==(otherNodeInstance);
                }

                bool isLeaf() {
                    return left == nullptr && right == nullptr;
                }
        };

        Node<T1, T2> *_root;

        Node<T1, T2>* reachLeaf(T1 index) {
            if (_root == nullptr) {
                throw runtime_error("There is no element with such index. "
                                    "This instance of binary tree is empty");
            }

            Node<T1, T2> *currentNode = _root;
            while (true) {
                if (index != currentNode->index) {
                    if (currentNode->isLeaf()) {
                        throw runtime_error("There is no element with such index");
                    } else if (index < currentNode->index) {
                        currentNode = currentNode->left;
                    } else {
                        currentNode = currentNode->right;
                    }
                } else {
                    return currentNode;
                }
            }
        }

    public:

        BinaryTree();
        ~BinaryTree();
        BinaryTree(BinaryTree<T1, T2> &otherBinaryTree);

        void pushNode(T1 index, T2 value);
        void popLeaf(T1 index);

        bool operator=(BinaryTree<T1, T2> &otherBinaryTree);
        bool operator==(BinaryTree<T1, T2> &otherBinaryTree);
        bool operator!=(BinaryTree<T1, T2> &otherBinaryTree);
        T2 operator[](T1 index);
};

template<typename T1, typename T2>
BinaryTree<T1, T2>::BinaryTree() {
    _root = nullptr;
}

template<typename T1, typename T2>
BinaryTree<T1, T2>::~BinaryTree() {
    if (_root != nullptr) {
        delete _root;
        _root = nullptr;
    }
}

template<typename T1, typename T2>
BinaryTree<T1, T2>::BinaryTree(BinaryTree<T1, T2> &otherBinaryTree) {
    _root = otherBinaryTree._root;
}

// template<typename T1, typename T2>
// void BinaryTree<T1, T2>::popLeaf(T1 index) {
//     Node<T1, T2> *leaf = reachLeaf(index);
//     if (leaf != _root) {
//         if (leaf->index > leaf->parent->index) {
//             delete leaf->parent->right;
//         } else if (leaf->index < leaf->parent->index) {
//             delete leaf->parent->left;
//         }
//     } else {
//         delete _root;
//     }
// }

template<typename T1, typename T2>
void BinaryTree<T1, T2>::pushNode(T1 index, T2 value) {
    if (_root == nullptr) {
        _root = new Node<T1, T2>(index, value);
        return;
    }

    Node<T1, T2> *currentNode = _root;
    while (true) {
        if (index == currentNode->index) {
            throw runtime_error("Binary tree already has node with such index");
        } else if (index < currentNode->index) {
            if (currentNode->left == nullptr) {
                currentNode->left = new Node<T1, T2>(index, value);
                currentNode->left->parent = currentNode;
                break;
            }
            
            currentNode = currentNode->left;
        } else {
            if (currentNode->right == nullptr) {
                currentNode->right = new Node<T1, T2>(index, value);
                currentNode->right->parent = currentNode;
                break;
            }

            currentNode = currentNode->right;
        }
    }
}

template<typename T1, typename T2>
T2 BinaryTree<T1, T2>::operator[](T1 index) {
    Node<T1, T2> *current = _root;
    while (current->index != index) {
        if (current->isLeaf()) {
            throw runtime_error("There is no element with given index");
        }

        if (index < current->index) {
            current = current->left;
        } else if (index > current->index) {
            current = current->right;
        }
    }

    return current->data;
}

int main() {
    BinaryTree<int, string> binaryTree;
    binaryTree.pushNode(5, "Hello");
    binaryTree.pushNode(8, "World");
    binaryTree.pushNode(7, "Wenamechainasama");
    binaryTree.pushNode(4, "Boom");


    cout << binaryTree[4] << endl;
    // binaryTree.popLeaf(5);

    cout << binaryTree[5] << endl;
}
