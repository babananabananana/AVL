#include "Node.h"
#include <iostream>

Node::Node(void) {
    data = 0;
    left = nullptr;
    right = nullptr;
    height = 0;
}

Node::Node(int newData) {
    data = newData;
    //TODO: set height on the new node
    height = height;
    left = nullptr;
    right = nullptr;
}

Node::~Node(){

}

int Node::getData() const {
    return data;
}

Node *Node::getLeftChild() const {

    return left;
}

Node *Node::getRightChild() const {
    return right;
}

int Node::getHeight() {
    return height;
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
    Node::height = height;
}

