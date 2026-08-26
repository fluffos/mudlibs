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

// Here is the code for level dependancy.
//  If the current_attacker changes, on the next heartbeat, so will his stats =)
//  hehehehehehehehe

void heart_beat(){
object vic;
int lev;

// Calling the inherited heart_beat here results in the rest of the code not
//  registering.  Hence a level 1 creature that does no damage. =(
::heart_beat();

vic = TO->query_current_attacker();
lev  = vic->query_level();
TO->set_level(lev);
TO->set("damage", ({ lev+3, lev*4 }));

}



void die(){
  object bk;
  bk =  present("quest_OB", TO);
  bk->remove();
  say("The hermit collapses at your feet, the book in his hands turns to ash
as hit hits the stonework floor.\n");
::die();
}