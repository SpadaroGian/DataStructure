#ifndef __RANDOM_H__
#define __RANDOM_H__

#include<stddef.h>

double random_double(double a, double b);
float random_float(float a, float b);
size_t random_size_t(size_t a, size_t b);
int random_int(int a, int b);
char random_char(char a, char b);
void random_init_string(char * c, size_t n);

#endif //__RANDOM_H__
