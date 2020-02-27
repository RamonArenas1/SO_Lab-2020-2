Nombre: Ramón Arenas Ayala
No. Cuenta: 315133455
Corre: ramon_cmk@ciencias.unam.mx

REPORTE

3.2
Aprovechando que el arreglo esta ordenado ascendentemente, podemos realizar un algoritmo
que en cada comparación descarte la mitad de los elementos de esto, ya que si tomamos el elemento
de en medio y comparamos A[i] con i, si A[i] es mayor que i, sabiendo que todo los elemtos de la 
derecha seran mayores y los de la izquierda menores, sabemos que todos los mayores seguiran siendo 
a su respectivo indice, asi que los descartamos y nos quedamos con solo la mitad del arreglo. Esto es
analogo para el caso de que A[i] es menor que i. ELiminado la mitad del arreglo restante en cada 
comparación nuestro algoritmo tardara O(log n), por lo tanto cumple o(n).

3.3
¿En términos de complejidad computacional asintótica, qué tiempo toma tu solución para 
resolver el problema?
Toma O(n), ya que solo se recorre el arreglo dos veces, y durante esto, se realizan operaciones que se 
hacen en O(1).

3.4
Se compara el elemento de nodo "raiz", con el maximo del subarbol izquierdo y este debe ser menor, y
también se compara con el minimo del subarbol derecho y este debe ser mayor. Posterior a esto se verifica
que ambos subarboles sean arboles de búsqueda.

En este caso aunque solo se este comparando con los que en teoria serían el maximo y el minimo (ya que solo
tome el elemento mas a la derecha y mas a la izquierda respectivamente), como también se pide verificar
recursivamente que ambos subarboles sean de busqueda, entonces este maximo y minimo teoricos seran el 
maximo y mino real de cada subarbol.
