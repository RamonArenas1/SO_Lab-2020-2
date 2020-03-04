/**
 * soluciones.c
 *
 *  Created on: 03/03/2020
 *  Author: Ramon ARenas Ayala
 */

#include "includes/problemas.h"
#include "includes/booleans.h"
#include "includes/list_node.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

/**
 * 
 */
struct list_node *list_create_copy(struct list_node *list) {
    return NULL;
}

void heapify(int arr[], int n, int i);

/**
 * Implementación del algoritmo de ordenación heapsort
 */
void heap_sort(int *array, size_t size) {
    int i = size / 2 - 1;
    while(i>=0){
        heapify(array, size, i);
        i--;
    }

    i = size-1;
    while(i>=0){
        int aux = array[0];
        array[0] = array[i];
        array[i] = aux; 

        heapify(array, i, 0); 
        i--;
    }
       
}

void heapify(int arr[], int n, int i) { 
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 
  
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    if (largest != i){ 
        int aux = arr[i];
        arr[i] = arr[largest];
        arr[largest] = aux; 

        heapify(arr, n, largest); 
    } 
}

/**
 * Esta función inserta una nodo en una lista simplemente 
 * ligada y ordenada ascendentemente.
 * Después de la insersión la lista conserva su orden.
 * @param list - apuntador a la lista donde ser realizará la incersión
 * @param new_node - nodo que será insertado
 */
void list_insert_node(struct list_node **list, struct list_node *new_node) {

    if(*list != NULL && new_node != NULL){
        new_node -> next = NULL;
        struct list_node *aux = *list;
        int is_insert = 0;
        
        while(aux -> next != NULL){
            if(new_node -> value > aux -> value){
                if(new_node -> value > aux -> next -> value){
                    aux = aux -> next;
                }else{
                    new_node -> next = aux -> next;
                    aux -> next = new_node;
                    is_insert++;
                    break;
                }
            }else{
                new_node -> next = aux;
                *list = new_node;
                is_insert++;
                break;
            }
        }
        
        if(!is_insert){
            aux->next = new_node;
        }

    }else if(new_node != NULL){
        new_node -> next = NULL;
        *list = new_node;
    }
}

/**
 * Estructura de lista ligada.
 */
struct list_pointer {
    void *old;
    struct list_pointer *next;
};

/**
 *Busca un elemento en una lista de tipo list_pointer y a partir del valor almacenado en old
 *return 0 si no lo encuentra el valor de new contenido en el nodo en el que lo encontró
 */
unsigned long search_pointer(void *p, struct list_pointer *list) {
    while (list != NULL) {
        if (list->old == p) {
            return 1;
        }
        list = list->next;
    }

    return 0;
}

/**
 * Agrega un elemento al principio de una lista de apuntadores
 * con los valores old y new que se pasan como parametros
 */
void push_pointer(void *old, struct list_pointer **list) {
    struct list_pointer *new_node = (struct list_pointer *) malloc(sizeof(struct list_pointer));
    new_node->old = old;
    new_node->next = *list;
    *list = new_node;
}

/**
 * Esta función decide si la lista 'list' tiene un ciclo.
 * @param list
 * @return TRUE si tiene ciclo, FALSE en caso contrario
 */
int list_has_cycle(struct list_node *list) {
    if(list != NULL){
        //La lista vacia 
    }
    return false;
}

int search(char c, char *str){
    size_t size = strlen(str);

    int i = 0;
    while(i < size){
        if(str[i]==c){
            str[i] = (char) 256;
            return TRUE;
        }
        i++;
    }
    return FALSE;
}
/**
 * Esta función decide si dos cadenas son anagramas.
 * @param string1 - cadena 1
 * @param string2 - cadena 2
 * @return TRUE si string1 y strin2 son anagramas, FALSE en caso contrario
 */
int anagrams(char *string1, char *string2) {
    if(string1 == NULL || string2 == NULL){
        return FALSE;
    }
    
    size_t size = strlen(string1);

    if(size != strlen(string2)){
        return FALSE;
    }

    int resul = TRUE;
    int i = 0;
    while(i < size){
        resul = resul && search(string1[i],string2);
        i++;
    }
    return resul;
}

/**
 * Esta genera la tabla de del método de multiplicación egipcia.
 * Regresa un arreglo unidimencional de enteros.
 */
long long *egypcian_multiplication(int _n, int _m) { 
    if (_n == 0 || _m == 0){
        return NULL;
    }else{
        int count = 0;
        long long res = _n;
        while(res!=0){
            if(res & 1){
                count++;
            }
            res = res >> 1;
        }
        count += 2;
        res = _n;
        long long aux = _m;
        long long *array = malloc(count*(sizeof(long long)));
        array[0]=count;
        int i = 1;

        while(res != 0){
            if (res & 1){
                array[i] = aux;
                i++;
            }
            aux = aux << 1;
            res = res >> 1;
        }

        i = 1;        
        while(i < count-1){
            res += array[i]; 
            i++;
        }

        array[count-1] = res;
        return array;
    }
}


/**
 * Para un arreglo de enteros calcula el máximo valor 
 */
long long calc_max_sum(int *array, size_t size) {
    if(array != NULL){

        if (size == 0){
            return 0;
        }
    
        if(size == 1){
            return array[0];
        }

        int aux = array[0];
        int cont;
        int i = 0;
        int j;

        while (i < size){
            cont = 0;
            j = i; 
            while (j < size){
                cont = cont + array[j];
                if (cont > aux){
                    aux = cont;
                }
                j++;
            }
            i++;
        }
        return aux;
    }
    return 0;
}
