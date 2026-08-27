
SPELL_CAST()      MISC. REFERENCE MANUAL PAGES       SPELL_CAST()

NAME
     spell_cast() - initialize a monster as a spellcaster

SYNOPSIS
     void spell_cast (string spell, int chance) ;

DESCRIPTION
     The spell_cast() lfun is defined in /std/monster.c. It takes
     two  arguments; the first is the name of a spell to cast and
     the second is the chance of casting that spell in any  given
     combat   round.  The  monster  will  not  do  anything  when
     spell_cast is called - it only initialized  the  appropriate
     properties. When the monster finds itself in combat, it will
     randomly choose to make a meelee attack or  cast  the  named
     spell  based on the given chance of casting the spell.  Mon-
     sters have access to the same  spells,  and  only  the  same
     spells,  as  players do, due to TMI's egalitarian beliefs in
     monster rights. :) If  you  want  to  code  monster-specific
     spells,    you   will   have   to   recode   the   monster's
     continue_attack function a little bit. This is  a  candidate
     for  being  done in future releases of the TMI-2 lib but has
     not been done as yet.

SEE_ALSO
     /cmds/std/_cast.c, /std/monster.c.

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

