/*
 * Node.h
 *
 *  Created on: Mar 20, 2017
 *      Author: cameron
 */

#ifndef NODE_H_
#define NODE_H_

#include "NodeInterface.h"
class Node: public NodeInterface {
	friend class BST;
public:
	Node(int in);
	virtual ~Node();
	virtual int getData() const;
	virtual NodeInterface * getLeftChild() const;
	virtual NodeInterface * getRightChild() const;
	int getHeight();
private:
	int data;
	Node * left;
	Node * right;

};


#endif /* NODE_H_ */
