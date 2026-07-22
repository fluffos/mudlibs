
SET_SKILL(L)            LOCAL FUNCTIONS              SET_SKILL(L)

NAME
     set_skill() - create a new skill in a living object.

SYNOPSIS
     void set_skill(string what, int val, string stat) ;

DESCRIPTION
     The set_skill() lfun is defined in /std/living/skills.c.  It
     is called once to initialize a new skill in a player or mon-
     ster. It should NOT be called to  change  the  level  of  an
     existing  skill: use improve_skill() or change_skill_level()
     to do that. The first argument, what, is  the  name  of  the
     newly created skill: the second argument, val, is the start-
     ing level of the skill; and the third argument, stat, is the
     name  of the statistic associated with the skill that deter-
     mines the rate at which the skill improves. You must set the
     statistic  before defining a skill that uses that statistic,
     otherwise things will not work correctly.

     In the TMI-2 mudlib, each time a player uses his skills,  he
     is  credited with a number of use points for that skill, the
     number depending on the relative difficulty of the task  and
     on  whether  he  succeeded  or  failed.  When the player has
     enough use points, his skill improves by one. The number  of
     use  points  required depends on the level of the associated
     statistic; the formula is defined  in  /std/living/spells.c,
     in the improve_skill lfun.

SEE ALSO
     init_skills(),     query_skills(),      query_skill_stats(),
     query_skill_points(),    modify_skill(),    improve_skill(),
     change_skill_level(), /std/living/skills.c.

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

