/* SSPLAY.H - Programmed by Ethereal Cashimor */
/* 171094: Started programming */

#include "/players/cashimor/include/skills.h"

int skills;

ss_reset() {
int newskills,i;

  if(!skills) {
    skills=allocate(SS_MAX);
    return;
  }
  if(sizeof(skills)<SS_MAX) {
    newskills=allocate(SS_MAX);
    for(i=0;i<sizeof(skills);i++) newskills[i]=skills[i];
    skills=newskills;
  }
}

/* USERDOC:
query_skill
Format: i1=query_skill(i2)
See also: /players/cashimor/include/skills.h, set_skill.

This function is used to query a specific skill in player.c. <i1> is the
value of the skill that is returned, and <i2> is the skill, as defined in
/players/cashimor/include/skills.h. This function will mainly be used from
SS_PLACE, the skill-master.
*/
query_skill(which) {
  return(skill[which]);
}

/* USERDOC:
set_skill
Format: set_skill(i1,i2)
Example: set_skill(SS_BEND_BARS_LIFT_GATES,5);
See also: /players/cashimor/include/skills.h, query_skill.

This function is used to set a specific skill in player.c. This function can
only be used from the skill-master. <i1> is the skill, <i2> is the value of
this skill.
*/
set_skill(which,what) {
  if(file_name(previous_object())!=SS_PLACE) return 0;
  if((what<0)||(what>=SS_MAX)) return 1;
  skill[which]=what;
  return 2;
}
