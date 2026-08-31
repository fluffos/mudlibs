#include <swamp.h>
#include <std.h>
inherit MONSTER;
int newbody();

string *my_kills = ({ });

void create() {
::create();
set_name("troll");
set_short("The swamp troll");
set_long("A nasty monstrocity of decayed flesh and molding hair, the swamp troll is as fearsome as a giant dragon and as dangerous as one too.  It has cold black eyes and rotten teeth and a green saliva foams at its mouth.");
set("aggressive", 60);
set_id(({"troll", "swamp troll", "the swamp troll"}));
set_class("fighter");
set_subclass("warrior");
set_alignment(-400);
set_skill("charging", 400);
set_stats("wisdom", 100);
set_race("troll");
set_body_type("giant");
set_gender("male");
set_spell_chance(20);
set_spells(({"rush"}));
set_level(50);
}


void heart_beat() {
 object env, ob;
 ::heart_beat();
  if (!this_object()) return;
   if (!this_object()->query_current_attacker()) return;
   if (random(3000) > 600) return;
   ob = this_object()->query_current_attacker();
   env = environment(ob);
   if(this_object()->query_paralyzed()) return;
   switch (random(2)) {
     case 1:  // slash
       tell_object(env, "%^BOLD%^The troll ANNIHILATES his victim with a flesh ripping slash!");
       ob->damage(750);
       break;
     default: // thuds
       tell_object(env, "%^BOLD%^The troll DEMOLISHES his victim with a terrible claw!");
      ob->damage(700);
   }
}

