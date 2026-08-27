// Cloaca. C3.
// Errante'97

#include "path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Pasillo secundario%^RESET%^");
   set_long("El agua que corre por debajo de tus pies a aumentado su caudal,"
	    "esto hace que el numero de insectos en el suelo haya disminuido y "
	    "el de la pared aumentado. Notas una corriente de aire bastante fria.\n");

   add_item("suelo", "El agua es de un color verde azulado. \n");
   add_item("pared", "La pared es resbaladiza, y esta llena de insectos.\n");
   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");


   add_exit("norte", CLOACAS+"c2", "corridor");
   add_exit("sur", CLOACAS+"c4", "corridor");

   set_light(10);
}
