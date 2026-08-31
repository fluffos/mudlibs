#include <std.h>
inherit ARMOUR;

void create() {
::create();
set_name("bracer");
set_short("%^YELLOW%^Gold%^RED%^ S%^RESET%^YELLOW%^erpent%^RESET%^ Bracer");
set_long("A finely crafted golden bracer in the form of a winding serpent.  A small ruby is set in the eye.");
set_id(({"bracer", "serpent bracer"}));
set_ac(3);
set_weight(6);
set_value(115);
set_type("bracers");
set_limbs(({"right arm"}));
}
int query_auto_load() {return 1; }

int CheckArmour(string str) {
   object ob;
   if (!str) return 0;
   ob = present(str, this_player());
   if (!ob || ob != this_object()) return 0;
   if (this_player()->query_armour("right arm") != ({ })) {
      write("You cannot wear the bracer with other armour on that limb.");
      return 1;
   }
   return 0;
}

void init() {
 ::init();
   add_action("CheckArmour", "wear");
}
