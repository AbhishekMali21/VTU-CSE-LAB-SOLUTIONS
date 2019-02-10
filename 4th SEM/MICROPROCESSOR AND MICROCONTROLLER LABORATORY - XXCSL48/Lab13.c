#include <LPC21xx.h>

void clock_wise(void) ;
void anti_clock_wise(void) ;
 
unsigned  int var1 ;
unsigned long int i=0,j=0,k=0;

int main(void)
{
   PINSEL2 = 0x00000000;	
   IO1DIR |= 0x00F00000;
   while(1)
   {		 
	for( j = 0 ; j < 50 ; j++ ) 
   	   clock_wise() ;
	for( k = 0 ; k < 65000 ; k++ ) ; 
	   for( j=0 ; j < 50 ; j++ )    
		anti_clock_wise() ;
	for( k = 0 ; k < 65000 ; k++ ) ; 
   } 							
}

void clock_wise(void)
{
    var1 = 0x00080000;    
    for(i=0;i<=3;i++)
    {
	var1 <<= 1 ;	
	IO1CLR =0x00F00000;
	IO1SET = var1;
	for( k = 0 ; k < 3000 ; k++); 
    }
}

void anti_clock_wise(void)
{
    var1 = 0x00800000 ;    
    IO1CLR =0x00F00000 ;	
    IO1SET = var1 ;
    for(k=0;k<3000;k++);
        for(i=0;i<3;i++)
        {
	    var1 >>=1;
	    IO1CLR =0x00F00000 ; 
	    IO1SET=var1 ;	
            for(k=0;k<3000;k++);
	}  
}
