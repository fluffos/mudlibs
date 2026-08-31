#include <std.h>
inherit ARMOUR;

void create() {
::create();
set_name("bracer");
set_short("%^BOLD%^ORANGE%^D%^RESET%^ORANGE%^war%^BOLD%^ORANGE%^ve%^RESET%^ORANGE%^n%^BOLD%^ Fo%^RESET%^ORANGE%^r%^BOLD%^ORANGE%^ge%^RESET%^ORANGE%^d%^RESET%^ Bracer%^RESET%^");
set_long("The dwarves make these bracers and sell them to others for a heavy profit.  They are lightweight and offer excellent protection.  They are also quite valuable.");
set_id(({"bracer", "dwarven forged bracer", "dwarven bracer", "forged bracer"}));
set_ac(2);
set_weight(4);
set_curr_value("gold",75);
set_type("bracers");
set_limbs(({"left arm"}));
}
int query_auto_load() {return 1; }

int CheckArmour(string str) {
   object ob;
   if (!str) return 0;
   ob = present(str, this_player());
   if (!ob || ob != this_object()) return 0;
   if (this_player()->query_armour("left arm") != ({ })) {
      write("You cannot wear the bracer with other armour on that limb.");
      return 1;
   }
   return 0;
}

void init() {
 ::init();
   add_action("CheckArmour", "wear");
}
