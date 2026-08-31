// Aziraphale

#include <std.h>
inherit WEAPON;
 
void create() {
::create();
    set_id(({"bow", "compund bow"}));
    set_name("compund bow");
    set_short("compund bow");
    set_long("This bow is of good quality with a long draw. A good choice for hitting targets at a distance.");
    set_mass(15);
    set_curr_value("gold", 100);
    set_wc(12);
    set_type("ranged");
    set_hands(2);
}
 
void init() {
   ::init();
     add_action("wielding", "wield");
}

int query_auto_load() {
    if (this_player()->query_level() > 36) return 1; 
}

int wielding(string str) {
   object tp;
   tp = this_player();
   if (!str || present(str, tp) != this_object()) return 0;
   if (tp->query_skill("ranged") > 140) return 0;
   write("You do not have the skill to wield this.");
   return 1;
}
