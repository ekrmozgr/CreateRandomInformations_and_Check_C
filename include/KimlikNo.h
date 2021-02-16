#ifndef KIMLIKNO_H
#define KIMLIKNO_H
#include <stdbool.h>
struct KIMLIKNO{
long long TC_No;	
long long (*rastgele_tc_uret)(struct KIMLIKNO*);
bool (*isValidTC)(struct KIMLIKNO*,long long TC);
void (*tcyi_ata)(struct KIMLIKNO*);
void (*Yoket)(struct KIMLIKNO*);
};
typedef struct KIMLIKNO* KimlikNo;
KimlikNo KimlikNoOlustur();
long long rastgele_tc(KimlikNo);
bool tc_validmi(KimlikNo,long long);
void tc_ata(KimlikNo);
void KimlikNoYoket(KimlikNo);
#endif
