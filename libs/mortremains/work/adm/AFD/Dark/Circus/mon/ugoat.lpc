#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "carnivorous unigoats");
  enable_commands();
  set("long", @ENDLONG
This creature has the pure white, long furred body of a goat, but maintains
a miniature unicorn head.  Blood pours from the mouth of the horrific beast.
ENDLONG
  );
  set_alignment(100);
  set_name("carnivorous unigoat");
  set("id", ({
    "goat",
    "unigoat",
  }));
  set("agressive", 1);
  set("damage", ({ 10, 30 }) );
  set("armor_class", 7);
  set("attack_strength", 12);
  set("race", "carnivorous goat");
  set("attrib1", "long-haired");  set("attrib2", "white");
  set("gender", "neuter");
  set("weapon_name", "teeth");
  set_verbs( ({
    "chomp at",
    "attempt to lacerate",
    
}));
  set_skill("defense", 6, "dexterity");
  set_skill("attack", 6, "strength");
  set_level(8);
  set("forgetful", 1);
  set("att_chat_output", ({ 
     "The carnivorous goat bleats at you as he tears at your unguarded areas!\n",
     "The carnivorous goat punctures you with his horn.\n",
}) );
}
void init(){ add_action("kill","kill"); }

int kill(string str){
  object *list;
  int i;
 list = children(file_name(TO));
  if(!str || str !="goat" || str !="unigoat") return 0;
 for(i = 0;i<sizeof(list);i++){
  tell_object(environment(), "The goats protect their own!\n");
  list[i]->kill_ob(TP);
 }
}