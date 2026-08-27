//By Koel & Dreyde

// mods by tyrael para adaptarlo al estado actual de la mudlib

inherit "obj/weapon";

void setup ()  
{
	set_base_weapon("bastard sword");
	set_name("Espada Sanguinaria");
	set_short("Espada Sanguinaria");
	add_alias("espada");
	add_alias("sanguinaria");
	add_plural("espadas sanguinarias");
	add_plural("espadas");
	set_main_plural("Espadas Sanguinarias");
	set_weight(20000);
	set_twohanded(0);
	set_long("Es una peasho de espada q hay hecho er yihad pq taba burrio en casa\n");
        set_enchant(100);
      //  add_property("guild", "antipaladin");
//      
//        remove_attack("tabla");
        //add_property("no_slice", 1);
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
		"Espada Sanguinaria en el suelo. "
		,({him,me}));
	  write("Hundes la Espada Sanguinaria"
	        " en el suelo.\n");
	  tell_object(him,me->query_cap_name()+" hunde su Espada " 
	  "Sanguinaria en el suelo.\n");
	  }
	  else if(dam <11)
	  {
	  tell_room(ENV(me),me->query_cap_name()+" roza con la "
		"Espada Sanguinaria a "
		+him->query_cap_name()+".\n"
		,({him,me}));
	  write("Rozas a "+him->query_cap_name()+" con tu "
		"Espada Sanguinaria.\n");
	  tell_object(him,me->query_cap_name()+" te roza con su "
	        "Espada Sanguinaria.\n");
	  }	
	  else if(dam >10 && dam < 22)
	  {
	  tell_room(ENV(me),me->query_cap_name()+" corta con la "
		"Espada Sanguinaria a "
		+him->query_cap_name()+" produciendole una herida sangrante.\n"
		,({him,me}));
	  write("Cortas a "+him->query_cap_name()+" con tu "
		"Espada Sanguinaria "
		"produciendole una herida sangrante.\n");
	  tell_object(him,me->query_cap_name()+" te corta con su "
	        "Espada Sanguinaria "
	        "produciendote una sangrante herida.\n");
	}	
	else if(dam>21 && dam<50)
	  {
	  tell_room(ENV(me),me->query_cap_name()+" de un rapido movimiento "
		"con su Espada Sanguinaria"
		"hiere a "+him->query_cap_name()+" haciendo saltar sus "
		"%^RED%^BOLD%^intestinos %^RESET%^por toda la zona.\n",({him,me}));
	  write("De un rapido movimiento con tu "
	  	"Espada Sanguinaria alcanzas a "
	  	+him->query_cap_name()+
	  	" haciendo saltar sus %^RED%^BOLD%^intestinos %^RESET%^por toda la zona.\n");
	  tell_object(him,me->query_cap_name()+" hace un rapido movimiento "
	  	"con su Espada Sanguinaria"
	        "incrustandola en tu estomago. "
	        "Tus %^RED%^BOLD%^intestinos %^RESET%^quedan repartidos por la zona.\n");
	}
		else
	  {
	  tell_room(ENV(me),me->query_cap_name()+" traza un gran arco en el aire "
		"con su Espada Sanguinaria"
		"sobre" +him->query_cap_name()+" quien comienza a "
		"%^RED%^BOLD%^sangrar %^RESET%^desmesuradamente.\n",({him,me}));
	  write("Trazas un gran arco en el %^BOLD%^aire %^RESET%^con tu "
	  	"Espada Sanguinaria sobre "
	  	+him->query_cap_name()+
	  	" que comienza a %^RED%^BOLD%^sangrar %^RESET%^desmesuradamente.\n");
	  tell_object(him,me->query_cap_name()+" traza un gran arco en el %^BOLD%^aire "
	  	"con su Espada Sanguinaria"
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
	write("La espada Sanguinaria brilla de placer "
	"con una luz %^BOLD%^RED%^rojiza%^RESET%^, cuando se cobra su dosis de energia.\n");
	tell_object(defdr, "La espada Sanguinaria de "+atckr->QCN+" brilla de placer con una luz %^BOLD%^RED%^rojiza%^RESET%^ cuando te cobra su dosis de energia.\n");
	tell_room(ENV(atckr), "La espada Sanguinaria de "+atckr->QCN+" emite una luz %^BOLD%^RED%^rojiza%^RESET%^ al impactar en "+defdr->QCN+".\n",({atckr,defdr}));
 defdr->adjust_hp(-b, atckr);
 atckr->adjust_hp(b);
}
//::weapon_attack(defdr,atckr,damage_roll);
::weapon_attack(defdr,atckr,damage_roll);

return ::weapon_attack(defdr,atckr,damage_roll);
}

//int query_damage_roll()
//{
//	if (this_player()->query_guild_name() == "antipaladin")
//	return (::query_damage_roll() + random(12)+5);
//
  //      return (::query_damage_roll() + random(12));
//}



//int set_in_use(int i, object miamo)
//{
  //  if(this_player()->query_guild_name()=="antipaladin")
    //{
      //  if (i) 
	//{
          //      tell_object(miamo,
            //    "Sientes penetrar en ti la fuerza de los espiritus, sintiendote poderoso.\n");
        //}
        //else
        //{
                //tell_object(miamo,
                //"Notas una calma interior al envainar el arma de tus antepasados.\n");
        //}
        //return ::set_in_use(i);
    //}
    //else
    //{
//	tell_room(this_player()->query_cap_name()+" es herido por una descarga "
                //"procedente de la Espada Sanguinaria.\n");
        //write("La Espada Sanguinaria te produce una descarga al rechazarte.\n");
        //this_player()->adjust_hp(-random(10)-20);  
    //}
//return 0;

//}
