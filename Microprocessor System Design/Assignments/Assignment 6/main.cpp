/*
    Andrew Skalicky
    113305953
    
    Microprocessor System Design - ECE 3223
    Assignment 6
*/

// Registers for port 0 
#define FIO0DIR (*(volatile unsigned int *)0x2009c000) 
#define FIO0PIN (*(volatile unsigned int *)0x2009c014)
#define FIO0SET (*(volatile unsigned int *)0x2009c018) 
#define FIO0CLR (*(volatile unsigned int *)0x2009c01C)

// Registers for port 1 
#define FIO1DIR (*(volatile unsigned int *)0x2009c020) 
#define FIO1PIN (*(volatile unsigned int *)0x2009c034)
#define FIO1SET (*(volatile unsigned int *)0x2009c038)
#define FIO1CLR (*(volatile unsigned int *)0x2009c03C)

// Pairs of bits in the PINMODE registers control the 
// resistor mode for particular port bits: 
//    00 pull-up <-- this is the default 
//    01 repeater 
//    10 resistor disabled (PullNone) 
//    11 pull-down 
// PINMODE0 : port 0, bits 0-15 
// PINMODE1 : port 0, bits 16-31 
#define PINMODE0 (*(volatile unsigned int *)0x4002c040) 
#define PINMODE1 (*(volatile unsigned int *)0x4002c044)
#define PINMODE2 (*(volatile unsigned int *)0x4002c048)
#define PINMODE3 (*(volatile unsigned int *)0x4002c04c)

/*
    This function emulates a wait function.
*/
void waitFun(float s)
{
    volatile int time = s * 1000000;
    
    while (time > 0)
    {
        time--;
    }
}

/*
    This function turns on and off appropriate LEDs
*/
void onLED(int n)
{
    if(n == 0)
    {
        FIO1PIN &= ~(1<<18);
    }
    else if(n == 1)
    {
        FIO1PIN &= ~(1<<20);
        waitFun(0.00001);
        FIO1PIN |= (001<<18);
    }
    else if(n == 2)
    {
        FIO1PIN &= ~(1<<21);
        waitFun(0.00001);
        FIO1PIN |= (001<<20);
    }
    else if(n == 3)
    {
        FIO1PIN &= ~(1<<23);
        waitFun(0.00001);
        FIO1PIN |= (001<<21);
    }
    else if(n == 4)
    {
        FIO1PIN |= (1<<23);
    }
}

int main() 
{
    // initializing inputs
    FIO0DIR &= ~(1<<6); // p8 P0.6 13:12
    FIO1DIR &= ~(1<<31);// p20 P1.31 31:30
    
    // initializing outputs
    FIO1DIR |= (1 << 18);// LED1 P1.18 5:4
    FIO1DIR |= (1 << 20);// LED2 P1.20 9:8
    FIO1DIR |= (1 << 21);// LED3 P1.21 11:10
    FIO1DIR |= (1 << 23);// LED4 P1.23 15:14
    
    // initialize proper pin modes for switches
    PINMODE0 |= (0b00 << 12);
    PINMODE3 |= (0b11 << 30);
    
    // variable to count number of LEDs that are on
    int numLED = 0;
    
    while (1) 
    {
        if(((FIO0PIN >> 6) & 1) == 0)
        {
            if(numLED < 4)
            {
                numLED++;
            }
        }
        
        else if(((FIO1PIN >> 31) & 1) == 1)
        {
            if(numLED > 0)
            {
                numLED--;
            }
        }
        
        onLED(numLED);
        waitFun(3);
    }
}
