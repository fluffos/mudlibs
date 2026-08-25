//Created by Mist Nov 1994
 
inherit "/obj/monster";
#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()
 
void setup() {
// Descriptions...
   set_name("bat");
   set_short("bat");
	set_long("This is a large vampire bat.  It has a sharp beak "
		"and long claws on its wings.  It looks angry, you must have "
		"woke it up.\n");
   set_main_plural("bats");
   set_gender(1);
   set_dex(13);
   set_int(4);
   set_wis(4);
   set_cha(5);
   set_level(5);
   set_wimpy(0);
   //set_aggressive(1);
 
   load_chat(50, ({
        1, "@skwaks at you",
		1, ":swoops down from the ceiling and charges at you."
   }));
   load_a_chat(100, ({
        1, ":howls with pain.",
        1, ":tries to hurt you.",
        1, ":tries to kill you",
   }));
 
 
} /* setup() */
 
mapping valid_attack() {
   return([
      "punch"    : ({ AN+" bites "+DN+" on the leg.\n",
                      "You bite "+DN+" on the leg.\n",
                      AN+" bites you on the leg.\n" }),
      "kick"     : ({ AN+" bites "+DN+" on the hand.\n",
                      "You bite "+DN+" on the hand.\n",
                      AN+" bites you on the hand.\n" }),
	"knee"     : ({ AN+" bites "+DN+" on the neck.\n",
			"You bite "+DN+" on the neck.\n",
			AN+" bites you on the neck.\n"}),
	   "headbutt" : ({ AN+" flaps its wings and skawks at "+DN+".\n",
			"You flap your wings and skwak at "+DN+".\n",
			AN+" flaps its wings and skawks at you.\n"})
   ]);
} /* mapping valid_attack() */
// Read /w/sojan/combat/unarmed_combat.doc for more info on mapping valid_attack()...

