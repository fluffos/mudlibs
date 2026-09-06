#include "priest_potion.h"
#include <conditions.h>

void serenity(int t) {
    int duration, tmp;

    duration = 5 + t/5 + random(t/5);
    if(t>45) t = 45;

    tmp = this_player()->query_condition(RESISTANCE(C_STUNNED));
    tmp = duration / (1 + (tmp / duration));
    this_player()->add_condition(RESISTANCE(C_STUNNED), tmp);
}

void
create_potion() {
    funs = #'serenity;
    lvl = 20;
    cost = 30;
    dif = 30;
    ingredients = ({"giant_sample", "jojojopo", "amaretto_cordial"});
    color = "violet";
    drinker_mess = "As you drink the potion, a great feeling of calm and \
control settles over you.";
    pot_name = "stun resistance";
    skills_used = ({SK_SERENITY, SK_ALCHEMY, SK_STUN_RES});
    skill_p = ({10,30,60});
}
