/* By Shimmer */

#define CREATOR "shimmer";

#include "../../../path.h"

inherit "obj/weapon";

void setup ()  
{
	set_base_weapon("long sword");
	set_name("Espada %^BOLD%^WHITE%^Angelical%^RESET%^");
	set_short("Espada %^BOLD%^WHITE%^Angelical%^RESET%^");
	add_alias("espada");
	add_alias("angelical");
	add_plural("espadas angelicales");
	add_plural("espadas");
	set_main_plural("Espadas %^BOLD%^WHITE%^Angelicales%^RESET%^");
	set_weight(200);
	set_twohanded(0);
	set_long("Esta es una de las miticas Espadas %^BOLD%^WHITE%^Angelicales%^RESET%^, creadas por Barthleby en tiempos antiguos y destinadas a "+
		"destruir el mal en nombre del bien, solo los de alma pura y algelica pueden soportar la carga ke infunde la espada.\n");
        set_enchant(1);
        add_property("guild", "paladin");
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
		"Espada %^BOLD%^WHITE%^Angelical%^RESET%^ en el suelo. "
		,({him,me}));
	  write("Hundes la espada %^BOLD%^WHITE%^Angelical%^RESET%^"
	        " en el suelo.\n");
	  tell_object(him,me->query_cap_name()+" hunde su Espada " 
	  "%^BOLD%^WHITE%^Angelical%^RESET%^ en el suelo.\n");
	  }
	  else if(dam <11)
	  {
	  tell_room(ENV(me),me->query_cap_name()+" roza con la "
		"Espada %^BOLD%^WHITE%^Angelical%^RESET%^ a "
		+him->query_cap_name()+".\n"
		,({him,me}));
	  write("Rozas a "+him->query_cap_name()+" con tu "
		"Espada %^BOLD%^WHITE%^Angelical%^RESET%^.\n");
	  tell_object(him,me->query_cap_name()+" te roza con su "
	        "Espada %^BOLD%^WHITE%^Angelical%^RESET%^.\n");
	  }	
	  else if(dam >10 && dam < 22)
	  {
	  tell_room(ENV(me),me->query_cap_name()+" corta con la "
		"Espada %^BOLD%^WHITE%^Angelical%^RESET%^ a "
		+him->query_cap_name()+" produciendole una herida sangrante.\n"
		,({him,me}));
	  write("Cortas a "+him->query_cap_name()+" con tu "
		"Espada %^BOLD%^WHITE%^Angelical%^RESET%^ "
		"produciendole una herida sangrante.\n");
	  tell_object(him,me->query_cap_name()+" te corta con su "
	        "Espada %^BOLD%^WHITE%^Angelical%^RESET%^ "
	        "produciendote una sangrante herida.\n");
	}	
	else if(dam>21 && dam<50)
	  {
	  tell_room(ENV(me),me->query_cap_name()+" de un rapido movimiento "
		"con su Espada %^BOLD%^WHITE%^Angelical%^RESET%^ "
		"hiere a "+him->query_cap_name()+" haciendo saltar sus "
		"%^RED%^BOLD%^intestinos %^RESET%^por toda la zona.\n",({him,me}));
	  write("De un rapido movimiento con tu "
	  	"Espada %^BOLD%^WHITE%^Angelical%^RESET%^ alcanzas a "
	  	+him->query_cap_name()+
	  	" haciendo saltar sus %^RED%^BOLD%^intestinos %^RESET%^por toda la zona.\n");
	  tell_object(him,me->query_cap_name()+" hace un rapido movimiento "
	  	"con su Espada %^BOLD%^WHITE%^Angelical%^RESET%^"
	        "incrustandola en tu estomago. "
	        "Tus %^RED%^BOLD%^intestinos %^RESET%^quedan repartidos por la zona.\n");
	}
		else
	  {
	  tell_room(ENV(me),me->query_cap_name()+" eleva sus manos "
		"apuntando su Espada %^BOLD%^WHITE%^Angelical%^RESET%^ hacia el cielo, con un certero giro"
		"la desliza sobre" +him->query_cap_name()+" abriendo brutalmente su abdomen y removiendole "
		"las entranyas.\n",({him,me}));
	  write("Elevas hacia el cielo tu Espada %^BOLD%^WHITE%^Angelical%^RESET%^ dejandola "
                "caer con un certero giro sobre "+him->query_cap_name()+" abriendo brutalmente su "
                "abdomen y removiendole las entranyas.\n");
	  tell_object(him,me->query_cap_name()+" eleva sus manos hacia el cielo dejando caer su Espada %^BOLD%^WHITE%^Angelical%^RESET%^ "
	        "con un certero giro abriendo brutalmente tu abdomen y removiendote las entranyas. Comienzas a %^RED%^BOLD%^sangrar %^RESET%^desmesuradamente.\n");
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
	write("La espada %^BOLD%^WHITE%^Angelical%^RESET%^ brilla de placer "
	"con una luz %^BOLD%^CYAN%^azulada%^RESET%^, cuando se cobra su dosis de energia.\n");
	tell_object(defdr, "La espada %^BOLD%^WHITE%^Angelical%^RESET%^ de "+atckr->QCN+" brilla de placer con una luz %^BOLD%^BOLD%^CYAN%^azulada%^RESET%^ cuando te cobra su dosis de energia.\n");
	tell_room(ENV(atckr), "La espada %^BOLD%^WHITE%^Angelical%^RESET%^ de "+atckr->QCN+" emite una luz %^BOLD%^CYAN%^azulada%^RESET%^ al impactar en "+defdr->QCN+".\n",({atckr,defdr}));
 defdr->adjust_hp(-b, atckr);
 atckr->adjust_hp(b);
}
//::weapon_attack(defdr,atckr,damage_roll);
::weapon_attack(defdr,atckr,damage_roll);

return ::weapon_attack(defdr,atckr,damage_roll);
}

int query_damage_roll()
{
	if (this_player()->query_guild_name() == "paladin")
	return (::query_damage_roll() + random(12)+5);

        return (::query_damage_roll() + random(12));
}



int set_in_use(int i, object miamo)
{
    if(this_player()->query_guild_name()=="paladin")
    {
        if (i) 
	{
                tell_object(miamo,
                "Sientes penetrar en ti la fuerza del Dios Barthleby, sintiendote poderoso.\n");
        }
        else
        {
                tell_object(miamo,
                "Notas una calma interior al envainar el arma forjada por Barthleby.\n");
        }
        return ::set_in_use(i);
    }
    else
    {
	tell_room(this_player()->query_cap_name()+" es herido por una descarga "
                "procedente de la Espada %^BOLD%^WHITE%^Angelical%^RESET%^.\n");
        write("La Espada %^BOLD%^WHITE%^Angelical%^RESET%^ te produce una descarga al rechazarte.\n");
        this_player()->adjust_hp(-random(10)-20);  
    }
return 0;

}
