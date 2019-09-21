// Data_Validation.c
// Validates the incoming data from the user interface.
#include "Lab9_All.h"

/*
Verify the incoming data.  Allows the user to input the following variations:
('1', 'r', or 'R') for Rock,
('2', 'p', or 'P') for Paper
('3', 's', or 'S') for Scissors.

The function then sets the data to the most acceptable format of the above variances.
It will reset the data if anything other than the above entries or the spacebar was pressed into the function.
*/
void DataValidation(char *pdata)
{
    if (ROCK_OPT(*pdata))
        // Set pdata to the most optimal variant of Rock, '1'.
        *pdata = ROCK;
    else if (PAPER_OPT(*pdata))
        // Set pdata to the most optimal variant of Paper, '2'.
        *pdata = PAPER;
    else if (SCISRS_OPT(*pdata))
        // Set pdata to the most optimal variant of Scissors, '3'.
        *pdata = SCISSORS;
    else if (*pdata != SPACE)
        // Reset the data if it's anything else other than the spacebar.
        *pdata = INVALID_OPT;
}
