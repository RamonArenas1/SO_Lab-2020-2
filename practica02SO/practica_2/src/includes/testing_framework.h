/*
 * testing_framework.h
 *
 *  Created on: 11/02/2012
 *      Author: Ricchy Alaín Pérez Chevanier
 */

#ifndef TESTING_FRAMEWORK_H_
#define TESTING_FRAMEWORK_H_

#include "booleans.h"

unsigned short test_passed;

int assert_true(int);

int assert_false(int);

int assert_null(void *);

int assert_equals_array(void *, void *, size_t);

int assert_equals_list();

#endif /* TESTING_FRAMEWORK_H_ */
