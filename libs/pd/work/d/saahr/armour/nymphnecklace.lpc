#include <std.h>
#include <saahr.h>

inherit ARMOUR;

void create() {
  ::create();
  set_name("necklace");
  set_id( ({ "necklace", NECKLACE_ID, "necklace of rubies and garnets",
	     "ruby necklace", "garnet necklace" }) );
  set_short("a necklace of %^BOLD%^%^RED%^rubies%^RESET%^ and %^RED%^garnets%^RESET%^");
  set_long("The necklace is made of alternating rubies and garnets on a silver chain. "
    "It shines bright red in the light and must be worth a fortune.");
  set_ac(1);
  set_type("necklace");
  set_limbs(({ "head" }));
  set_weight(6);
  set_curr_value("gold",1800);
}

int query_auto_load() { return 0; }
