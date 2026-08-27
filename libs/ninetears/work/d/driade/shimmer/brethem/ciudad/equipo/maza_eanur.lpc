/* By Shimmer */

#define CREATOR "shimmer";

#include "../../../path.h"

inherit "/obj/weapon";

void setup() 
   {
   set_base_weapon("mace");
   set_name("maza");
   set_short("%^BOLD%^Maza de %^BOLD%^CYAN%^Eanur%^RESET%^");
   set_main_plural("%^BOLD%^Mazas de %^BOLD%^CYAN%^Eanur%^RESET%^");
   add_plural("mazas");
     
   add_property("noslice",1);
   set_twohanded(1);
}

int query_damage_roll()
{
   return ::query_damage_roll() + random(40);
}

void write_message(string happen,int dam,string str,object me,object him) 
{
	  if(dam <= 0)
	  {
	    tell_room(ENV(me),me->query_cap_name()+" hunde su "
		"maza en el suelo retumbando a tu alrededor. "
		,({him,me}));
	  write("Hundes la %^BOLD%^Maza de %^BOLD%^CYAN%^Eanur%^RESET%^"
	        " en el suelo haciendo que retumbe.\n");
	  tell_object(him,me->query_cap_name()+" hunde su maza" 
	  " en el suelo haciendo que retumbe.\n");
	  }
	  else if(dam <11)
	  {
	  tell_room(ENV(me),me->query_cap_name()+" roza debilmente con su "
		"maza a "+him->query_cap_name()+".\n"
		,({him,me}));
	  write("Rozas debilmente a "+him->query_cap_name()+" con tu "
		"maza.\n");
	  tell_object(him,me->query_cap_name()+" te roza debilmente con su "
	        "maza.\n");
	  }	
	  else if(dam >10 && dam < 30)
	  {
	  tell_room(ENV(me),me->query_cap_name()+" golpea fuertemente con su "
		"maza a "+him->query_cap_name()+" produciendole dolorosos moratones.\n"
		,({him,me}));
	  write("Golpeas a "+him->query_cap_name()+" con tu "
		"maza produciendole dolorosos moratones.\n");
	  tell_object(him,me->query_cap_name()+" te golpea con su "
	        "maza produciendote dolorosos moratones.\n");
	}	
	else if(dam > 29 && dam < 50)
	  {
	  tell_room(ENV(me),me->query_cap_name()+" con un certero movimiento "
		"de su %^BOLD%^Maza de %^BOLD%^CYAN%^Eanur%^RESET%^"
		" alcanza a "+him->query_cap_name()+" en la cabeza haciendo saltar sus "
		"%^BOLD%^YELLOW%^dientes %^RESET%^por toda la zona.\n",({him,me}));
	  write("Con un certero movimiento de tu "
	  	"%^BOLD%^Maza de %^BOLD%^CYAN%^Eanur%^RESET%^ alcanzas a "
	  	+him->query_cap_name()+ " en la cabeza haciendo saltar sus %^BOLD%^YELLOW%^dientes%^RESET%^ por toda la zona.\n");
	  tell_object(him,me->query_cap_name()+" con un certero movimiento de su %^BOLD%^Maza de %^BOLD%^CYAN%^Eanur%^RESET%^"
	        " la hunde brutalmente en tu cabeza. Tus pobres %^BOLD%^YELLOW%^dientes %^RESET%^quedan repartidos por la zona.\n");
	}
		else
	  {
	  tell_room(ENV(me),me->query_cap_name()+" traza un gran arco en el aire "
		"con su %^BOLD%^Maza de %^BOLD%^CYAN%^Eanur%^RESET%^ "
		"hundiendo brutalmente el pecho de "+him->query_cap_name()+" que "
		"comienza a %^RED%^BOLD%^sangrar%^RESET%^ desmesuradamente.\n",({him,me}));
	  write("Trazas un gran arco en el aire con tu "
	  	"%^BOLD%^Maza de %^BOLD%^CYAN%^Eanur%^RESET%^ hundiendola brutalmente en el pecho de "
	  	+him->query_cap_name()+
	  	" que comienza a %^RED%^BOLD%^sangrar%^RESET%^ desmesuradamente.\n");
	  tell_object(him,me->query_cap_name()+" traza un gran arco en el aire "
	  	"con su %^BOLD%^Maza de %^BOLD%^CYAN%^Eanur%^RESET%^ "
	        "hundiendola brutalmente en tu pecho. Comienzas a %^RED%^BOLD%^sangrar%^RESET%^ desmesuradamente.\n");
	}

}