#include <std.h>
inherit ARMOUR;

void create() {
::create();
set_name("bracer");
set_short("%^BOLD%^BLACK%^Black%^BOLD%^WHITE%^ Steel Bracer%^RESET%^");
set_long("These bracers are quite common due to their inexpensive price and fair protection.");
set_id(({"bracer", "black steel bracer", "steel bracer", "black bracer"}));
set_ac(2);
set_weight(5);
set_curr_value("gold",56);
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
