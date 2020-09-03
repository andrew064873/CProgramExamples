 #include "mbed.h"

/*
    Andrew Skalicky
    113305953
    
    Microprocessor System Design - ECE 3223
    Assignment 2
    
    V1.173
*/

// Switch #1, each time pressed and held, generate a siren effect
// that ranges back and forth from 900 - 1100 Hz, while the red led's
// brightness changes accordingly
DigitalIn sw1(p19, PullDown);
    
// Switch #2, each time pressed and held, generate an effect of alternating
// frequencies (770 Hz <-> 960 Hz) and LED's
DigitalIn sw2(p20, PullDown);

// Piezo unit, allows for emmision of frequencies
PwmOut piezo(p21);

// pwmout for red led, so that brightness can fluctuate
PwmOut rLED(p22);

// Blue LED, active high
DigitalOut bLED(LED1);
/*
    Main method operates board.
    
    When a switch is held, a while loop with a specific set of instructions
    operates.
*/
int main() 
{
    // initialize float values needed for future computations
    float s = 1;
    
    // these are primarily for sw1 functions
    float freq;
    float T = s/freq;
    float top = 2200;
    
    // these float values are the frequencies of the alternating values
    // for sw2
    float low = 770;
    float high = 960;
    
    // since red led will begin off, only blue needs to be initialized to off
    bLED = 0;
    rLED = 0;
    
    // while loop operates continuously
    while(1)
    {
            // loop while switch 1 is pushed
            while(sw1)
           {
                // run over the frequencies 900 - 1100, 
                // with 1100 - 1300 values being used to deescalate
                for(freq= 900; freq <= 1300; freq+=5)
                {   
                    // rising frequency
                    if(freq < 1100)
                    {
                        // calculate period
                        T = s/freq;
                        
                        // set period for piezo
                        piezo.period(T);
                        
                        // set duty-cycle
                        piezo.write(0.5f);
                        
                        // calculate brightness of LED
                        rLED = (freq - 900)/200;
                    }
                    
                    // falling frequency
                   else
                    {
                        T = s/(top - freq);
                        piezo.period(T);
                        piezo.write(0.5f);
                        rLED = (top - freq - 900)/200;
                    }
                    
                    // check if switch has been released, if so, terminate loop
                    if(!sw1)
                    {
                        break;    
                    }
                    
                    // wait 12.5 ms, occurs 80 times = 1 s
                    wait(0.0125);
                }
            }
            
            // loop while switch 2 is pushed
            while(sw2)
            {
                // set frequency to 770 Hz
                piezo.period(s/low);
                piezo.write(0.5f);
                
                // turn on blue LED and turn red LED off
                bLED = 1;
                rLED = 0;
                
                // wait 0.7 s
                wait(0.7);
                
                // check if switch 2 has been released, if so, terminate loop
                if(!sw2)
                {
                    break;
                }
                
                // set frequency to 960 Hz
                piezo.period(s/high);
                piezo.write(0.5f);
                
                // turn on red LED and turn blue LED off
                bLED = 0;
                rLED = 1;
                
                // wait 0.7 s
                wait(0.7);
            }
            
            // ensure that the LED's turn completely off after switches
            // are no longer pressed
            bLED = 0;
            rLED = 0;
            wait(0.001);
            
            // silence piezo
            piezo.write(0);
    }
    
}
