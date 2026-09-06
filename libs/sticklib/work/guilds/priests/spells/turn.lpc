#include "priest_spell.h"

#define TM(x,y,z) (x)->tell_me(y,z,0,who,target,0);
#define TH(x,y,z) HERE->tell_here(x,y,0,z,who,target,0);

void begin_turn(object who, mixed target);
status end_turn(object who, mixed target);

void
create_spell() {
    dif = 0;
    lvl = 1;
    cost = 10;
    spell_damage_rate = 40.0;
    dam_p = 25;
    spell_type = SP_OFFENSIVE;
    check_target = 1;
    skills_used = ({SK_SERENITY, SK_SPIRITS, SK_FORCES});
    skill_p = ({30,50,20});
    funs = ({ #'begin_turn, #'end_turn });
}

void
begin_turn(object who, mixed target)
{
    if(!target->query(LIV_UNDEAD)) {
	who->tell_me("That is not an undead living, it can't be turned!");
	target = 0;
    }
    else {
	TH(({
	    ":%<me.capname>% show%<me.ending_s>% the symbol of " GOD_NAME " to \
%<him.name>% and begin to chant.",
	    "You hear someone beginning to chant.",
	  }), ({LIV_CAN_SEE, LIV_CAN_HEAR}),0);
    }
}


status
end_turn(object who, mixed target)
{
    object sym;
    int chance, dam, my_l, tar_l, skill, t;

    sym = who->query_guild_object();

    skill = get_skill(sym);
    inc_skills(who, sym, get_attack_spell_train(who, sym, target));

    cost = 10;
    if(who->query_sp() < cost) {
	who->tell_me("You are too tired to finish your chanting.");
	return 0;
    }
    who->add_sp(-cost); 

    my_l = who->query_level();
    tar_l = target->query_level();
    chance = my_l - tar_l + skill/100;
    t = 100 * (chance + 15) / 30;
    chance += random(30);

    spell_damage_rate = 40.0 + 40.0 * skill / 1000.0;
    dam = get_damage(who,sym,interactive(target));

    sym->inform_debugger(sprintf("probability: %d, cost: %d, damage: %d",
	t, cost, dam));

    cost = -1; // let's reset it so that "spells" list knows
    // that the cost varies

    if (chance <= 0) {  
	TM(who,":You finish your chanting, but notice that %<him.name>% \
is too strong to be harmed by your measle chanting!",0);
	TH(({
	    ":%<me.capname>% ends %<me.possessive>% chanting and looks at \
%<him.objective>%. %<me.capname>% looks dissapointed.",
	    "The chanting ends.",
	  }), ({LIV_CAN_SEE, LIV_CAN_HEAR}), who);
	target->attacked_by(who, 1); // let's make it aggressive!
	return 1;
    }

    if (chance < 15) {
	TM(who,":You finish your chanting, but to your disappointment, \
%<him.name>% seems unaffected by the divine curse!",0);
	TH(({
	    ":%<me.capname>% ends %<me.possessive>% chanting, and looks at \
 %<him.name>%. %<me.capname>% looks surprised and somewhat dissapointed.",
	    "The chanting ends.",
	  }), ({ LIV_CAN_SEE, LIV_CAN_HEAR }), who);
	return 1;
    }

    if(chance < 35) {
	TH(({
	    ":As %<me.name>% finish%<me.ending_es>% %<me.possessive>% chanting, \
the divine wrath hits %<him.name>%.",
	    "The chanting ends.",
	  }), ({ LIV_CAN_SEE, LIV_CAN_HEAR }),0);
	HERE->tell_here(({
	    ":%<cap(me.gen_possessive)>% face twist%<me.ending_es>% in agony.",
	  }), ({ LIV_CAN_SEE }), 0, 0, target, 0, 0);  
    }
    else {
	TH(({
	    ":As %<me.name>% finish%<me.ending_es>% %<me.possessive>% chanting, \
the divine wrath roasts %<him.name>%",
	    "The chanting ends.",
	  }), ({ LIV_CAN_SEE, LIV_CAN_HEAR}) ,0);
	HERE->tell_here(({
	    ":%<cap(me.gen_possessive)>% face twist%<me.ending_es>% in utter agony.",
	  }), ({ LIV_CAN_SEE }), 0, 0, target, 0, 0);  

	dam += random(dam);
    }

    who->attacked_by(target, 0);
    target->hit_player(dam, DT_NEGATIVE, random(10), who);
    return 1;
}
