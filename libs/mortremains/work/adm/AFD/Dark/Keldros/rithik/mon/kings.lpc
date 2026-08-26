#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "kingsley, keeper of the dead");
  enable_commands();
  set("long", @ENDLONG
Kingsley is wearing a filthy set of pajamas. He maintains
a blank stare into nothingness.  His dry lips are pursed
into an eternal grimace.
ENDLONG
  );
  set_alignment(-30);
  set_name("kingsley");
  set("id", ({
    "kingsley",
    "keeper",
    "keeper of the dead",
  }));
  set_level(7);
  credit( 100+random(200) );
  set("damage", ({ 10, 20 }) );
  set("armor_class", 5);
  set("attack_strength", 15);
  set("race", "dwarf");
  set("attrib2", "grey-faced");  set("attrib1", "corpse-like");
  set("gender", "male");
  set("weapon_name", "rusty shovel");
  set("size", 4);
  set_verbs( ({
    "bash",
    "try to demolish",
    "bludgeon",
}));
set_verbs2( ({
    "bashes",
    "tries to demolish",
    "attempts to bludgeon",
}));
  
  set_skill("defense", 22, "dexterity");
  set_skill("Blunt weapons", 20, "strength");  
}
void init(){ add_action("kill", "kill"); }

int kill(string arg){
  string *idee;
  idee = query("id");
  if(!arg || member_array(arg, idee)==-1) return 0;
  tell_object(environment(TP), "Kingsley reaches into his pile of tools and grabs a rusty shovel!\n");
  clone_object(WEAPONS(gshovel))->move(TO);
  TO->command("wield shovel");
return 0;
}



