#include <main6.h>
#include <stdint.h>
#include "servo.h"
#include "DC.h"
#include "i2clcd.h"
#include <uart1.h>
void check()
{
output_high(pin_C0);
   if(rb0==0)
   {
      
       if(a_s==8){a_s=0;}
    
       if(rd6==0){
       i_s|=(1<<a_s);
         a_s++;
   
   
   }
      else{
      i_s&=~(1<<a_s);
      a_s++;
   
   }
     
      f++;
      
   }
   while(rb0==0); 
   
}


void main()
{  uint32_t i;
   int32_t so1,so2;
   int m;
   so1=0;
   so2=0;
   TRISE&=~(7<<0);
   TRISA&=~(1<<0);
   char str1[]="Loai 1:";
   char str2[]="Loai 2:";
 
  
   UART_Init(9600); 
   I2C_LCD_Init();
   
   I2C_LCD_Clear();
   I2C_LCD_BackLight(1);
   I2C_LCD_Puts(str1);
   move_LCD(2,1);
   I2C_LCD_Puts(str2);
   bandau();
   innit_DC();
   
   cao=0;
   oldf=f;
  
   while(TRUE){
   i=1;
   check();
   m=a_s;
   move_LCD(1,8);
   
   if(rd7==0&&(f-oldf)>0)
   {
   output_low(pin_C0);
   oldf++;
   b_s=(i_s&(1<<(c_s)));
   
   if(b_s!=0){
            //dc dung
            
            
            
            kieu1();
            
            //dc tiep
              
            //lcd
           
           UART_TxChar("1");
            so1++;
            c_s++;
             move_LCD(1,8);
           tachso(so1);
            
      }
    if(b_s==0){
            //dc dung
          
          
            
            kieu2();
            //dc tiep
            
           
            //lcd
          
            UART_TxChar("2");
            so2++;
            c_s++;
              move_LCD(2,8);
            tachso(so2);
      }
   if(c_s==8) c_s=0;
   
   while(rd7==0);
   
   
   }
}
}

