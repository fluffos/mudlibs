#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "ant queen");
  enable_commands();
  set("long", @ENDLONG
This ant is approximately six feet high and holds its head high,
as if a noble.  Her posterior is swollen and she appears to be
moving slowly.
ENDLONG
);
  set_name("ant queen");
  set("id", ({
    "queen",
    "ant",
}));
  wear( ARMOR(newbie_cloak), "cloak");
  wear(OBJ(necklace), "necklace");
  credit(random(60) + random(60) + 15 );
  set("damage", ({ 3, 13 }) );
  set("armor_class", 8);
  set("attack_strength", 12);
  set("race", "ant");
  set("attrib1", "giant");  set("attrib2", "black");
  set("gender", "female");
  set("weapon_name", "claws");
  set_verbs( ({
    "tear at",
    "attempt to shred",
}));
  set_skill("defense", 2, "dexterity");
  set_skill("attack", 1, "strength");
  set_level(4);

}

void die(){
  say("The Ant Queen screams in anguish and falls to the ground in despair.\n");
::die();
}