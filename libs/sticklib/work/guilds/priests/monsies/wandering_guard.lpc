/* New guard for the priests's guild */
#include <npc_defs.h>
#include "../priest.h"

inherit PRIEST_MON_DIR "templar";

void create_monster(){                    
    ::create_monster();
    set_wander(15);
    set_level(30); // Was 20
    set_ep(1000000);
    set_hp(3000); // Was 2000
    set_wc(45);
    set_ac(32);
    set_follow(1,1,4,3);
    set_keep_hb(-30);
}

