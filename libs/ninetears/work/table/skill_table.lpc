/* The skilltable.
 * It will include all skills usable on the mud.
 * New ones can easily be added.
 * 
 * This is going to be complicated.. 
 * You have 10 points to deal to a skill, you can weight str with 5 of them
 * and then you have 5 to put on the rest, say 3 on int and 2 on wis.. 
 *
 * The skillbonus will be calculated in /std/living/skills.c
 * 
 * The mapping has this parts:
 *  
 * 0 : xp_cost : Cost in XP to advance one level.
 * 1 : str
 * 2 : con
 * 3 : dex
 * 4 : wis
 * 5 : int
 * 6 : cha
 * 7 : Max level
 * 8 : Dependant skill. can be negative, so that fire is dependant on -cold..
 * 
 * 
 */

mapping skills;

create()
{
    skills = ([
      /* These skills are not adjusted! just examples.. */
      "testing" 		: ({ 100, 0, 0, 2, 5, 3, 0, 10, "" }),
      "swimming" 		: ({ 200, 2, 2, 3, 3, 0, 0, 10, "testing" }),
      "berserk" 		: ({ 200, 2, 2, 3, 3, 0, 0, 10, "-patience" }),
      "patience" 		: ({ 200, 2, 2, 3, 3, 0, 0, 10, "" }),
      "fire": ({400, 0, 0, 0, 1, 2, 0, 10, "-cold" }),
      "cold": ({400, 0, 0, 0, 1, 2, 0, 10, "-fire" }),
      "air": ({500, 0, 0, 1, 0, 2, 0, 10, "-stone" }),
      "stone":({400, 1, 0, 0, 1, 2, 0, 10, "-air" } ),
    "electrical":({450, 0, 0, 1, 0, 3, 0, 10, "-acid" } ),
"magical":({200, 0, 0, 2, 3, 0, 10, "" }),
"acid":({500, 0, 0, 1, 2, 2, 0, 10, "-poison" }),
"poison":({300, 0, 2, 2, 2, 1, 0, 10, "-acid" }),
"good":({200, 0, 0, 0, 2, 0, 2, 10, "-evil" }),
"evil":({200, 0, 0, 0, 2, 0, 2, 10, "-good" }),
"psionic":({600, 0, 0, 0, 2, 2, 4, 10, "" }),
   "blunt":({100, 4, 0, 2, 0, 0, 2, 10, "" }),
   "sharp":({100, 3, 0, 3, 0, 0, 2, 10, "-magical" }),
   "pierce":({100,2, 0, 5, 0, 0, 2, 10, "-magical" }),
   "unarmed":({300, 3, 0, 3, 0, 0, 1, 10, "" }),
   "vision near":({100, 0, 2, 4, 2, 2, 2, 10, "-vision far"}),
   "vision far":({100, 0, 2, 6, 2, 2, 0, 10, "-vision near"}),
   "searching":({100, 0, 0, 3, 3, 3, 1, 10, "vision near"}),
   "aiming":({100, 0, 0, 5, 2, 2, 1, 10, "vision far"}),
/* End of examples, put the real stuff under here.
 * move the adjusted skills from above when they are ready.
 * 
 * Remember, ginve out 10 POINTS! neverm ever more than that. may be less tho.
 *
 */ 
]);

} /* create() */

int *lookup_skill(string lookup)
{
    return (int *)skills[lookup];
}
