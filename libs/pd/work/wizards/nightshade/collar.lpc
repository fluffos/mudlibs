#include <std.h>

inherit ARMOUR;

void create() {
  ::create();
  set_name("brooch");
  set_short("%^RESET%^%^BOLD%^a small wh%^BLACK%^i%^WHITE%^te brooch%^RESET%^");
  set_long("The brooch itself is a dark crystal, so dark it could easily be mistaken for obsidian.  Either side of the brooch is connected to a thin strip of white silk that clasps in the back.");
  set_id(({"brooch", "white brooch", "small white brooch"}));
  set_type("halo");
  set_limbs(({"head"}));
  set("dragon wear", 1);
  set_wear("%^RESET%^%^BOLD%^The soft silk slides gently across your neck as it snugly wraps around and clasps in the back.%^RESET%^");
  set_weight(1);
  set_curr_value("gold", 0);
  set_ac(0);
}

void init() {
  ::init();
  add_action("peer", "peer");
}

int peer(string str) {
  if(!str)
    return 0;
  if(str != "into the crystal")
    return 0;
  if(environment(this_object()) != this_player())
    return 0;
  write("%^BOLD%^%^BLACK%^Peering into the crystal, some faint forms begin to form.  A figure standing outside of a house, the black of the crystal casting a sense of night on the scene.  As you peer closer, you realize that there are actually two people there, holding each other tightly.  It is obvious that at that moment, nothing else to them matters.  That moment will be remembered always, at least by the creator of the brooch.%^RESET%^");
  say(this_player()->query_cap_name()+" peers into the crystal on her brooch.");
  return 1;
}

int query_auto_load() {
  if(this_player()->query_name() == "azire") return 1;
  return 0;
}
