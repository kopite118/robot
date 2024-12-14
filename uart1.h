
#bit TXEN =0x98.5 
#bit SPEN =0x18.7 
#bit CREN =0x18.4 
#byte TRISC =0x87 
#byte SPBRG =0x99 
#bit TXIF =0x0C.4
#byte TXREG =0x19 
#bit RCIF =0x0C.5 
#byte RCREG =0x1A 

void UART_Init(int baudRate)
{    
    TRISC|=(1<<7);            // Configure Rx pin as input and Tx as output  
    TXEN=1;  // Asynchronous mode, 8-bit data & enable transmitter
    SPEN=1;  // Enable Serial Port and 8-bit continuous receive
    CREN=1;
    SPBRG = 32;      // baud rate @20Mhz Clock
}


void UART_TxChar(char ch)
{
    while(TXIF==0);    // Wait till the transmitter register becomes empty
    TXIF=0;            // Clear transmitter flag
    TXREG=ch;          // load the char to be transmitted into transmit reg
}


char UART_RxChar()
{
    while(RCIF==0);    // Wait till the data is received 
    RCIF=0;            // Clear receiver flag
    return(RCREG);     // Return the received data to calling function
}
