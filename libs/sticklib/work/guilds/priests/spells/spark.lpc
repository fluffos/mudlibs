#include "priest_spell.h"

void begin_spark(object who, mixed target);
status end_spark(object who, mixed target);

void
create_spell() {
    spell_type = SP_OFFENSIVE;
    check_target = 1;
    dif = -30;
    lvl = 1;
    cost = 10;
    spell_damage_rate = 15.0;
    dam_p = 50; // 50%.. full damage
    skills_used = ({SK_SERENITY, SK_NATURE, SK_FORCES});
    skill_p = ({30,35,35});
    funs = ({ #'begin_spark, #'end_spark });
}


void
begin_spark(object who, mixed target)
{
    HERE->tell_here(":%<me.capname>% point%<me.ending_s>% at \
%<him.name>%, praying for " GOD_NAME ".",0,0,0,who,target,0);
}


status
end_spark(object who, mixed target)
{
    int dam, t;
    object here, sym;

    sym = who->query_guild_object();
    here = HERE;

    who->add_sp(-cost);
    who->tell_me(":Small sparks fly from your fingertips at %<him.name>% \
and burn %<him.objective>%.",0,0,who,target,0);
    target->tell_me(":Small sparks fly from %<me.gen_possessive>% \
fingertips at you, burning small wounds on you.",
      0,0,who,target,0);
    here->tell_here(":Small sparks fly from %<me.gen_possessive>% \
fingertips at %<him.name>%, and when they hit %<him.objective>%, they \
burn nasty looking wounds on %<him.objective>%.",
      0,0,({who,target}),who,target,0);

    t = who->query_level();
    if(t<15)
	inc_skills(who, sym, 150-10*t);

    dam = get_damage(who,sym,interactive(target));
    // let's make sure that we can't cast another attack spell at this round
    who->attacked_by(target,1);
    target->hit_player(dam, DT_FIRE, 0, who);
    return 1;
}
