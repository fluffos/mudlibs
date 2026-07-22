
QUERY_SKILLS(L)         LOCAL FUNCTIONS           QUERY_SKILLS(L)

NAME
     query_skills() - return a copy of a  living  object's  skill
     mapping.

SYNOPSIS
     mapping query_skills() ;

DESCRIPTION
     The query_skills() lfun is defined in  /std/living/spells.c.
     It  returns  a  copy  of  the object's skill mapping. In the
     TMI-2 mudlib, each skill has three  values  associated  with
     it:  the  level  of  the  skill,  the  number  of use points
     credited towards the next improvement of that skill, and the
     level  of  the  statistic that controls the rate of improve-
     ment.  These  variables  are  stored  in  three   mapppings:
     query_skills() returns the one containing the skill levels.

     Since query_skills() returns a copy of the mapping, you  can
     safely  alter the returned mapping without changing the ori-
     ginal data in the  living  object.  Conversely,  you  cannot
     alter  a  living  object's skills this way: you must use the
     lfuns designed for that.

SEE ALSO
     init_skills(),  query_skill_points(),   query_skill_stats(),
     set_skill(),         modify_skill(),        improve_skill(),
     change_skill_level(), /std/living/skills.c.

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

