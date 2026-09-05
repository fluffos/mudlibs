#ifndef _manufactory_h_
#define _manufactory_h_

#define CANNOT_BUY_THIS 0
#define NOT_ENOUGH_MONEY 1
#define SOMETHING_MISSING 2
#define YOU_GOT_IT 3
#define CANNOT_CARRY_MORE 4
#define STANDARD_MESSAGES \
    ({ \
        "You cannot buy such a thing here.\n", \
        "You do not have enough money to order this.\n", \
        "There is something missing to create such a thing.\n", \
        "You receive it.\n", \
        "You drop it because you cannot carry it.\n" \
    })

#endif
