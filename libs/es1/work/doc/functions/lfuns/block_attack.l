
BLOCK_ATTACK(L)         LOCAL FUNCTIONS           BLOCK_ATTACK(L)

NAME
     block_attack() - prevent a player from attacking  or  spell-
     casting

SYNOPSIS
     void block_attack (int i) ;

DESCRIPTION
     block_attack() is defined in /std/body/attack.c. It is  used
     to  prevent  a  player  from attacking or spellcasting for a
     given period of time, ie if  he  changes  weapons,  casts  a
     spell,  or  other combat-interfering action, then for a cer-
     tain amount of time he cannot make attacks or begin  casting
     new spells.

     The body object defines a property  "stop_attack".  Each  of
     the  forbidden  activities  checks the stop_attack property,
     and if it is greater than zero, the activity does  not  take
     place.  The  stop_attack  property  is decreased by 1 in the
     object's heart_beat.

     The block_attack()  lfun  takes  as  argument  a  number  of
     seconds  to  block  attacks,  divides  by  2  to  convert to
     heart_beats, and adds that number to the  current  value  of
     stop_attack.  Thus,  if  a player casts a 6-second spell and
     then checks his hits (a 2-second penalty)  he  will  lose  a
     total of four attacks.

KNOWN BUGS
     Spells are timed by  call_out  rather  than  by  heartbeats.
     Thus,  when  the  game  is  lagged,  a spell may take effect
     before the prescribed number  of  heart_beats  has  elapsed.
     This  does not offer a way to cheat (a la the missile bug in
     2.4.5) because the user is always blocked  for  N/2  attacks
     regardless of lag. It does cause an odd visual effect, which
     is that the user may see blocked attack messages _after_ the
     spell takes effect.

SEE ALSO
     /std/body/attack.c,     /cmds/std/_cast.c,      /std/user.c,
     /std/monster.c.

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

