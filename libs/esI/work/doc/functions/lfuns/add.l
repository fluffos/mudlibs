
ADD(L)                  LOCAL FUNCTIONS                    ADD(L)

NAME
     add - adds a property to an object's data

SYNOPSIS
     void add (string prop, mixed data) ;

DESCRIPTION
     The add lfun is defined in the standard object. It  is  used
     to  add a new element to a pre-existing property whose value
     is a mapping.

     Suppose you had the following line of code:

     set ("wealth", ([ "gold" : 10, "silver" : 10 ]) ) ;

     and wished to add a new element to the wealth  mapping.  You
     can't  use  set  because  that  would  wipe out the existing
     wealth property. Instead, you can do the following:

     add ("wealth/copper", 50) ;

     and create a new element of the wealth mapping whose key  is
     "copper" and whose value is 50.

     If add is called on an already-existing property,  then  the
     passed  value  will  be  added to the existing value. In the
     case of integers, the values are numerically added.  Strings
     will  be concatenated, and arrays and mappings will be added
     as normal. Examples:

     set ("frog", 10) ; add ("frog", 20) ;

     will result in the "frog" property having the value 30.

     The statement:

     add ("wealth", ([ "copper" : 50 ]) ) ;

     will have the same effect as add  ("wealth/copper",  50)  in
     the first example.

SEE ALSO
     set(), query(), delete(), /std/object/prop.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

