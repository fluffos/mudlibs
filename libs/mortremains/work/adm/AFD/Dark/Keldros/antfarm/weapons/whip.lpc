#include <mudlib.h>

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("short", "slaver's whip");
  set("long", @ENDLONG
This whip is fashioned out of tough leather.  It is wrapped quite tightly, around
the edges of the wrapping, the leather becomes sharp making it quite painful
to any of its victims.
ENDLONG
  );
  set("id", ({
    "whip",
    "slaver's whip",
  }));
  set("name", "slaver's whip");
  set("bulk", 22);
  set("mass", 12);
  set_value(215);


  set("weapon", 10);
  set("damage", ({ 2,8 }));
  set_type("cutting");
  set_verbs(({
   "try to lacerate",
    "thwack at",
  }) );
set_verbs2(({
   "tries to lacerate",
    "thwacks at",
  }) );
}