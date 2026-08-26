
CHANGE_SKILL_LEVEL(L)   LOCAL FUNCTIONS     CHANGE_SKILL_LEVEL(L)

NAME
     change_skill_level() - directly set the level  of  a  living
     object's skill.

SYNOPSIS
     void change_skill_level(string str, int i) ;

DESCRIPTION
     The    change_skill_level()    lfun    is     defined     in
     /std/living/skills.c.  In  the  TMI-2  mudlib,  each  time a
     player uses his skills, he is  credited  with  a  number  of
     skill  use points, the number depending on the relative dif-
     ficulty of the skill and on whether he succeeded or  failed.
     When  he gets enough use points, the level of his skill goes
     up by one.

     The change_skill_level() lfun circumvents  this  process  of
     skill  improvement  and sets the skill level directly. Ordi-
     narily you should not use this lfun; instead, you should use
     improve_skill()  which  credits  the  user  with a number of
     skill use points. You should  use  the  change_skill_level()
     lfun to handle training and other situations where the skill
     level changes in some way other than by  accumulating  skill
     points. The first argument, str, is the name of the skill to
     be set, and the second argument, i, is the level to  set  it
     to.

     You can make temporary modifications to skills,  which  last
     for a set period of time, using the modify_skill lfun.

SEE ALSO
     init_skills(),     query_skills(),      query_skill_stats(),
     query_skill_points(),      modify_skill(),      set_skill(),
     improve_skill(), /std/living/skills.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

