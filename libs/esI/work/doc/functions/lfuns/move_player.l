
MOVE_PLAYER(L)          LOCAL FUNCTIONS            MOVE_PLAYER(L)

NAME
     move_player() - move a player into a given room

SYNOPSIS
     varargs int move_player(mixed dest, string  message,  string
     dir) ;

DESCRIPTION
     The move_player() lfun is defined in all  body  objects.  It
     moves  the  player  into  a  new  environment,  printing the
     appropriate messages and doing the necessary  error  checks.
     It  calls  the move() lfun, and you should never call move()
     in the player object yourself: you should always go  through
     move_player(),  to make sure that the appropriate checks are
     done and the messages are sent.

     The first argument supplied to the function is the object to
     be  moved to (or its filename). First, the function tried to
     move the player to the new environment, and prints a  bounce
     message  if the move is unsuccessful.  If the move succeeds,
     then the second argument, which is the movement  message  to
     use,  is  used  for  message  control.  If  that  message is
     "SNEAK", then no messages are printed: the move is conducted
     silently.  (This will NOT prevent the player from triggering
     the init() functions of any objects in his new  environment,
     so  that objects may notice his entrance anyway.) If another
     message is provided, then that message  is  printed  to  the
     room  that  the player left, and the player's min message is
     printed to the new room. If no message is  provided,  or  if
     the  message  provided  is  "",  then  the third argument is
     treated as a direction and  the  player's  mout  message  is
     printed  using  that  direction  for the $D wildcard. If the
     third argument is not supplied or is "", then  the  player's
     mmout  message  is used. Thus, you can use either of the two
     standard movement messages, or each room and  movement  com-
     mand can define a custom movement message to be used in mov-
     ing a particular direction, by passing the appropriate argu-
     ments  to  move_player.  In either event, the min message is
     printed to the entry room.

     Last, the player is force to look at  his  new  environment.
     First,  the  "forced_to_look"  property is set in the player
     object; this causes the look command to check  the  player's
     brief  property  to  determine  whether  the  long  or short
     description is to be printed. Next, the user  is  forced  to
     look, and the "forced_to_look" property is unset.

SEE ALSO
     move(), /std/user.c, /std/monster.c, /std/ghost.c.


TMI-2 Release 0.9         Last change:                   4-2-93

MOVE_PLAYER(L)          LOCAL FUNCTIONS            MOVE_PLAYER(L)

AUTHOR
     Mobydick@TMI-2

Sun Release 4.1           Last change:                          2

