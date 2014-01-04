#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Nameval Nameval;

struct Nameval {
  char *name;
  int value;
  Nameval *left, *right;
};

Nameval *lookup(Nameval *treep, char *name) {
  if (treep == NULL) {
    return NULL;
  }
  int cmp = strcmp(name, treep->name);
  if (cmp == 0) {
    return treep;
  } else if (cmp < 0) {
    return lookup(treep->left, name);
  } else {
    return lookup(treep->right, name);
  }
}

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
  Nameval foo = (Nameval) {.name = "foo"};
  Nameval bar = (Nameval) {.name = "bar"};
  Nameval derp = (Nameval) {.name = "derp"};
  Nameval eleph = (Nameval) {.name = "elep"};
  insert(&foo, &bar);
  insert(&foo, &derp);
  insert(&foo, &eleph);
  printTree(&foo);
  printTree(lookup(&foo, "derp"));
}
