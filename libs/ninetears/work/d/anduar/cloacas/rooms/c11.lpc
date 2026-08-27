// Cloaca. C11.
// Errante'97

#include "path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Pasillo auxiliar%^RESET%^");
   set_long("Te cuesta mucho mantener el equilibrio debido a que el suelo "
            "es peligrosamente resbaladizo, ademas, empiezas a notar como si te "
            "hundieses en el suelo. \n");

   add_item("suelo", "Debido al agua el suelo es fangoso. \n");
   add_item("pared", "Las paredes estan llenas de grietas, parece que no vayan "
                     "a resistir el peso del techo. \n");
   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");

   add_clone(CLOACABICHO+"murcielago",1);

   add_exit("norte", CLOACAS+"c10", "corridor");
   add_exit("sur", CLOACAS+"c12", "corridor");

   set_light(0);
}
