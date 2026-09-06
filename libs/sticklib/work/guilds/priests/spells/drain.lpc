#include "priest_spell.h"

void begin_drain(object who, mixed victim);
status end_drain(object who, mixed victim);

mapping stats;

#define STAT_NAMES ({"str", "int", "con", "dex"})


void
create_spell() {
    spell_type = SP_OFFENSIVE;
    dif = 40;
    lvl = 22;
    cost = 120;
    duration = 3;
    skills_used = ({SK_SERENITY, SK_LIFE});
    skill_p = ({30,70});
    funs = ({ #'begin_drain, #'end_drain });

    stats = ([
      "str": ST_STR, "strength":   ST_STR,
      "con": ST_CON, "constitution":  ST_CON,
      "dex": ST_DEX, "dexterity":  ST_DEX,
      "int": ST_INT, "intelligency":  ST_INT,
    ]);
}

mixed
parse_target_string(string s) {
    string stat_name, tar_name;
    int stat;

    notify_fail("Drain what from whom?\n");
    if(!s) return 0;
    s = lower_case(s);
    if(sscanf(s, "%s from %s", stat_name, tar_name)!=2)
	return 0;
    if(!member(stats, stat_name))
	return notify_fail("No such ability.\n"),0;
    stat = stats[stat_name];
    return ({tar_name, stat});
}

void
begin_drain(object who, mixed data)
{
    string tar_name;
    object target;
    int stat;

    tar_name = data[0];
    stat = data[1];
    data = 0;
    if (!(target = present(tar_name, HERE))) {
	who->tell_me(sprintf("Can't see any '%s' here.",tar_name));
	return;
    }
    if (!target->query(LIV_IS_PLAYER)) {
	who->tell_me("This spell only works on players.");
	return;
    }
    if (target == who) {
	who->tell_me("You can't be serious!");
	return;
    }
    HERE->tell_here(":%<me.capname>% start%<me.ending_s>% chanting.",
      0,0,0,who,0,0);
    data = ({target,stat});
}

status
end_drain(object who, mixed data)
{
    int amount,t,stat,s,skill;
    object target, here, sym;

    target = data[0];
    stat = data[1];
    sym = who->query_guild_object();
    here = HERE;
    if (!target || ENV(target) != here){
	who->tell_me("You've lost your target.");
	return 0;
    }
    if(!(target->attacked_by(who,-1))){
	who->tell_me("You feel " GOD_NAME " is less than pleased.");
	return 1;
    }
    who->attacked_by(target,0);
    target->attacked_by(who);
    who->add_sp(-cost);
    skill = get_skill(sym);
    s = skill_roll(sym, skill);

    t = who->query_level();
    t = 50*(target->query_level() - t) / t;
    inc_skills(who,sym,50+t);
    s += 2*t;
    if(s<0) {
	who->tell_me("You failed in your chanting.");
	if(critical_failure && who->query_luck() < 0) {
	    who->tell_me("The prayer backfires! You feel stupider!");
	    who->add_stat(ST_INT,-1);
	}
	return 1;
    }

    who->tell_me(":%<me.capname>% succeed%<me.ending_s>% in %<me.possessive>% \
prayer! %<him.capname>% flinche%<him.ending_s>% back as if %<him.pronoun>%'d \
been struck!",0,0,who,target,0);

    amount = 2;
    if(critical_success)
	amount++;

    target->add_stat(stat, -amount);

    write_file(DRAINLOG, sprintf("%s %s drained %s from %s\n",
	ctime(time()),who->query_real_name(),STAT_NAMES[stat-1],
	target->query_real_name()));

    switch(stat) {
    case ST_STR :
	target->tell_me("You feel weaker!");
	break;
    case ST_CON : 
	target->tell_me("You feel frailer!");
	break;
    case ST_INT : 
	target->tell_me("You feel stupider!");
	break;
    case ST_DEX :
	target->tell_me("You feel clumsier!");
	break;
    }
    return 1;
}

