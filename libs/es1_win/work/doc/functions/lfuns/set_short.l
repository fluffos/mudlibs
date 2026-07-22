
SET_SHORT(L)              LOCAL FUNCTIONS                SET_SHORT(L)

NAME
     set_short() - set short description of an object.

SYNOPSIS
     vararg set_short(string short, string c_short) ;

DESCRIPTION
     set_short() is defined in /std/object/ob_login.c. It accepts first arg
     short description of the monster. The function set the short property
     to <short>, if c_short property is not defined, set it to <c_short> (
     if <c_short> not present, use <short> instead ).

EXAMPLE
     set_short( "An ugly orc", "一只丑陋的半兽人");

SEE ALSO
     set_long(),   set_name().

AUTHOR
     Annihilator@Eastern.Stories


Eastern Stories             Last change:                   10-5-93

