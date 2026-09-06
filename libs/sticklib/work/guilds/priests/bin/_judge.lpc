#include "../priest.h"
#include "../skills.h"
inherit PSKILLS;

int get_coef(object sym, int first, int last) {
    int i,t;
    int *skills;

    skills = sym->query_pexes();
    for(i=first;i<=last;i++) {
	t += skills[i];
    }
    return t;
}

string get_ave(object sym, int first, int last) {
    int i;
    float t;
    int *skills;

    skills = sym->query_pexes();
    t = 0.0;
    for(i=first;i<=last;i++) {
	t += pex2skill(skills[i]);
    }
    return pex2str(skill2pex(t / (last - first + 1)));
}

status
judge_cmd(object who, object sym, string s) {
    object target, tar_sym;
    int a_coef, p_coef;
    string ave_skill, ave_a_skill, ave_p_skill;
    string str;

    if(!sym->query_rank()) return
	notify_fail("You don't have that power.\n"),0;
    notify_fail("Usage: judge [player]\n");
    if(!s) {
	target = who;
	tar_sym = sym;
    }
    else {
	target = find_player(s);
	if(!target) return 0;
	if(!IS_PRIEST(target)) return
	    notify_fail("That player isn't a priest!\n"),0;
	tar_sym = target->query_guild_object();
	if(!tar_sym) return
	    notify_fail("That player has lost his symbol!\n"),0;
    }
    if(environment(target) != environment(who))
	return notify_fail("That player is not here.\n"),0;

    ave_a_skill = get_ave(tar_sym, FIRST_A_SKILL, LAST_A_SKILL);
    ave_p_skill = get_ave(tar_sym, FIRST_P_SKILL, LAST_P_SKILL);
    ave_skill = get_ave(tar_sym, FIRST_SKILL, LAST_SKILL);

    str = sprintf("Average askill: %s\nAverage pskill: %s\nOverall average skill: %s",
      ave_a_skill, ave_p_skill, ave_skill);

    if(who==target) {
	who->tell_me(sprintf("Your skills:\n%s", str));
    }
    else {
	who->tell_me(":%<him.gen_possessive>% skills:\n%<1>%",
	  0,({0,str}),who,target,0);
	target->tell_me(":%<me.capname>% studies you closely. \
%<cap(me.pronoun)>% sees that your average skills are:\n%<1>%"
	  ,0,({0,str}),who,target,0);
	environment(who)->tell_here(":%<me.capname>% examines %<him.name>% \
closely.",0,0,({who,target}),who,target,0);
    }
    return 1;
}

int
clean_up(int arg) {
    destruct(this_object());
    return 0;
}
