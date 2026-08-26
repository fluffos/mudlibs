#define DEALER            CASINO + "npcs/carvey"
#define BETTING_TIME      90
#define LAST_CALL         10
#define SPIN_TIME         20
#define NO_BET_TIME       60

#define REDS              ({  1,  4,  5,  7, 10, 11, 12, 15, 19, \
                             20, 21, 24, 25, 27, 30, 32, 35, 36 })
#define BLACKS            ({  2,  3,  6,  8,  9, 13, 14, 16, 17, \
                             18, 22, 23, 26, 28, 29, 31, 33, 34 })

#define COLOR(xxx)        ((member_array(xxx, REDS + BLACKS) < 18) ? \
                          "%^RESET%^%^RED%^red%^RESET%^" : "%^RESET%^black")
#define NUMBER(xxx)       ((xxx == 0) ? ("%^BOLD%^%^WHITE%^00%^RESET%^") : \
                          ((member_array(xxx, REDS + BLACKS) < 18) ? \
                          ("%^RESET%^%^RED%^" + xxx + "%^RESET%^") : \
                          ("%^RESET%^" + xxx)))

#define OPP_COLOR(xxx)    ((xxx == "red") ? "black" : "red")
#define OPP_NUMBER(xxx)   ((xxx == "even") ? "odd" : "even")

#define RED_BLACK         1
#define EVEN_ODD          2
#define NUMBERS           3

#define RED_BLACK_PAYOFF  1
#define EVEN_ODD_PAYOFF   1
#define NUMBER_PAYOFF_1   36
#define NUMBER_PAYOFF_2   17
#define NUMBER_PAYOFF_3   11   
#define NUMBER_PAYOFF_4   8
#define NUMBER_PAYOFF_5   6
#define NUMBER_PAYOFF_6   5
#define NUMBER_PAYOFF_7   4
#define NUMBER_PAYOFF_8   3
#define NUMBER_PAYOFF_9   2

#define X_NUMBER_PAYOFF   ({ NUMBER_PAYOFF_1, NUMBER_PAYOFF_2, \
                             NUMBER_PAYOFF_3, NUMBER_PAYOFF_4, \
                             NUMBER_PAYOFF_5, NUMBER_PAYOFF_6, \
                             NUMBER_PAYOFF_7, NUMBER_PAYOFF_8, \
                             NUMBER_PAYOFF_9 })

#define PAYOFF(xxx)       X_NUMBER_PAYOFF[xxx - 1]
#define MAX_NUMBER_BETS   sizeof(X_NUMBER_PAYOFF)
        
#define ANTE              0
#define SPIN              1
