#include <std.h>
inherit WEAPON;

create() {
 ::create();
   set_id(({ "dagger", "kris" }));
   set_name("kris");
   set_short("a deadly kris");
   set_long("A dagger with a greyish black, serpentine, double edged "
     "blade. It's handle is black. It is made to maximize the damage "
     "of a wound it inflicts, by tearing it open unevenly beneath the "
     "skin.");
   set_weight(7);
    set_curr_value("gold", 28);
   set_wc(6);
   set_type("knife");
}

int query_auto_load() { if (this_player()->query_skill("knife") >= 20) return 1; }
