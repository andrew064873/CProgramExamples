#include "mbed.h"

/*
    Andrew Skalicky
    113305953
    
    Microprocessor System Design - ECE 3223
    Assignment 3
    
    V1.57
*/


// switch 1 that dictates that temp should display in Fahrenheit
InterruptIn sw1(p21, PullUp);

// switch 2 that dictates that temp should display in Celsius
InterruptIn sw2(p23, PullDown);

// temperature sensor
AnalogIn tempRead(p20);

// 7 segment display
BusOut display(p5, p6, p7, p8, p9, p10, p11, p12);

// boolean variable indicating the current units to display in
// 0 - C, 1 - F
volatile bool unit; 

/*
     This method calculates temperature from the MCP9700A, 
     by default it is in C.
*/
float calcDeg()
{
    // initialize degree value
    float degree = 0;
    
    // measure over 10000 values
    for(int i = 0; i < 10000; ++i)
    {
        degree += (((tempRead.read() * 3.3) - 0.5) * 100);
    }
    
    // find average of 10000 values, to eliminate noise when temp is stable
    degree = degree/10000;
    
    return degree;
}

/*
    This method displays the appropriate C or F on the 7-segment display,
    depending on the bool unit value.
*/ 
void displayUnit(bool val)
{
        // Display proper unit, based on bool unit value
        if(val)
        {
            // F
            display = 0x71;
        }
        else
        {
            // C
            display = 0x39;
        }
    }   

/*
    This method displays a singular digit to the 7-segment display.
*/
void displayTemp(int val)
{
    // based on the value given to the method, this switch displays the
    // cooresponding value on the 7-segment display
    switch(val)
    {
        case 0: 
            display = 0x3F;
            break;
        case 1:
            display = 0x06;
            break;
        case 2:
            display = 0x5B;
            break;
        case 3:
            display = 0x4F;
            break;
        case 4:
            display = 0x66;
            break;
        case 5:
            display = 0x6D;
            break;
        case 6:
            display = 0x7D;
            break;
        case 7:
            display = 0x07;
            break;
        case 8:
            display = 0x7F;
            break;
        case 9:
            display = 0x6F;
            break;
        default:
            display = 0x79;
            break;
    }   
}

/*
    This method displays all the information required, in sequence, on the
    7-segment display.
*/
void fullDisp(float val, float tens, float ones, bool unitVal)
{
    // checks if negative symbol is necessary
    if(val < 0)
    {
        display = 0x40;
        wait(0.66);
        display = 0x00;
        wait(0.1);
    }   
    
    // display first digit, followed by clearing the display
    displayTemp(tens);
    wait(0.66);
    display = 0x00;
    wait(0.1);

    // display second digit, followed by clearing the display
    displayTemp(ones);
    wait(0.66);
    display = 0x00;
    wait(0.1);

    // display the appropriate unit, followed by clearing the display
    displayUnit(unitVal);
    wait(0.66);
    display = 0x00;
    wait(0.1);
}

/*
    This method switches the unit of local bool value, from 0 to 1 iff bool 
    is currently 0. Figuratively sets unit to F.
*/
void swUnitF()
{
    if(!unit)
    {
        unit = !unit;
    }  
}

/*
    This method switches the unit of local bool value, from 1 to 0 iff bool
    is currently 1. Figuratively sets unit to C.
*/
void swUnitC()
{
    if(unit)
    {
        unit = !unit;
    }
}

/*
    This method dictates the board.
    
    Using while loops, this method displays temperature information converted
    from the MCP9700A, in C or F, depending on the bool unit value. These while
    loops are interrupted by switches that, when pressed cause an exit from the
    current while loop if the unit has been changed.
*/
int main() 
{
    // initialize local variables to be used later,
    // specifically, C (degree) and F (degreeF)
    float degree;
    float degreeF;
    float degValTens;
    float degValOnes;
    
    // default unit to 0 (C)
    unit = 0;
    
    // perform operation forever
    while(1) 
    {
        // interrupt Fahrenheit while loop if unit needs changing to C
        sw2.fall(*swUnitC);
        
        // while the current unit is F
        while(unit)
        {
            // calculate degree in C
            degree = calcDeg();
            
            // convert degree from C to F
            degreeF = (degree * 9/5) + 32;
            
            // calculate the tens place value of F
            degValTens = abs(floor(degreeF / 10.0));
            
            // calculate the ones place value of F
            degValOnes = abs(floor(fmod(degreeF, 10)));
            
            // display value to 7-segment display
            fullDisp(degree, degValTens, degValOnes, unit);
        }

        // interrrupt Celcius while loop if unit needs changing to F
        sw1.fall(*swUnitF);
        
        // while current unit is C
        while(!unit)
        {
            // calculate degree in C
            degree = calcDeg();
            
            // calculate the tens place value of C
            degValTens = abs(floor(degree / 10.0));
            
            // calculate the tens place value of C
            degValOnes = abs(floor(fmod(degree, 10)));
            
            // displace value to 7-segment display
            fullDisp(degree, degValTens, degValOnes, unit);
        }
    }
}
