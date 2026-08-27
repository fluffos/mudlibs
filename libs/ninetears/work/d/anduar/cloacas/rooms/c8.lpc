// Cloaca. C8
// Errante'97

#include "path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Pasillo principal%^RESET%^");
   set_long("El frio y el agua te esta empezando a entumecer las piernas. "
            "Las hierbas que cubren el techo parece que tengan vida propia. Notas "
            "como los insectos se ceban contigo. \n");

   add_item("suelo", "Ves un bulto surgir del agua. \n");
   add_item("bulto", "Es una simple roca erosionada por el agua. \n");
    add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");

   add_exit("este", CLOACAS+"c4", "corridor");
   add_exit("oeste", CLOACAS+"c9", "corridor");

   set_light(0);
}
