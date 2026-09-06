#include "priest_potion.h"
#include <conditions.h>
#include <room_defs.h>

void
poison(int t)
{
    int dur;

    dur = 5 + t/2 + random(t/2);
    this_player()->add_condition(C_POISONED,dur);
    this_player()->add_hp(-dur/2); // let's do some damage too
}


status
poison_em(object who, mixed data) {
    int l, dur;
    object where, ob;

    if(!data) return 0;
    where = data[0];
    l = data[1];
    ob = clone_object(PRIEST_OBJ_DIR "area_poison");
    dur = 10 + l/2 + random(l/2);
    if(where->query(ROOM_WD, WD_OUTDOORS))
	dur = dur / 2 - nature()->query_wind();
    if(dur<2) dur = 2;
    ob->set_duration(dur);
    move_object(ob, where);
    return 1;
}

void
create_potion() {
    funs = #'poison;
    smash_funs = ({ #'begin_smash, #'poison_em });
    lvl = 15;
    cost = 15;
    dif = 15;
    ingredients = ({ 
      ({"scorpion_sample", "spider_sample", "snake_sample"}),
      "special",
    });
    color = "clear";
    drinker_mess = "Hmm... not much happens...";
    pot_name = "poison";
    skills_used = ({SK_SERENITY, SK_ALCHEMY, SK_POISON});
    skill_p = ({10,30,60});
}
