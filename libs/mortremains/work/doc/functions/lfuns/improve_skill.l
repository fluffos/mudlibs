
IMPROVE_SKILL(L)        LOCAL FUNCTIONS          IMPROVE_SKILL(L)

NAME
     improve_skill() - credit the user with skill use points.

SYNOPSIS
     void improve_skill (string what, int points) ;

DESCRIPTION
     The improve_skill() lfun is defined in /std/living/skills.c.
     In  the TMI-2 mudlib, each time a player uses his skills, he
     is credited with a number of skill use  points,  the  number
     depending  on  the  relative  difficulty of the skill and on
     whether he succeeded or failed.  When  he  gets  enough  use
     points, the level of his skill goes up by one.

     The improve_skill() lfun is used to credit a player or  mon-
     ster  with use points. The first argument, what, is the name
     of the skill being credited.  The second  argument,  points,
     is  the  number of points being awarded. The improve_skill()
     lfun adds the points to the skill_points mapping, checks  to
     see  if the user has enough to improve the skill, and if so,
     raises the level of the skill by one.

     You should almost always improve a user's skills  this  way.
     The  other  lfun  in  the  mudlib  that alters the skills is
     change_skill_level(), which has no effect on the use points:
     it alters the level directly. This is only used for training
     and other non-use methods of improving the skill. You should
     usually use increase_skill instead.

SEE_ALSO
     init_skills(),     query_skills(),      query_skill_stats(),
     query_skill_points(),      modify_skill(),      set_skill(),
     change_skill_level(), /std/living/skills.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

