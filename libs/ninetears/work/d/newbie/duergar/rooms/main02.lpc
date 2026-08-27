/*  Text alterations and additions by Grimbrand 2-3-96                   */

#include "path.h"
inherit "/std/underground";


void setup() {
   
   add_property("no_undead",1); set_light(10);

   set_short("Reinado Duergar:  Hall");
   
   set_long("\n   Reinado Duergar:  Hall.\n\n"
	    "     Esta es una habitacion lisa y sin adornos.Lo unico "
	    "que llama la atencion es una escalera en espiral  que "
	    "baja.\n"
	    "\n");

   add_item(({"escarela", "staircase", "stairway" "spiraling staircase"}),
	    "   Es una escalera  hecha de metal trabajado a mano.  "
	    "Esta llena de filigranas ,es un trabajo exquisito.  "
	    "No cabe duda,esta hecha por los maestros herreros  "
	    "duergars.\n"
	    "\n");

   add_exit("abajo",NEWBIE+"main03","door");
   add_exit("norte",NEWBIE+"grubhall","door");
   add_exit("sur",NEWBIE+"main01","door");
   add_exit("noreste",NEWBIE+"store","door");
   add_exit("este",NEWBIE+"guildrm","door");
}


