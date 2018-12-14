#include "stdio.h"
#include "stdlib.h"
#include "math.h"
void growTree( Node *head);
Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent );
void growTree( Node *head );
void destroyTree(Node *head);
void removeChildren(Node * parent);
double nodeValue( Node *node, double time );
double value( double x, double y, double time );
void sflag( Node *node);
void cTree( Node *node);
extern int count_remove;
extern int count_add;
void adapt(Node *head);

