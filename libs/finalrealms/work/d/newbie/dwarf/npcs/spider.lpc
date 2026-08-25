// created by feadorious. builder if wierdness
 
inherit "/obj/monster";
#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()
 
void setup() {
// Descriptions...
   set_name("spider");
   set_short("spider");
set_long(" This is a massive spider. It has green and brown fur all over its hard sheled back. You almost dont notice it because it blends in so well with the forest around it. It has razor sharp fangs that could pierce your body, and huge legs that could crush your skull. You shudder with horror as saliva drips down onto you. Maybe you should run now while you can. \n\n");
	
   set_main_plural("spiders");
   set_gender(1);
   set_dex(13);
   set_int(4);
   set_wis(4);
   set_cha(5);
   set_str(3);
   set_level(1);
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
      "headbutt" :({ AN+" wraps its legs around "+DN+".\n",
                  "You hurt someone.\n",
               AN+" wraps its legs around you and chews on your face.\n"})
   ]);
} /* mapping valid_attack() */
// Read /w/sojan/comspider/unarmed_combat.doc for more info on mapping valid_attack()...

