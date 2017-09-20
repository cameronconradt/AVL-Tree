/*
 * AVL.h
 *
 *  Created on: Apr 4, 2017
 *      Author: cameron
 */

#ifndef AVL_H_
#define AVL_H_

#include "BST.h"
#include "AVLInterface.h"

class AVL: public AVLInterface {
public:
	AVL();
	virtual ~AVL();
	NodeInterface * getRootNode() const;
	bool add(int data);
	bool remove(int data);
	void clear();
private:
	BST mybst;
};

#endif /* AVL_H_ */
