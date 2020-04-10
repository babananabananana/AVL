//
// Created by Ethan Low on 4/7/20.
//

#ifndef AVL_AVL_H
#define AVL_AVL_H

#include "AVLInterface.h"
#include "Node.h"
class AVL {

public:
    //Please note that the class that implements this interface must be made
    //of objects which implement the NodeInterface

    /*
    * Returns the root node for this tree
    *
    * @return the root node for this tree.
    */
    NodeInterface * getRootNode() const;

    /*
    * Attempts to add the given int to the AVL tree
    * Rebalances the tree if data is successfully added
    *
    * @return true if added
    * @return false if unsuccessful (i.e. the int is already in tree)
    */
    bool add(int data);

	bool add_wrapped(Node* cur, int data);
    /*
    * Attempts to remove the given int from the AVL tree
    * Rebalances the tree if data is successfully removed
    *
    * @return true if successfully removed
    * @return false if remove is unsuccessful(i.e. the int is not in the tree)
    */
    bool remove(int data);

	Node* findParentNode(Node* curr, int toRemove);
    /*
    * Removes all nodes from the tree, resulting in an empty tree.
    */
    void clear();

	void clear_wrapped(Node* cur);

	Node* AVLrightRotate(Node* y);
	Node* AVLleftRotate(Node* x);
	int getBalance(Node* N);
	Node* insert(Node node, int key);
	void replace_parent(Node*& old_root, Node*& local_root);

private:
	Node* local_root;
	//Node* root;

};


#endif //AVL_AVL_H
