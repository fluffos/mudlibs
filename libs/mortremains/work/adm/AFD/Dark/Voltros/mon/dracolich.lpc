#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "a Dracolich");
  enable_commands();
  set("long", @ENDLONG
This is a creature that most would call an undead dragon.  The bones
of this dracolich have a faint red tint to them.  Dead scales and skin
drape his frame; his wings are about 25 feet across.  They provide no
visable means of locomotion, but he seems to be hovering above the
ground just fine.  His bones are in perfect shape;  his teeth jut from his
skull, extending about 4 feet out.  His eye sockets hold no eyeballs, but
you can see a faint purple glimmer emanating from them.  He stares at
you and you know that he is very intelligent.  You know he is plotting
you're demise.
ENDLONG
  );
  set_alignment(-100);
  set_name("dracolich");
  set("id", ({
    "dracolich",
    "Dracolich",
  }));
  credit(150);
  set("damage", ({ 17, 80 }) );
        wear(ARMOR(jade_amulet),"amulet");
  set("armor_class", 10);
  set("hit_points", 320);
  set("attack_strength", 12);
        set ("gender", "male");
  set("race", "Dracolich");
		set("undead", 19);
        set_hide_race();
  set("attrib2", "domineering");  set("attrib1", "malicious");
  set("weapon_name", "claws");
  set_verbs( ({
    "swipe at",
    "stab at",
}));
  set_skill("defense", 11, "dexterity");
  set_skill("attack", 11, "strength");
  set_level(14);

}

void init(){ add_action("kill_func", "kill"); }

void kill_func(string str){
 if(str =="figure"){
write("The Dracolich leaps to the defense of the figure!\n");
say("The Dracolich leaps to the defense of the figure!\n");
kill_ob(TP);
 }
}