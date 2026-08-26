#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "follower");
  enable_commands();
  set("long", @ENDLONG
This man is a follower of Mayas.  He follows the heretic,
blessing the world with his good deeds.
ENDLONG
  );
  set_alignment(20);
  set_name("follower");
  set("id", ({
    "follower",
  }));
  credit(50);
  set("damage", ({ 5, 20 }) );
  set("armor_class", 5);
  set("attack_strength", 6);
  set("race", "human");
  set("attrib1", "lean");  set("attrib2", "dirty");
  set("weapon_name", "fists");
  set_verbs( ({
    "punch",
    "swing",
}));
  set_level(2);

}
void init(){ add_action("kill_func", "kill"); }

void kill_func(string str){
 if(str =="heretic"){
write("The follower screams as you attack the heretic!\n");
say("The follower attacks "+TPN+" as "+subjective(TP->query("gender"))+" attacks the heretic!\n");
kill_ob(TP);
 }
}
