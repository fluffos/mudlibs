/* By Shimmer */

#define CREATOR "shimmer";

#include "../../../path.h"

inherit "obj/weapon";

void setup ()  
{
	set_base_weapon("long sword");
	set_name("%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^");
	set_short("%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^");
	add_alias("filo");
	add_alias("angelical");
	add_plural("filo infernal");
	add_plural("filos");
	set_main_plural("%^BOLD%^RED%^Filos %^YELLOW%^Infernales%^RESET%^");
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
      switch(random(3)){

      case 0:     

      tell_room(ENV(me),me->query_cap_name()+" hunde el "
	        "%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ en el suelo sin tocar a su enemigo. "
		 ,({him,me}));
      write("Hundes el %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^"
	        " en el suelo sin tocar a tu enemigo.\n");
      tell_object(him,me->query_cap_name()+" hunde su %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ " 
	        "en el suelo sin tocar a su enemigo.\n");
      break;

      case 1:

      tell_room(ENV(me),me->query_cap_name()+" ondea su "
	        "%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ fallando al intentar golpear a su enemigo. "
		 ,({him,me}));
      write("Ondeas el %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ "
	        " fallando al intentar golpear a tu enemigo.\n");
      tell_object(him,me->query_cap_name()+" ondea su " 
	        "%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ fallando cuando intentaba golpearte.\n");
      break;

      case 2:

      tell_room(ENV(me),me->query_cap_name()+" agita su "
	        "%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ fallando al intentar golpear a "+him->query_cap_name()+"
		 ",({him,me}));
      write("Agitas el %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^"
	        " al fallar cuando intentabas golpear a "+him->query_cap_name()+".\n");
      tell_object(him,me->query_cap_name()+" agita su " 
	        "%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ fallando cuando intentaba golpearte.\n");
      break; }
      

   }
   else if(dam <11)
   {
      switch(random(3)) {
 
      case 0:
      
      tell_room(ENV(me),me->query_cap_name()+" desliza debilmente su "
		"%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ sobre un brazo de "
		+him->query_cap_name()+" cortandoselo levemente.\n"
		,({him,me}));
      write("Deslizas debilmente tu %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ "
                "sobre uno de los brazos de "+him->query_cap_name()+" cortandoselo levemente.\n");
      tell_object(him,me->query_cap_name()+" desliza debilmente su %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ "
	        "sobre uno de tus brazos cortandotelo debilmente.\n");

      break;

      case 1:
      
      tell_room(ENV(me),me->query_cap_name()+" blandea su "
		"%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ alcanzando una pierna de "
		+him->query_cap_name()+" y producendole leves heridas.\n"
		,({him,me}));
      write("Blandeas tu %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ "
                "alcanzando una pierna de "+him->query_cap_name()+" produciendole leves heridas.\n");
      tell_object(him,me->query_cap_name()+" blandea su %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ "
	        "alcanzando una de tus piernas y produciendo leves heridas.\n");


      break;

      case 2:
      
      tell_room(ENV(me),me->query_cap_name()+" raja ligeramente a "+him->query_cap_name()+" con su "
		"%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^.\n",({him,me}));
      write("Rajas ligeramente a "+him->query_cap_name()+" con tu %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^.\n");
      tell_object(him,me->query_cap_name()+" te raja ligeramente con su %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^.\n");

      break; }

   }	
   else if(dam >10 && dam < 31)
   {

      switch(random(3)) {

      case 0:

      tell_room(ENV(me),me->query_cap_name()+" corta con su "
		"%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ la espalda de "
		+him->query_cap_name()+" causandole gran dolor.\n"
		,({him,me}));
      write("Cortas la espalda de "+him->query_cap_name()+" con tu "
		"%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ "
		"causandole gran dolor.\n");
      tell_object(him,me->query_cap_name()+" te corta en la espalda con su "
	        "%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ "
	        "causandote gran dolor.\n");

      break;

      case 1:

      tell_room(ENV(me),me->query_cap_name()+" desliza su "
		"%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ sobre un muslo de "
		+him->query_cap_name()+" haciendole un profundo corte.\n",({him,me}));
      write("Deslizas tu %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ sobre "
                "un muslo de "+him->query_cap_name()+" haciendole un profundo corte.\n");
      tell_object(him,me->query_cap_name()+" desliza su "
	        "%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ "
	        "sobre uno de tus muslos haciendote un profundo corte.\n");

      break;

      case 2:

      tell_room(ENV(me),me->query_cap_name()+" taja a "
		+him->query_cap_name()+"con su "
                "%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ "
                "cortandole en un hombro. "+him->query_cap_name()+" gime de dolor.\n"
		,({him,me}));
      write("Tajas a "+him->query_cap_name()+" con tu "
		"%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ "
		"cortandole uno de los hombros. "+him->query_cap_name()+" gime de dolor.\n");
      tell_object(him,me->query_cap_name()+" te taja en uno de los hombros con su "
	        "%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^. "
	        "Gimes de dolor.\n");

      break; }

   }	
   else if(dam>30 && dam<50)
   {
  
      switch(random(3)) {

      case 0:

      tell_room(ENV(me),me->query_cap_name()+" de un desgarrador y brusco movimiento "
		"con su %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ "
		"hiere gravemente a "+him->query_cap_name()+" haciendo saltar sus "
		"%^RED%^BOLD%^intestinos %^RESET%^por toda la zona.\n",({him,me}));
      write("De un desgarrador y brusco movimiento con tu "
	  	"%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ hieres gravemente a "
	  	+him->query_cap_name()+
	  	" haciendo saltar sus %^RED%^BOLD%^intestinos%^RESET%^ por toda la zona.\n");
      tell_object(him,me->query_cap_name()+" de un desgarrador y brusco movimiento "
	  	"con su %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ "
	        "te hiere gravemente. "
	        "Tus %^RED%^BOLD%^intestinos %^RESET%^quedan repartidos por la zona.\n");

      break;

      case 1:

      tell_room(ENV(me),me->query_cap_name()+" mueve velozmente su "
		"%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ alcanzando "
		"el pecho de "+him->query_cap_name()+" y desgarrando sus entranyas, "
		"su %^RED%^BOLD%^sangre%^RESET%^ brota sin cesar.\n",({him,me}));
      write("Mueves velozmente tu "
	  	"%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ alcanzando el pecho de "
	  	+him->query_cap_name()+
	  	", su %^RED%^BOLD%^sangre%^RESET%^ brota sin cesar.\n");
      tell_object(him,me->query_cap_name()+" mueve velozmente su "
	  	"%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ "
	        "alcanzandote en el pecho. "
	        "Tu %^RED%^BOLD%^sangre%^RESET%^ brota sin cesar por las heridas.\n");

      break;

      case 2:

      tell_room(ENV(me),me->query_cap_name()+" hunde salvajemente su "
		"%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ "
		"en el estomago de "+him->query_cap_name()+" rajando sus entranyas. "
		"Su %^RED%^BOLD%^sangre%^RESET%^ y sus %^BOLD%^intestinos%^RESET%^ te manchan totalmente.\n",({him,me}));
      write("Hundes salvajemente tu "
	  	"%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ en el estomago de "
	  	+him->query_cap_name()+
	  	" rajando sus entranyas. Su %^RED%^BOLD%^sangre%^RESET%^ y sus %^BOLD%^intestinos%^RESET%^ te manchan totalmente.\n");
      tell_object(him,me->query_cap_name()+" hunde salvajemente su "
	  	"%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ "
	        "incrustandola en tu estomago. "
	        "tu %^RED%^BOLD%^sangre%^RESET%^ y tus %^BOLD%^intestinos%^RESET%^ te manchan totalmente.\n");

      break; }


   }
   else
   {

      switch(random(3)) {

      case 0:
     
      tell_room(ENV(me),me->query_cap_name()+" encaja un perfecto movimiento "
                "con su %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ "
                "que abre %^BOLD%^BLACK%^salvajemente%^RESET%^ en canal a "+him->query_cap_name()+" destrozandole "
		"completamente el cuerpo.\n",({him,me}));
      write("Encajas un perfecto movimiento con tu %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ que abre "
                "%^BOLD%^BLACK%^salvajemente%^RESET%^ en canal a "+him->query_cap_name()+" destrozandole "
                "completamente el cuerpo.\n");
      tell_object(him,me->query_cap_name()+" encaja un perfecto movimiento con su %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ "
	        "abriendote %^BOLD%^BLACK%^salvajemente%^RESET%^ en canal y destrozandote completamente el cuerpo. "
                "El tajo cominza a %^RED%^BOLD%^sangrar%^RESET%^ descontroladamente.\n");

      break;

      case 1:
     
      tell_room(ENV(me),me->query_cap_name()+" eleva su %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ que brilla con "
                "un fuego rojizo al caer %^BOLD%^YELLOW%^brutalmente%^RESET%^ sobre el cuerpo de "+him->query_cap_name()+" arancandole "
		"las entranyas al atravesar su carne.\n",({him,me}));
      write("Elevas tu %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ que brilla con un fuego rojizo al caer %^BOLD%^YELLOW%^brutalmente%^RESET%^ "
                "sobre el cuerpo de "+him->query_cap_name()+" arrancandole las entranyas al atravesar su carne.\n");
      tell_object(him,me->query_cap_name()+" eleva su %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ que brilla "
	        "con un fuego rojizo al caer %^BOLD%^YELLOW%^brutalmente%^RESET%^ sobre tu cuerpo arrancandote las entranyas al atravesar tu dabil carne. "
                "Se te nubla la vista y pierdes parciamente la orientacion y el equilibrio.\n");

      break;

      case 2:
     
      tell_room(ENV(me),me->query_cap_name()+" hace un majestuoso movimiento con su  "
                "%^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ alcanzando poderosamente la cabeza de "
                +him->query_cap_name()+" destrozandole el rostro y dejandolo conmocionado.\n",({him,me}));
      write("Con un majestuoso movimiento de tu %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ alcanzas "
                "podersamente la cabeza de "+him->query_cap_name()+" destrozandole el rostro y dejandolo comocionado.\n");
      tell_object(him,me->query_cap_name()+" hace un majestuoso movimiento con su %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ "
	        "alcanzandote poderosamente la cabeza destrozandote el rostro y dejandote conmocionado. "
                "Pierdes el sentido y notas como la vida se te escapa.\n");

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
	write("El %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ brilla de placer "
	"con una luz %^ORANGE%^anaranjada%^RESET%^, cuando se cobra su dosis de energia.\n");
	tell_object(defdr, "El %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ de "+atckr->QCN+" brilla de placer con una luz %^ORANGE%^anaranjada%^RESET%^ cuando te cobra su dosis de energia.\n");
	tell_room(ENV(atckr), "El %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ de "+atckr->QCN+" emite una luz %^ORANGE%^anaranjada%^RESET%^ al impactar en "+defdr->QCN+".\n",({atckr,defdr}));
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
                "Sientes penetrar en ti una fuerza demoniaca al empunyar el Filo Infernal, te sientes extraordinariamente poderoso.\n");
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
                "procedente del %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ al no reconocerlo como su legitimo duenyo.\n");
        write("El %^BOLD%^RED%^Filo %^YELLOW%^Infernal%^RESET%^ te produce una descarga al rechazarte y no reconocerte como su legitimo duenyo.\n");
        this_player()->adjust_hp(-random(100)-20);  
    }
return 0;

}