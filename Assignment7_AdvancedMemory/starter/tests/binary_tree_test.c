#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "test.h"
#include "timer.h"

#define SIZE 10
#define TIMES 30000

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node* newNode(int data) {
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}

int main(int argc, char *argv[]){
  char *progname;
  progname = (argc > 0) ? argv[0] : "";
  start_timer();

  MESSAGE("Allocate Binary Tree\n");

  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);

  (root->left->left->data == 4) ? MESSAGE("ALLOCATE SUCCESS! \n") : MESSAGE("ALLOCATE FAILED! \n");

  end_timer();
  print_log_timer();
  return 0;
}
