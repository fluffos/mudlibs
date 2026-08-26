
MOVE_AROUND(L)          LOCAL FUNCTIONS            MOVE_AROUND(L)

NAME
     move_around() - cause a moving monster to move.

SYNOPSIS
     void move_around() ;

DESCRIPTIOn
     The move_around() lfun is defined in /std/monster.c. In  the
     TMI-2  mudlib,  you  can  cause  a  monster  to  move around
     automatically by setting two properties.  The  first,  "mov-
     ing",  identifies this monster as a moving one.  The second,
     "speed",  is  the  time  in  seconds  between  moves.  If  a
     monster's  moving  property  is  set  to 1, then in the next
     heartbeat, the monster will call_out the  move_around  func-
     tion with a delay of "speed". The move_around function picks
     a random exit, moves through it, sets the "moving"  property
     to  -1  (so  the  heart_beat won't call_out again), and then
     call_outs itself for the next move.

SEE ALSO
     move_player(), /std/monster.c.

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

