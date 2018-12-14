#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#ifndef TREESTRUCT_H
#define TREESTRUCT_H

struct qnode {
  int level;
  double xy[2];
  struct qnode *child[4];
  int flag;
};
typedef struct qnode Node;
#endif
