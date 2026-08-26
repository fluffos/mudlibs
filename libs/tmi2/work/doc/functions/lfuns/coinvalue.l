
COINVALUE(L)            LOCAL FUNCTIONS              COINVALUE(L)

NAME
     coinvalue() - return the value, in base units,  of  a  given
     coin type

SYNOPSIS
     int coinvalue(string str) ;

DESCRIPTION
     The coinvalue() lfun  is  defined  in  /std/coinvalue.c.  It
     takes  a  string as an argument and returns the value of the
     type of coin named by the string in terms  of  the  cheapest
     coin. The list of all coin types and their values is defined
     in /std/coinvalue.c. If you had the defines like this:

     #define COINVALS ({ 1000, 100, 10, 1 }) #define COINTYPES ({
     "platinum", "gold", "silver", "copper" })

     Then coinvalue("gold") would return 100,  gold  coins  being
     worth 100 copper coins.

SEE ALSO
     /std/coinvalue.c.

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

