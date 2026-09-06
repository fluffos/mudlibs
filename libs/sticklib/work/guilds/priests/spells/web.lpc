#include "priest_spell.h"

void begin_web(object who, mixed victim);
status end_web(object who, mixed victim);

void
create_spell() {
    spell_type = SP_OFFENSIVE;
    check_target = 1;
    dif = 0;
    lvl = 12;
    cost = 35;
    skills_used = ({SK_SERENITY, SK_NATURE, SK_SPIRITS});
    skill_p = ({30,40,30});
    order_restriction = ({ 1 });
    funs = ({ #'begin_web, #'end_web });
}


void
begin_web(object who, mixed victim)
{
    if(victim->query_condition(C_STUNNED)) {
	who->tell_me("But "+victim->query_name()+" is unable to move already.");

	victim = 0;
	return;
    }
    HERE->tell_here(":%<me.capname>% start%<me.ending_s>% chanting."
      ,0,0,0,who,0,0);
}


status
end_web(object who, mixed victim)
{
    object here,sym;
    int myluck,eneluck;
    int mylvl,enelvl;
    int i,j,k;
    int dur, skill;

    sym = who->query_guild_object();

    here = HERE;
    if (!victim->attacked_by(who,0)) {
	who->tell_me("Something made you fail the web prayer!");
	return 1;
    }
    who->add_sp(-cost);

    myluck = who->query_luck();
    eneluck = victim->query_luck();
    mylvl = who->query_level();
    enelvl = victim->query_level();

    skill = get_skill(sym);
    i = (myluck + mylvl) + skill/20;
    j = eneluck + enelvl;
    k = 5 + (mylvl/5); // Give break as level increases.

    inc_skills(who, sym, 50 + j);
    if(random(i) + k >= random(j)) {
	dur = BALANCE_D->duration(skill,GN_PRIEST,cost);
	if(interactive(victim)) dur /= 4;
	sym->inform_debugger("Duration: " + dur + ".");
	if(victim->set_condition(C_STUNNED,dur)) {
	    who->tell_me(":You finish your prayer, pointing your hands at \
%<him.name>%. A Web forms out of nowhere, like a flash from the \
heavens, trapping %<him.name>%!",0,0,who,victim,0);
	    here->tell_here(":%<me.capname>% points %<me.possessive>% hands at \
%<him.name>%, and a Web forms out of nowhere trapping %<him.name>%!",
	      0,0,who,who,victim,0);
	    who->attacked_by(victim,0);
	    return 1;
	}
    }
    who->tell_me(GOD_NAME+" is against you, you fail in the spell!");
    here->tell_here(":%<me.capname>% looks disappointed.",0,0,who,who,0,0);
    return 1;
}
