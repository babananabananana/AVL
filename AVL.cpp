#include "AVL.h"



NodeInterface *AVL::getRootNode() const {
    return local_root;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}
bool AVL::add(int data) { // Add copied from BST lab :)
    if (local_root == nullptr) {
        local_root = new Node(data);
        return true;
    }
    addBool = true;
    Node* cur = local_root;
    local_root = add_wrapped(cur, data);
    return addBool;
}

Node* AVL::add_wrapped(Node* node, int data) {
    if (node == nullptr) {
        return (new Node(data));
    }
    else if (data < node->getData()) {
        node->setLeft(add_wrapped(node->getLeftChild(), data));
        node->setHeight(max(1 + node->getLeftChild()->getHeight(), node->getHeight()));
    }
    else if (data > node->getData()) {
        node->setRight(add_wrapped(node->getRightChild(), data));
        node->setHeight(max(1 + node->getRightChild()->getHeight(), node->getHeight()));
    }
    else { // data == node->getData()
        addBool = false;
        return node;
    }

    int balance = getBalance(node);
    //if balance indicates unbalance, then rotate
    //left left case
    if(balance > 1 && data < node->getLeftChild()->getData()){
        return AVLrightRotate(node);
    }
    //right right case
    if(balance < -1 && data > node->getRightChild()->getData()){
        return AVLleftRotate(node);
    }
    //left right case
    if(balance > 1 && data > node -> getLeftChild() -> getData()){
        node -> setLeft(AVLleftRotate(node->getLeftChild()));
        return AVLrightRotate(node);
    }
    //right left case
    if(balance < -1 && data < node -> getRightChild() -> getData()){
        node -> setRight(AVLrightRotate(node->getRightChild()));
        return AVLleftRotate(node);
    }

    return node;
}

bool AVL::remove(int data) {
    if (local_root == nullptr) {
        return false;
    }
    Node* toRemove = local_root;
    delBool = true;
    local_root = remove_wrapped(toRemove, data);
    return delBool;
}

//update depth
//        node->depth = 1 + max(depth(node->left), depth(node->right));
Node* AVL::remove_wrapped(Node* node, int data) {
    if (node == nullptr) {
        delBool = false;
        return nullptr;
    }
    else if (data < node -> getData()){
        node->setLeft(remove_wrapped(node->getLeftChild(), data));
    }
    else if (data > node -> getData()){
        node->setRight(remove_wrapped(node->getRightChild(), data));
    }
    else { // data == node->getData()
        if ((node->getLeftChild() == NULL) && (node->getRightChild() == NULL)){
            delete node;
            node = NULL;
        }
        else if ((node->getLeftChild() == NULL) || (node->getRightChild() == NULL)){
            Node* temp = node->getLeftChild() ? node->getLeftChild() : node->getRightChild();
            *node = *temp;
            delete temp;
        }
        else { // there are 2 children
            Node* temp = maxValueNode(node->getLeftChild());
            node->setData(temp->getData());
            // Delete the inorder successor
            node->setLeft(remove_wrapped(node->getLeftChild(), temp->getData()));
        }

        if (!node){
            return node;
        }
    }

    node->setHeight(0);
    //get balance factor
    int balance = getBalance(node);
    //if balance indicates unbalance, then rotate
    //left left case
    if(balance > 1 && getBalance(node->getLeftChild()) >= 0){
        node = AVLrightRotate(node);
    }
    //right right case
    if(balance < -1 && getBalance(node->getRightChild()) <= 0){
        node = AVLleftRotate(node);
    }
    //left right case
    if(balance > 1 && getBalance(node->getLeftChild()) < 0){
        node -> setLeft(AVLleftRotate(node->getLeftChild()));
        node = AVLrightRotate(node);
    }
    //right left case
    if(balance < -1 && getBalance(node->getRightChild()) > 0){
        node -> setRight(AVLrightRotate(node->getRightChild()));
        node = AVLleftRotate(node);
    }

    return node;
}

Node* AVL::maxValueNode(Node* cur){
    Node* current = cur;

    // find the leftmost leaf */
    while (current->getRightChild() != NULL) {
        current = current->getRightChild();
    }

    return current;
}

void AVL::replace_parent(Node*& removeNode, Node*& replacee) {
    if (replacee->getRightChild() != nullptr) {
        replacee = replacee -> getRightChild();
        replace_parent(removeNode, replacee);
    }
    else {
        removeNode->setData(replacee->getData());
        removeNode = replacee;
        replacee = replacee->getLeftChild();
    }
}
void AVL::clear() {
    clear_wrapped(local_root);
    local_root = nullptr;
}

void AVL::clear_wrapped(Node* cur) {
    if (cur == nullptr) {
        return;
    }
    //    if (cur->getRightChild()){
    clear_wrapped(cur->getRightChild());
    //    }
    //    if(cur->getLeftChild()){
    clear_wrapped(cur->getLeftChild());
    //    }
//    delete (cur); //If i remove this it works, but it doesn't remove things.
return;
}


Node* AVL::AVLrightRotate(Node* y) {
    Node *x = y->getLeftChild();
    Node *T2 = x->getRightChild();

    //perform rotation
    x->setRight(y);
    y->setLeft(T2);
    y->setHeight(0);
    x->setHeight(0);

    //return new root
    return x;
}

Node *AVL::AVLleftRotate(Node *x) {
    Node *y = x->getRightChild();
    Node *T2 = y->getLeftChild();

    //perform rotation
    y->setLeft(x);
    x->setRight(T2);

    x->setHeight(0);
    y->setHeight(0);

    //return new root
    return y;
}

int AVL::getBalance(Node *N) {
    if (N == NULL)
        return 0;
    int rightHeight = 0;
    int leftHeight = 0;
    if(N->getLeftChild()){
        leftHeight = N->getLeftChild()->getHeight();
    }
    if(N->getRightChild()){
        rightHeight = N->getRightChild()->getHeight();
    }
    return (leftHeight - rightHeight);
}

Node *AVL::insert(Node node, int key) {
    return nullptr;
}
