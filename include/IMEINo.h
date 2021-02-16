#ifndef IMEINO_H
#define IMEINO_H
#include <stdbool.h>
struct IMEINO{	
char* (*imei_olustur)(struct IMEINO*);
int (*sumDig)(struct IMEINO*,int);
bool (*isValidIMEI)(struct IMEINO*,char[]);
void (*Yoket)(struct IMEINO*);
};
typedef struct IMEINO* IMEINo;
IMEINo IMEINoOlustur();
int sumDigits(IMEINo,int);
char* imei(IMEINo);
bool validmi(IMEINo,char[]);
void IMEINoYoket(IMEINo);
#endif
