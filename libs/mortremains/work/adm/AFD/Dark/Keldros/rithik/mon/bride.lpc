#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "homely bride");
  enable_commands();
  set("long", @ENDLONG
This dwarf has a face only a mother could love.  Huge hips jut
from beneath her wedding dress.
ENDLONG
  );
  set("size", 4);
  set_alignment(-30);
  set_name("charlene");
  set("id", ({
    "bride",
    "charlene",
  }));
  
  credit(60+random(20) );
  set("damage", ({ 10, 20 }) );
  wear(ARMOR(gown), "gown");
  wear(ARMOR(bgloves), "gloves");
  set("attack_strength", 17);
  set("race", "dwarf");
  set("attrib1", "overweight");  set("attrib2", "beady-eyed");
  set("gender", "female");
  set("weapon_name", "pudgy fists");
  set_verbs( ({
    "jump at",
    "pound at",
    "lunge at",
    "suffocate",
}));
  set_skill("defense", 1, "dexterity");
  set_skill("attack", 6, "strength");
  set_level(7); 
  set("armor_class", 9);
}
void init(){
  add_action("kill", "kill");
}
int kill(string str){
  if(!str || str !="groom" && str !="john") return 0;
  tell_object(environment(), "Charlene leaps in front of you to protect her beloved.\n");
  kill_ob(TP);
}

