// RPS_Things.c
// Stores the functions required to play Rock, Paper, Scissors.
#include "Lab9_All.h"

/*
Initializes the features and structs used.
*/
void Initializations(void)
{
    srand((unsigned int)time(0));
#if _LINUX_
    PrgmInit();
#endif // _LINUX_
    printf("Press the spacebar to exit\n");
}

/*
Collects input from the player.
*/
char ManInput(void)
{
    char choice;
    do
    {
        printf("Pick [1]Rock, [2]Paper, [3]Scissors:\n");
#if _LINUX_
        while (!Kbhit())
            MSLEEP(10);
        choice = Getch();
#else
        while (!_kbhit());
        choice = _getch();
#endif
        DataValidation(&choice);
    } while (choice == INVALID_OPT);

    return choice;
}

/*
Randomly chooses Rock, Paper, or Scissors for a few rounds, then uses a queue to predict the player's next move.
This allows it to try to win.
*/
char MachineInput(int *flag)
{
    char choice;
    choice = INT_2_CHAR(rand() % (DECISIONS + WEIGHTING(flag)) + 1);    //  rand() %    (3+(0 or 1))    +1
    if (flag)   // Breakpoint here.
    {
        // This starts on the 7th round.
        printf("\n\nDebug point\nVariable 'choice':\t%c\n\n", choice);
        *flag = 1;
        if (choice > DECISIONS)         // DECISIONS = 3.  If the choice is > 3 (is it 4?)
            choice = AverageQueue();
    }
    return choice;
}

/*
Calculates who won this round.
*/
enum outcome Judgement(PLAYER *man, PLAYER *machine)
{
    enum outcome result;
    if (WIN_COND(man->choice, machine->choice))
    {
        man->score++;
        result = WIN;
    }
    else if (TIE_COND(man->choice, machine->choice))
        result = TIE;
    else
    {
        // Losing condition.
        machine->score++;
        result = LOSS;
    }
    return result;
}
