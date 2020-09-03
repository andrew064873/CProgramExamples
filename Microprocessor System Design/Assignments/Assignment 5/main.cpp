#include "mbed.h"

// configure Slave/Master interface
SPI spi(p11, p12, p13);

// configure memory
I2C comb(p9, p10);

// create constant address for memory
const int address = 0b1010000  << 1;

// create character array to store user's input
char userComb[5];

// SS for 74HC595 and LED Display
DigitalOut displaySelect(p14);

// SS for the 74HC165 and switches
DigitalOut combSelect(p15);

// pin dictates whether the program will 
// operate in programming mode or user mode
DigitalIn mode(p20);

/*
    This method clears the LED segment display
*/
void clearDisplay()
{
    // deselect SS
    displaySelect = 1;
    
    // format for display
    spi.format(8, 0);
    
    // set frequency
    spi.frequency(1000000);
    
    // select SS
    displaySelect = 0;
    
    // write a 0 value to display
    spi.write(0x00);
    
    // deselect SS
    displaySelect = 1;
}

/*
    This method displays letters on the display as needed,
    by taking in a character.
*/
void display(char dis)
{
    // deselect SS
    displaySelect = 1;
    
    // format for display
    spi.format(8, 0);
    
    // set frequency
    spi.frequency(1000000);
    
    // select SS
    displaySelect = 0;
    
    // switch that dictates the proper spi write for each letter
    switch(dis)
    {
        case 'A':
            spi.write(0xEE);
            break;
        case 'B':
            spi.write(0xFE);
            break;
        case 'C':
            spi.write(0x9C);
            break;
        case 'D':
            spi.write(0xFC);
            break;
        case 'L':
            spi.write(0x1C);
            break;
        case 'U':
            spi.write(0x7C);
            break;
        default:
            spi.write(0x00);
            break;
    }
    
    // deselect SS
    displaySelect = 1;
}

/*
    This method checks switch values to see if any are pushed.
*/
int checkSw()
{
    // int value that stores what is given from switches
    int data;
    
    // deselect SS
    combSelect = 0;
    
    // format spi for switches
    spi.format(8, 2);
    
    // set frequency
    spi.frequency(1000000);
    
    // select SS
    combSelect = 1;
    
    // write out dummy variable to receive value
    data = spi.write(0);
    
    // deselect SS
    combSelect = 0;
    
    // displays the pressed switch
    switch(data)
    {
        case 1:
            display('A');
            break;
        case 2:
            display('B');
            break;
        case 4:
            display('C');
            break;
        case 8:
            display('D');
            break;
        default:
            display('X');
            break;
    }
    
    // return value given from read
    return data;
}

/*
    This method retrieves a combination from the user
*/
void setUserComb()
{
    // counts number of letters given
    int combSel = 1;
    
    // current value from switches
    int currData = 0;
    
    // current character, translated from switch pressed
    char currChar;
    
    // dummy variable for writing later
    userComb[0] = 0x01;
    
    // itterate until user gives 4 characters
    while(combSel < 5)
    {
        // recieve value of switches
        currData = checkSw();
        
        // evaluate whether or not a switch was pressed
        if(currData == 1 || currData == 2 || currData == 4 || currData == 8)
        {
            // set character depending on which switch is pressed
            switch(currData)
            {
                case 1:
                    currChar = 'A';
                    break;
                case 2:
                    currChar = 'B';
                    break;
                case 4:
                    currChar = 'C';
                    break;
                case 8:
                    currChar = 'D';
                    break;
            }
            
            // set value in array to value given by user
            userComb[combSel] = currChar;
            
            // itterate to next value
            combSel++;
            
            // give user time to release
            wait(0.4);
        }
    }
}

/*
    This method acts as a puppetmaster, using other methods to operate
    combinational lock.
*/
int main() 
{
    // initially clear display
    clearDisplay();
    
    // set variable to stop taking input after user puts in
    // combination for lock
    int go = 1;
    
    // set variable to tell if device has been unlocked
    int unlock = 0;
    
    // value to hold stored combination
    char storedComb[4];
    
    // while combination has not been set, go
    while(go) 
    {
        // program mode
        if(mode)
        {
            // allow user to input combination
            setUserComb();
            
            // write user's input to memory
            comb.write(address, userComb, 8);
            wait(0.5);
            
            // display that device is now locked
            display('L');
            wait(0.4);
            clearDisplay();
            
            // disable further input by ending fucntion            
            go = 0;
        }
        
        // user mode
        else
        {
            // if device has been unlocked
            if(unlock)
            {
                // display a U to let user know that 
                // the device has been unlocked
                display('U');
            }
            else
            {
                // display a L to let user know that the device is locked
                display('L');
                wait(0.2)
                clearDisplay();
                
                // allow user to enter lock combination
                setUserComb();
                
                // read saved lock combination
                comb.read(address, storedComb, 8);
                
                // compare user input with stored lock combination
                for(int i = 1; i < 5; ++i)
                {
                    // if user input matches, keep unlock as 1
                    if(userComb[i] == storedComb[i])
                    {
                        unlock = 1;
                    }
                    // if user input does not match, no unlock
                    else
                    {
                        unlock = 0;
                    }
                }
            } 
        }
    }
}