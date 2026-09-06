#include "priest_spell.h"

void begin_curelight(object who, mixed victim);
status end_curelight(object who, mixed victim);

void
create_spell() {
    spell_type = SP_HEALING;
    check_target = 1;
    dif = -45;
    lvl = 5;
    cost = 15;
    finish_cost = 2*cost/3;
    skills_used = ({SK_SERENITY, SK_LIFE});
    skill_p = ({30,70});
    funs = ({ #'begin_curelight, #'end_curelight });
}

void
begin_curelight(object who, mixed victim)
{
    if(who==victim) {
	who->tell_me("You start chanting a healing prayer, closing \
your eyes and touching your forehead with your left hand's fingertips.");
	HERE->tell_here(":%<me.capname>% starts chanting a prayer, closing \
%<me.possessive>% eyes and making a gesture with %<me.possessive>% left \
hand before %<me.possessive>% face.",0,0,who,who,0,0);
    }
    else {
	who->tell_me(":You start chanting a healing prayer, \
closing your eyes, and raising your left hand towards %<him.name>%.",
	  0,0,who,victim,0);
	HERE->tell_here(":%<me.capname>% start%<me.ending_s>% chanting \
a prayer, raising %<me.possessive>% left hand towards %<him.name>%.",
	  0,0,0,who,victim,0);
    }
    // Now, 1/3 of total cost subtracted...
    who->add_sp(-(cost-finish_cost));
}


status
end_curelight(object who, mixed victim)
{
    int my_level, amount, heal, old_hp_fp, skill;
    object here, sym;

    sym = who->query_guild_object();
    here = HERE;
    my_level = who->query_level();
    skill = get_skill(sym);

    if (skill_roll(sym, skill)>0) {
	who->tell_me(":You succeeded! %<him.capname>% gain%<him.ending_s>% \
some life energy!",0,0,0,victim,0);
	here->tell_here(":%<me.capname>% succeeds in %<me.possessive>% prayer, \
%<cap(him.gen_possessive)>% wounds are healed a little.",
	  0,0,who,who,victim,0);

	// And rest of the sp cost is used here...
	who->add_sp(-finish_cost);
	old_hp_fp = victim->query_hp() + victim->query_fp();
	amount = BALANCE_D->healing(skill,GN_PRIEST,cost);
	amount -= random(amount/4);

	if (critical_success) {
	    who->tell_me("You feel " GOD_NAME " is exceptionally \
pleased with you today!");
	    amount = amount * (105 + random(96)) / 100;
	}
	sym->inform_debugger("Heal amount: " + amount);
	heal = (victim->add_hp(amount) + victim->add_fp(amount) - old_hp_fp) / 2;

	// Should this be removed??
	if (victim != who && sym->is_valid_heal(victim))
	    who->add_exp(heal * 10);

	// no train if player already has full hp / fp
	inc_skills(who,sym,heal * 100 / amount);
    }
    else {
	who->tell_me("But you fail. " GOD_NAME " wasn't on your side \
this time...");
	here->tell_here(":%<me.capname>% finishes %<me.possessive>% chanting, \
but looks rather disappointed." ,0,0,who,who,0,0);
	inc_skills(who,sym,100);
    }
    return 1;
}
