#include "mbed.h"

// defined serial object, in order for mbed to output information to computer
Serial pc(USBTX, USBRX);

// define switches for players, which will generate interrupts when pressed
InterruptIn p1sw1(p30, PullDown);
InterruptIn p1sw2(p25, PullDown);

InterruptIn p2sw1(p11, PullUp);
InterruptIn p2sw2(p16, PullUp);

// define timer that tracks duration of game
Timer t1;

// define ticker that outputs progress for players
Ticker tick;

// define variables that will be changed by methods other than main
// int track current and previous switch pressed by P1
int nowP1;
int lastP1;

// int track current and previous switch pressed by P2
int nowP2;
int lastP2;

// int track placement of players
int p1step;
int p2step;

/*
    This method calculates a rounded time for output.
*/
float calcTime(float t)
{
    float time = floor(t * 100.0)/100.0;
    
    return time;
}

/*
    These next two methods count a step for P1 if the previous switch pressed 
    wasn't the current switch.
*/
void stepCount1sw1()
{
    nowP1 = 0;
    
    if(nowP1 != lastP1)
    {
        p1step++;
        lastP1 = nowP1;
    }
}

void stepCount1sw2()
{
    nowP1 = 1;
    
    if(nowP1 != lastP1)
    {
        p1step++;
        lastP1 = nowP1;
    }
}

/*
    These next two methods count a step for P2 if the previous switch pressed 
    wasn't the current switch.
*/
void stepCount2sw1()
{
    nowP2 = 0;
    
    if(nowP2 != lastP2)
    {
        p2step++;
        lastP2 = nowP2;
    }
}

void stepCount2sw2()
{
    nowP2 = 1;
    
    if(nowP2 != lastP2)
    {
        p2step++;
        lastP2 = nowP2;
    }
}

/*
    This method outputs to the serial object a progress report to be
    displayed to the players.
*/
void progressReport()
{
    pc.printf("Player 1: %i steps,   Player 2: %i steps\n", p1step, p2step);
}

/*
    Main method handles the entirety of the game played by P1 and P2, by
    envoking other methods when necessary.
*/
int main() 
{
    // game variable that means game is ongoing
    int game = 1;
    
    // variable to track time
    float time;
    
    // initilize playerstep count to 0
    p1step = 0;
    p2step = 0;
    
    // initialize player first button press
    nowP1 = 1;
    lastP1 = 0;
    nowP2 = 1;
    lastP2 = 0;
    
    // print wanrning for players to begin the game
    pc.printf("On your mark!\n");
    wait(0.5);
    
    pc.printf("Get set!\n");
    wait(0.5);
    
    pc.printf("GO!\n");

    // start timer as game starts
    t1.start();  
    
    // cause progress report to be output every second
    tick.attach(&progressReport, 1.0);
    
    // channel interrupts when player presses buttons
    p1sw1.rise(&stepCount1sw1);
    p1sw2.rise(&stepCount1sw2);
    p2sw1.fall(&stepCount2sw1);
    p2sw2.fall(&stepCount2sw2);
    
    // continue until the game ends
    while(game) 
    {
        // calculate time to appropriate format
        time = calcTime(t1.read());
        
        // check if a player has reached the goal
        
        // player 1 has won
        if(p1step == 40)
        {
            // stop timer as game is over
            t1.stop();
            
            // stop outputting progress reports
            tick.detach();
            
            // let P1 know they have won
            pc.printf("Congratulations, P1 won! %0.2f seconds!\n", time);
            
            // end game
            game = 0;
        }
        // player 2 has won
        else if(p2step == 40)
        {
            // stop timer as game is over
            t1.stop();
            
            // stop outputting progress reports
            tick.detach();
            
            // let P1 know they have won
            pc.printf("Congratulations, P2 won! %0.2f seconds!\n", time);
            
            // end game
            game = 0;
        }
    }
}
