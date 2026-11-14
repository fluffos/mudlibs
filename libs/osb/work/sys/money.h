/*--------------------------------------------------------------------------
 * /sys/money.h -- Headerfile for money related defined
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

#ifndef _MONEY_H_
#define _MONEY_H_

#include "daemons.h"

/* file names */
#define MONEY             "/p/money/obj/money"
#define MONEY_DEMON       MONEY_D
#define MONEY_LIB         "/p/money/lib/money"
#define MONEY_LOGGER      MONEYLOG_D

#define MONEY_CONFIG      "/save/daemons/money"

#define STATISTIC         "/p/money/lib/statistics"

#define MONEY_ERRORLOG    "finance/MONEYERROR"
#define MONEY_WATCHLOG    "finance/WATCHLOG"

/* Bank related defines */
#define BANK_TELLER       "/p/money/obj/cbteller"

#define A_AMOUNT 0
#define A_CREATED 1
#define A_DEPOSIT 2
#define A_WITHDRAW 3

/* id of money */
#define MONEY_NAME "some money for me"
/*  example:  money=present(MONEY_NAME,this_player());  */

#define MONEY_CONTENTS 0
#define MONEY_COINTYPE 1
#define MONEY_PLURAL   2
#define MONEY_SHORT    3
#define MONEY_LONG     4

/* names */
#define N_COPPER "copper"
#define N_SILVER "silver"
#define N_GOLD   "gold"
#define N_PLATIN "platinum"

/* values in MU (Monetary Units) */
#define V_COPPER    4
#define V_SILVER   10
#define V_GOLD    100
#define V_PLATIN  500

/* Some errorcodes */

#define MONEY_NEGATIVE     0  /* Occurs if you want to pay a negative value */
#define MONEY_NO_MONEY     1  /* Occurs if the player has no money object */
#define MONEY_NOT_ENOUGH   2  /* Occurs if the total value of the player's
                               * money is too low */
#define MONEY_CANT_PAY     3  /* Occurs if the player hasn't the value in the
                               * asked currencies */
#define MONEY_WRONG_RESULT 4  /* An internal error occured. Inform the Office
                               * of Finance! */

#endif


