// Aziraphale

#include <std.h>
inherit WEAPON;
 
void create() {
::create();
    set_id(({"flail", "spiked flail"}));
    set_name("spiked flail");
    set_short("Spiked flail");
    set_long("This flail is of good quality, though seems to be well used. Not a bad weapon.");
    set_mass(15);
    set_curr_value("gold", 100);
    set_wc(12);
    set_type("flail");
    set_hands(1);
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
   if (tp->query_skill("flail") > 140) return 0;
   write("You do not have the skill to wield this.");
   return 1;
}
