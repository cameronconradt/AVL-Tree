/*
 * Node.cpp
 *
 *  Created on: Mar 20, 2017
 *      Author: cameron
 */

#include "Node.h"
#include <iostream>
#ifndef NULL
#define NULL   ((Node *) 0)
#endif

Node::Node(int in) {
	// TODO Auto-generated constructor stub
	data = in;
	left = NULL;
	right = NULL;

}

Node::~Node() {
	// TODO Auto-generated destructor stub
	/*delete right;
	delete left;*/
}
int Node::getData() const
{
	return data;
}
NodeInterface * Node::getLeftChild() const
{
	return left;
}
NodeInterface * Node::getRightChild() const
{
	return right;
}
int Node::getHeight()
{
	int leftheight = 1;
	int rightheight = 1;
	if(left != NULL)
	{
		leftheight += left->getHeight();
	}
	if(right != NULL)
	{
		rightheight += right->getHeight();
	}
	if( (right == NULL) && (left == NULL))
	{
		return 1;
	}
	if (leftheight > rightheight)
		return leftheight;
	else
		return rightheight;
}

