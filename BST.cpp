/*
 * BST.cpp
 *
 *  Created on: Mar 20, 2017
 *      Author: cameron
 */

#include "BST.h"
#include <iostream>
#include <stdlib.h>
#ifndef NULL
#define NULL   ((Node *) 0)
#endif

BST::BST() {
	// TODO Auto-generated constructor stub
	root = NULL;

}

BST::~BST() {
	// TODO Auto-generated destructor stub
	clear();
}
bool BST::find(int data, NodeInterface* test)
{
	if(test == NULL)
		return true;
	if(data == test->getData())
		return true;
	else if(data > test->getData())
	{
		if(test->getRightChild() != NULL)
		{
			if(find(data, test->getRightChild()))
					return true;
		}
	}
	else if(data < test->getData())
	{
		if(test->getLeftChild() != NULL)
		{
			if(find(data, test->getLeftChild()))
				return true;
		}
	}
	return false;
}
NodeInterface * BST::getRootNode() const
{
	return root;
}
bool BST::add(int data)
{
	return addhelper(data, root);
}
bool BST::addhelper(int item, Node*& local_root)
{	bool temp;
	if(local_root == NULL)
	{
		local_root = new Node(item);
		return true;
	}
	else if(item < local_root->data)
	{
		temp = addhelper(item, local_root->left);
		balance(local_root);
		return temp;
	}
	else if(item > local_root->data)
	{
		temp = addhelper(item, local_root->right);
		balance(local_root);
		return temp;
	}
	else
		return false;
}
bool BST::remove(int data)
{
	cout << "remove " << data << endl;
	return removehelper(root, data);
}
bool BST::removehelper( Node*& local_root, int item)
{
	bool temp;
	if(local_root == NULL)
		return false;
	else if(item >local_root->data)
	{
		if(local_root->right != NULL)
		{
			temp = removehelper(local_root->right, item);
			if(temp)
			{
			balance(local_root);
			}
			return temp;
		}
	}
	else if(item < local_root->data)
	{
		if(local_root->left != NULL)
		{
			temp = removehelper(local_root->left, item);
			if(temp)
			{
			balance(local_root);
			}
			return temp;
		}
	}
	else
	{
		if(local_root->right == NULL)
		{
			if(local_root->left == NULL)
			{
				//local_root = local_root->right;
				delete local_root;
				local_root = NULL;
				return true;
			}
			else
			{
				Node* temp = local_root;
				local_root = local_root->left;
				delete temp;
				temp = NULL;
				balance(local_root);
				return true;
			}
		}
		else if(local_root->left == NULL)
		{
			Node* temp = local_root;
			local_root = local_root->right;
			delete temp;
			temp = NULL;
			balance(local_root);
			return true;
		}
		else
		{
			return replace_parent(local_root, local_root->left);
		}
	}
	return false;
}
bool BST::replace_parent(Node*& old_root, Node*& local_root)
{bool temp;
	  if (local_root->right != NULL) {
	     temp = replace_parent(old_root, local_root->right);
	     balance(local_root);
	     return temp;
	  } else {
		 Node* temp = local_root;
	    old_root->data = local_root->data;
	    local_root = local_root->left;
	    delete temp;
	    temp = NULL;
	    balance(old_root);
	    /*
	    if(old_root->left != NULL)
	    	balance(old_root->left);
	    if(old_root->right != NULL)
	    	balance(old_root->right);*/
	    return true;
	  }
	  return false;
}
void BST::clear()
{
	RecurClear(root);
}
void BST::RecurClear(Node*& node)
{
	if(node != NULL)
	{
		if(node->left != NULL)
		{
			RecurClear(node->left);
		}
		if(node->right != NULL)
			RecurClear(node->right);
		delete node;
		node = NULL;
	}
}
void BST::rotate_right(Node*& local_root)
{
    Node* temp = local_root->left;
    local_root->left = temp->right;
    temp->right = local_root;
    local_root = temp;
    cout << "rotate_left" << endl;
}
void BST::rotate_left(Node*& local_root)
{
	Node* temp = local_root->right;
	local_root->right = temp->left;
	temp->left = local_root;
	local_root = temp;
	cout << "rotate_right" << endl;
}
void BST::double_left(Node*& local_root)
{
	rotate_right(local_root->right);
	rotate_left(local_root);
}
void BST::double_right(Node*& local_root)
{
	rotate_left(local_root->left);
	rotate_right(local_root);
}
bool BST::balance(Node*& local_root)
{
	int diff;
	int leftheight = 0;
	int rightheight = 0;
	if(local_root->left != NULL)
	{
		leftheight = local_root->left->getHeight();
	}
	if(local_root->right != NULL)
	{
		rightheight = local_root->right->getHeight();
	}
	diff = abs(leftheight - rightheight);
	if(diff > 1)
	{
		cout << "left =" << leftheight << endl;
		cout << "right =" << rightheight << endl;
		if(heavy(local_root) == 1)
		{
			if(heavy(local_root->left) == 2)
				double_right(local_root);
			else
				rotate_right(local_root);
		}
		else
		{
			if(heavy(local_root->right) == 1)
				double_left(local_root);
			else
				rotate_left(local_root);
		}
	}
	return false;
}
int BST::heavy(Node*& local_root)
{
	int leftheight = 0;
	int rightheight = 0;
	if(local_root->left != NULL)
	{
		leftheight = local_root->left->getHeight();
	}
	if(local_root->right != NULL)
	{
		rightheight = local_root->right->getHeight();
	}
	//left heavy == 1, right heavy == 2, equal == 0
	if(leftheight > rightheight)
		return 1;
	else if(rightheight > leftheight)
		return 2;
	else
		return 0;

}
