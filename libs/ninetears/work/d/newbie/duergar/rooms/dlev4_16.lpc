#include "path.h"
inherit "/std/underground";

object *npcs;

void reset() {
   int i;
   for(i=0;i<sizeof(npcs);i++) 
     {
      if(!npcs[i]) 
	{
	 npcs[i]=clone_object(DNPC+"dhulk");
	 npcs[i]->move(this_object());
	}
     }
}

void setup() {
   add_property("no_undead",1); set_light(10);
   npcs = allocate(1);

  set_short("Reinado Duergar:  Simulacion de Submundos");

   set_long("\n   Reinado Duergar:  Simulacion de Submundos.\n\n"
	    "     Oscura y mohosa, esta cueva te recuerda tus dias de "
	    "ninyo.  Dias de vagabundeo incesante a traves de tuneles "
	    "y cuevas, buscando algo de comida, bebida, y un sitio mas o "
	    "menos seguro donde dormir. Ahora, al menos, dispones de un arma,"
	    " y esta claro que la necesitaras, ya que por aqui, en algun sitio, "
	    "notas que hay cosas esperando para matarte. Tienes la sensacion "
	    "de estar atrapado en un laberinto repleto de bestias hostiles "
	    "y agresivas. Las paredes son rugosas y de forma irregular, "
	    "un musgo fosforescente que crece sobre la pared de roca es "
	    "la unica fuente de luz. Tus temores se refuerzan al mirar "
	    "al suelo y ver charcos de sangre recien derramada, que se "
	    "coagula lentamente en este fresco entorno.\n"
	    "\n");

   add_item("suelo",
	    "    Manchas oscuras y viejas le dan un aspecto sucio a la "
	    "piedra que forma el suelo. Pero son manchas muy viejas para "
	    "poder determinar su origen.\n\n");

   add_item("sangre",
	    "   Recien derramada se diria, alguien ha pasado por aqui "
	    "no hace mucho, por suerte cuando te los encuentres seran "
	    "mas faciles de vencer, supones.\n\n");

   add_item(({"muro", "muros", "roca", "rocas", "pared", "paredes"}),
	      "   De corte rugoso, los muros han sido talladas con "
	      "intencion de hacerlas simplemente medio habitables.\n\n");

   add_exit("norte",NEWBIE+"dlev4_11","path");
   add_exit("sur",NEWBIE+"dlev4_21","path");
   add_exit("este",NEWBIE+"dlev4_17","path");
   add_exit("oeste",NEWBIE+"dlev4_15","path");
}

void dest_me() {
   int i;
   for(i=0;i<sizeof(npcs);i++)
   if(npcs[i]) npcs[i]->dest_me();

   ::dest_me();
}
 

