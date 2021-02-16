/**
*
*   Ekrem Ozgur
* 	@since  04.04.2020 	
* <p>
* 	TestProgram.c
* </p>
*/

#include <stdio.h>
#include <stdbool.h>
#include "Kisi.h"
void Secenek_Yazdir()
    {     
        printf("\n1- Rastgele Kisi Uret\n");
        printf("2- Uretilmis Dosya Kontrol Et\n");
        printf("3- Cikis\n");
        printf("Secim : ");
    }
    
int main()
{
	bool kontrol = true;
    Kisi kisi;
    int secim;
    Secenek_Yazdir();
    scanf("%d", &secim);  
    
    while(kontrol)
	{
        switch(secim)
        {
            case 1:
                printf("Kac Kisi : ");
                int kisi_sayisi;
                scanf("%d",&kisi_sayisi);
                for(int i = 0;i< kisi_sayisi;i++)
                {   
                    kisi = KisiOlustur();
					kisi->kisiyi_tamamla(kisi);
					kisi->txt_yazdir(kisi);
					kisi->Yoket(kisi);               
                }
                Secenek_Yazdir();
                scanf("%d",&secim);
                break;
            case 2 :
                Oku();
                Secenek_Yazdir();
                scanf("%d",&secim);
                break;
            case 3 :
                kontrol = false;
                break;
            default:
                Secenek_Yazdir();
                scanf("%d",&secim);
                break;
        }
        
    }
        
        
	return 0;
}
