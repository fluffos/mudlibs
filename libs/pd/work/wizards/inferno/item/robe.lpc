#include <std.h>
inherit ARMOUR;

int check_wearer();

void create() {
 ::create();
   set_short("%^ORANGE%^a strange robe of %^BOLD%^%^BLACK%^b%^WHITE%^l%^BLACK%^a%^WHITE%^c%^BLACK%^k%^RESET%^%^ORANGE%^ flames");
   set_long("%^ORANGE%^The robe is made not out of cloth, but rather "
     "a strange combination of %^RED%^crimson %^ORANGE%^and %^BOLD%^%^BLACK%^b%^WHITE%^l%^BLACK%^a%^WHITE%^c%^BLACK%^k%^ORANGE%^ flames.");
   set_name("infrobe");
   set_weight(1);
   set_id(({ "robe" }));
   set_value(0);
   set_ac(50);
   set_type("robe");
   set_limbs((string)this_player()->query_limbs());
}

void init() {
 ::init();
   add_action("check_wearer", "wear");
}

int query_auto_load() { return 1; }

int check_wearer(string str) {
   object ob;
   if (!str) return 0;
   ob = present(str, this_player());
   if (!ob || ob != this_object()) return 0;
   if (this_player()->query_name() != "inferno") {
      write("%^ORANGE%^For you, the flames die down a bit.");
      tell_room(environment(this_player()), "%^ORANGE%^The flames on "
       +this_player()->query_cap_name()+"'s robe die down a bit.",
      ({ this_player() }));
      this_object()->set_ac(13);
      return 1;
   }
   tell_room(environment(this_player()), "%^ORANGE%^The flames on "
    "Inferno's robe of %^BOLD%^%^BLACK%^b%^WHITE%^l%^BLACK%^a%^WHITE%^c%^BLACK%^k "
    "%^RESET%^%^ORANGE%^flame spring to life, even higher than before!",
    ({ }));
   this_object()->set_ac(1000);
   return 0;
}
