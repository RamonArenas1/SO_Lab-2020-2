#ifndef THREADS_FIX_POINT_H_
#define THREADS_FIX_POINT_H_

#include <stdint.h>

#define FRACT_BITS 14 // Amount of bits used for the decimal part of the number 
#define F_CONST 16384 // Equivalent to 2**14

/* Convierte un entero en un numero equivalente en representacion de punto fijo 17.14 */
#define INT_TO_FIXPOINT(p, q)   (((p)<<FRACT_BITS) / (q))
/* Convierte un número en representacion de punto fijo 17.14 a un entero truncando su parte decimal */
#define FIXPOINT_TO_INT(x)      ((x) / F_CONST)
/* Multiplica dos numeros en representacion de punto fijo 17.14 */
#define MULT_FP(x, y)           ((((int64_t) x) * (y)) / F_CONST)
/* Divide dos numeros en representacion de punto fijo 17.14 */
#define DIV_FP(x, y)            ((((int64_t) x) * F_CONST ) / (y))

#endif
