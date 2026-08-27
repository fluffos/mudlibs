//By Koel & Dreyde

// mods by tyrael para adaptarlo al estado actual de la mudlib

inherit "obj/weapon";

void setup ()  
{
	set_base_weapon("halberd");
	set_name("alabarda");
	set_short("%^BOLD%^BLACK%^Alabarda %^CYAN%^Espectral%^RESET%^");
	add_alias("alabarda");
	add_adjective("espectral");
	add_plural("alabardas espectrales");
	add_plural("espectrales");
	set_main_plural("%^BOLD%^BLACK%^Alabardas %^CYAN%^Espectrales%^RESET%^");
	set_weight(500);
	set_twohanded(1);
	set_long(
		""
	    	".\n");
        set_enchant(0);
//        remove_attack("tabla");
//        add_attack("slashing",5,10,0);
        add_attack("blunt",5,4,0);
//        set_genero(1); 
}

void write_message(string happen,int dam,string str,object me,object him) 
{
	  if(dam <= 0)
	  {
	    tell_room(ENV(me),me->query_cap_name()+" hunde la  "
		"%^BOLD%^BLACK%^Alabarda %^CYAN%^Espectral%^RESET%^ en el suelo. "
		,({him,me}));
	  write("Hundes la %^BOLD%^BLACK%^Alabarda %^CYAN%^Espectral%^RESET%^"
	        " en el suelo.\n");
	  tell_object(him,me->query_cap_name()+" hunde su %^BOLD%^BLACK%^Alabarda" 
	  " %^CYAN%^Espectral%^RESET%^ en el suelo.\n");
	  }
	  else if(dam <11)
	  {
	  tell_room(ENV(me),me->query_cap_name()+" roza con la "
		"%^BOLD%^BLACK%^Alabarda %^CYAN%^Espectral%^RESET%^ a "
		+him->query_cap_name()+".\n"
		,({him,me}));
	  write("Rozas a "+him->query_cap_name()+" con tu "
		"%^BOLD%^BLACK%^Alabarda %^CYAN%^Espectral%^RESET%^.\n");
	  tell_object(him,me->query_cap_name()+" te roza con su "
	        "%^BOLD%^BLACK%^Alabarda %^CYAN%^Espectral%^RESET%^.\n");
	  }	
	  else if(dam >10 && dam < 22)
	  {
	  tell_room(ENV(me),me->query_cap_name()+" corta con la "
		"%^BOLD%^BLACK%^Alabarda %^CYAN%^Espectral%^RESET%^ a "
		+him->query_cap_name()+" produciendole una herida sangrante.\n"
		,({him,me}));
	  write("Cortas a "+him->query_cap_name()+" con tu "
		"%^BOLD%^BLACK%^Alabarda %^CYAN%^Espectral%^RESET%^ "
		"produciendole una herida sangrante.\n");
	  tell_object(him,me->query_cap_name()+" te corta con su "
	        "%^BOLD%^BLACK%^Alabarda %^CYAN%^Espectral%^RESET%^ "
	        "produciendote una sangrante herida.\n");
	}	
	else
	  {
	  tell_room(ENV(me),me->query_cap_name()+" traza un gran arco en el aire "
		"con su %^BOLD%^BLACK%^Alabarda %^CYAN%^Espectral %^RESET%^"
		"sobre" +him->query_cap_name()+" quien comienza a "
		"%^RED%^BOLD%^sangrar %^RESET%^desmesuradamente.\n",({him,me}));
	  write("Trazas un gran arco en el aire con tu "
	  	"%^BOLD%^BLACK%^Alabarda %^CYAN%^Espectral %^RESET%^sobre "
	  	+him->query_cap_name()+
	  	" que comienza a %^RED%^BOLD%^sangrar %^RESET%^desmesuradamente.\n");
	  tell_object(him,me->query_cap_name()+" traza un gran arco en el aire "
	  	"con su %^BOLD%^BLACK%^Alabarda %^CYAN%^Espectral %^RESET%^"
	        "descargandola brutalmente contra ti. "
	        "Comienzas a %^RED%^BOLD%^sangrar %^RESET%^desmesuradamente.\n");
	}

}
int weapon_attack(object defdr, object atckr,int damage_roll)
{
int a,b;
if(random(397)<50)
{ 
a=defdr->query_hp();
b=a/10;
// buffffffff, usar adjust_hp!!!
//defdr->set_hp(a-b);
	write("La %^BOLD%^BLACK%^Alabarda %^CYAN%^Espectral%^RESET%^ brilla de placer "
	"con una luz %^CYAN%^azulada%^RESET%^, cuando se cobra su dosis de energia.\n");
	tell_object(defdr, "La %^BOLD%^%^BLACK%^Alabarda %^CYAN%^Espectral%^RESET%^ de "+atckr->QCN+" brilla de placer con una luz %^CYAN%^azulada%^RESET%^ cuando te cobra su dosis de energia.\n");
	tell_room(ENV(atckr), "La %^BOLD%^%^BLACK%^Alabarda %^CYAN%^Espectral%^RESET%^ de "+atckr->QCN+" emite una luz %^CYAN%^azulada%^RESET%^ al impactar en "+defdr->QCN+".\n",({atckr,defdr}));
 defdr->adjust_hp(-b, atckr);
	 
}
::weapon_attack(defdr,atckr,damage_roll);
::weapon_attack(defdr,atckr,damage_roll);
::weapon_attack(defdr,atckr,damage_roll);
::weapon_attack(defdr,atckr,damage_roll);
::weapon_attack(defdr,atckr,damage_roll);
::weapon_attack(defdr,atckr,damage_roll);
return ::weapon_attack(defdr,atckr,damage_roll);
}

int query_damage_roll()
{
	return (::query_damage_roll() + random(5) + 1);
}
