#include <stdio.h>
#include <stdlib.h>
#include "treeStructure.h"
#include "nodeValue.h"

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
