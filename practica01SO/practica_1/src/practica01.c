/**
 * Autor: Ramon Arenas Ayala
 * Sistemas Operativos
 * Practica 1
 * Profesor: Luis Enrique Serrano Gutiérrez
 * Ayudante: Ricchy Alain Pérez Chevanier
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Struct para simular un árbol binario por medio de apuntadores
 */
struct node {
  int node_value;
  struct node* left;
  struct node* right;
};

typedef struct node b_tree;

/**
 * Firmas de las funciones realizadas
 */

// Firmas para ejercicio 2
int exist_Ai_eq2_i (int* array, int array_size,int begin);
// Firmas para ejercicio 3
char* invert_statement (char* statement);
int num_words(char* statement);
// Firmas para ejercicio 4
int is_search_tree (b_tree* tree);
int min(b_tree* tree);
int max(b_tree* tree);
b_tree* newNode(int node_value);

//----------------------- EJERCICIO 1 (Pruebas) --------------------------//

/*
 * Compara el resultado de una prueba con el valor esperado, ambos enteros y en caso de ser 
 * iguales indica que la prueba fue exitosa, y en caso contrario indica que falló mostrando
 * el resultado esperado. En ambos casos muestra el nombre de la prueba.
 */  
void assert_int_eq (int expected_value, int value, char* test_case_name) {
    if(expected_value ==  value) {
        printf("Test '%s' passes.\n", test_case_name);
    }else {
        printf("Test '%s' fails. Expected %d, received %d\n", test_case_name, expected_value, value);
    }
}

/*
 * Test para la funcion exist_Ai_eq2_i, se crean tres arreglos en los cuales al aplicar la función
 * testeada los dos primeros regresan true y el ultimo false, comparando con el resultado esperado.
 */
void exist_Ai_eq2_i_test_one(){
    int array1[] = {-2,0,2,9,16,32};
    int array2[] = {-10,-2,0,1,2,3,6,14};
    int array3[] = {-40,-8,0,6,65,36,47};

    assert_int_eq (1,exist_Ai_eq2_i(array1,6,0),"Successfull assertion. Exist A[i] = i in left part of the array");
    assert_int_eq (1,exist_Ai_eq2_i(array2,8,0),"Successfull assertion. Exist A[i] = i in right part of the array");
    assert_int_eq (0,exist_Ai_eq2_i(array3,7,0),"Successfull assertion. Dont exist A[i] = i");
}

/*
 * Compara el resultado de una prueba con el valor esperado, ambos cadenas y en caso de ser 
 * iguales indica que la prueba fue exitosa, y en caso contrario indica que falló mostrando
 * el resultado esperado. En ambos casos muestra el nombre de la prueba.
 */  
void assert_string_eq (char* expected_value, char* value, char* test_case_name) {
    if(strcmp(expected_value,value)==0) {
        printf("Test '%s' passes.\n", test_case_name);
    }else {
        printf("Test '%s' fails. Expected '%s', received '%s'\n", test_case_name, expected_value, value);
    }
}

/*
 * Test para la funcion inver_statement, se crean dos cadenas de las cuales una solo contiene
 * caracteres del alfabeto y la otra tambien incluye simbolos. Se les aplica la función y se
 * compara con el resultado esperado.
 */
void invert_statement_test(){
    char* string1= "Hola como estas amigo mio";
    char* string2= "ESt@ tiene!! simbolos Extr@ños?";

    assert_string_eq("mio amigo estas como Hola ",invert_statement(string1),"Successfull assertion. Normal String");
    assert_string_eq("Extr@ños? simbolos tiene!! ESt@ ", invert_statement(string2),"Successfull assertion. String with symbols.");
}

/*
 * Test para la funcion is_search_tree, se crean dos arboles, el primero es un BST y el segundo no,
 * se aplica la función a ambos y se compara con el resultado esperado.
 */
