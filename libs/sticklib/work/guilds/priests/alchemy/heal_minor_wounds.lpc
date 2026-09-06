#include "priest_potion.h"

void
heal_min(int t)
{
    int heal_amount;

    heal_amount = 10 + t/4 + random(t/3);
    this_player()->add_hp(heal_amount);
}

void
create_potion() {
    funs = #'heal_min;
    lvl = 5;
    cost = 5;
    dif = -20;
    ingredients = ({"gnome_sample", "beer"});
    color = "azure";
    drinker_mess = "A couple of scratches fade and disappear.";
    pot_name = "heal minor wounds";
    skills_used = ({SK_SERENITY, SK_ALCHEMY, SK_HEAL_MIN});
    skill_p = ({10,30,60});
}
