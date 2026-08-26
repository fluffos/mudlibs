// Coded by Waxer, with some help from Chronos's Object Maker. :)

#include <mudlib.h>

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "a splintered ruler");
  set("long", @ENDLONG
This is a disciplinary tool used to punish the children who break school rules.
ENDLONG
  );
  set("id", ({
    "ruler",
    "weapon",
  }));
  set("name", "splintered ruler");
  set("bulk", 20);
  set("mass", 30);
  set_value(1000);
  set("weapon", 15);
  set("damage", ({ 15,40 }));
  set_type("slicing");
  set_verbs(({
    "thrash",
    "thwack",
  }) );
  set_verbs2( ({
    "thrashes",
    "thwacks",
  }) );
  set("raise_stat", "int");
  set("modifier", 3);
  set("second", 1);
}
