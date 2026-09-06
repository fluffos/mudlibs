#include "priest_spell.h"

#define REG_COST 80
#define REG_FAR_COST 120
#define REG_FAR_LEVEL 24

void begin_regenerate(object who, mixed victim);
status end_regenerate(object who, mixed victim);

void
create_spell() {
    spell_type = SP_HEALING;
    dif = 0;
    lvl = 16;
    cost = -1; // varies
    skills_used = ({SK_SERENITY, SK_LIFE, SK_SPIRITS});
    skill_p = ({25,45,30});
    funs = ({ #'begin_regenerate, #'end_regenerate });
}

void begin_regenerate(object who, mixed data)
{
    object sym, target;
    int cost;

    if(data == "") {
	who->tell_me("Who do you want to regenerate?");
	data = 0;
	return;
    }
    target = find_player(data);
    data = 0;
    if(!target || !living(target) || !interactive(target)) {
	who->tell_me("No such living player.");
	return;
    }
    if(target == who) {
	who->tell_me("You can't regenerate yourself!");
	return;
    }
    if(target->query_hp()>50) {
	who->tell_me(sprintf("%s doesn't need that right now.",
	    target->query_name()));
	return;
    }
    if(EXCOM_D->excomed(target->query_real_name())) {
	who->tell_me("That player is excommunicated and thus does not deserve \
to be healed.");
	return;
    }
    if(present4("pkflag",target,who,IL_TOTALLY_INVISIBLE)) {
	who->tell_me(sprintf("That player is being punished, you can't \
heal %s.", target->query_objective()));
	return;
    }
    if(target->query_ghost()) {
	who->tell_me("That player has already passed the line...");
	return;
    }
    sym = who->query_guild_object();
    if(!present(target, HERE)) {
	if(who->query_level()<REG_FAR_LEVEL) {
	    who->tell_me("Your mind is still too untrained to heal players \
over distance.");
	    return;
	}
	cost = REG_FAR_COST;
    }
    else cost = REG_COST;
    if(sym->query_rank() == EM_RANK)
	cost /= 2;
    if(who->query_sp()<cost) {
	who->tell_me("You chant a few words, but are too weary to complete \
the incantation.");
	return;
    }
    HERE->tell_here(":%<me.capname>% close%<me.ending_s>% %<me.possessive>% \
eyes and chant%<me.ending_s>% softly some words",0,0,0,who,0,0);
    data = ({target, cost});
}

status
end_regenerate(object who, mixed data) {
    object target, sym;
    int cost, skill, amount;

    sym = who->query_guild_object();
    target = data[0];
    cost = data[1];
    who->add_sp(-cost);
    inc_skills(who, sym, 100);
    skill = get_skill(sym);
    if(skill_roll(sym, skill)<0) {
	who->tell_me("You feel no holy power. The spell has failed.");
	return 1;
    }
    who->tell_me(sprintf("You feel the power of the great god " GOD_NAME "! \
You feel that %s has gained healing and life force!",target->query_name()));

    amount = BALANCE_D->healing(skill,GN_PRIEST,cost);
    target->tell_me(":You feel %<me.gen_possessive>% mind reaching for you \
and giving your body health and life force!",0,0,who,0,0);
    target->heal_self(amount-random(amount/2));
    return 1;
}

