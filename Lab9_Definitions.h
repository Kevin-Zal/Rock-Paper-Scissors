// Lab9_Definitions.h
// Stores the #defines, macros, enumerations, structures, typedef definitions, and function prototypes used in the program.
/*---- #defines ----*/
// Definitions
#define SPACE       ' '
#define ROCK        '1'
#define PAPER       '2'
#define SCISSORS    '3'
#define INVALID_OPT 0
#define C_I_DIFF    '0'
#define DECISIONS   3
#define DEC_WEIGHT  1
#define Q_SIZE      7

/*---- Macros ----*/
// RPS_Things.c
#define WEIGHTING(flag)     ((flag) != 0 ? DEC_WEIGHT : 0)
#define INT_2_CHAR(integer) C_I_DIFF + (integer)
#define WIN_ROC(p1, p2)     ((p1) == ROCK && (p2) == SCISSORS)
#define WIN_PAP(p1, p2)     ((p1) == PAPER && (p2) == ROCK)
#define WIN_SCI(p1, p2)     ((p1) == SCISSORS && (p2) == PAPER)
#define WIN_COND(p1, p2)    (WIN_ROC((p1), (p2)) || WIN_PAP((p1), (p2)) || WIN_SCI((p1), (p2)))
#define TIE_COND(p1, p2)    (p1) == (p2)
// Queueing.c
#define LIKESROCK           (roctot > paptot && roctot > scitot)
#define LIKESPAPER          (paptot > roctot && paptot > scitot)
// Data_Validation.c
#define ROCK_OPT(entry)     (entry) == ROCK || (entry) == 'r' || (entry) == 'R'
#define PAPER_OPT(entry)    (entry) == PAPER || (entry) == 'p' || (entry) == 'P'
#define SCISRS_OPT(entry)   (entry) == SCISSORS || (entry) == 's' || (entry) == 'S'

#if _LINUX_
#define MSLEEP(ms)          usleep((ms) * 1000)
#endif

/*---- Enumerations ----*/
enum stage
{
    PICK,       // Computer and player choose their move
    JUDGE,      // 
    DECLARE,    // 
};

enum outcome
{
    WIN,
    TIE,
    LOSS
};

/*---- Structure Definitions ----*/
struct player_fmt
{
    int score;
    char choice;
};

/*---- Typedef Definitions ----*/
typedef struct player_fmt PLAYER;

/*---- Function Prototypes ----*/
// RPS_Things.c
void Initializations(void);
char ManInput(void);
char MachineInput(int *flag);
enum outcome Judgement(PLAYER *man, PLAYER *machine);
// Queueing.c
int Add2Queue(char newentry);
char AverageQueue(void);
// Data_Validation.c
void DataValidation(char *pdata);
