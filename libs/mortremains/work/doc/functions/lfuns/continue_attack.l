
CONTINUE_ATTACK(L)      LOCAL FUNCTIONS        CONTINUE_ATTACK(L)

NAME
     continue_attack() - begin a new round of combat.

SYNOPSIS
     void continue_attack() ;

DESCRIPTION
     The continue_attack function is defined in all body objects.
     It is called from the heart_beat function to handle any com-
     bat that the body needs to carry out in that heartbeat.  The
     exact  implementation varies from body to body, but the fol-
     lowing calls should be in  all  bodies.  First,  the  object
     checks  its  hit_points to see if it needs to die this turn.
     Second, the object calls clean_up_attackers() to see  if  it
     still  has any opponents.  Third, check to see if the object
     is permitted to make an attack, and if so, make it  by  cal-
     ling  the  execute_attack() function.  Other things that are
     done in the various bodies include: checking wimpy to see if
     the  object needs to flee, checking to see if a spellcasting
     monster begins to cast a spell, and whether  to  summon  any
     other  monsters  to assist in the combat.  Bodies who do not
     engage in combat need not define this function. For example,
     the ghost body does not define it.

SEE ALSO
     heart_beat(),    execute_attack(),     clean_up_attackers(),
     /std/user.c, /std/monster.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

