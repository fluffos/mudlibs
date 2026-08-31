#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("tailties");
    set_short("centaur tail ties");
    set_id(({ "ties", "tail ties", "tailties", "centaur ties" }));
    set_long("They can be tied onto a centaur's tail.");
    set_weight(2);
    set_curr_value("gold", 5);
    set_type("armour");
    set_limbs(({ "tail" }));
    set_ac(2);
}

int query_auto_load() { if(this_player()->query_race() == "centaur") return 1;
}
int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_race() == "centaur") return 0;
   write("These are not meant for you.");
   say(this_player()->query_cap_name()+" dosent have a horses tail.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
}

