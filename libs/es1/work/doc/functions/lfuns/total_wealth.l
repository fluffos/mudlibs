
TOTAL_WEALTH(L)         LOCAL FUNCTIONS           TOTAL_WEALTH(L)

NAME
     total_wealth() - return the wealth of the object in  lowest-
     value coins

SYNOPSIS
     nomask int total_wealth() ;

DESCRIPTION
     The total_wealth() lfun  is  defined  in  /std/living.c.  It
     queries  the  object's  wealth  property, and multiplies the
     number of that coin by its value in  terms  of  the  lowest-
     denomination  coin. It adds up the result for all coin types
     carried and returns the total. Coins  that  cannot  be  con-
     verted  into the low-valued coin do not enter the total fig-
     ure.  This lfun is used  to  determine  whether  the  living
     object has enough money to buy something.

SEE ALSO
     coins_carried(), /std/coinvalue.c, /std/living.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

