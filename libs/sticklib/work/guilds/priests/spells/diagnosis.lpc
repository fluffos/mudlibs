#include "priest_spell.h"

#define HP_STRS ({"in terrible", "in bad", "not in a good", "in good", \
"in excellent"})
#define SP_STRS ({"exhausted", "very tired", "tired", "quite alert", \
"very alert"})
#define FP_STRS ({"exhausted", "very tired", "tired", "relaxed", \
"very relaxed"})

void begin_diagnosis(object who, mixed target);
status end_diagnosis(object who, mixed target);

void
create_spell() {
    lvl = 9;
    cost = 10;
    funs = ({ #'begin_diagnosis, #'end_diagnosis });
    skills_used = ({ });
}


void
begin_diagnosis(object who, mixed target) {
    if(!who->query_can_see()) {
	who->tell_me("But you can't see anything!");
	return;
    }
    if(!target || !(target = present(target, HERE))) {
	who->tell_me("You can't see any such living being here.");
	return;
    }
    if(target == who) {
	who->tell_me("Use 'sc' command instead.");
	target = 0;
	return;
    }
    else {
	HERE->tell_here(":%<me.capname>% touch%<me.ending_es>% %<him.name>% \
gently.",0,0,0,who,target,0);
    }
}

status
end_diagnosis(object who, mixed target) {
    string hp_str, sp_str, fp_str;

    who->add_sp(-cost);
    hp_str = HP_STRS[target->query_hp()*9/(target->query_max_hp()+1)/2];
    sp_str = SP_STRS[target->query_sp()*9/(target->query_max_sp()+1)/2];
    fp_str = FP_STRS[target->query_fp()*9/(target->query_max_fp()+1)/2];
    if(interactive(target)) {
	who->tell_me(":%<him.capname>% is %<1>% condition, \
mentally %<him.pronoun>% is %<2>%, physically \n%<him.pronoun>% is %<3>%.",
	  0,({0,hp_str, sp_str, fp_str}),0,target,0);
    } else {
	who->tell_me(":%<him.capname>% is %<1>% condition, \
mentally %<him.pronoun>% is %<2>%.",
	  0,({0,hp_str, sp_str, fp_str}),0,target,0);
    }
}
