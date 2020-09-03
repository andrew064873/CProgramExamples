#include "mbed.h"

/*
    Andrew Skalicky
    113305953
    
    Microprocessor System Design - ECE 3223
    Assignment 1
    
    V1.26
*/

// Switch #1, each time pressed, turn off one red
DigitalIn sw1(p19, PullUp);

// Switch #2, each time pressed, turn off one green
DigitalIn sw2(p20, PullUp);

// Switch #3, each time pressed, turn on one green and one red, if able
DigitalIn sw3(p21, PullDown);

// Red LED's #1-3
// These LED's are Active High (= 1, means on)
DigitalOut r1(p11);
DigitalOut r2(p12);
DigitalOut r3(p13);

// Green LED's #1-3
// These LED's are Active Low (= 0, means on)
DigitalOut g1(p30);
DigitalOut g2(p29);
DigitalOut g3(p28);

/*
    This method turns off or on Red LED's
*/
void chLedRed(int val)
{
    switch(val)
    {
        case 3:
            r3 = 1;
            break;
                
        case 2:
            r3 = 0;
            r2 = 1;
            break;
                
        case 1:
            r2 = 0;
            r1 = 1;
            break;
                
        case 0:
            r1 = 0;
            break;    
    }
}

/*
    This method turns off or on Green LED's
*/
void chLedGreen(int val)
{
    switch(val)
    {
        case 3:
            g3 = 0;
            break;
                
        case 2:
            g3 = 1;
            g2 = 0;
            break;
                
        case 1:
            g2 = 1;
            g1 = 0;
            break;
                
        case 0:
            g1 = 1;
            break;    
    }
}

/*
    Main method operates board.
    
    Switches dictate which LED's are active, differentiating between
    LED's actived with high and low voltages.
    
*/
int main() 
{
    // initially set all LED's to on
    
    // RED
    r1 = 1;
    r2 = 1;
    r3 = 1;
    
    // GREEN
    g1 = 0;
    g2 = 0;
    g3 = 0;
    
    // initialize number of on LED's for each color
    int numRed = 3;
    int numGreen = 3;
    
    // Declare initial values for switch response
    int sw1Val; 
    int sw2Val; 
    int sw3Val;
    
    while(1) 
    {
        // Set initial values for switch response
        sw1Val = sw1;
        sw2Val = sw2;
        sw3Val = sw3;
        
        if(sw1Val != 1 || sw2Val != 1 || sw3Val != 0)
        {
            wait(0.25);
        }
        
        // check that Switch 1 is pushed and if any Red LED's are on
        if(!sw1Val && numRed > 0)
        {
            numRed -= 1;
        }
        
        // check that Switch 2 is pushed and if any Green LED's are on
        if(!sw2Val && numGreen > 0)
        {
            numGreen -= 1;
        }
        
        // check if Switch 3 has been pushed
        if(sw3Val)
        {
            if(numRed < 3)
            {
                numRed += 1;    
            }
            
            if(numGreen < 3)
            {
                numGreen += 1;    
            }
        }
        
        // set values to original positions
        sw1Val = 0;
        sw2Val = 0;
        sw3Val = 1;
        
        // envoke methods to cause the proper amount of LED's to be active
        chLedRed(numRed);
        chLedGreen(numGreen);
    }
}
