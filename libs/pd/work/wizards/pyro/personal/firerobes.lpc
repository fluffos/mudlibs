#include <std.h>
inherit ARMOUR;
void create() {
  ::create();
  set_name("robes");
  set("id", ({ "robes", "robes of fire", "full-body robes of fire" }) );
  set_short("%^RESET%^%^RED%^full-body robes of fire%^RESET%^");
set_long("This is a very long full-body set of robes made completely out of fire, but strangely, it does not burn. A gentle warmth radiates from the robes, and the fire seems to be almost impenetrable. The cloak wraps around one's entire body and doesn't seem to leave any body parts unprotected.");
  set_weight(6);
  set_curr_value("gold", 0);
  set_type("robes");
  set("read", "Why are you wasting your life trying to read fire?");
}

int query_auto_load() { return wizardp(this_player()); }
