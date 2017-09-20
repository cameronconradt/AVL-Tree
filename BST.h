/*
 * BST.h
 *
 *  Created on: Mar 20, 2017
 *      Author: cameron
 */

#ifndef BST_H_
#define BST_H_

#include "BSTInterface.h"
#include "Node.h"

class BST: public BSTInterface {
public:
	BST();
	virtual ~BST();
	NodeInterface * getRootNode()const;
	bool add(int data);
	bool remove(int data);
	void clear();
protected:
	bool addhelper(int item, Node*& local_root);
	bool find(int data, NodeInterface* test);
	bool removehelper( Node*& local_root, int item);
	Node* root;
	void RecurClear(Node*& node);
	bool replace_parent(Node*& old_root, Node*& local_root);
	void rotate_right(Node*& local_root);
	void rotate_left(Node*& local_root);
	bool balance(Node*& local_root);
	void double_right(Node*& local_root);
	void double_left(Node*& local_root);
	int heavy(Node*& local_root);
};

#endif /* BST_H_ */
