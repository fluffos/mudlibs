// Ampliacion de las cloacas. C31.
// Errante'97, Aokromes'99

#include "../../path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Ciudad de anduar: Cloaca obstruida%^RESET%^");
   set_long("Bajo tus pies ya no hay insectos y no hay agua, a pesar de esto "
   "aun no estas tranquilo. Se ve bastante bien, ves como al fondo el pasillo "
   "se va haciendo mas y mas angosto. \n");

   add_item("suelo", "Ves el suelo totalmente seco.\n");
   add_item("pared", "En la pared ves mucho moho.\n");
   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. "
   "\n");

   add_clone(CLOACABICHO+"rata",2);
   add_exit("noreste", CLOACAS+"c32", "corridor");
   add_exit("southwest", CLOACAS+"c30", "corridor");
   set_light(30);
}
