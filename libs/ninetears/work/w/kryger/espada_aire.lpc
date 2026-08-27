//By Koel & Dreyde

// mods by tyrael para adaptarlo al estado actual de la mudlib

inherit "obj/weapon";

void setup ()  
{
	set_base_weapon("short sword");
	set_name("Espada de %^BOLD%^CYAN%^Aire%^RESET%^");
	set_short("Espada de %^BOLD%^CYAN%^Aire%^RESET%^");
	add_alias("espada");
	add_alias("aire");
	add_adjective("aire");
	add_plural("espadas de aires");
	add_plural("espadas");
	add_plural("aires");
	set_main_plural("Espadas de %^BOLD%^CYAN%^Aire%^RESET%^");
	set_weight(200);
	set_twohanded(0);
	set_long(
		"Ante ti tienes una magnifica espada de aire, su origen parece ser magico, muy ligera "
	    "y maniobrable, te permitira manejarla con velocidad y eficacia, parece no tener filo "
		"pero un ligero fulgor azulado que surge de la empunyadura te hace pensar que en "
		"realidad no es asi.\n");
        set_enchant(0);
//        remove_attack("tabla");
        add_attack("slashing",5,10,0);
        add_attack("blunt",5,4,0);
//        set_genero(1); 
//        
//      
}

void write_message(string happen,int dam,string str,object me,object him) 
{
	  if(dam <= 0)
	  {
	    tell_room(ENV(me),me->query_cap_name()+" hunde la  "
		"Espada de %^CYAN%^Espectral%^RESET%^ en el suelo. "
		,({him,me}));
	  write("Hundes la espada de %^CYAN%^%^BOLD%^aire%^RESET%^"
	        " en el suelo.\n");
	  tell_object(him,me->query_cap_name()+" hunde su Espada de" 
	  " %^CYAN%^%^BOLD%^aire%^RESET%^ en el suelo.\n");
	  }
	  else if(dam <11)
	  {
	  tell_room(ENV(me),me->query_cap_name()+" roza con la "
		"Espada de %^BOLD%^CYAN%^Aire%^RESET%^ a "
		+him->query_cap_name()+".\n"
		,({him,me}));
	  write("Rozas a "+him->query_cap_name()+" con tu "
		"Espada de %^BOLD%^CYAN%^Aire%^RESET%^.\n");
	  tell_object(him,me->query_cap_name()+" te roza con su "
	        "Espada de %^BOLD%^CYAN%^Aire%^RESET%^.\n");
	  }	
	  else if(dam >10 && dam < 22)
	  {
	  tell_room(ENV(me),me->query_cap_name()+" corta con la "
		"Espada de %^BOLD%^CYAN%^Aire%^RESET%^ a "
		+him->query_cap_name()+" produciendole una herida sangrante.\n"
		,({him,me}));
	  write("Cortas a "+him->query_cap_name()+" con tu "
		"Espada de %^BOLD%^CYAN%^Aire%^RESET%^ "
		"produciendole una herida sangrante.\n");
	  tell_object(him,me->query_cap_name()+" te corta con su "
	        "Espada de %^BOLD%^CYAN%^Aire%^RESET%^ "
	        "produciendote una sangrante herida.\n");
	}	
	else if(dam>21 && dam<50)
	  {
	  tell_room(ENV(me),me->query_cap_name()+" de un rapido movimiento "
		"con su Espada de %^BOLD%^CYAN%^Aire%^RESET%^"
		"hiere a "+him->query_cap_name()+" haciendo saltar sus "
		"%^RED%^BOLD%^intestinos %^RESET%^por toda la zona.\n",({him,me}));
	  write("De un rapido movimiento con tu "
	  	"Espada de %^BOLD%^CYAN%^Aire%^RESET%^ alcanzas a "
	  	+him->query_cap_name()+
	  	" haciendo saltar sus %^RED%^BOLD%^intestinos %^RESET%^por toda la zona.\n");
	  tell_object(him,me->query_cap_name()+" hace un rapido movimiento "
	  	"con su Espada de %^BOLD%^CYAN%^Aire%^RESET%^"
	        "incrustandola en tu estomago. "
	        "Tus %^RED%^BOLD%^intestinos %^RESET%^quedan repartidos por la zona.\n");
	}
		else
	  {
	  tell_room(ENV(me),me->query_cap_name()+" traza un gran arco en el aire "
		"con su Espada de %^BOLD%^CYAN%^Aire%^RESET%^"
		"sobre" +him->query_cap_name()+" quien comienza a "
		"%^RED%^BOLD%^sangrar %^RESET%^desmesuradamente.\n",({him,me}));
	  write("Trazas un gran arco en el %^BOLD%^aire con tu "
	  	"Espada de %^BOLD%^CYAN%^Aire%^RESET%^ sobre "
	  	+him->query_cap_name()+
	  	" que comienza a %^RED%^BOLD%^sangrar %^RESET%^desmesuradamente.\n");
	  tell_object(him,me->query_cap_name()+" traza un gran arco en el %^BOLD%^aire "
	  	"con su Espada de %^BOLD%^CYAN%^Aire%^RESET%^"
	        "descargandola brutalmente contra ti. "
	        "Comienzas a %^RED%^BOLD%^sangrar %^RESET%^desmesuradamente.\n");
	}

}
int weapon_attack(object defdr, object atckr,int damage_roll)
{
int a,b;
if(random(100)<10)
{ 
a=defdr->query_hp();
b=a/((random(10))+1);
// buffffffff, usar adjust_hp!!!
//defdr->set_hp(a-b);
	write("La Espada de %^BOLD%^CYAN%^Aire%^RESET%^ brilla de placer "
	"con una luz %^BOLD%^CYAN%^azulada%^RESET%^, cuando se cobra su dosis de energia.\n");
	tell_object(defdr, "La Espada de %^BOLD%^CYAN%^Aire%^RESET%^ de "+atckr->QCN+" brilla de placer con una luz %^BOLD%^CYAN%^azulada%^RESET%^ cuando te cobra su dosis de energia.\n");
	tell_room(ENV(atckr), "La Espada de %^BOLD%^CYAN%^Aire%^RESET%^ de "+atckr->QCN+" emite una luz %^BOLD%^CYAN%^azulada%^RESET%^ al impactar en "+defdr->QCN+".\n",({atckr,defdr}));
 defdr->adjust_hp(-b, atckr);
	 
}
//::weapon_attack(defdr,atckr,damage_roll);
::weapon_attack(defdr,atckr,damage_roll);


return ::weapon_attack(defdr,atckr,damage_roll);
}

int query_damage_roll()
{
	return (::query_damage_roll() + random(22));
}

