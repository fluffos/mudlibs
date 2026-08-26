#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "busy wight");
  enable_commands();
  set("long", @ENDLONG
This wight is attending to his masters needs.  He walks very slowly,
and does every action in a painstaking manner.  It's skin is a pale
pallor, it's flesh suspended in a rotten state.
ENDLONG
  );
  set_alignment(-100);
  set_name("wight");
  set("id", ({
    "wight",
  }));
  credit(50);
  set("damage", ({ 5, 40 }) );
		set("undead", 9);
  set("race", "wight");
  set("attrib1", "nightmarish");  set("attrib2", "man-sized");
  set("weapon_name", "claws");
  set_verbs( ({
    "rake at",
    "gouge",
}));
  set_level(12);

}

void init(){ add_action("kill_func", "kill"); }

void kill_func(string str){
 if(str =="dracolich"){
write("The wight floats in front of the dracolich, protecting him!\n");
say("The wight attacks "+TPN+" as "+subjective(TP->query("gender"))+" attacks the dracolich!\n");
kill_ob(TP);
 }
}