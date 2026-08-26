#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "Destin, the idle sherrif");
  set("long", @ENDLONG
This is an elderly gentleman wearing purple robes and and a long hat
showing his rank as Minsteriot in the church of Dryox.
ENDLONG
  );
  set_alignment(400);
  set_name("destin");
  set("id", ({
    "destin",
    "sherrif",
  }));
  set("alt_wander", 1);
  credit(500 +random(1000) );
  set("damage", ({ 18, 80 }) );
  set("armor_class", 9);
  arm(WEAPONS(avenger), "sword");
  set("attack_strength", 20);
  set("race", "dwarf");
  set("attrib1", "muscular");  set("attrib2", "young");
  set("gender", "male");
  set("weapon_name", "Avenger");
  set_verbs( ({
    "lunge at",
    "attempt to maim",
    "slice repeatedly at",
    "gouge at",
    "attempt to lancinate",
}));
  set_skill("defense", 17, "dexterity");
  set_skill("cutting weapons", 50, "strength");
  set_level(20);
  set("chat_chance", 5);
  set("chat_output", ({
    "Destin hums a tune to himself.\n",
    "Destin sighs deeply.\n",
    "Destin says: \"Nothing ever happens in this damn town except for elves.\"\n",
    "Destin says: \"One day the gods are just gonna get sick of those elves and
just irradicate them entirely.\"\n",
    "The idle sherrif yawns loudly.\n",
  }) );
 set("att_chat_output", ({
     "The evil sherrif calls you an elf-lover!\n",
     "Destin pulls out a can of Whoop-ass and you feel you could never defeat him.\n",
     "You see the blade of Avenger swooping towards your face!\n",
     "The sherrif says: \"Finally, someone I can put in jail!\"\n",
     "Destin says: 'You will be nailed to the cross for this!'\n",  
}) );

}
void init(){
  string fname;
   if((string)TP->query("race") =="elf" || (string)TP->query("race") =="drow" && TP->query_level() > 14){
                       tell_object(TP, "Destin detests elves!\nYou must DIE!\n");
                       kill_ob(TP);
         }
  if((string)TP->query("race") =="elf" && TP->query_level() <= 14){
         command("spit "+TPn);
  }
  if((string)TP->query("race") =="half-elf"){
       command("say I hate half-elf bastards!");
       command("spit "+TPn);
}
  if((string)TPN=="Gendor") command("say Isn't gendor the greatest?");

}

