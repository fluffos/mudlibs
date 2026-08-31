#include <swamp.h>
#include <std.h>
inherit MONSTER;
int newbody();

string *my_kills = ({ });

void create() {
::create();
set_name("tiamat");
set_short("%^BOLD%^RED%^T%^GREEN%^i%^BLACK%^a%^BLUE%^m%^WHITE%^a%^RED%^t%^RESET%^");
set_long("Tiamat is as ancient as the universe itself.  One of the dragon immortals, Tiamat may be defeated but never truly killed.  Tiamat appears as a large red dragon with five heads, each head of a differing color. \n%^BOLD%^RED%^**Tiamat is a very powerful adversary.**%^RESET%^");
set("aggressive", 0);
set_id(({"tiamat", "dragon", "immortal"}));
set_skill("magic attack", 500);
set_class("mage");
set_subclass("pyromancer");
set_alignment(0);
set_skill("riding", 1000);
set_skill("charging", 1000);
set_stats("intelligence", 200);
set_stats("wisdom", 200);
set_race("dragon");
set_body_type("tiamat");
set_gender("female");
set_emotes(3, ({"The great dragon seems to find you harmless and ignores you.", "Tiamat rests wearily.", "%^BLUE%^Tiamat says:%^RESET%^ Are you still here?  Go away kid ya bodda me."}),0);
set_spell_chance(30);
set_spells(({"scorch", "shroud"}));
set_lang_prof("draul", 10);
set_speech(50,"draul",({"Foolish mortal...  I shall relieve this realm of your stupidity.", "It seems fate has deemed you to die."}),1);
set_level(85);
set_exp(150000);
restore_object("/d/merkkerri/swamp/mob/save/tiamat");
}

string *query_pks() { return my_kills; }

void heart_beat() {
 int i;
 object env, ob, *all;
 ::heart_beat();
   if (!this_object()->query_current_attacker()) return;
   if (random(3000) > 600) return;
   ob = this_object()->query_current_attacker();
   env = environment(ob);
   switch (random(5)) {
     case 1:  // Red
       tell_object(env, "%^BOLD%^%^RED%^The Tiamat's red dragon head "
         "spews fire over her opponent!");
       ob->damage(666, "fire");
       break;
     case 2:  // Blue
       tell_object(env, "%^BOLD%^%^BLUE%^The Tiamat's blue dragon head "
         "sends electricity to strike down her opponent!");
       ob->damage(666, "energy");
       break;
     case 3:  // Black
       tell_object(env, "%^BOLD%^%^BLACK%^The Tiamat's black dragon head "
         "spits acid all over her opponent!");
       ob->damage(666, "acid");
       break;
     case 4:  // Green
       tell_object(env, "%^BOLD%^%^GREEN%^A poisonous gas escapes from "
         "the Tiamat's green dragon head!");
       tell_object(env, "You choke on the gas.");
       all = all_inventory(env);
       i = sizeof(all);
       while (i--) {
         if (!all[i]->is_living()) continue;
         if (all[i] == this_object()) continue;
         all[i]->add_poisoning(random(4));
         all[i]->damage(333, "gas");
       }
       break;
     case 5:  // White
       tell_object(env, "%^BOLD%^%^CYAN%^The Tiamat's white dragon head "
         "sends a cone of ice smashing into her opponent!");
       ob->damage(666, "cold");
       break;
     default: // bite their ass
       tell_object(env, "%^YELLOW%^All five of Tiamat's heads bite "
         "her opponent's flesh!");
      ob->damage(900);
   }
}

void catch_tell(string str) {
   string person;
   object ob;
   if (!sscanf(lower_case(str), "%s dies a horrible death.", person)) return;
   if (!find_player(person)) return;
   message("info", "%^BOLD%^ORANGE%^A terrible screech is heard throughout the lands!", users());
   ob = find_player(person);
   my_kills += ({ ob->query_name() });
   save_object("/wizards/asmodeus/swamp/mob/save/tiamat");
}
