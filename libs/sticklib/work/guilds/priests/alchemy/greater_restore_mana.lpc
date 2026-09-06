#include "priest_potion.h"

void
gre_res(int t)
{
    int res_amount;

    res_amount = 30 + t/2 + random(t/2);
    this_player()->add_sp(res_amount);
}

void
create_potion() {
    funs = #'gre_res;
    lvl = 12;
    cost = 20;
    dif = 20;
    ingredients = ({"giant_sample", "special"});
    color = "swirly";
    drinker_mess = "You feel that your concentration improves!";
    pot_name = "greater restore mana";
    skills_used = ({SK_SERENITY, SK_ALCHEMY, SK_GRE_RES});
    skill_p = ({10,30,60});
}
