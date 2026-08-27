/* By Shimmer */

#define CREATOR "shimmer";

#include "../../../path.h"

inherit "obj/weapon";

void setup ()  
{
	set_base_weapon("long sword");
	set_name("%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^");
	set_short("%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^");
	add_alias("filo");
	add_alias("angelical");
	add_plural("filo infernal");
	add_plural("filos");
	set_main_plural("%^BOLD%^WHITE%^Filos %^CYAN%^Celestiales%^RESET%^");
	set_weight(200);
	set_twohanded(0);
	set_long("Este poderoso filo fue creado por y para el creador Shimmer, su mango estrecho y fino parece fundirse con tu cuerpo "
                 "cuando lo empunyas, su hoja larga y fina brilla con un tenue resplandor rojo y amarillo como si un fuego crecise en "
                 "su interior deseando salir y mostrar su poder.\n");
        set_enchant(1);
        add_property("name", "tyrael");

        add_attack("slashing",5,10,0);
        add_attack("blunt",5,4,0);

     
}

void write_message(string happen,int dam,string str,object me,object him) 
{
   if(dam <= 0)
   {
      switch(random(3)) {

      case 0:     

      tell_room(ENV(me),me->query_cap_name()+" falla estrepitosamente cuando "
                "intentaba golpear a "+him->query_cap_name()+"con su %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^."
                 ,({him,me}));
      write("Fallas estrepitosamente cuando intentabas golpear a tu enemigo "
                "con tu %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^.\n");
      tell_object(him,me->query_cap_name()+" falla estrepitosamente al intentar golpearte con su %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^.\n");

      break;

      case 1:

      tell_room(ENV(me),me->query_cap_name()+" hace silbar su %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ "
	        "al cortar el aire cuando su enemigo esquiva el ataque."
                ,({him,me}));
      write("Tu %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ silba al cortar el aire cuando tu enemigo "
	        "esquiva tu ataque.\n");
      tell_object(him,"Esquivas habilmente el ataque de "+me->query_cap_name()+" y su "
	        "%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ silba al cortar el aire.\n");
      break;

      case 2:

      tell_room(ENV(me),me->query_cap_name()+" agita su "
	        "%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ fallando al intentar golpear a su enemigo "
                ,({him,me}));
      write("Agitas el %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^"
	        " al fallar cuando intentabas golpear a "+him->query_cap_name()+".\n");
      tell_object(him,me->query_cap_name()+" agita su " 
	        "%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ fallando cuando intentaba golpearte.\n");
      break; }
      

   }
   else if(dam <11)
   {
      switch(random(3)) {
 
      case 0:
      
      tell_room(ENV(me),me->query_cap_name()+" raja debilmente con su "
		"%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ la cara de "
		+him->query_cap_name()+" cortandosela levemente.\n"
		,({him,me}));
      write("Rajas debilmente tu %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ "
                "la cara de "+him->query_cap_name()+" cortandosela levemente.\n");
      tell_object(him,me->query_cap_name()+" te raja debilmente en la cara con su %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ "
	        "cortandotela levemente.\n");

      break;

      case 1:
      
      tell_room(ENV(me),me->query_cap_name()+" blande su "
		"%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ alcanzando una pierna de "
		+him->query_cap_name()+" y producendole leves heridas.\n"
		,({him,me}));
      write("Blandes tu %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ "
                "alcanzando una pierna de "+him->query_cap_name()+" produciendole leves heridas.\n");
      tell_object(him,me->query_cap_name()+" blande su %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ "
	        "alcanzando una de tus piernas y produciendo leves heridas.\n");


      break;

      case 2:
      
      tell_room(ENV(me),me->query_cap_name()+" corta ligeramente a "+him->query_cap_name()+" con su "
		"%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^.\n",({him,me}));
      write("Rajas ligeramente a "+him->query_cap_name()+" con tu %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^.\n");
      tell_object(him,me->query_cap_name()+" te raja ligeramente con su %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^.\n");

      break; }

   }	
   else if(dam >10 && dam < 31)
   {

      switch(random(3)) {

      case 0:

      tell_room(ENV(me),me->query_cap_name()+" corta con su "
		"%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ uno de los brazos de "
		+him->query_cap_name()+" produciendole una sangrante herida.\n"
		,({him,me}));
      write("Cortas uno de los brazos de "+him->query_cap_name()+" con tu "
		"%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ "
		"produciendole una sangrante herida.\n");
      tell_object(him,me->query_cap_name()+" te corta uno de tus brazos con su "
	        "%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ "
	        "produciendote una sangrante herida.\n");

      break;

      case 1:

      tell_room(ENV(me),me->query_cap_name()+" desliza su "
		"%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ sobre las piernas de "
		+him->query_cap_name()+" haciendole un profundo corte.\n",({him,me}));
      write("Deslizas tu %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ sobre "
                "las piernas de "+him->query_cap_name()+" haciendole un profundo corte.\n");
      tell_object(him,me->query_cap_name()+" desliza su "
	        "%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ "
	        "sobre tus piernas haciendote un profundo corte.\n");

      break;

      case 2:

      tell_room(ENV(me),me->query_cap_name()+" produce un gran corte a "
		+him->query_cap_name()+"con su "
                "%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ "
                "abriendole el costado. "+him->query_cap_name()+" gime de dolor.\n"
		,({him,me}));
      write("Produces un gran corte a "+him->query_cap_name()+" con tu "
		"%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ "
		"abriendole el costado. "+him->query_cap_name()+" gime de dolor.\n");
      tell_object(him,me->query_cap_name()+" te produce un gran corte el costado con su "
	        "%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^. "
	        "Gimes de dolor.\n");

      break; }

   }	
   else if(dam>30 && dam<50)
   {
  
      switch(random(3)) {

      case 0:

      tell_room(ENV(me),me->query_cap_name()+" dibuja un magnifico y suave movimiento "
		"con su %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ "
		"hiere gravemente a "+him->query_cap_name()+" en el abdomen, sus "
		"%^RED%^BOLD%^intestinos %^RESET%^ vuelan por toda la zona.\n",({him,me}));
      write("Dibujas un magnifico y suave movimiento con tu "
	  	"%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ hiriendo gravemente en el abdomen a "
	  	+him->query_cap_name()+" sus %^RED%^BOLD%^intestinos %^RESET%^ vuelan por toda la zona.\n");
      tell_object(him,me->query_cap_name()+" dibuja un magnifico y suave movimiento "
	  	"con su %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ "
	        "que te hiere gravemente en el abdomen. Tus %^RED%^BOLD%^intestinos %^RESET%^ vuelan por toda la zona.\n");

      break;

      case 1:

      tell_room(ENV(me),me->query_cap_name()+" mueve agil y velozmente su "
		"%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ alcanzando "
		"el pecho de "+him->query_cap_name()+" y desgarrando sus entranyas, "
		"su %^RED%^BOLD%^sangre%^RESET%^ brota sin cesar.\n",({him,me}));
      write("Mueves agil y velozmente tu "
	  	"%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ alcanzando el pecho de "
	  	+him->query_cap_name()+
	  	", su %^RED%^BOLD%^sangre%^RESET%^ brota sin cesar.\n");
      tell_object(him,me->query_cap_name()+" mueve agil y velozmente su "
	  	"%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ "
	        "alcanzandote en el pecho. "
	        "Tu %^RED%^BOLD%^sangre%^RESET%^ brota sin cesar por las heridas.\n");

      break;

      case 2:

      tell_room(ENV(me),me->query_cap_name()+" desliza salvajemente su "
		"%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ "
		"sobre el costado de "+him->query_cap_name()+" danyando sus pulmones. "
		"Su %^RED%^BOLD%^sangre%^RESET%^ te mancha totalmente de arriba a abajo.\n",({him,me}));
      write("Deslizas salvajemente tu "
	  	"%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ sobre el costado de "
	  	+him->query_cap_name()+
	  	" danyando sus pulmones. Su %^RED%^BOLD%^sangre%^RESET%^ te mancha totalmente de arriba a abajo.\n");
      tell_object(him,me->query_cap_name()+" desliza salvajemente su "
	  	"%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ "
	        "sobre tu torso alcanzandote los pulmones. "
	        "Tu propia %^RED%^BOLD%^sangre%^RESET%^ te mancha totalmente de aariba a abajo.\n");

      break; }


   }
   else
   {

      switch(random(3)) {

      case 0:
     
      tell_room(ENV(me),me->query_cap_name()+" describe un armonico movimiento "
                "con su %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ "
                "abriendo %^BOLD%^GREEN%^salvajemente%^RESET%^ en canal a "+him->query_cap_name()+" desgarrandole "
		"completamente el cuerpo.\n",({him,me}));
      write("Describes un armonico movimiento con tu %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ abriendo "
                "%^BOLD%^GREEN%^salvajemente%^RESET%^ en canal a "+him->query_cap_name()+" desgarrandole "
                "completamente el cuerpo.\n");
      tell_object(him,me->query_cap_name()+" describe un armonico movimiento con su %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ "
	        "abriendote %^BOLD%^GREEN%^salvajemente%^RESET%^ en canal y desgarrandote completamente el cuerpo. "
                "El corte comienza a %^RED%^BOLD%^sangrar%^RESET%^ descontroladamente.\n");

      break;

      case 1:
     
      tell_room(ENV(me),me->query_cap_name()+" desliza suavemente su %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ sobre el "
                "cuerpo de "+him->query_cap_name()+" destrozandole un brazo y tajandole %^BOLD%^YELLOW%^brutalmente%^RESET%^ el torso.\n",({him,me}));
      write("Deslizas suavemente tu %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ sobre el cuerpo de "
                +him->query_cap_name()+" destrozandole un brazo y tajandole %^BOLD%^YELLOW%^brutalmente%^RESET%^ el torso.\n");
      tell_object(him,me->query_cap_name()+" desliza suavemente su %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ que brilla "
	        "con un fuego %^BOLD%^BLUE%^azulado%^RESET%^ al destrozarte un brazo y abrirte %^BOLD%^YELLOW%^brutalmente%^RESET%^ el torso. "
                "Notas como te faltan las fuerzas y pierdes el equilibrio.\n");

      break;

      case 2:
     
      tell_room(ENV(me),me->query_cap_name()+" con un %^BOLD%^WHITE%^dulce balanceo%^RESET%^ de su  "
                "%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ alcanza la cabeza de "
                +him->query_cap_name()+" abriendole %^BOLD%^MAGENTA%^gravemente%^RESET%^ el cuello.\n",({him,me}));
      write("Con un %^BOLD%^WHITE%^dulce balanceo%^RESET%^ de tu %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ alcanzas "
                "la cabeza de "+him->query_cap_name()+" abriendole %^BOLD%^MAGENTA%^gravemente%^RESET%^ el cuello.\n");
      tell_object(him,me->query_cap_name()+" realiza un %^BOLD%^WHITE%^dulce balanceo%^RESET%^ con su "
                "%^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ alcanzandote la cabeza y abriendote %^BOLD%^MAGENTA%^gravemente%^RESET%^ el cuello. "
                "Notas como pierdes sangre sin control.\n");

      break; }

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
	write("El %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ brilla de placer "
	"con una luz %^BOLD%^%^BLUE%^azulada%^RESET%^, cuando se cobra su dosis de energia.\n");
	tell_object(defdr, "El %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ de "+atckr->QCN+" brilla de placer con una luz %^BOLD%^BLUE%^azulada%^RESET%^ cuando te cobra su dosis de energia.\n");
	tell_room(ENV(atckr), "El %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ de "+atckr->QCN+" emite una luz %^BOLD%^BLUE%^azulada%^RESET%^ al impactar en "+defdr->QCN+".\n",({atckr,defdr}));
 defdr->adjust_hp(-b, atckr);
 atckr->adjust_hp(b);
}
//::weapon_attack(defdr,atckr,damage_roll);
//::weapon_attack(defdr,atckr,damage_roll);

return ::weapon_attack(defdr,atckr,damage_roll);
}



int query_damage_roll()
{
//	if (this_player()->query_name() == "shimmer")
	return (::query_damage_roll() + random(30)+5);
        return (::query_damage_roll() + random(30)+5);
}



int set_in_use(int i, object miamo)
{
    if(this_player()->query_name()== "shimmer" || "honny" || "haggard" || "tyrael" || "scout" )
    {
        if (i) 
	{
                tell_object(miamo,
                "Al empunyar el Filo Celestial notas como una fuerza divina recorre tu cuerpo, sintiendote extraordinariamente poderoso.\n");
        }
        else
        {
                tell_object(miamo,
                "Notas una calma interior al envainar el arma forjada por Shimmer.\n");
        }
        return ::set_in_use(i);
    }
    else
    {
	tell_room(this_player()->query_cap_name()+" es herido por una descarga "
                "procedente del %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ al no reconocerlo como su legitimo duenyo.\n");
        write("El %^BOLD%^WHITE%^Filo %^CYAN%^Celestial%^RESET%^ te produce una descarga al rechazarte y no reconocerte como su legitimo duenyo.\n");
        this_player()->adjust_hp(-random(100)-20);  
    }
return 0;

} 


