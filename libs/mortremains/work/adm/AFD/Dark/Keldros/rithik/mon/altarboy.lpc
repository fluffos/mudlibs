#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Altar boy");
  enable_commands();
  set("long", @ENDLONG
This altar boy is dressed in the standard pink cloth robes of neophytes to the
church.  He has sad eyes, he seems to be hiding something within his heart.
ENDLONG
  );
  set_alignment(50);
  set_name("spiv");
  set("id", ({
    "altar boy",
    "boy",
  }));
  set("size", 3);
  credit(random(15)+5);
  set("damage", ({ 5, 12 }) );
  set("armor_class", 4);
  set("attack_strength", 13);
  set("race", "dwarf");
  set("attrib1", "young");  set("attrib2", "red-haired");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "punch",
    "tap",
}));
  set_verbs2( ({
    "punches",
    "taps",
}));
  
  set_skill("defense", 4, "dexterity");
  set_skill("attack", 4, "strength");
  set_level(5);
  set("chat_chance", 1);
  set("chat_output", ({
    "The altar boy looks up to the priest in admiration.\n",
    "Spiv says: \"After the wedding I am going to camp with Minsteriot 
Felgar!\"\n",
}) );  
}
void init(){
  add_action("kill", "kill");
}
int kill(string str){
  if(!str || str !="priest" && str !="felgar") return 0;
  tell_object(environment(), "Spiv leaps to defend Felgar!\n");
  kill_ob(TP);
}
