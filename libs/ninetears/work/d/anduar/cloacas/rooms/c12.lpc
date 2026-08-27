// Cloaca. C12.
// Errante'97

#include "path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Pasillo auxiliar%^RESET%^");
   set_long("La luz ha bajado considerablemente respecto a la del principio "
 	    "parece ser que te estas acercando al fondo de la cloaca.\n");

   add_item("suelo", "No ves el fondo. \n");
   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");
 
   add_exit("norte", CLOACAS+"c11", "corridor");
   add_exit("sur", CLOACAS+"c13", "corridor");

   set_light(0);
}
