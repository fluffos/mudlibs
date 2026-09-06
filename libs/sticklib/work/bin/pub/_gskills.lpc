#include <skills_defs.h>

#define BORDER "#--------------------------------------------------------------------#"
int gskills_cmd(string arg, object me) {
    mapping skills;
    string ret, *indc;
    int i, oc;

    if(!me || me != this_player()) return 0;
    skills = me->query_skills();
    ret = sprintf("%s\n|   Skill%61s\n%s\n", BORDER, "Achieved   |", BORDER);
    indc = sort_array(m_indices(skills), #'<);
    i = sizeof(indc);
    if(!i)
	ret = sprintf("%s    None%58s\n",
	  ret, "None");
    else while(i--)
	    ret = sprintf("%s    %s%"+ to_string(62 - sizeof(
		  indc[i]))+"s\n",
	      ret, capitalize(indc[i]), capitalize(SK_RANKS[
		  to_int(skills[indc[i]])]));
    ret = sprintf("%s%s", ret, BORDER);
    i = sizeof(indc);
    while(i--)
	if(skills[indc[i], SKILL_POS_LEV] == 1)
	    oc ++;
    oc = SKILL_LIMIT - oc;
    ret = sprintf(
      "%s\n|%57s%12s\n%s", ret, sprintf(
	"You have %d open skill slots out of a maximum %d.",
	oc, SKILL_LIMIT), "|", BORDER);
    me->tell_me(ret);

    return 1;
}

