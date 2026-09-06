#include "priest_potion.h"

void
les_res(int t)
{
    int res_amount;

    res_amount = 10 + t/4 + random(t/3);
    this_player()->add_sp(res_amount);
}

void
create_potion() {
    funs = #'les_res;
    lvl = 5;
    cost = 5;
    dif = -20;
    ingredients = ({"dark elf_sample", "amaretto"});
    color = "cloudy";
    drinker_mess = "Your concentration improves slightly.";
    pot_name = "lesser restore mana";
    skills_used = ({SK_SERENITY, SK_ALCHEMY, SK_LES_RES});
    skill_p = ({10,30,60});
}
