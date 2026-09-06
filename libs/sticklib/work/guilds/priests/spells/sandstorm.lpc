#include "priest_spell.h"

void begin_sandstorm(object who, mixed target);
status end_sandstorm(object who, mixed target);

void
create_spell() {
    spell_type = SP_OFFENSIVE;
    check_target = 1;
    dif = 10;
    lvl = 15;
    cost = 25;
    spell_damage_rate = 40.0;
    dam_p = 50; // 50%.. full damage
    skills_used = ({SK_SERENITY, SK_NATURE, SK_FORCES});
    skill_p = ({30,35,35});
    funs = ({ #'begin_sandstorm, #'end_sandstorm });
}


void
begin_sandstorm(object who, mixed target)
{
    HERE->tell_here(({":%<me.capname>% point%<me.ending_s>% %<me.possessive>% \
hands at the heavens, chanting a prayer.", ":%<me.capname>% point\
%<me.ending_s>% %<me.possessive>% hands at the heavens.",
	"You hear someone chanting a prayer"}),
      ({LIV_CAN_SEE | LIV_CAN_HEAR, LIV_CAN_SEE, LIV_CAN_HEAR}),
      0,0,who,target,0);
}


status
end_sandstorm(object who, mixed target)
{
    int dam, t;
    object here, sym;

    sym = who->query_guild_object();
    here = HERE;

    who->add_sp(-cost);
    // These messages need adding something
    who->tell_me(":You raise a small, but furious storm of sand from the earth \
to whirl around %<him.name>%.",0,0,who,target,0);
    target->tell_me(":%<me.capname>% raises a small sand storm around you! \
The sand scratches your skin badly and makes it difficult to breath.",
      0,0,who,target,0);
    here->tell_here(":%<me.capname>% raises a small sand storm around \
%<him.name>%! The sand scratches bad wounds to %<him.gen_possessive>% skin \
and makes %<him.objective>% wither in pain.",0,0,({who,target}),who,target,0);

    inc_skills(who, sym, get_attack_spell_train(who, sym, target));

    dam = get_damage(who,sym,interactive(target));
    // let's make sure that we can't cast another attack spell at this round
    who->attacked_by(target,1);
    target->hit_player(dam, DT_EARTH, 2, who);
    return 1;
}
