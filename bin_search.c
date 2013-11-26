#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;

struct Nameval {
  char *name;
  int value;
  Nameval *left, *right;
};

Nameval *insert(Nameval *treep, Nameval *newp) {
  if (treep == NULL) {
    treep = newp;
    return treep;
  }
  int cmp = strcmp(newp->name, treep->name);
  if (cmp == 0) {
    return treep;
  } else if (cmp < 0) {
    treep->left = insert(treep->left, newp);
  } else {
    treep->right = insert(treep->right, newp);
  }
  return treep;
}

void printTree(Nameval* treep) {
  if (treep == NULL) {
    return;
  }
  printTree(treep->left);
  printf("My name is %s\n", treep->name);
  printTree(treep->right);
}

int main() {
  Nameval joe = (Nameval) {.name = "Joe"};
  Nameval bill = (Nameval) {.name = "Bill"};
  Nameval frank = (Nameval) {.name = "Frank"};
  insert(&joe, &bill);
  insert(&joe, &frank);
  printTree(&joe);
}
