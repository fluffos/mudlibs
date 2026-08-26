
MODIFY_SKILL(L)         LOCAL FUNCTIONS           MODIFY_SKILL(L)

NAME
     modify_skill() - temporarily alter the  level  of  a  living
     object's skill.

SYNOPSIS
     varargs void modify_skill(string what, int val, int time) ;

DESCRIPTION
     The modify_skill() lfun is defined in  /std/living/spells.c.
     It  allows you to make a temporary increase, or decrease, in
     a living object's skills.  The first argument, what, is  the
     name  of the skill to be modified. The second argument, val,
     is the change to be made: positive for skill  increases  and
     negative  for  skill decreases. The third argument, time, is
     the amount of time for which the modification  is  to  last.
     The  modify_skill()  lfun  calls_out  to  the remove_bonus()
     lfun, which removes the  modification.   Modifications  will
     also end if the user logs out.

     Do not use this lfun to make permanent  modifications  to  a
     user's  skills - use improve_skill() or change_skill_level()
     for that. It is  designed  to  let  you  create  items  like
     potions  or  spells  that  temporarily  make a user more (or
     less) powerful than normal.

SEE ALSO
     init_skills(),     query_skills(),      query_skill_stats(),
     query_skill_points(),      set_skill(),     improve_skill(),
     change_skill_level(), /std/living/skills.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

