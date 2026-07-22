
SET_NAME(L)              LOCAL FUNCTIONS                SET_NAME(L)

NAME
     set_name() - set names of an object.

SYNOPSIS
     vararg set_names(string str, string c_str) ;

DESCRIPTION
     set_name() is defined in /std/object/ob_logic.c. It accepts the name 
     of a monster as first argument. The function will set two properties
     in monster: name and cap_name. If the second argument presents, the
     c_name and c_cap_name is also set to c_str, else use str instead. If
     short or c_short properties is not set yet, the function set it, too.
     Finally, it checks if id is set, if not, set it to ({ str }).

EXAMPLE
     set_name("orc", "半兽人");

SEE ALSO
     set_long(),    set_short().

AUTHOR
     Annihilator@Eastern.Stories


Eastern Stories             Last change:                   4-2-93

