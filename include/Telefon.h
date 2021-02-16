#ifndef TELEFON_H
#define TELEFON_H
#include <stdbool.h>
struct TELEFON{	
char *imeiNo;
char telNo[12];
char* (*telNoBaslangic)(struct TELEFON*);
char* (*telNoDevami)(struct TELEFON*);
void (*telOlustur)(struct TELEFON*);
void (*Yoket)(struct TELEFON*);
};
typedef struct TELEFON* Telefon;
Telefon TelefonOlustur();
char* baslangic (Telefon);
char* devam(Telefon);
void olustur(Telefon);
void TelefonYoket(Telefon);
#endif
