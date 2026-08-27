// Bichos submarinos by Folken '2000

#include "path.h"

inherit "obj/monster";

void setup()
{


int azar = random(5) + 1; // azar [1..5]
switch (azar)
  {
  case 1:
    set_name("medusa");
    set_short("Medusa"); 
    set_long("Una medusa de colores grisaceos, muy tipica en estas zonas del oceano. "
             "Sus movimientos son pausados, y siguen una danza que te hipnotiza. No "
	     "reconoces su especie, asi que no tienes forma de saber si sera venenosa "
	     "o no.\n");
    set_main_plural("Medusas");
    add_plural("medusas");

    set_level(10);
    set_random_stats(10, 16);
    set_align(0);
    set_gender(random(2) + 1);
    load_chat(40,
      ({
	    1,":se agita bajo el agua.\n",
	    1,":se deja mecer por las corrientes submarinas.\n",
      }));
    load_a_chat(100,
              ({
               1,":se mueve violentamente bajo el agua!!\n",
               1,":da vueltas a tu alrededor rapidamente!\n",
             }));
break;

  case 2:
    set_name("pez globo");
    set_short("Pez globo");
    add_alias("pez");
    set_long("Es un pez con una apariencia extranya, de aspecto esferico. "
             "No tiene la pariencia de ser un pez agresivo, pero no "
    	     "seria conveniente fiarse demasiado de animales salvajes, ya que "
     	     "podrian tomarte como enemigo por encontrarte en sus habituales "
	     "dominios de caza.\n");
    set_main_plural("Peces globo");
    add_plural("peces");

    set_level(10);
    set_random_stats(10, 17);
    set_align(0);
    set_gender(random(2) + 1);
    load_chat(40,
      ({
	    1,":se agita bajo el agua.\n",
	    1,":se deja mecer por las corrientes submarinas.\n",
      }));
    load_a_chat(100,
              ({
               1,":comienza a hincharse y aumentar de tamanyo!\n",
               1,":vuelve a deshincharse y se prepara para un nuevo ataque!\n",
             }));


break;
  case 3:
    set_name("delfin");
    set_short("Delfin");
    set_long("Un delfin que destaca especialmente por su belleza, y su mirada "
    	     "inteligente, que parece abrumarte. Se mueve despacio, como si no tuviera "
	     "prisa por volver a la superficie a por mas oxigeno. \n");
    set_main_plural("Delfines");
    add_plural("delfines");

    set_level(12);
    set_random_stats(10, 17);
    set_int(18);
    set_align(-1000);
    set_gender(random(2) + 1);
    load_chat(40,
      ({
            1,":te observa con curiosidad.\n",
	    1,":grita con un extranyo sonido.\n",
      }));
    load_a_chat(100,
              ({
               1,":se mueve violentamente bajo el agua!\n",
               1,":ensenya sus dientes en gesto amenazador!\n",
             }));
break;

  case 4:
    set_name("anguila");
    set_short("Anguila");
    set_long("Una alargada anguila que parece destacar por su malhumorado caracter. "
    	     "Sus movimientos son rapidos y agiles, y no parece ser recomendable "
	     "seguir observandola por mucho tiempo. \n");
    set_main_plural("Anguilas");
    add_plural("anguilas");

    set_level(10);
    set_random_stats(10, 16);
    set_dex(18);
    set_align(1000);
    set_gender(random(2) + 1);
    load_chat(40,
      ({
	    1,":se agita bajo el agua.\n",
	    1,":se deja mecer por las corrientes submarinas.\n",
      }));
    load_a_chat(100,
              ({
               1,":se mueve violentamente bajo el agua!\n",
               1,":da vueltas a tu alrededor rapidamente!\n",
             }));


break;
  case 5:
    set_name("pintarroja");
    set_short("Pintarroja");
    add_alias("tiburon");
    set_long("Se trata de un pequenyo tipo de tiburon, con aletas muy pronunciadas "
    	     "que le facilitan enormemente la tarea de la caza bajo el agua. Pese a "
	     "su pequenyo tamanyo, parece bastante agresivo, como casi todos "
	     "los tiburones.\n");
    set_main_plural("Pintarrojas");
    add_plural("pintarrojas");
    add_plural("tiburones");

    set_level(10);
    set_random_stats(10, 16);
    set_dex(18);
    set_align(1000);
    set_gender(random(2) + 1);
    load_chat(40,
      ({
	    1,":observa placidamente a su proxima presa.\n",
	    1,":se oculta parcialmente tras unas algas.\n",
      }));
    load_a_chat(100,
              ({
               1,":se mueve violentamente bajo el agua!\n",
               1,":ensenya sus dientes en gesto amenazador!\n",
             }));


break;
  } // fin switch (azar)

  set_move_after(20, 40);

  add_property("no_ahogo",1);
  add_property("resistente_presion",1);

} // fin setup

#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()

int unarmed_attack(object target,object me)
{
  object *att;
  att = (object*)me->query_attacker_list();
  monster::unarmed_attack(att[random(sizeof(att))],me);
}

mapping valid_attack()
{

  switch(TO->query_short())
  {
  case "Medusa":
  return([
      "knee"  :({AN+" golpea a "+DN+".\n",
                 "Golpeas con fiereza a "+DN+".\n",
                 AN+" te golpea con una fuerza increible.\n"}),
      "punch"  :({AN+" se enreda entre los brazos de "+DN+".\n",
                 "Te enredas entre los brazos de "+DN+".\n",
                 AN+" se enreda entre tus brazos, produciendote un picor insoportable.\n"}),
      "kick"  :({AN+" roza a "+DN+".\n",
                 "Rozas a "+DN+".\n",
                 AN+" te roza en un brazo produciendote un terrible escozor.\n"})]);
  break;
  case "Anguila":
  return([
      "knee"  :({AN+" muerde a "+DN+".\n",
                 "Muerdes con fiereza a "+DN+".\n",
                 AN+" te muerde con una fuerza increible.\n"}),
      "punch"  :({AN+" propina un coletazo a "+DN+".\n",
                 "Propinas un coletazo a "+DN+".\n",
                 AN+" te propina una coletazo en un brazo.\n"}),
      "kick"  :({AN+" propina una pequenya descarga electrica a "+DN+".\n",
                 "Propinas una pequeya descarga electrica a "+DN+".\n",
                 AN+" te propina una pequenya descarga electrica.\n"})]);
  break;
  default:
  return([
      "knee"  :({AN+" muerde a "+DN+".\n",
                 "Muerdes con fiereza a "+DN+".\n",
                 AN+" te muerde con una fuerza increible.\n"}),
      "punch"  :({AN+" propina una dentellada a "+DN+".\n",
                 "Propinas una dentellada a "+DN+".\n",
                 AN+" te propina una dentellada y parece no querer soltarte.\n"}),
      "kick"  :({AN+" raja a "+DN+".\n",
                 "Rajas a "+DN+".\n",
		 AN+" te raja un brazo produciendote un terrible dolor.\n"})]);
  break;
  } // fin switch

}
