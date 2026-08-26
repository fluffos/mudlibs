#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "nervous groom");
  enable_commands();
  set("long", @ENDLONG
The groom is very muscular and looks very nervous.
ENDLONG
  );
  set_alignment(29);
  set_name("jonn");
  set("id", ({
    "groom",
  }));
 
  credit(100+random(100) );
  set("damage", ({ 10, 30 }) );
  set("armor_class", 9);
  set("attack_strength", 50);
  set("race", "dwarf");
  set("attrib1", "stocky");  set("attrib2", "green-eyed");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "jump at",
    "jab",
}));
  
  set_skill("defense", 7, "dexterity");
  set_skill("attack", 18, "strength");
  set_level(7);
}
void init(){
  add_action("kill", "kill");
}
int kill(string str){
  if(!str || str !="bride" && str!="charlene") return 0;
  tell_object(environment(), "The groom leaps to protect his soon-to-be wife.\n");
  kill_ob(TP);
}