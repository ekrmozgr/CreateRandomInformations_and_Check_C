#ifndef RASTGELE_H
#define RASTGELE_H
#include "stdio.h"
#include "stdlib.h"
struct RASTGELE{
int int_seed;
long long long_seed;
int INCREMENT_C;
int MODULUS;
long long long_MODULUS;
int (*randomPositiveInt)(struct RASTGELE*,int);
long long (*randomPositiveLong)(struct RASTGELE*,long long);
void (*Yoket)(struct RASTGELE*);
};
typedef struct RASTGELE* Rastgele;
Rastgele RastgeleOlustur();
int random_positive_int(Rastgele,int);
long long random_positive_long(Rastgele,long long);
void RastgeleYoket(Rastgele);
#endif
