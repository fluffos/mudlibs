#include "priest_potion.h"

void
invis(int t)
{
    object ob;
    int duration;

    duration = 20 + t/3 + random(t/4);
    if(t>100) t = 100;
    this_player()->invis(100 + t*4);
    ob = clone_object(PRIEST_OBJ_DIR "invis_ob");
    ob->inv_time(duration);
    move_object(ob,this_player());
}

void
create_potion() {
    funs = #'invis;
    lvl = 10;
    cost = 15;
    dif = 0;
    ingredients = ({"orc_sample", "amaretto"});
    color = "indigo";
    drinker_mess = "";
    pot_name = "invisibility";
    skills_used = ({SK_SERENITY, SK_ALCHEMY, SK_INVIS});
    skill_p = ({10,30,60});
}
