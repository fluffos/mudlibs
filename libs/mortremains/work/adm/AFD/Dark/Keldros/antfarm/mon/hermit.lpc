#include "../defs.h"

inherit MONSTER;

void create() {
  seteuid(getuid());
  ::create();
  set("short", "crochety old hermit");
  enable_commands();
  set("long", @ENDLONG
This is an old dwarf, worn and haggard.  He has a crazy
look in his eye, perhaps he's been down here just a 
little to long.
ENDLONG
);
  set_name("hermit");
  set("id", ({
    "hermit",
    "old hermit",
}));
  clone_object(OBJ(quest_book))->move(TO);
  credit(random(180) + 20 );
  set("race", "dwarf");
  set("attrib1", "leathery");  set("attrib2", "old");
  set("gender", "male");
  set("weapon_name", "fists");
  set_verbs( ({
    "attack",
    "pound at",
}));
  set_skill("defense", 2, "dexterity");
  set_skill("attack", 1, "strength");
 set("chat_chance", 2);
  set("chat_output", ({
   "The old man says:\"Have you come to release my companions from the curse?\n\"",
   "The hermit tries to clean himself off, but manages only to make himself look worse.\n",
   "The old dwarf says:\"My wife was once a dwarf, now she's a monster.\n\"",
  }) );
}


 void heart_beat() {
   object theAttacker, Quester;
   int i,j,lv,hp;
   theAttacker = TO->query_current_attacker();
   hp=TO->query("hit_points");
   set_level(theAttacker->query_level());
   set("hit_points", hp);
   lv=theAttacker->query_level();
   i = lv + 2;
   j = lv*lv;
   set("damage", ({ i, j }) );
 ::heart_beat();
}

void die(){
  object bk;
  bk =  present("quest_OB", TO);
  bk->remove();
  say("The hermit collapses at your feet, the book in his hands turns to ash
as hit hits the stonework floor.\n");
::die();
}