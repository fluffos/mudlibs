#include <mudlib.h>

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "the mayor");
  enable_commands();
  set("long", @ENDLONG
The mayor is a swine of a creature, letting politics
rule over his heart....All he does is for money. 
ENDLONG
  );
  set_alignment(-70);
  set_name("the mayor");
  set("id", ({
    "mayor",
}));
  credit(100 + random(300) );
  set("damage", ({ 10, 30 }) );
  set("armor_class", 3);

  
  set("attack_strength", 10);
  set("race", "human");
  set("attrib1", "short");  set("attrib2", "fat");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "beat",
    "jab",
}));
  set_skill("defense", 4, "dexterity");
  set_skill("attack", 4, "strength");
  set_level(5);
  set("chat_chance", 4);
}
void kill_me(){
   TO->receive_damage(100000);
}
void die(){ ::die(); }
