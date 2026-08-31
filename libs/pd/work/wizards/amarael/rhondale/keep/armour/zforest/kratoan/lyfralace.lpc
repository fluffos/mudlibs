// This item is only held until you finish the quest, you can only get it once.
// Hence, the good AC.

#include <std.h>
inherit ARMOUR;
 
void create() {
::create();
    set_property("no steal", 1);
    set_id(({"amulet", "leaf amulet", "lyfralace"}));
    set_name("leaf amulet");
    set_short("%^RESET%^GREEN%^Leaf amulet%^RESET%^");
    set_long("This amulet is a simple leaf, it hardly seems worth all the trouble of getting it.");
    set_mass(1);
    set_curr_value("gold", 0);
    set_ac(5);
    set_type("necklace");
    set_limbs(({"head"}));
    set_wear("%^RESET%^GREEN%^You slip the amulet around your neck.%^RESET%^");
}

void init() {
   ::init();
     if(member_array("kratoan", this_player()->query_quests()) || present("lyfralace 2", this_player()))
     add_action("nostore", "store");
       this_object()->remove();
}

int query_auto_load() { if(this_player()->query_level() > 49) return 1; else return 0; }

int drop() { return 1; }

int get() { return 1; }

int give() { return 1; }

int bury() { return 1; }

int nostore(string str) {
    if((str == "amulet" || str == "leaf amulet" || str == "lyfralace") && present(str, this_player()) == this_object()) { write("It would be best to hang onto this."); return 1; }
    return 0;
}
