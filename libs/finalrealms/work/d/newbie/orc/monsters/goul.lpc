// by Sojourn June 1995
 
inherit "/obj/monster";
#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()
 
void setup() {
// Descriptions...
set_name("ghoul");
set_short("ghoul");
set_long(" Flesh hangs losely from its arms and legs, only the old molden shirt and pants keep the 'rest' together."
" It stands some six feet tall and appears to some very disgusting eating habits.\n");
set_main_plural("ghouls");
   set_gender(1);
   set_dex(13);
   set_int(4);
   set_wis(4);
   set_cha(5);
   set_level(10);
   set_wimpy(0);
   set_aggressive(4);
 
   load_chat(50, ({
1, "@grasps at you",
1, ":exhails a foul smell of death and lunges at you!"
   }));
   load_a_chat(100, ({
1, ":howls in frustration.",
        1, ":tries to hurt you.",
        1, ":tries to kill you",
   }));
 
 
} /* void setup() */
 
mapping valid_attack() {
   return([
      "punch"    : ({ AN+" grasps "+DN+" on the leg.\n",
                      "You grasp "+DN+" on the leg.\n",
                      AN+" grasps you on the leg.\n" }),
      "kick"     : ({ AN+" rips "+DN+" on the hand.\n",
                      "You rip "+DN+" on the hand.\n",
                      AN+" rips you on the hand.\n" }),
	"knee"     : ({ AN+" bites "+DN+" on the neck.\n",
			"You bite "+DN+" on the neck.\n",
			AN+" bites you on the neck.\n"}),
"headbutt" : ({ AN+" stangers and waves its arms at "+DN+".\n",
"You stanger and wave your arms at "+DN+".\n",
AN+" stangers and waves its arms at you.\n"})
   ]);
} /* mapping valid_attack() */
// Read /w/sojan/combat/unarmed_combat.doc for more info on mapping valid_attack()...

