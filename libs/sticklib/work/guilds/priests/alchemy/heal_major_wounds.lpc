#include "priest_potion.h"

void
heal_maj(int t)
{
    int heal_amount;

    heal_amount = 30 + t/2 + random(t/2);
    this_player()->add_hp(heal_amount);
}

void
create_potion() {
    funs = #'heal_maj;
    lvl = 12;
    cost = 20;
    dif = 20;
    ingredients = ({"troll_sample", "special"});
    color = "emerald";
    drinker_mess = "Some of your wounds fade before your eyes.";
    pot_name = "heal major wounds";
    skills_used = ({SK_SERENITY, SK_ALCHEMY, SK_HEAL_MAJ});
    skill_p = ({10,30,60});
}
