/* Added 28.10.92 //Hawthorn */

#include "priest_spell.h"

void begin_disease(object who, mixed target);
status cause_disease(object who, mixed target);

void
create_spell() {
    spell_type = SP_OFFENSIVE;
    check_target = 1;
    duration = 3;
    dif = 40;
    lvl = 23;
    cost = 200;
    skills_used = ({SK_SERENITY, SK_LIFE});
    skill_p = ({30,70});
    funs = ({ #'begin_disease, #'cause_disease });
}


void begin_disease(object who, mixed target)
{
    if(!interactive(target)) {
	target = 0;
	who->tell_me("That's not a player.");
	return;
    }
    HERE->tell_here(":%<me.capname>% quietly speaks out a horrible curse \
pointing at %<him.name>%.",0,0,0,who,target,0);
}

status
cause_disease(object who, mixed target) {
    object plague, sym;
    int all, skill;

    sym = who->query_guild_object();

    write_file(DISEASELOG,sprintf("%s %s diseased %s\n",ctime(time()),
	who->query_real_name(),target->query_real_name()));

    inc_skills(who,sym,100);
    skill = get_skill(sym);
    all = who->query_sp();
    who->add_sp(-(all/2+random(all/2)));
    if (skill_roll(sym, skill)>0) {
	who->tell_me(sprintf("Your exorcise has succeeded, the plague \
is raging in %s's body!",target->query_name()));
	plague = clone_object("obj/disease");
	plague->set_disease("plague");
	move_object(plague, target);
	return 1;
    }
    who->tell_me("You failed in your exorcise!");
    if(critical_failure) {
	plague = clone_object("obj/disease");
	plague->set_disease("plague");
	move_object(plague, who);
	who->tell_me("You infected yourself!");
    }
    return 1;
}

