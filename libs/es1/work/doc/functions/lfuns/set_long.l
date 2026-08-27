
SET_LONG(L)               LOCAL FUNCTIONS                   SET_LONG(L)

NAME
     set_long() - set long description of an object.

SYNOPSIS
     vararg set_long(string long, string c_long) ;

DESCRIPTION
     set_long() is defined in /std/object/ob_logic.c. It accepts first arg
     long description of the monster. The function set the long property
     to <long>, if c_long property is not defined, set it to <c_long> (
     if <c_long> not present, use <long> instead ).

EXAMPLE
     set_long( 
         "The orc grins evily at you, and points at your wallet.\n",
         "这只半兽人向你扮个鬼脸，然後指一指你的钱包。\n"
     );

SEE ALSO
     set_short(),  set_name().

AUTHOR
     Annihilator@Eastern.Stories


Eastern Stories             Last change:                   10-5-93

