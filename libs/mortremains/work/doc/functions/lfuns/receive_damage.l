
RECEIVE_DAMAGE(L)       LOCAL FUNCTIONS         RECEIVE_DAMAGE(L)

NAME
     receive_damage() - do damage to a living object.

SYNOPSIS
     int receive_damage (int damage) ;

DESCRIPTION
     The receive_damage() lfun is defined in  /std/body/attack.c.
     It  in inherited by body.c and thence by users and monsters.
     Any time you wish to do damage to an object you should  call
     receive_damage  in  that object. It checks the make sure the
     target is neither dead nor link-dead,  applies  the  damage,
     and  causes  the  now-damaged  object  to begin fighting the
     damage-doer (if not already fighting it).

SEE_ALSO
     kill_ob(), receive_healing(), /std/body/attack.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

