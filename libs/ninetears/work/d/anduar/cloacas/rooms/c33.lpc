// Ampliacion de las cloacas. C33.
// Errante'97, Aokromes'99

#include "../../path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Ciudad de anduar: Cloaca obstruida%^RESET%^");
   set_long("Bajo tus pies ya no hay insectos y no hay agua, el pasillo se "
   "hace tan bajo que te obliga a ir arrastrandote por el suelo. \n");

   add_item("suelo", "Ves el suelo totalmente seco.\n");
   add_item("pared", "En la pared ves mucho moho.\n");
   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. "
   "\n");

   add_clone(CLOACABICHO+"rata",2);
    add_exit("norte", CLOACAS+"c34", "corridor");
   add_exit("southwest", CLOACAS+"c32", "corridor");
   set_light(30);
}
