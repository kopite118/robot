#Byte CCP1CON = 0x17                
#Byte PR2 = 0x92
#Byte CCPR1L = 0x15
#bit TMR2ON = 0x12.2 
#byte TRISC =0x87
void innit_DC(){

   TRISC&=~(7<<0);
   output_high(pin_C0);
   output_high(pin_C2);
   output_low(pin_C1);
   CCP1CON = 0x0F; // Select the PWM mode.
   PR2 = 100;      // Set the Cycle time to 100 for varying the duty cycle from 0-100
   CCPR1L = 40;    // By default set the dutyCycle to 50
   TMR2ON = 1;  }
   
