//By Koel & Dreyde

// mods by tyrael para adaptarlo al estado actual de la mudlib

inherit "obj/weapon";

void setup ()  
{
	set_base_weapon("long sword");
	set_name("Espada %^BOLD%^BLACK%^Negra%^RESET%^");
	set_short("Espada %^BOLD%^BLACK%^Negra%^RESET%^");
	add_alias("espada");
	add_alias("negra");
	add_plural("espadas negras");
	add_plural("espadas");
	set_main_plural("Espadas %^BOLD%^BLACK%^Negras%^RESET%^");
	set_weight(200);
	set_twohanded(0);
	set_long("La famosa Espada %^BOLD%^BLACK%^Negra%^RESET%^, pasada de generacion en generacion, "+
		"capaz de aprender por si misma por el uso, algunos dicen que un hechizo es la causa de su poder... \n");
        set_enchant(1);
        add_property("guild", "caballero de jade");
//      
//        remove_attack("tabla");
        add_property("no_slice", 1);
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
	    tell_room(ENV(me),me->query_cap_name()+" hunde la "
		"Espada %^BOLD%^BLACK%^Negra%^RESET%^ en el suelo. "
		,({him,me}));
	  write("Hundes la espada %^BOLD%^BLACK%^Negra%^RESET%^"
	        " en el suelo.\n");
	  tell_object(him,me->query_cap_name()+" hunde su Espada " 
	  "%^BOLD%^BLACK%^Negra%^RESET%^ en el suelo.\n");
	  }
	  else if(dam <11)
	  {
	  tell_room(ENV(me),me->query_cap_name()+" roza con la "
		"Espada %^BOLD%^BLACK%^Negra%^RESET%^ a "
		+him->query_cap_name()+".\n"
		,({him,me}));
	  write("Rozas a "+him->query_cap_name()+" con tu "
		"Espada %^BOLD%^BLACK%^Negra%^RESET%^.\n");
	  tell_object(him,me->query_cap_name()+" te roza con su "
	        "Espada %^BOLD%^BLACK%^Negra%^RESET%^.\n");
	  }	
	  else if(dam >10 && dam < 22)
	  {
	  tell_room(ENV(me),me->query_cap_name()+" corta con la "
		"Espada %^BOLD%^BLACK%^Negra%^RESET%^ a "
		+him->query_cap_name()+" produciendole una herida sangrante.\n"
		,({him,me}));
	  write("Cortas a "+him->query_cap_name()+" con tu "
		"Espada %^BOLD%^BLACK%^Negra%^RESET%^ "
		"produciendole una herida sangrante.\n");
	  tell_object(him,me->query_cap_name()+" te corta con su "
	        "Espada %^BOLD%^BLACK%^Negra%^RESET%^ "
	        "produciendote una sangrante herida.\n");
	}	
	else if(dam>21 && dam<50)
	  {
	  tell_room(ENV(me),me->query_cap_name()+" de un rapido movimiento "
		"con su Espada %^BOLD%^BLACK%^Negra %^RESET%^"
		"hiere a "+him->query_cap_name()+" haciendo saltar sus "
		"%^RED%^BOLD%^intestinos %^RESET%^por toda la zona.\n",({him,me}));
	  write("De un rapido movimiento con tu "
	  	"Espada %^BOLD%^BLACK%^Negra%^RESET%^ alcanzas a "
	  	+him->query_cap_name()+
	  	" haciendo saltar sus %^RED%^BOLD%^intestinos %^RESET%^por toda la zona.\n");
	  tell_object(him,me->query_cap_name()+" hace un rapido movimiento "
	  	"con su Espada %^BOLD%^BLACK%^Negra %^RESET%^"
	        "incrustandola en tu estomago. "
	        "Tus %^RED%^BOLD%^intestinos %^RESET%^quedan repartidos por la zona.\n");
	}
		else
	  {
	  tell_room(ENV(me),me->query_cap_name()+" traza un gran arco en el aire "
		"con su Espada %^BOLD%^BLACK%Negra%^RESET%^"
		"sobre" +him->query_cap_name()+" quien comienza a "
		"%^RED%^BOLD%^sangrar %^RESET%^desmesuradamente.\n",({him,me}));
	  write("Trazas un gran arco en el %^BOLD%^aire con tu "
	  	"Espada de %^BOLD%^BLACK%^Negra%^RESET%^sobre "
	  	+him->query_cap_name()+
	  	" que comienza a %^RED%^BOLD%^sangrar %^RESET%^desmesuradamente.\n");
	  tell_object(him,me->query_cap_name()+" traza un gran arco en el %^BOLD%^aire "
	  	"con su Espada %^BOLD%^BLACK%^Negra%^RESET%^"
	        "descargandola brutalmente contra ti. "
	        "Comienzas a %^RED%^BOLD%^sangrar %^RESET%^desmesuradamente.\n");
	}

}



int weapon_attack(object defdr, object atckr)
{
int a,b;
if(random(100)<10)
{ 
a=defdr->query_hp();
b=a/((random(10))+1);
// buffffffff, usar adjust_hp!!!
//defdr->set_hp(a-b);
	write("La espada %^BOLD%^BLACK%^Negra%^RESET%^ brilla de placer "
	"con una luz %^BOLD%^BLUE%^azulada%^RESET%^, cuando se cobra su dosis de energia.\n");
	tell_object(defdr, "La espada %^BOLD%^BLACK%^Negra%^RESET%^ de "+atckr->QCN+" brilla de placer con una luz %^BOLD%^BOLD%^BLACK%^azulada%^RESET%^ cuando te cobra su dosis de energia.\n");
	tell_room(ENV(atckr), "La espada %^BOLD%^BLACK%^Negra%^RESET%^ de "+atckr->QCN+" emite una luz %^BOLD%^BOLD%^BLACK%^azulada%^RESET%^ al impactar en "+defdr->QCN+".\n",({atckr,defdr}));
 defdr->adjust_hp(-b, atckr);
	 
}
//::weapon_attack(defdr,atckr,damage_roll);
::weapon_attack(defdr,atckr);

return ::weapon_attack(defdr,atckr);
}






int query_damage_roll()
{
	if (this_player()->query_guild_name() == "antipaladin")
	return (::query_damage_roll() + random(8)+5);

        return (::query_damage_roll() + random(8));
}



int set_in_use(int i, object miamo)
{
    if(miamo->query_guild_name()=="antipaladin")
    {
        if (i) 
	{
                tell_object(miamo,
                "Sientes penetrar en ti la fuerza de los espiritus, sintiendote poderoso.\n");
        }
        else
        {
                tell_object(miamo,
                "Notas una calma interior al envainar el arma de tus antepasados.\n");
        }
        return ::set_in_use(i);
    }
    else
    {
	tell_room(miamo->query_cap_name()+" es herido por una descarga "
                "procedente de la Espada%^BLACK%^BOLD%^Negra%^RESET%^.\n");
        tell_object(miamo,"La Espada %^BOLD%^BLACK%^Negra%^RESET%^ te produce una descarga al rechazarte.\n");
        miamo->adjust_hp(-random(10)-20);  
    }
return 0;

}