void is_search_tree_test(){
    b_tree* tree1 = newNode(6);
    tree1 -> left = newNode(4);
    tree1 -> left -> right = newNode(5);
    tree1-> left -> left = newNode(3);
    tree1 -> right = newNode (9);
    tree1 -> right -> left = newNode(8);
    tree1 -> right -> left -> left = newNode(7);
    tree1 -> right -> right = newNode(10);

    b_tree* tree2 = newNode(6);
    tree2 -> left = newNode(4);
    tree2 -> left -> right = newNode(5);
    tree2-> left -> left = newNode(5);
    tree2 -> right = newNode (9);
    tree2 -> right -> left = newNode(8);

    assert_int_eq(1,is_search_tree(tree1),"Successfull assertion. Is a Binary Search Tree");
    assert_int_eq(0,is_search_tree(tree2),"Successfull assertion. Not is Binary Search Tree");
}
//----------------------- EJERCICIO 2 (A[i] = i) --------------------------//
int exist_Ai_eq2_i (int* array, int array_size,int begin){
    int middle = (int) array_size/2;

    if(array_size == 0){
        return 0;
    }else if (array_size == 1){
        return array[0] == begin; 
    }else{
        if (array[middle] == middle+begin){
            return 1;
        }else if (array[middle] > middle){
            return exist_Ai_eq2_i(array,middle,begin);
        }else{
            return exist_Ai_eq2_i(&array[middle + 1] , array_size - (middle+1), begin + middle + 1);
        }
    }
}

//----------------------- EJERCICIO 3 (Cadenas) --------------------------//
char* invert_statement(char* statement){
    int nw = num_words(statement);
    char* palabras[nw];

    int i = 0;
    int count = 0;
    int word = 1;
    int pos_word = 0;
    while(i<=strlen(statement)){
        if(statement[i] != ' '  && statement[i] !='\0'){
            count++;
        }else{
            palabras[nw-word] = malloc((count+1)*sizeof(char));
            strncpy(palabras[nw-word],&statement[pos_word],count);
            pos_word=i+1;
            count=0;
            word++;
        }
        i++;
    }

    char* result = malloc(strlen(statement)*sizeof(char));
    int j = 0;
    int pos_result = 0;
    while(j<nw){
        strcpy(&result[pos_result],palabras[j]);
        result[strlen(palabras[j])+pos_result] = ' ';
        pos_result = strlen(palabras[j]) + 1 + pos_result;
        j++;
    }
    return result;
}

/*
 * Funcion num_words, recorre una cadena y cuenta las palabras que contiene por medio
 * de los espacios.
 */
int num_words(char* statement){
    int i = 0;
    int count = 1;
    while(statement[i] != '\0'){
        if(statement[i] == ' '){
            count++;
        }
    i++;
    }
    return count;
}

//----------------------- EJERCICIO 4 (BST) --------------------------//
int is_search_tree (b_tree* tree){
    if (tree == NULL){
        return 1;
    }
    if(tree -> left == NULL && tree -> right == NULL){
        return 1;
    }else if(tree -> left == NULL){
        return (tree -> node_value) <= min(tree -> right) && is_search_tree(tree -> right);
    }else if(tree -> right == NULL) {
        return (tree -> node_value) >= max(tree -> left) && is_search_tree(tree -> left);
    }else{
        return 
        (tree -> node_value) >= max(tree -> left) && 
        (tree -> node_value) <= min(tree -> right) && 
        is_search_tree(tree -> left) && 
        is_search_tree(tree -> right);
    }
}

/*
 * Funcion min, recibe un árbol y regresa el elemento que en teoria seria el menor en un 
 * árbol de busqueda (el elemento mas a la izquierda)
 */
int min(b_tree* tree){
    if(tree -> left == NULL){
        return tree -> node_value;
    }else{
        return min(tree -> left);
    }
}

/*
 * Funcion max, recibe un árbol y regresa el elemento que en teoria seria el mayor en un 
 * árbol de busqueda (el elemento mas a la derecha)
 */
int max(b_tree* tree){
    if(tree -> right == NULL){
        return tree -> node_value;
    }else{
        return max(tree -> right);
    }
}

/*
 * Funcion newNode, función auxiliar para facilitar la construccon de arboles
 */
b_tree* newNode(int node_value){
    b_tree* tree = (struct node*) malloc(sizeof(struct node));

    tree -> node_value = node_value;
    tree -> left = NULL;
    tree -> right = NULL;

    return(tree);
}

int main(){
    exist_Ai_eq2_i_test_one();
    invert_statement_test();
    is_search_tree_test();
    return EXIT_SUCCESS;
}