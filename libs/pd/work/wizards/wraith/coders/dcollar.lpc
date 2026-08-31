//made by wraith for delthia
#include <std.h>;

inherit ARMOUR;

void create() {
  ::create();

  set_name("collar");
  set("id", ({ "collar", "delthia's collar", "chain" }) );
  set("short", "Delthia's collar");
  set("long", "This collar has been encrusted with small gems and little spikes. It has "
"small hoops set at the front and the back of it, like it was made for a leash. An engraved "
"plate at the back of the neck has a single phrase on it.....");
  set_type("necklace");
  set_ac(0);
  set_limbs( ({ "head" }) );
  set_weight(5);
    set_curr_value("gold", 0);
}
int query_auto_load() { if (this_player()->query_name() == "delthia") return 1; }
int slap_on_the_wrist(string str) {
   if (!str || present(str, this_player()) != this_object()) return 0;
   if (this_player()->query_name() == "delthia") return 0;
   write("This is Delthia's collar, return it NOW.");
   say(this_player()->query_cap_name()+" is a moron.", this_player());
   return 1;
}

void init() {
 ::init();
   add_action("slap_on_the_wrist", "wear");
 add_action("fRead", "read");
}

int fRead(string str)
{
 if (!str || str!="engraving")
   return notify_fail("Read what?\n");
 say (this_player()->query_cap_name()+" reads at the back of a collar.");
 write("
The engraving reads:
%^BOLD%^%^BLACK%^-----------------------------------------
%^BOLD%^%^BLACK%^This one is owned and loved by Wraith.
-----------------------------------------");
 return 1;
}
