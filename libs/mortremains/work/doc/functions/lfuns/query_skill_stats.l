
QUERY_SKILL_STATS(L)    LOCAL FUNCTIONS      QUERY_SKILL_STATS(L)

NAME
     query_skill_stats() - return the level of the  stat  associ-
     ated with each skill.

SYNOPSIS
     mapping query_skill_stats() ;

DESCRIPTION
     The    query_skill_stats()    lfun     is     defined     in
     /std/living/skills.c.  In  the  TMI-2  mudlib,  each  time a
     player uses a skill, he is credited with  a  number  of  use
     points  for  that  skill.  When  he  accumulates  enough use
     points, his skill level improves by one. The number  of  use
     points  needed  to  advance  is  determined  by the player's
     statistics: each skill  is  associated  with  one  statistic
     which    determines    the    rate   of   advancement.   The
     query_skill_stats() lfun returns a mapping  with  the  skill
     names  as keys and the value of the associated statistic (an
     integer) as value. The formula determining the number of use
     points     required     to    advance    is    defined    in
     /std/living/spells.c in the improve_skill() lfun.

     Since query_skill_stats() returns a copy of the mapping, you
     can  safely  alter the returned mapping without changing the
     original data in the living object. Conversely,  you  cannot
     alter  a  living  object's skills this way: you must use the
     lfuns designed for that.

SEE ALSO
     init_skills(),     query_skills(),      query_skill_stats(),
     set_skill(),         modify_skill(),        improve_skill(),
     change_skill_level(), /std/living/skills.c.

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

