
INIT_SKILLS(L)          LOCAL FUNCTIONS            INIT_SKILLS(L)

NAME
     init_skills() - initialize a living object's skills.

SYNOPSIS
     void init_skills() ;

DESCRIPTION
     The init_skills() lfun is defined  in  /std/living/skills.c.
     It  checks to see if the various skill variables are defined
     and if they are not, initializes them to ([ ]). It  is  used
     to  avoid getting empty-mapping errors. Generally you should
     not need to use this lfun: it is called at create  time  for
     all  living bodies, except players for whom skill values are
     read from the .o file.

SEE ALSO
     query_skills(),  query_skill_points(),  query_skill_stats(),
     set_skill(),         modify_skill(),        improve_skill(),
     change_skill_level(), /std/living/skills.c.

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

