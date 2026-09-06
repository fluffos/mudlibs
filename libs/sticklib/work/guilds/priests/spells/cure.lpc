/* Added new spell 24.10.92 //Hawthorn */
/* fixed to cure any single disease 170293 //Haw */

#include "priest_spell.h"

void begin_cure(object who, mixed data);
status cure_disease(object who, mixed data);

void
create_spell() {
    dif = 20;
    lvl = 20;
    duration = 3;
    cost = 100;
    skills_used = ({SK_SERENITY, SK_LIFE});
    skill_p = ({30,70});
    funs = ({ #'begin_cure, #'cure_disease });
}

void
begin_cure(object who, mixed data)
{
    string tar_name;
    object target;
    string str;

    tar_name = data;
    data = 0;

    if(tar_name == "") {
	who->tell_me("Cure who?");
	return;
    }
    target = find_player(lower_case(tar_name));
    if(!target || !present(target,HERE) || !living(target)) {
	who->tell_me("That player is not here.");
	return;
    }
    if(EXCOM_D->excomed(target->query_real_name())) {
	who->tell_me("That player is excommunicated and thus does not deserve \
to be healed.");
	return;
    }

    str = ":%<me.capname>% start%<me.ending_s>% mumbling a prayer";
    if(who!=target) str += " and thouch%<me.ending_s>% %<him.name>% gently.";
    HERE->tell_here(str,0,0,0,who,target,0);
    data = target;
}

status
cure_disease(object who, mixed data)
{
    object target, disease, sym;
    string dis_name,a,b,c,d;
    int skill;

    sym = who->query_guild_object();
    target = data;
    if(ENV(target) != HERE) {
	who->tell_me("You have lost your patient");
	return 1;
    }

    disease = present("disease",target);
    if(!disease) {
	if(target==who) a = "you are";
	else a = "that player is";
	who->tell_me(sprintf("But %s not diseased!",a));
	return 1;
    }
    dis_name = disease->query_nickname();
    if(!dis_name) dis_name = disease->query_name();
    dis_name = lower_case(dis_name);
    skill = get_skill(sym);
    inc_skills(who, sym, 100);
    who->add_sp(-cost);

    if(skill_roll(sym, skill)>0) {
	HERE->tell_here(":%<me.capname>% succeeded in %<me.possessive>% \
prayer!",0,0,0,who,0,0);
	if(target==who) {
	    who->tell_me(sprintf("Your body is again pure from the %s.",
		dis_name));
	    HERE->tell_here(sprintf("%s has recovered from the %s",
		who->query_name(), dis_name),who);
	}
	else {
	    who->tell_me(sprintf("%s's body is again pure from the %s.",
		target->query_name(), dis_name));
	    HERE->tell_here(sprintf("%s has recovered from the %s.",
		target->query_name(), dis_name),({who,target}));
	    target->tell_me(sprintf("You have recovered from the %s!",
		dis_name));
	}
	disease->remove();
    }
    else {
	who->tell_me("You didn't concentrate hard enough. The prayer fails.");
	HERE->tell_here(":%<him.capname>% fails in %<him.possessive>% prayer.",
	  0,0,who,0,who,0);

	/* A chance that priest gets infected if he/she fails: */

	if(critical_failure && !present("disease",who)) {
	    disease = clone_object("/obj/disease");
	    move_object(disease,who);
	    disease->set_disease(dis_name);
	    who->tell_me("You got infected!");
	}
    }
    return 1;
}
