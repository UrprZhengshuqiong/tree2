#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include "tree.h"
#include "print.h"
#include "treeStructure.h"
#include "nodeValue.h"

//#define MAXLEVEL 6
int add;
int sub;
int ownlevel;

void leafvalue(Node *node)
{
  int i;
  double time = 0.0;
  double g_value;
  if(node->child[0] == NULL)
  {
        g_value = nodeValue(node,time);
        if(g_value > 0.5)
        {
           node->flag = 1;
        }
        else if(g_value < -0.5)
        {
           node->flag = -1;
        }
        return;
  }
  else
  {
       for(i = 0;i < 4;i++)
       {
         leafvalue(node->child[i]);
       }
  }
}

void judge(Node *node)
{
  int i;
  int count = 0;
  if(node->child[0] == NULL)
  {
     //the node is a leaf
     if(node->flag == 1)
     {
          makeChildren(node);
          add++;
     }
    return;
  }
  else
  {
     //the node is not a leaf node
     for(i = 0;i < 4;i++)
     {
        if(node->child[i]->flag == -1)
        {
            count++;
        }

        judge(node->child[i]);
     }
     if(count == 4)
     {
        removeChildren(node);
        sub++;
     }
  }
}

void re_judge(Node *node)
{
  int i;
  int count = 0;
  int re_level;
  if(node->child[0] == NULL)
  {
     //the node is a leaf
     if(node->flag == 1 && node->level < MAXLEVEL)
     {
          makeChildren(node);
          re_level = node->child[0]->level;
          if(re_level > ownlevel)
          {
              ownlevel = re_level;
          }
          add++;
     }
    return;
  }
  else
  {
     //the node is not a leaf node
     for(i = 0;i < 4;i++)
     {
        if(node->child[i]->flag == -1 )
        {
            count++;
        }

        re_judge(node->child[i]);
     }
     if(count == 4)
     {
        removeChildren(node);
        sub++;
     }
  }
}

void adapt(Node *node)
{
  do{
     add = 0;
     sub = 0;
     leafvalue(node);
     re_judge(node);
     printf("add = %d ,sub = %d\n",add,sub);
     printf("ownlevel = %d\n",ownlevel);
    }while(ownlevel < MAXLEVEL);
}

int main( int argc, char **argv ) {

  Node *head;
  head = makeNode( 0.0,0.0, 0 );
  growtree(head);
  growtree(head);
  int i;
  for(i = 0;i < 4;i++)
  {
    growtree(head->child[i]);
  }

  //Stage 1
  leafvalue(head);

  //Stage 2
  judge(head);
  /*
  //Stage 1
  leafvalue(head);

  //Stage 2
  judge(head);
  */
  printf("add = %d,remove = %d\n",add,sub);

  //part 3 extend
  adapt(head);

  writeTree( head );

}






