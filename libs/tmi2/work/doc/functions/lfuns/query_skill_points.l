
QUERY_SKILL_POINTS(L)   LOCAL FUNCTIONS     QUERY_SKILL_POINTS(L)

NAME
     query_skill_points() - return the number of use points of an
     object's skills.

SYNOPSIS
     mapping query_skill_points() ;

DESCRIPTION
     The    query_skill_points()    lfun    is     defined     in
     /std/living/skills.c.  In  the  TMI-2  mudlib,  each  time a
     player uses a skill, he is credited with  a  number  of  use
     points  for  that  skill.  When  he  accumulates  enough use
     points,   his   skill   level   improves   by    one.    The
     query_skill_points()  lfun  returns a copy of the mapping of
     skill points credited to each skill. The  number  of  points
     required  to  advance  the  skill  depends  on  the player's
     statistics, which are kept in a seperate mapping  and  which
     can be accessed by calling the query_skill_stats() lfun.

     Since query_skill_points() returns a copy  of  the  mapping,
     you  can  safely alter the returned mapping without changing
     the original data in the original  object.  Conversely,  you
     cannot alter a living object's skills this way: you must use
     the lfuns designed for that.

SEE_ALSO
     init_skills(),     query_skills(),      query_skill_stats(),
     set_skill(),         modify_skill(),        improve_skill(),
     change_skill_level(), /std/living/skills.c.

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

