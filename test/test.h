#ifndef TEST_H
#define TEST_H

#include "malloc.h"
#include <stdio.h>

void test_malloc(int mode);
void test_free(int mode);
void test_realloc(int mode);

void print_ko(char* s, int mode);
void print_ok(char* s, int mode);

#endif