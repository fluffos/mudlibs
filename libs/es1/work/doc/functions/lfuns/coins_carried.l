
COINS_CARRIED(L)        LOCAL FUNCTIONS          COINS_CARRIED(L)

NAME
     coins_carried() - return the number of coins in the object's
     wealth.

SYNOPSIS
     nomask int coins_carried() ;

DESCRIPTION
     The coins_carried() lfun is  defined  in  /std/living.c.  It
     queries  the  living  object's  wealth  property, counts the
     total number of coins  carried  of  all  denominations,  and
     returns  the  total  number.  It  is  used mostly to track a
     user's weight carried, since all coins weigh 1 mass unit  in
     the default lib.

SEE ALSO
     total_wealth(), /std/coinvalue, /std/living.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

