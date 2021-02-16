#ifndef RASTGELEKISI_H
#define RASTGELEKISI_H
struct RASTGELEKISI{	
char*(*isim_soyisim_sec)(struct RASTGELEKISI*);
int (*yas_sec)(struct RASTGELEKISI*);
void (*Yoket)(struct RASTGELEKISI*);
};
typedef struct RASTGELEKISI* RastgeleKisi;
RastgeleKisi RastgeleKisiOlustur();
char* isim_sec(RastgeleKisi);
int yas(RastgeleKisi);
void RastgeleKisiYoket(RastgeleKisi);
#endif
