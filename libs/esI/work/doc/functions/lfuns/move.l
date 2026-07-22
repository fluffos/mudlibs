
MOVE(L)                 LOCAL FUNCTIONS                   MOVE(L)

NAME
     move() - move an item from one environment to another.

SYNOPSIS
     int move (mixed dest) ;

DESCRIPTION
     The move() lfun is defined in the  standard  object.  It  is
     called  whenever  an  object  is  moved  from  one  place to
     another. It checks to make  sure  that  the  object  can  be
     moved,  that  the new destination can accept it, and that it
     does not exceed the volume and capacity limits  of  the  new
     environment.  It  updates the volume and capacity of the old
     and new environments to reflect the movement of the  object.
     You  should  almost  always  use  this  function  to move an
     object. The only exception is that living objects like  mon-
     sters  and  players  should be moved using the move_player()
     lfun instead, which prints the appropriate messages and then
     calls  the  move()  lfun itself.  The argument passed can be
     either an object, in which case the item  is  moved  to  the
     object,  or a string, in which case the string is treated as
     a file name and the item is moved to the  object  with  that
     file name, loading the object if necessary.  The move() lfun
     returns an integer code which describes the  result  of  the
     move.  The  responses  are  defined in /include/move.h; they
     are:

     MOVE_OK                    0    MOVE_NOT_ALLOWED           1
     MOVE_NO_ROOM               2    MOVE_DESTRUCTED            3
     MOVE_NO_DEST               4    MOVE_TOO_HEAVY             5
     MOVE_DOOR_CLOSED        6

     The move() lfun  also  sets  the  property  "last_location",
     which  is  the  environment from which the object was moved.
     This property can be used to return an object to its  start-
     ing  point  if  the new object chooses not to accept it, for
     example.

SEE_ALSO
     move_player(),       remove(),       /std/object/ob_logic.c,
     /include/move.h.

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

