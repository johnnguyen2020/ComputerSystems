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
  char *p, *q;
  char *a, *b, *c;
  char *start_address;
  char *end_address;
  char *progname;
  double *d;

  if (argc > 0)
    progname = argv[0];
  else
    progname = "";

  start_timer();

  MESSAGE("ALLOCATE Exhaustive test\n");
  int i = 0 ;
  a = malloc(5);
  start_address = a;
  for (i = 0 ; i < 10; i++){
    b = malloc(1);
  }
  c = malloc(4);
  end_address = c;
  free(a);
  free(c);
  a = malloc(4);

  ((a - end_address) == 0)
    ? MESSAGE("BEST FIT IMPLEMENTATION \n")
    : MESSAGE("FIRST FIT IMPLEMENTATION \n");

  printf("%ld\n", a - end_address);

  MESSAGE("-- Test malloc() for unusual situations\n");

  MESSAGE("Allocate small block of 17 bytes \n");
  p = malloc(17);
  if (p == NULL)
    MESSAGE("* ERROR: Can't allocate even 17 bytes. Must be bug in malloc\n");
  MESSAGE("Write on allocated block\n");
  p[0] = p[16] = 17;

  MESSAGE("Allocate big block of 4711 bytes\n");
  q = malloc(4711);
  if (q == NULL)
    MESSAGE("* ERROR: Could not allocate big block\n");
  MESSAGE("Write on allocated block\n");
  q[4710] = 47;
  MESSAGE("Free big block\n");
  free(q);

  MESSAGE("Free small block\n");
  free(p);

  MESSAGE("Allocate zero\n");
  if ((p = malloc(0)) != NULL)
    MESSAGE("* Warning: malloc(0) returned non NULL pointer!\n");

  MESSAGE("Free pointer from malloc(0)\n");
  free(p);

  MESSAGE("Test alignment for double\n");
  if ((d = malloc(2 * sizeof(double))) == NULL)
    MESSAGE("* ERROR: malloc(2 * sizeof(double)) returned NULL\n");
  d[0] = d[1] = (double)4711.4711;
  free(d);

  end_timer();

  print_log_timer();
  return 0;
}
