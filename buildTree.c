#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "Treestruct.h"
#include "buildTree.h"

Node *makeNode( double x, double y, int level ) {

  int i;

  Node *node = (Node *)malloc(sizeof(Node));

  node->level = level;

  node->xy[0] = x;
  node->xy[1] = y;

  for( i=0;i<4;++i )
    node->child[i] = NULL;

  return node;
}



void makeChildren( Node *parent ) {

  double x = parent->xy[0];
  double y = parent->xy[1];

  int level = parent->level;

  double hChild = pow(2.0,-(level+1));

  parent->child[0] = makeNode( x,y, level+1 );
  parent->child[1] = makeNode( x+hChild,y, level+1 );
  parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
  parent->child[3] = makeNode( x,y+hChild, level+1 );

  return;
}

void growTree( Node *head ) {

  int i;

  if( head->child[0] == NULL )
    makeChildren( head );
  else {
    for ( i=0; i<4; ++i ) {
      growTree( head->child[i] );
    }
  }
  return;
}
void destroyTree(Node *head)
{
	int i;
	if( head->child[0] == NULL )
	{
    	free(head);
    	head->child[0]=NULL;
	free(head);
	}
  else {
    for ( i=0; i<4; ++i ) {
      destroyTree( head->child[i] );
	free(head->child[i]);
    }
	free(head);
  }
  return;
}
double nodeValue( Node *node, double time ) {

  int level = node->level;
  double x = node->xy[0];
  double y = node->xy[1];

  double h = pow(2.0,-level);

  return( value( x+0.5*h, y+0.5*h, time ) );
}


double value( double x, double y, double time ) {

  return( 2.0*exp(-8.0*(x-time)*(x-time)) - 1.0 ) ;
}

void removeChildren(Node * parent)
{
	int i;
	for ( i=0; i<4; i++ ) {
		free(parent->child[i]);
		parent->child[i]=NULL;
		
	}
	return;
}
void sflag( Node *node)
{
	int i;
	double wang;
	node->flag=0;
	if (node->child[0]==NULL)
	{
		wang=nodeValue( node,0.0);
		if (wang>0.5)
			node->flag=1;
		if (wang<-0.5)
			node->flag=-1;
	}
	else
	{
		for ( i=0; i<4; i++ ) 
			sflag(node->child[i]);
	}
	return;
}

int count_remove,count_add;
void cTree( Node *node)
{
	int count=0;
	int i,j; 
	if(node->child[0]==NULL&& node->flag==1&&node->level<6)
	{
		makeChildren(node);
		count_add+=4;
	}
	else if(node->child[0]!=NULL)
	{
		for ( i=0; i<4; i++ )
			if(node->child[i]->flag==-1)
				count+=1;
		if(count==4)
		{
			removeChildren(node);
			count_remove+=4;
		}
	    else
		for(j=0;j<4;j++)
			cTree(node->child[j]);
	}	
	
}
void adapt(Node *head)
{
	do
	{
		count_remove=0;
		count_add=0;
		sflag( head);
		cTree( head);
		printf("%i\n",count_add);
		printf("%i\n",count_remove);	
	}
	while(count_remove!=0&&count_add!=0);
	return;
}


	
