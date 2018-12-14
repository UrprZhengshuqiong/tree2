#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include "treeStructure.h"

Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent );
void growtree(Node *node);
void removeChildren(Node *parent);
void destroyTree(Node *node);


#endif // TREE_H_INCLUDED

