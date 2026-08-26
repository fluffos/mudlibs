#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "A two-headed reptillian horse");
  enable_commands();
  set("long", @ENDLONG
This creature has the basic form of a horse.  Four legs, long tail and
TWO heads!  The flesh of the horse is a slick, green scaly surface.  You
can see long fangs jutting from both heads' mouths.
ENDLONG
  );
  set_alignment(100);
  set_name("the two headed horse");
  set("id", ({
    "horse",
    "reptile",
    "two-headed horse",
  }));
  set("agressive", 1);
  set("damage", ({ 15, 40 }) );
  set("armor_class", 6);
  set("attack_strength", 14);
  set("race", "horse");
  set("attrib1", "slimy");  set("attrib2", "snake-like");
  set("gender", "male");
  set("weapon_name", "hooves");
  set_verbs( ({
    "kick at",
    "attack",
    
}));
  set_skill("defense", 6, "dexterity");
  set_skill("attack", 6, "strength");
  set_level(7);
  set("forgetful", 1);
  set("att_chat_output", ({
      "One the horses' heads chomps at you ferociously.\n",
      "The horse rears back his hind legs and kicks you square in the groin!\n",
      "The repltillian horse hisses ferociously.\n",
}) );
}
