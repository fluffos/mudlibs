#include <std.h>
inherit ARMOUR;

void create() {
::create();
set_name("bracer");
set_short("%^BOLD%^WHITE%^S%^BOLD%^BLACK%^kul%^BOLD%^WHITE%^l B%^BOLD%^BLACK%^race%^BOLD%^WHITE%^r%^RESET%^");
set_long("This bracer is made of black iron and has a screaming demonic skull etched into the side.");
set_wear("%^BOLD%^WHITE%^T%^BOLD%^BLACK%^he bracer makes your arm feel secur%^BOLD%^WHITE%^e%^RESET%^.");
set_remove("%^BOLD%^WHITE%^Y%^BOLD%^BLACK%^our arm feels more vunerabl%^BOLD%^WHITE%^e%^RESET%^.");
set_id(({"bracer", "skull bracer"}));
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
