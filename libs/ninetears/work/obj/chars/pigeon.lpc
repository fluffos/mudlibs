inherit "/obj/monster";
#include "unarmed_combat.h";
 
void setup() 
{
   set_name("pigeon");
   set_short("Pigeon");
   set_long("A white pigeon scurries along on the ground, scavenging "
            "for scraps.\n");
   set_main_plural("Pigeons");
   set_level(2);
   set_gender(2);
   set_race("bird");
   set_guild("fighter");
   set_str(9);
   set_dex(18);
   set_max_hp(15);
   set_al(30);
   load_chat(100, ({
	1, "The pigeon pecks around looking for scraps.",
	1, "A pigeon circles low over your head.",
	1, "The pigeon coos quietly.",
	1, "The pigeon whitens the ground around him.",
	1, "Flying low, the pigeon dumps a whitish-brown substance "
		"on your head.",
   }));
   load_a_chat(150, ({
	1, "The pigeon sqawks angrily at you.",
	1, "The pigeon flies up angrily into your face, momentarily "
		"blinding you.",
   1,"The pigeon defecates on your person.\n",
   }));
 
 
} 
 
mapping valid_attack() 
{
   return([
	"punch"  : ({ AN+" buffets "+DN+" with its wings.\n",
		      "You buffet "+DN+" with your wings.\n",
		      AN+" buffets you with its wings.\n" }),
	"kick"  : ({  AN+" pecks at "+DN+" with its beak.\n",
		      "You peck at "+DN+" with your beak.\n",
		      AN+" pecks at you with its sharp beak.\n" }),
	"knee"  : ({  AN+" scratches at "+DN+"'s eyes.\n",
		      "You scratch at "+DN+"'s eyes.\n",
		      AN+" scratches angrily at your eyes.\n" }),
	"headbutt"  : ({ AN+" bites "+DN+".\n",
		     	 "You bite "+DN+".\n",
			 AN+" bites you, hard!\n" }),
   ]);
 
} 
