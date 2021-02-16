/**
*
*   Ekrem Ozgur
* 	@since  04.04.2020 	
* <p>
* 	Rastgele.c
* </p>
*/

#include "Rastgele.h"
#include<sys/time.h>

Rastgele RastgeleOlustur(){
Rastgele this;
this = (Rastgele)malloc(sizeof(struct RASTGELE));
this->int_seed = 0;
this->long_seed = 0;
this->INCREMENT_C = 1013904226;
this->MODULUS = 0;
this->long_MODULUS = 0;
this->randomPositiveInt = &random_positive_int;
this->randomPositiveLong = &random_positive_long;
this->Yoket = &RastgeleYoket;
return this;
}

int random_positive_int(Rastgele this,int max)
{
	static int MULTIPLIER_A = 1664525;
	static int x = 333;
	struct timeval tv;
    gettimeofday(&tv,NULL);
    this->int_seed = (int)((((int)tv.tv_sec)*1000)+(tv.tv_usec/1000));
    x+= this->int_seed % 10;
    this->MODULUS = max;
   	MULTIPLIER_A += 111;
    this->int_seed = (this->int_seed * MULTIPLIER_A + this->INCREMENT_C+x) % this->MODULUS;
    if(this->int_seed < 0)
    {
    	this->int_seed = this->int_seed * -1;
	}
	return this->int_seed;
}

long long random_positive_long(Rastgele this,long long max)
{
	static int MULTIPLIER_A = 1664525;
	static int x = 333;
	struct timeval tv;
    gettimeofday(&tv,NULL);
    this->long_seed = (((long long)tv.tv_sec)*1000)+(tv.tv_usec/1000);
    this->long_MODULUS = max;
   	MULTIPLIER_A += 111;
   	x+= this->long_seed % 10;
    this->long_seed = (this->long_seed * MULTIPLIER_A + this->INCREMENT_C + this->randomPositiveInt(this,500)+x) % this->long_MODULUS;
    if(this->long_seed < 0)
    {
    	this->long_seed = this->long_seed * -1;
	}
	return this->long_seed;
}

void RastgeleYoket(Rastgele this){
if(this == NULL) return;
free(this);
}
