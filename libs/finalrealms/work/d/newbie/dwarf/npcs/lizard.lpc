//  Creatures for the Dwarven Newbie area  Restock by Feadorious ...
//  Monster by Mist ...
 
inherit "/obj/monster";
#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()
 
void setup() {
// Descriptions...
   set_name("lizard");
   set_short("Lizard");
   set_long("\n"
            "   This is a large green lizard with an extremely long "
            "tail.  It is perched on all fours and looks ready to pounce "
            "on you at any moment.  It has sharp looking claws at the " 
            "end of each of its four legs.  "
            "\n\n");
   set_main_plural("lizards");
   set_gender(1);
   set_dex(13);
   set_int(4);
   set_wis(4);
   set_cha(5);
   set_str(3);
   set_level(2);
   set_wimpy(0);
   set_aggressive(0);
 
   load_chat(50, ({
                 //modified by Christian oct 28//
                 1, ":jumps from rock to rock.",
          1, ":drips venomous saliva on you."
   }));
   load_a_chat(100, ({
        1, ":squeels in agony.",
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
      "headbutt" :({ AN+" uses its tail to smack "+DN+".\n",
                  "You hurt someone.\n",
               AN+" smacks you across the face with its tail. \n"})
   ]);
} /* mapping valid_attack() */
// Read /w/sojan/comspider/unarmed_combat.doc for more info on mapping valid_attack()...

