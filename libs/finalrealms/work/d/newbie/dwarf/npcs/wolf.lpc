//Created by Mist Nov 1994
 
inherit "/obj/monster";
#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()
 
void setup() {
// Descriptions...
   set_name("wolf");
   set_short("wolf");
   set_long("This is a small grey wolf.  It looks rather hungry.  "
         "\n");
   set_main_plural("wolfs");
   set_gender(1);
   set_dex(13);
   set_int(4);
   set_wis(4);
   set_cha(5);
   set_level(2);
   set_wimpy(0);
   set_aggressive(1);
 
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
      "headbutt" : ({ AN+" leaps at "+DN+".\n",
                   "You leap at someone.\n",
                   AN+" leaps at your throat!\n"})
   ]);
} /* mapping valid_attack() */
// Read /w/sojan/comwolf/unarmed_combat.doc for more info on mapping valid_attack()...

