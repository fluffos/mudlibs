// Coded by Waxer, with some help from Chronos's Object Maker. :)

#include <mudlib.h>

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a metal frying pan");
  set("long", @ENDLONG
This is a metal frying pan for use on an open fire.
ENDLONG
  );
  set("id", ({
    "pan",
    "frying pan",
  }));
  set("name", "frying pan");
  set("bulk", 300);
  set("mass", 40);
  set_value(300);
  set("weapon", 12);
  set("damage", ({ 10, 30 }));
  set_type("bashing");
  set_verbs(({
    "bash at",
    "swipe at",
    "clobber at",
  }) );
  set_verbs2( ({
    "bashes at",
    "swipes at",
    "clobbers at",
  }) );
  set("second", 1);
}
