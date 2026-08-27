#define BONO_RAZA 3
inherit "/baseobs/weapons/dagger";

void setup()
{
	::setup();
	 set_short("Daga goblin");
       set_main_plural("Dagas goblin");
	 set_long("Tus manos sostienen uno de los ultimos regalos de los ancestros de"
	 " los goblins a dicha raza. Se dice que el shaman J'Zhadra, antes de morir enloquecido, "
	 "menciono la existencia de una daga de gran valor para los goblins.\n");
}

/* if the wielder is a dwarf, and this is his only weapon, he gets a bonus */
int weapon_attack(object him,object me)
{
	int rv;
	::weapon_attack(him,me);
	if(sizeof(me->query_weapons_wielded()) == 2 && (string)me->query_race() == "goblin")
	{
/* this checks to make sure that this is the ONLY wielded weapon then 50% of the time awards a bonus attack */
		if(!random(BONO_RAZA))
	  {
			tell_object(me,"La sabiduria de los goblins ancestrales se canaliza a traves de tu brazo !\n");
		  tell_object(him,"Una tenue aura recorre el brazo de este goblin, que parece atacar con mayor decision !\n");
			::weapon_attack(him,me);
	  }

	}

		/* Hmm, wonder if this will work....*/
/*	else if((string)me->query_race() != "goblin")
	{
	 if( sizeof(me->query_weapons_wielded()) == 2)
	 {
		  tell_object(me,"Los ancestros goblins se enfurecen y detienen tu ataque !\n");
		  tell_object(him,"El ataque de tu contrincante es detenido por fuerzas ancestrales !\n");
		  call adjust_hp(-10)me
	  }

	}
*/
}
