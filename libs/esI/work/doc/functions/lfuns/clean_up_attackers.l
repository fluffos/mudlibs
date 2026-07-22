
CLEAN_UP_ATTACKERS()MISC. REFERENCE MANUAL PAGESCLEAN_UP_ATTACKERS()

NAME
     clean_up_attackers() - remove dead or absent  monsters  from
     the attack list

SYNOPSIS
     private int clean_up_attackers() ;

DESCRIPTION
     The  clean_up_attackers()  lfun  is  defined  in  all   body
     objects. It is used to get dead monsters and those that have
     left the room out of the list of monsters  the  player  will
     attack.  It  can  also  be  used  to  make  a note of former
     opponents, for whatever scandalous purpose the body desires;
     this  is  done  in  the monster body to cause the monster to
     "remember" and attack opponents who left  combat  when  they
     reappear.  It can also be used to do other accounting on the
     attackers list. It is called in the continue_ attack lfun of
     each body object. It works by creating an new, empty list of
     attackers, considering whether each current attacker  should
     be  copied into the new list, and then swapping the new list
     into the place of the old. There are three criteria  in  the
     default  lib  for  removal:  they  are  1)  object no longer
     exists, 2) object is not longer in the same  environment  as
     the  player/monster, 3) object returns 1 when query_ghost is
     called. The monster object keeps track of opponents who left
     combat with it if the "forgetful" property is not set. Other
     bodies do not keep track at all; let the player restart  the
     combat  if  he wants to.  Bodies which do not engage in com-
     bat, such as the ghost body, do  not  need  to  define  this
     function.

SEE ALSO
     heart_beat,       continue_attack(),       execute_attack(),
     /std/user.c, /std/monster.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

