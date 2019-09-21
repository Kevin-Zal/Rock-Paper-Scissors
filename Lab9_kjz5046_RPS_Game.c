/************************************************************************************\
Kevin Zalewski
CMPET 456
Lab 9 Rock Paper Scissors Game
<Short description>
This program plays a game of Rock, Paper, Scissors with the user.  It is compatable
with Linux-based systems.

<Interactions, UI, error cases>
The program begins by prompting the user to press a '1' for Rock, '2' for Paper, or
'3' for Scissors on the keyboard.  The user interface recognizes 3 forms of entry:
('1', 'r', or 'R') for Rock, ('2', 'p', or 'P') for Paper, or ('3', 's', or 'S') for
Scissors.  If the user enters anything other than the aboce choices or the spacebar,
it will reprompt the user.  The program then displays the player's choice and its
choice, and informs the player of the result.  It then displays the score.  For the
first 7 rounds the program will play randomly.  However, after the first 7 rounds
the program will start to play against the user's past trends.

<Code Design / structure>
This program was designed to be compatabe with Linux environments.

Academic Integrity Statement
I certify that, while others may have assisted me in brain storming, debugging and
validating this program, the program itself is my own work.  I understand that
submitting code which is the work of other individuals is a violation of the course
Academic Integrity Policy and may result in a zero credit for the assignment, or
course failure and a report to the Academic Dishonesty Board.  I also understand
that if I knowingly give my original work to another individual that it could also
result in a zero credit for the assignment, or course failure and a report to the
Academic Dishonesty Board.
I assisted:             	{N/A}
I was assisted by:    	{N/A}
I used the following internet sources:     {N/A}
\************************************************************************************/

/*---- Declarations ----*/
#include "Lab9_All.h"

/*---- Constants ----*/
const char* options[DECISIONS] = { "Rock    ", "Paper   ", "Scissors" };

/*---- Main ----*/
int main(void)
{
    enum stage state = PICK;
    enum outcome result;
    PLAYER man = { 0, 0 };
    PLAYER machine = { 0, 0 };
    int queuefull = 0;

    Initializations();

    do
    {
        switch (state)
        {
        case PICK:
            // Decide for the computer.
            machine.choice = MachineInput(&queuefull);
            // Player Decides.
            man.choice = ManInput();
            queuefull = Add2Queue(man.choice);
            state = JUDGE;
            break;

        case JUDGE:
            result = Judgement(&man, &machine);
            state = DECLARE;
            break;

        case DECLARE:
            // Display who picked what.
            printf("Man picked:  %s\tMachine picked:  %s\n", options[man.choice - '1'], options[machine.choice - '1']);
            switch (result)
            {
            case WIN:
                printf("Win\n");
                break;
            case TIE:
                printf("    Tie\n");
                break;
            case LOSS:
                printf("        Lose\n");
                break;
            default:
                break;
            }
            printf("The score is Man:  %i\tMachine:  %i\n\n", man.score, machine.score);
            state = PICK;
            break;

        default:
            break;
        }
    } while (man.choice != SPACE);

#if _LINUX_
    PrgmExit();
#endif // _LINUX_
    return 0;
}
