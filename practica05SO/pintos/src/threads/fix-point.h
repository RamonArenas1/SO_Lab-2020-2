#ifndef THREADS_FIX_POINT_H_
#define THREADS_FIX_POINT_H_

#include <stdint.h>

#define FRACT_BITS 14 // Amount of bits used for the decimal part of the number 
#define F_CONST 16384 // Equivalent to 2**14

/* Convierte un entero en un numero equivalente en representacion de punto fijo 17.14 */
#define INT_TO_FIXPOINT(p)                ((p)* F_CONST )
/* Convierte una fracción en un numero equivalente en representacion de punto fijo 17.14 */
#define FRAC_TO_FIXPOINT(p, q)             (((p)* F_CONST) / (q))
/* Convierte un número en representacion de punto fijo 17.14 a un entero truncando su parte decimal */
#define FIXPOINT_TO_INT_TRUNCATED(x)      ((x) / F_CONST)
/* Convierte un número en representacion de punto fijo 17.14 a un entero redondenando su parte decimal */
#define FIXPOINT_TO_INT_ROUNDED(x)        ((x) >= 0 ? (((x) + F_CONST /2) / F_CONST) : (((x) - F_CONST  / 2) / F_CONST ))
/* Suma dos numeros en representacion de punto fijo 17.14 */
#define ADD_FP(x, y)            ((x) + (y))
/* Resta dos numeros en representacion de punto fijo 17.14 */
#define SUB_FP(x, y)            ((x) - (y))
/* Suma un numero en representacion de punto fijo 17.14 y un entero*/
#define ADD_FP_INT(x, n)        ((x) + ((n) * F_CONST))
/* Resta un numero en representacion de punto fijo 17.14 y un entero*/
#define SUB_FP_INT(x, n)        ((x) - ((n) * F_CONST))
/* Multiplica dos numeros en representacion de punto fijo 17.14 */
#define MULT_FP(x, y)           ( (((int64_t) (x)) * (y)) / F_CONST )
/* Divide dos numeros en representacion de punto fijo 17.14 */
#define DIV_FP(x, y)            ( (((int64_t) (x)) * F_CONST) / (y) )
/* Multiplica un numero en representacion de punto fijo 17.14 y un entero*/
#define MULT_FP_INT(x, n)           ((x) * (n))
/* Divide un numeros en representacion de punto fijo 17.14 y un entero*/
#define DIV_FP_INT(x, n)            ((x) / (n))

#endif
