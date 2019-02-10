#include<lpc214x.h>
#include<stdio.h>

//Function prototypes
void lcd_init(void);
void wr_cn(void);
void clr_disp(void);
void delay(unsigned int);
void lcd_com(void);						   
void wr_dn(void);
void lcd_data(void);

unsigned char temp1;
unsigned long int temp,r=0;
unsigned char *ptr,disp[] = " HI HELLO ",disp1[] = "HOW ARE YOU";

int main()
{	
	PINSEL0 = 0X00000000;		  
	IO0DIR = 0x000000FC;

	lcd_init();   
	delay(3200);				

        clr_disp();
	delay(3200);            


	temp1 = 0x81;
	lcd_com();
	 
	ptr = disp;
    while(*ptr!='\0')
    {
   		temp1 = *ptr;
     	lcd_data();
	 	ptr ++;
    } 
	
	temp1 = 0xC0;
	lcd_com();
	
  	ptr = disp1;   
	while(*ptr!='\0')
    {
    	temp1 = *ptr;
    	lcd_data();
		ptr ++;
    }
   	while(1);

}

void lcd_init(void)
{
	temp = 0x30;		   
	wr_cn();
	delay(3200);  			
		
	temp = 0x30;
	wr_cn();
	delay(3200);  					 
		
	temp = 0x30;
	wr_cn();
	delay(3200);  				

	temp = 0x20;
	wr_cn();
	delay(3200);  				

	temp1 = 0x28;
	lcd_com();
	delay(3200);  			
		
	temp1 = 0x0C;
	lcd_com();
	delay(800);  				
	
	temp1 = 0x06;
	lcd_com();
	delay(800);  				
	
	temp1 = 0x80;
	lcd_com();
	delay(800);  				
}

void lcd_com(void)
{
	temp = temp1 & 0xf0;
    wr_cn();
    temp = temp1 & 0x0f;
    temp = temp << 4; 
    wr_cn();
    delay(500);
}

void wr_cn(void)      
{ 	 
	IO0CLR  = 0x000000FC;
	IO0SET 	= temp;		
	IO0CLR  = 0x00000004;
	IO0SET 	= 0x00000008;
	delay(10);
	IO0CLR  = 0x00000008;
}
  

void wr_dn(void)
{  	  
	IO0CLR = 0x000000FC;
	IO0SET = temp;		
	IO0SET = 0x00000004;   	
	IO0SET = 0x00000008;   	
	delay(10);
	IO0CLR = 0x00000008;
}

void lcd_data(void)
{   	         
	temp = temp1 & 0xf0;
    temp = temp ;//<< 6;
    wr_dn();
    temp= temp1 & 0x0f;	
    temp= temp << 4;
    wr_dn();
    delay(100);					
} 

void clr_disp(void)
{
    temp1 = 0x01;
    lcd_com();
    delay(500);					
}  

void delay(unsigned int r1)
{
	for(r=0;r<r1;r++);
} 		