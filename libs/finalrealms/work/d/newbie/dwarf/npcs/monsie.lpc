// Example monster 
// Snotling newbie monster...
// Made by Mirath 1994
 
#include "path.h"
inherit "/obj/monster";
#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()
 
void setup() {
// Descriptions...
   set_name("snotling");
   set_short("Snotling");
   set_long("This is your average soblin. A snotling is the smallest "
                "of the goblinoid races. He has greenish-black skin, "
                "drooling mouth and no clothes.\n");
   set_main_plural("snotlings");
   set_gender(1);
   set_race("snotling");
   set_guild("fighter");
   set_random_stats(1, 6);
   set_level(55);
   set_al(random(10));
   set_wimpy(25);
   set_aggressive(1);
 
   load_chat(50, ({
        1, "@fart",
        1, ":picks his nose and stuffs something into his mouth."
   }));
   load_a_chat(100, ({
        1, ":howls with pain.",
        1, ":tries to hurt you.",
        1, ":tries to kill you",
   }));
 
   adjust_money(random(2), "copper");
 
   add_move_zone("goblin_newbie");
   set_move_after(20, 40);
 
} /* setup() */
 
mapping valid_attack() {
   return([
      "punch"    : ({ AN+" bites "+DN+" in the leg.\n",
                      "You bite "+DN+" in the leg.\n",
                      AN+" bites you in the leg.\n" }),
      "kick"     : ({ AN+" bites "+DN+" in the hand.\n",
                      "You bite "+DN+" in the hand.\n",
                      AN+" bites you in the hand.\n" }),
      "knee"     : ({ AN+" tosses a rock at "+DN+".\n",
                      "You toss a rock at "+DN+".\n",
                      AN+" tosses a rock at you.\n" }),
      "headbutt" : ({ AN+" flails his arms at "+DN+".\n",
                      "You flail your arms at "+DN+".\n",
                      AN+" flails his arms at you.\n" })
   ]);
} /* mapping valid_attack() */
// Read /w/sojan/combat/unarmed_combat.doc for more info on mapping valid_attack()...

