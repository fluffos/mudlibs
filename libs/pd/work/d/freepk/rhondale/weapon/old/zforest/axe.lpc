// Aziraphale

#include <std.h>
inherit WEAPON;
 
void create() {
::create();
    set_id(({"axe", "hunting axe"}));
    set_name("hunting axe");
    set_short("hunting axe");
    set_long("This axe has a very sharp edge and looks excellent for use in hunting animals.");
    set_mass(15);
    set_curr_value("gold", 100);
    set_wc(12);
    set_type("axe");
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
   if (tp->query_skill("axe") > 140) return 0;
   write("You do not have the skill to wield this.");
   return 1;
}
