#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "long winded priest");
  enable_commands();
  set("long", @ENDLONG
This is an elderly gentleman wearing purple robes and and a long hat
showing his rank as Minsteriot in the church of Dryox.
ENDLONG
  );
  set_alignment(400);
  set_name("felgar");
  set("id", ({
    "priest",
    "felgar",
  }));
  set("size", 4);
  credit(180 );
  set("damage", ({ 18, 25 }) );
  set("armor_class", 9);
  clone_object(OBJ(bible.c))->move(TO);
  set("attack_strength", 15);
  set("race", "dwarf");
  set("attrib1", "tall");  set("attrib2", "elderly");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "jump at",
    "jab",
}));
  
  set_skill("defense", 5, "dexterity");
  set_skill("Brawling", 20, "strength");
  set_level(6);
  set("chat_chance", 3);
  set("chat_output", ({
    "The priest rambles on in an uncomprehensible language.\n",

  }) );
 
}
