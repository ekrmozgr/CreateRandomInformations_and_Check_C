#ifndef KISI_H
#define KISI_H
#include "stdio.h"
#include "stdlib.h"
#include "KimlikNo.h"
#include "Telefon.h"
#include "RastgeleKisi.h"
struct KISI{
char *isim_soyisim;
KimlikNo tc;
Telefon telefon;
int yas;
void (*txt_yazdir)(struct KISI*);
void (*kisiyi_tamamla)(struct KISI*);
void (*Yoket)(struct KISI*);
};
typedef struct KISI* Kisi;
Kisi KisiOlustur();
void Yazdir(const Kisi);
void Oku();
RastgeleKisi rastgelekisi;
void kisi_tamamla(Kisi);
void KisiYoket(Kisi);
#endif
