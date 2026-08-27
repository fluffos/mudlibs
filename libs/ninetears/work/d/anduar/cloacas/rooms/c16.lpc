// Cloaca. C16.
// Errante'97

#include "path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Pasillo auxiliar%^RESET%^");
   set_long("El agua que corre por debajo de tus pies a disminuido su caudal,"
	    "esto hace que el numero de insectos en el suelo haya aumentado. "
	    "Notas una corriente de aire bastante fria ha disminuido, y el agua "
            "empieza a oler mal. \n");

   add_item("suelo", "El agua es de un color verde azulado. \n");
   add_item("pared", "La pared es resbaladiza, y tiene insectos.\n");
   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");

   add_exit("norte", CLOACAS+"c17", "corridor");
   add_exit("sur", CLOACAS+"c10", "corridor");

   set_light(0);
}
