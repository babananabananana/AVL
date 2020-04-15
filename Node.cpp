#include "Node.h"
#include <iostream>

Node::Node(void) {
    data = 0;
    left = nullptr;
    right = nullptr;
    depth = 0;
}

Node::Node(int newData) {
    data = newData;
    depth = 1;
    left = nullptr;
    right = nullptr;
}

Node::~Node(){

}

int Node::getData() const {
    return data;
}

Node *Node::getLeftChild() const {
    if (left) return left;
    else return nullptr;
}

Node *Node::getRightChild() const {
    if (right) return right;
    else return nullptr;
}

int Node::getHeight() {
    return depth;
}

void Node::setRight(Node *right) {
    Node::right = right;
}

void Node::setLeft(Node *left) {
    Node::left = left;
}

void Node::setData(int data) {
    Node::data = data;
}

void Node::setHeight(int height) {
    if(!this->getLeftChild() && !this->getRightChild()){
        depth = 1;
    }
    else if (!left){
        depth = right->getHeight() + 1;
    }
    else if (!right){
        depth = left->getHeight() + 1;
    }
    else{
        depth = max(right->getHeight(), left->getHeight()) + 1;
    }
}

