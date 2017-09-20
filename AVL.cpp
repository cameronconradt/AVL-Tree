/*
 * AVL.cpp
 *
 *  Created on: Apr 4, 2017
 *      Author: cameron
 */

#include "AVL.h"

AVL::AVL() {
	// TODO Auto-generated constructor stub

}

AVL::~AVL() {
	// TODO Auto-generated destructor stub
}
NodeInterface* AVL::getRootNode() const
{
	return mybst.getRootNode();
}
bool AVL::add(int data)
{
	return mybst.add(data);
}
bool AVL::remove(int data)
{
	return mybst.remove(data);
}
void AVL::clear()
{
	mybst.clear();
}

