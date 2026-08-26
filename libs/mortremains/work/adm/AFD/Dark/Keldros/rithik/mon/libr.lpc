#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "lois the lonely librarian");
  enable_commands();
  set("long", @ENDLONG
Lois has a kind face and shy eyes.  Her gestures are deliberate
and delicate with the precision of someone who has done her
job for many years.
ENDLONG
  );
  set_alignment(300);
  set_name("lois");
  set("id", ({
    "librarian",
    "lois",
    "lonely librarian",
  }));
  
  credit( 100+random(200) );
  set("damage", ({ 10, 20 }) );
  set("armor_class", 5);
  set("attack_strength", 15);
  set("race", "dwarf");
  set("attrib2", "elderly");  set("attrib1", "kind");
  set("gender", "female");
  set("weapon_name", "thick library book");
  set_verbs( ({
    "bash",
    "try to demolish",
    "bludgeon",
}));
set_verbs2( ({
    "bashes",
    "tries to demolish",
    "bludgeons",
}));
  
  set_skill("defense", 1, "dexterity");
  set_skill("attack", 6, "strength");
  set_level(7);
  set("chat_chance", 4);
  set("chat_output", ({
    "Lois says: \"Go ahead and look around, even though no one else does.\"\n",
    "Lois continues reading her book.\n",
    "Lois says: \"One day we are going to get funding for entertaining books.\"\n",
    "Lois says: \"Welcome to rithik!  I know you are a stranger because you are here.\"\n"+"Lois winks at you.\n",
  }));
  set("forgetful", 1);
  
}
