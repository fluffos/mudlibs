#include "/gilden/bardengilde/barden_extern.h"
#include <wizlevels.h>

public void checkForBardItem(object pl, int chance) {
    object ob;

    if(IS_LEARNER(pl)) {
        tell_object(pl, sprintf("checkForBardItem: %O %d\n", pl, chance));
    }

    if(pl->QueryProp(P_GUILD) != "bardengilde") return;
    if( call_other("/gilden/bardengilde/master/bardenmaster", "GetBardGroup", pl) != BARD_GROUP_ALESTRA)
        return;
	if(pl->QuerySkill("haette ich ein herz") != 0) return;
    if(objectp(present(BARD_ID_GS8_KERZE, pl))) return;

    if(random(chance)) return;

    ob = clone_object("/gilden/bardengilde/obj/quest/gs8_alestra_task");
    if(ob->move(pl, M_GET) != 1) {
        tell_object(pl, BS("Dieser Vampir hatte die Grabkerze also! Leider kannst du sie "
                           "nicht mehr tragen."));
        ob->remove(1);
    } else {
        tell_object(pl, BS("Du findest die Grabkerze in den sterblichen Ueberresten des Vampris."));
    }
}

public void die(int pd) {
    object killer;

    killer = QueryProp(P_KILLER) || TP;
    if(objectp(killer)) checkForBardItem(killer, 3);

    ::die(pd);
}