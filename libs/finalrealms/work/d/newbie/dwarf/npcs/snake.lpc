// created by feadorious. builder if wierdness
 
inherit "/obj/monster";
#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()
 
void setup() {
// Descriptions...
   set_name("snake");
   set_short("Snake");
   set_long("\n"
            "   This is a long black snake.  It is coiled up on th"
            "ground here and ready to strike at any moment.  Its sharp "
            "fangs curve backwards into its mouth and would likely "
             "tear out a chunk of skin if you were bitten.  "
             "\n");
   set_main_plural("snakes");
   set_gender(1);
   set_dex(15);
   set_int(4);
   set_wis(4);
   set_cha(5);
   set_str(3);
   set_level(2);
   set_wimpy(0);
   set_aggressive(0);
 
   load_chat(50, ({
                 //modified by Christian oct 28//
                1, ":slithers across the ground.",
                1, ":hisses at you.",
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
      "headbutt" :({ AN+" wraps its body around "+DN+".\n",
                  "You hurt someone.\n",
            AN+" wraps its body around you and bites you repeatedly.\n"})
   ]);
} /* mapping valid_attack() */
// Read /w/sojan/comspider/unarmed_combat.doc for more info on mapping valid_attack()...

