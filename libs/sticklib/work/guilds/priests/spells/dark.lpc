#include "priest_spell.h"
#include <lights.h>

status dark(object who, mixed data);

void
create_spell() {
    dif = -20;
    lvl = 2;
    duration = 3;
    cost = 5;
    skills_used = ({SK_SERENITY, SK_NATURE});
    skill_p = ({30,70});
    funs = ({ #'gen_begin_spell, #'dark });
}

status
dark(object who, mixed data) {
    object sym;
    int old_l, could_see;

    sym = who->query_guild_object();
    old_l = sym->query_light_level();
    if(old_l) {
	who->tell_me(sprintf("But you already have an aura of %s surrounding \
you", (old_l>0) ? "light":"darkness"));
	return 1;
    }
    who->add_sp(-cost);
    inc_skills(who,sym,100);
    /* Lasted far too little time, changed /8 to /5 ++Baccata */
    // still too short: /5 to /4
    call_out("extinguish_dark", get_skill(sym)/4 + random(50),
      who, sym);
    could_see = who->query_can_see();
    sym->set_light_level(-3);
    if(!could_see && who->query_can_see())
	who->tell_me("You can see again!");
    who->tell_me(GOD_NAME " enshrouds you in an aura of darkness.");
    HERE->tell_here(":%<me.capname>% is enshrouded in an aura of darkness."
      ,0,0,who,who,0,0);
    return 1;
}

void
extinguish_dark(object who, object sym)
{
    if(sym)
	sym->set_light_level(0);
    if (who)
	who->tell_me("The aura of darkness around you dims and fades away.");
}
