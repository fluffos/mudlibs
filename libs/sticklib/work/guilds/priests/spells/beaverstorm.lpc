#include "priest_spell.h"

void begin_beaverstorm(object who, mixed target);
status end_beaverstorm(object who, mixed target);

void
create_spell() {
    spell_type = SP_OFFENSIVE;
    testing = 1;
    check_target = 1;
    dif = -30;
    lvl = 1;
    cost = 10;
    dam_p = 50; // 50%.. full damage
    skills_used = ({SK_SERENITY, SK_NATURE, SK_FORCES});
    skill_p = ({30,35,35});
    funs = ({ #'begin_beaverstorm, #'end_beaverstorm });
}


void
begin_beaverstorm(object who, mixed target)
{
    HERE->tell_here(":%<me.capname>% point%<me.ending_s>% at \
%<him.name>%, grunting a prayer for " GOD_NAME ".",0,0,0,who,target,0);
}


status
end_beaverstorm(object who, mixed target)
{
    int dam, t;
    object here, sym;

    sym = who->query_guild_object();
    here = HERE;

    who->add_sp(-cost);
    who->tell_me(":Fuzzy beavers fly from the skies at %<him.name>% \
and start chewing %<him.objective>%!",0,0,who,target,0);
    target->tell_me(":Fuzzy beavers fly from %<me.gen_possessive>%'s \
direction at you, hitting you!",
      0,0,who,target,0);
    here->tell_here(":Fuzzy beavers fly from %<me.gen_possessive>%'s \
direction at %<him.name>%, and they start biting %<him.objective>%, \
who moans in pain!",
      0,0,({who,target}),who,target,0);

    t = who->query_level();
    if(t<15)
	inc_skills(who, sym, 150-10*t);

    dam = get_damage(who,sym,interactive(target));
    // let's make sure that we can't cast another attack spell at this round
    who->attacked_by(target,1);
    target->hit_player(dam, DT_MAGICAL, 0, who);
    return 1;
}

