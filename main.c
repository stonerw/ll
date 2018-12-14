
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "Treestruct.h"
#include "buildTree.h"
#include "writeTree.h"

count_remove=0,count_add=0;
int main( int argc, char **argv ) {

  Node *head;

  // make the head node
  head = makeNode( 0.0,0.0, 0 );
 
 /*
     growTree(head);
     growTree(head);
     writeTree( head );//level 2 full---task 1-1
     destroyTree( head );
     */
    
    
   /*
     growTree(head);
     makeChildren(head->child[1]);
     writeTree( head );
     destroyTree( head );
     // print the tree for Gnuplot task1-2
    */
    
    
    /*
     growTree(head);
     growTree(head);
     removeChildren(head->child[1]);// task2-1
     writeTree( head );
     destroyTree(head);
     */
    
    
    
    /*
     growTree(head);
     makeChildren( head->child[1]);
     makeChildren( head->child[2]);
     removeChildren(head->child[1]);
     writeTree( head );
     destroyTree(head);//task2-2
     */
   
    
    
    
    
    
    /*
    growTree(head);
    growTree(head);
    growTree(head);
    sflag(head);
    cTree( head);
    printf("%i\n",count_remove);
	printf("%i",count_add);
    writeTree( head );//task3-1
    */
    

    

    
    /*
    growTree(head);
    growTree(head);
    growTree(head);
    adapt( head );
    writeTree(head);  //task3-2
    */
    
  return 0;
}





