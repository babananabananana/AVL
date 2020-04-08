//
// Created by Ethan Low on 4/7/20.
//

#include "AVL.h"

NodeInterface *AVL::getRootNode() const {
    return local_root;
}

bool AVL::add(int data) { // Add copied from BST lab :)
	if (local_root == nullptr) {
		local_root = new Node(data);
		return true;
	}
	Node* cur = local_root;
	return add_wrapped(cur, data);
}
bool AVL::add_wrapped(Node* cur, int data) {
	if (cur == nullptr) {
		cur = new Node(data);
		return true;
	}
	else if (cur->getData() == data) {
		return false;
	}
	else if (cur->getData() < data) {
		if (cur->getRightChild() == nullptr) {
			cur->setRight(new Node(data));
			return true;
		}
		else return add_wrapped(cur->getRightChild(), data);
	}
	else if (cur->getData() > data) {
		if (cur->getLeftChild() == nullptr) {
			cur->setLeft(new Node(data));
			return true;
		}
		else return add_wrapped(cur->getLeftChild(), data);
	}
	return false;
}

bool AVL::remove(int data) {
	if (local_root == nullptr) {
		return false;
	}
	else {
		return remove_wrapped(local_root, data);
	}
}

bool AVL::remove_wrapped(Node* &local_root, int toRemove) {
    if (local_root == nullptr) {
		return false;
	}
	else {
		if (toRemove < local_root->getData()) {
		    local_root = local_root->getLeftChild();
			return remove_wrapped(local_root, toRemove);
		}
		else if (toRemove > local_root->getData()) {
		    local_root = local_root->getRightChild();
			return remove_wrapped(local_root, toRemove);
		}
		else { // If toRemove is found
			Node* old_root = local_root;
			if (local_root->getLeftChild() == nullptr) {
				local_root = local_root->getLeftChild();
			}
			else {
			    Node* temp = old_root->getLeftChild();
				replace_parent(old_root, temp);
			}
//			delete old_root;
			return true;
		}
	}
return false;
}

void AVL::replace_parent(Node*& old_root, Node*& local_root) {
	if (local_root->getRightChild() != nullptr) {
	    local_root = local_root -> getRightChild();
		replace_parent(old_root, local_root);
	}
	else {
		old_root->setData(local_root->getData());
		old_root = local_root;
		local_root = local_root->getLeftChild();
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
//	delete (cur); //If i remove this it works, but it doesn't remove things.
return;
}


//int AVL::getHeight() {
//
//}

Node* AVL::AVLrightRotate(Node* y) {
	Node* x = y->getLeftChild();
	Node* T2 = x->getRightChild();
	//Finish me
	//updated heights

	return nullptr;
}

Node *AVL::AVLleftRotate(Node *x) {
    return nullptr;
}

int AVL::getBalance(Node *N) {
    return 0;
}

Node *AVL::insert(Node node, int key) {
    return nullptr;
}
