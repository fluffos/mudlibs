/*  Text additions and alterations by Grimbrand 2-3-96                 */

#include "path.h"
inherit "/std/newbieguild";

object board;

void setup()
  {
   add_property("no_undead",1); set_light(20);

   set_short("Reinado Duergar:  Guild  de Aventureros");

   set_long("\n   Reinado Duergar:  Guild de Adventureros .\n\n"
	    "     Este es  un cuarto suavemente iluminado donde los nuevos "
	    "adventureros duergars se unen al gremio .  Es un cuarto  "
	    "sin detalles, lo unico que resalta es una %^BOLD%^YELLOW%^senyal%^RESET%^ que cuelga "
	    "de la pared.\n"
	    "\n");
   
   add_item("senyal","\nLa senyal dice:\n"
       "+-----------------------------------------------------+\n"
       "|                                                     |\n"
"|          -%^BOLD%^RED%^Guild de Duergas Aventureros%^RESET%^-             |\n"
       "|                                                     |\n"
       "|      'coste' Para saber lo que cuesta avanzar.      |\n"
       "|      'avanzar' Para avanzar de nivel.               |\n"
       "|      'info' Para informacion sobre el gremio.       |\n"
       "|                                                     |\n"
       "|      No puedes avanzar por encima de nivel 5 aqui   |\n"
       "|      Para unirte al gremio pon  'avanzar'.          |\n"
       "|                                                     |\n"
       "+-----------------------------------------------------+\n"
       "\n");
   
   add_exit("oeste",NEWBIE+"main02","door");
  }

