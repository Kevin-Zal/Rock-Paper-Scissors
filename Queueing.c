// Queueing.c
// Store the functions required to operate the queue which controls the AI.
#include "Lab9_All.h"

/*---- Static Globals ----*/
static char ai_queue[Q_SIZE] = { 0 };

/*
Adds the recently added input to the queue.
*/
int Add2Queue(char newentry)
{
    static int flag = 0;
    static int queuepos = 0;
    ai_queue[queuepos++] = newentry;
    if (queuepos >= Q_SIZE)
    {
        queuepos = 0;
        flag = 1;
    }
    return flag;
}

/*
Alalyzes the player's last few moves and determines the best way to win.
This also makes the computer resistant to the player entering patterns.
*/
char AverageQueue(void)
{
    int qpos;
    int roctot = 0, paptot = 0, scitot = 0;

    // Sum the instances in the queue.
    for (qpos = 0; qpos < Q_SIZE; qpos++)
    {
        switch (ai_queue[qpos])
        {
        case ROCK:
            roctot++;
            break;
        case PAPER:
            paptot++;
            break;
        case SCISSORS:
            scitot++;
            break;
        default:
            break;
        }
    }
    // Return what will beat the mode of the results.
    if (LIKESROCK)
        return PAPER;
    else if (LIKESPAPER)
        return SCISSORS;
    // They must like picking scissors.
    else
        return ROCK;
}
