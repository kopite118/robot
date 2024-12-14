#bit rbie = 0x0b.3 
#bit gie = 0x0b.7
#bit RBPU =0x81.7 
#bit inte = 0x0b.4
#bit INTEDG =0x81.6 
#byte PORTB =0x06 
#bit rd0 =0x08.0
#bit rd1 =0x08.1
#byte TRISE=0x89
#byte TRISA=0x85
uint8_t b_s;
uint8_t a_s=0;
uint8_t i_s=0;
uint8_t c_s=0;
#bit rd5 =0x08.5
#bit rd6 =0x08.6
#bit rd7 =0x08.7
#bit rb0 =0x06.0 
int cao;
int thap;
int f=0;
int soluong=0;
int oldf;

void innit_extint(){
   
   INTEDG=1;// intr rising
   inte=1;// intr ext
   rbpu=0;//pull up port b
   gie=1;//global int
}

void xoay1(uint16_t goc){
   uint16_t a,b;
    uint32_t i;
   a=goc*10.55+600;
   b=20000-a;
    
   output_high(pin_E2);
   delay_us(a); // pulse of 800us
   output_low(pin_E2);
   delay_us(b);
   

}


void xoay2(uint16_t goc){
   uint16_t a,b;
   uint32_t i;
   a=goc*10.55+600;
   b=20000-a;
   
   output_high(pin_E1);
   delay_us(a); // pulse of 800us
   output_low(pin_E1);
   delay_us(b);
   

}
void xoay3(uint16_t goc){
   uint16_t a,b;
    uint32_t i;
   a=goc*10.55+600;
   b=20000-a;
   
   output_high(pin_E0);
   delay_us(a); // pulse of 800us
   output_low(pin_E0);
   delay_us(b);
   

}
void xoay4(uint16_t goc){
   uint16_t a,b;
    uint32_t i;
   a=goc*10.55+600;
   b=20000-a;
   
   output_high(pin_A0);
   delay_us(a); // pulse of 800us
   output_low(pin_A0);
   delay_us(b);
   

}


void loai1()
{  
   int c,i;
   for(c=0;c<40;c++)
   {
      for( i=1;i<20;i++)
       {
          xoay2(c);
       }
   }
   for(c=0;c<40;c++)
   {
      for( i=1;i<20;i++)
       {
          xoay1(c);
       }
   }
   for(c=0;c<40;c++)
   {
      for( i=1;i<20;i++)
       {
          xoay3(c);
       }
   }
   

   
}
void loai2()
{  
   int c,i;
   for(c=0;c<40;c++)
   {
      for( i=1;i<20;i++)
       {
          xoay2(c);
       }
   }
   for(c=0;c<40;c++)
   {
      for( i=1;i<20;i++)
       {
          xoay1(c);
       }
   }
   for(c=0;c<40;c++)
   {
      for( i=1;i<20;i++)
       {
          xoay3(c);
       }
   }

   
}
void bandau()
{
int i,c;
  
   
   for( i=1;i<100;i++)
       {
          xoay3(80);
       }
   for(c=100;c<=120;c=c+10)
   {
      for( i=1;i<20;i++)
       {
          xoay2(c);
       }
   }
  
   for( i=1;i<100;i++)
       {
          xoay1(60);
       }

}
void gap()
{
int i,c;
for(c=120;c>=60;c=c-10)
   {
      for( i=1;i<20;i++)
       {
          xoay2(c);
       }
   }
  for( i=1;i<100;i++)
       {
          xoay3(150);
       }

 for( i=1;i<100;i++)
       {
          xoay3(165);
       }
 
   

 

  for( i=1;i<100;i++)
       {
          xoay1(0);
       }
 
   
}
void colen()
{
int i;
     for( i=1;i<100;i++)
       {
          xoay3(140);
       }
   
 
}
void phai()
{
int i,c;
for(c=90;c<=180;c=c+10)
   {
      for( i=1;i<20;i++)
       {
          xoay4(c);
       }
   }
  for( i=1;i<100;i++)
       {
          xoay1(60);
       }
}
void trai()
{
int8_t i,c;
for(c=90;c>=0;c=c-10)
   {
      for( i=1;i<20;i++)
       {
          xoay4(c);
       }
   }
  for( i=1;i<100;i++)
       {
          xoay1(60);
       }
}
 
void kieu1()
{
int c,i;
   gap();
   colen();
   trai();
   for(c=0;c<=90;c=c+10)
   {
      for( i=1;i<20;i++)
       {
          xoay4(c);
       }
   }
    
   bandau();
}
void kieu2()
{
int c,i;
   gap();
   colen();
   phai();
  
     for(c=180;c>=90;c=c-10)
   {
      for( i=1;i<20;i++)
       {
          xoay4(c);
       }
   }
   bandau();
}

void gap2()
{
int i,j;

for( i=1;i<100;i++)
       {
          xoay3(180);
       }
 
 

  for( i=1;i<100;i++)
       {
          xoay1(0);
       }
 
   
}
void colen2()
{
int i;
     for( i=1;i<100;i++)
       {
          xoay3(130);
       }
   

}
void bandau2()
{
int i;

   
   for( i=1;i<100;i++)
       {
          xoay3(120);
       }
    
 
   for( i=1;i<100;i++)
       {
          xoay1(90);
       }

}
 
void kieu12()
{
int8_t c,i;
   gap2();
   colen2();
   trai();
 
   for(c=0;c<=90;c=c+10)
   {
      for( i=1;i<20;i++)
       {
          xoay4(c);
       }
   }
   bandau2();
}
void kieu22()
{
int c,i;
   gap2();
   colen2();
   phai();
   for(c=180;c>=90;c=c-10)
   {
      for( i=1;i<20;i++)
       {
          xoay4(c);
       }
   }
   bandau2();
}
