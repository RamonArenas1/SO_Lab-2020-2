Nombre: Ramón Arenas Ayala
No. Cuenta: 315133455
Corre: ramon_cmk@ciencias.unam.mx

REPORTE

3.1.1
No logré implementar este algoritmo ya que en realidad se me hizo muy confuso como poder ir recorriendo la
lista.

3.1.2
Este algoritmo es inestable 2 . Supón que utilizas un max-heap para representar una
priority queue, dicha queue representa la lista de espera de clientes para acceder a un spa, cada cliente
compra un boleto para acceder al spa y entre más caro es el boleto mayor prioridad tienen el cliente
en la lista de espera. ¿crees que la inestabilidad del algoritmo pueda eventualmente traer algún com-
portamiento no aceptable para algún cliente?. Contesta brevemente esta pregunta como parte de tu
reporte.

Pues suponiendo que dos clientes compran dos boletos del mismo precio, osea con la misma prioridad
sería lógico que se atienda primero al que compro primero el boleto (en la entrada estaría primero el 
que compro primero el boleto), pero como heap sort es inestable puede que invierta el ordén de estos dos
y eso podría causar molestia a un cliente.

3.1.3
Para este problema me costo entender algunos casos en los que fallaba, en especial porque me daban
errores debido a las referencias nulas, pero para esto me apoye en las pruebas para notar a que se
debían estos fallos. Mi implemengación tarda 0(n) ya que solova recorriendo la lista una vez y en el
peor caso inserta el nodo al final.

3.1.4
Este creo fue uno de los más faciles, ya que utilice las operaciones de corrimiento de bits y de 
verificar si el b.m.s esta encendido de la multiplicación bitwise para poder ver que potencias de dos
componen un número y poder hacer la muliplicación por dos facilmente.

3.1.5
No logré implementar esto.

3.1.6
Para este problema solo logré realizar la implementación en tiempo cuadratico, ya que recorrí una de
las cadenas y mientras en cada caracter recorrí la otra cadena buscando el caracter y en caso de 
encontrarlo lo transformo en un caracter que no pertenece al ascii ya que de esta manera ya no pertenece
al dominio del problema. Si todos los caracteres de la cadena recorrida estan en la otra y tienen el mismo
tamaño entonces si son anagramas.

3.1.7
Este problema igual solo pude resolverlo en tiempo cuadratico, esto lo hice examinando todos los
subintervalos y calculando la suma, al final solo me quedo con el máximo. Al igual hice casos especiales
para cadenas nulas y vacias.