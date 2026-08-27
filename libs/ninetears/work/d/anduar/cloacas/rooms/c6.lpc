// Cloaca. C6.
// Errante'97

#include "path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Pasillo secundario%^RESET%^");
   set_long("La luz ha bajado considerablemente respecto a la del principio "
 	    "parece ser que te estas acercando al fondo de la cloaca.\n");

   add_item("suelo", "No ves el fondo. \n");
   add_item("pared", "Las paredes estan llenas de grietas, parece que no vayan "
                     "a resistir el peso del techo. \n");
   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");

   add_clone(CLOACABICHO+"mobat",1);

   add_exit("norte", CLOACAS+"c5", "corridor");
   add_exit("sur", CLOACAS+"c7", "corridor");

   set_light(0);
}
