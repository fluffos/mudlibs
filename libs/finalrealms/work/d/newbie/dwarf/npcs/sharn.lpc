//  Character created by Mist ---  Fall 1994

#include "unarmed_combat.h"
 
inherit "/obj/monster";
void setup() {
// Descriptions...
   set_name("sharn");
   set_short("Sharn");
	set_long("This is the bartender, Sharn.  Sharn is a stout "
		"Dwarven male with thick hair covering most of his "
		"body.  He seems to be happy and easy-going, but it "
		"would not be a good idea to make him mad. He keeps "
		"an enormous war-hammer within his reach behind the "
		"bar.  "
		"\n\n");
   set_gender(1);
   set_race("dwarf");
   set_guild("fighter");
   set_damage_dice(5,5);
   set_random_stats(1, 6);
   adjust_dex(9);
   adjust_int(4);
   adjust_wis(4);
   adjust_str(16);
   adjust_con(12);
   adjust_cha(9);
   set_level(12);
   set_al(random(10));
   set_wimpy(0);
   set_aggressive(0);
 
   load_chat(160, ({
        1, ":cleans off the counter with a towel.",
               1, "'What will it be?"
   }));
   load_a_chat(100, ({
        1, ":howls with pain.",
        1, ":tries to hurt you.",
        1, ":tries to kill you",
   }));
 
   adjust_money(random(5), "gold");
 
 
} /* setup() */
 
mapping valid_attack() {
   return([
	"punch"     :  ({"\n\nSuddenly, from out of nowhere, a "
			"winged warhammer appears in a green flash "
			"\n"
			"right next to "+AN+". \n\n"
			"He grabs it and throws it at "+DN+" scoring a "
			"a direct hit to the chest.\n\n"
			"While "+DN+" is stunned Sharn follows up with a "
			"massive uppercut.\n\n"
			"The hammer disappears in a bright green fla\n\n",
			"\n\n"
			"You throw a hammer at "+DN+".\n",
			"\n\n"
			"Suddenly, from out of nowhere, a winged warhammer "
			"appears in a green flash\n"
			"right next to "+AN+".\n\n"
			"Sharn throws the hammer at you, hitting you square in "
			"the chest.\n\n"
			"Sharn follows up with a massive uppercut while "
			"you were stunned.\n\n"
			"The hammer disappears in a bright green flash.\n" }),
	"kick"  : ({ AN+" grabs "+DN+"'s head and slams it into the bar.\n",
		     "You slam "+DN+"'s head into the bar.\n",
               "\n"+AN+" grabs your head and slams it into the bar.\n\n"}),
	"knee"  : ({ AN+" throws "+DN+" into a wall.\n",
		     "You throw "+DN+" into a wall.\n",
                "\n"+AN+" grabs you and throws you against the wall.\n\n"}),
	"headbutt"     :  ({"\n\nSuddenly, a winged warhammer appears in the "
			"air next to Sharn.\n"
			"  "+DN+" dodges the attack and stumbles around.\n\n"
			"Sharn attacks while "+DN+" is off-balance, "
			"delivering a two-fisted \n"
			"blow to the head.\n\n"
			"The hammer disappears in a green flash.\n\n",
			"You hit "+DN+" with the hammer.",
			"\n\n"
			"Suddenly, a winged warhammer appears in the air "
			"next to Sharn.\n"
			"\n"
			"He grabs the hammer and throws it at you.  You "
			"are just \n"
			"able to dodge it, but the movement puts you off "
			"balance.\n"
			"\n"
			"Sharn attacks you while you are trying to regain "
			"your footing. \n"
			"\nSharn clasps his hands together and delivers "
			"a forceful blow to your \nforehead. \n\n"})
]);
} /* mapping valid_attack() */
// Read /w/sojan/combat/unarmed_combat.doc for more info on mapping valid_attack()...

