// Modified 07-oct-95 by Doomdark; fixed this to work with new
// stat-system.

#include "priest_spell.h"

void begin_restore(object who, mixed victim);
status restore_stat(object who, mixed victim);

mapping stats;

void
create_spell() {
    spell_type = SP_HEALING;
    dif = 20;
    lvl = 22;
    cost = 120;
    skills_used = ({SK_SERENITY, SK_LIFE});
    skill_p = ({30,70});
    funs = ({ #'begin_restore, #'restore_stat });

    stats = ([
      "str": ST_STR; ST_BASE_STR,
      "con": ST_CON; ST_BASE_CON,
      "dex": ST_DEX; ST_BASE_DEX,
      "int": ST_INT; ST_BASE_INT,
    ]);
}

mixed
parse_target_string(string s) {
    string stat_name, tar_name;
    int stat;

    notify_fail("Restore what ability, and to whom?\n");
    if(!s) return 0;
    s = lower_case(s);
    if(sscanf(s, "%s to %s", stat_name, tar_name)!=2)
	return 0;
    stat_name = stat_name[0..2];
    if(!member(stats, stat_name))
	return notify_fail("No such ability.\n"),-1;
    return ({tar_name, stat_name});
}

void
begin_restore(object who, mixed data)
{
    string stat, name;
    object target;

    name = data[0];
    stat = data[1];
    data = 0;
    target = find_player(name);
    if(!target || ENV(target) != HERE) {
	who->tell_me("No such player here.");
	return;
    }
    if(EXCOM_D->excomed(target->query_real_name())) {
	who->tell_me("That player is excommunicated and thus does not deserve \
to be healed.");
	data = 0;
	return 0;
    }


    if (target->query_stat(ST_DRAINED + stats[stat,0]) >=
      target->query_stat(stats[stat,1])) {
	who->tell_me("That player doesn't seem to need it.");
	return;
    }
    HERE->tell_here(":%<me.capname>% start%<me.ending_s>% chanting a prayer.",
      0,0,0,who,0,0);
    data = ({target, stat});
}

status
restore_stat(object who, mixed data)
{
    string stat;
    object sym, target;
    int amount, skill;

    target = data[0];
    stat = data[1];
    if(!target || ENV(target) != HERE) {
	who->tell_me("You've lost your target.");
	return 1;
    }
    sym = who->query_guild_object();
    skill = get_skill(sym);
    inc_skills(who,sym,100);
    who->add_sp(-cost);
    if(skill_roll(sym, skill)<0) {
	who->tell_me("You fumbled the prayer.");
	if (critical_failure && who->query_luck()<0) {
	    who->tell_me("The prayer backfires! You feel stupider!");
	    who->add_stat(ST_INT, -1);
	}
	return 1;
    }
    who->tell_me("Your prayer was heard!"); 
    HERE->tell_here(":%<me.capname>% seems to have healed %<him.name>% \
in some mysterious way.", 0,0,({who, target}),who,target,0);

    amount = target->query_stat(stats[stat,1])
    - target->query_stat(stats[stat,0] + ST_DRAINED);
    if(amount>5)
	amount = 5;
    if(amount>1)
	amount = random(amount) + 1;

    write_file(RESTORELOG, sprintf("%s %s restored %s to %s\n",
	ctime(time()),who->query_real_name(),stat,
	target->query_real_name()));
    if (amount<0) {
	who->tell_me("Error in restore; try to contact the guild coder!");
	return 1;
    }

    target->add_stat(stats[stat,0], amount);
    switch(stat) {
    case "str":
	target->tell_me("You feel stronger!"); break;
    case "con":
	target->tell_me("You feel hardier!"); break;
    case "int":
	target->tell_me("You feel more intelligent!"); break;
    case "dex":
	target->tell_me("You feel nimbler!"); break;
    }
}

