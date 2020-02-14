#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Añade los comentarios pertinentes a este archivo, especialmente
 * en las funciones auxiliares que utilices.
 */
struct node {
  int node_value;
  struct node *left;
  struct node *right;
};

typedef struct node b_tree;

int exist_Ai_eq2_i (int* array, int array_size, int value);
char* invert_statement (char* statement);
int is_search_tree (b_tree* tree);

void assert_int_eq (int expected_value, int value, char* test_case_name) {
  if(expected_value ==  value) {
    printf("Test '%s' passes.\n", test_case_name);
  }
  else {
    printf("Test '%s' fails. Expected %d, received %d\n", test_case_name, expected_value, value);
  }
}

void exist_Ai_eq2_i_test_one () {
  assert_int_eq (1, 3, "Failing assertion example");
  assert_int_eq (5, 5, "Successful assertion example");
}

int exist_Ai_eq2_i (int* array, int array_size, int value){
  if(array )
  }
}

int main() {
  exist_Ai_eq2_i_test_one ();
  return EXIT_SUCCESS;
}
