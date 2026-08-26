
HEAL_UP(L)              LOCAL FUNCTIONS                HEAL_UP(L)

NAME
     heal_up() - restore an object's good health.

SYNOPSIS
     void heal_up() ;

DESCRIPTION
     The  heal_up()  lfunn  is  defined  in   /std/body/attack.c,
     although  it  can be overriden in other bodies. It is called
     every heart_beat in monsters and users. It  queries  a  pro-
     perty  "time_to_heal",  and every time_to_heal heart- beats,
     it gives the user back some hit points and spell points.  It
     also  reduces  drunkenness  if  you put that option into the
     code: in the default lib this code is commented  out.   Usu-
     ally  you  should not call this directly: it ought to happen
     once per heartbeat. You can cause  it  to  happen  more  (or
     less) frequently by changing the value of the "time_to_heal"
     property should you want to do that.

SEE ALSO
     /std/body/attack.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

