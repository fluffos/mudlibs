
KILL_OB(L)              LOCAL FUNCTIONS                KILL_OB(L)

NAME
     kill_ob()  -  cause  an  object  to  enter  combat  with  an
     opponent.

SYNOPSIS
     int kill_ob (object victim) ;

DESCRIPTION
     The kill_ob() lfun  is  defined  in  /std/body/attack.c.  It
     causes  the  object  to  enter combat with the victim object
     passed as an argument. It initializes the attacker array, if
     necessary,  and  adds victim to the top of that list.  Thus,
     if the object is already in combat  with  several  opponent,
     you  can use kill_ob() to move one of them to the top of the
     list, causing it to be  the  one  attacked.  Kill_ob()  also
     turns  on  the  object's  heartbeat, if needed, and sets its
     any_attack variable to 1.  Use this lfun  to  start  fights,
     either in tke kill command or in any other command with hos-
     tile intent, such as combat spells, failed attempts to steal
     from  the  given  object,  or  other  circumstances where an
     object gets angry enough to start waving weapons around.

SEE ALSO
     execute_attack(), continue_attack(), /std/body/attack.c.

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

