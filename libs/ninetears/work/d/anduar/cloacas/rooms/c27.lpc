// Ampliacion de las cloacas. C27.
// Errante'97, Aokromes'99

#include "../../path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Ciudad de anduar: Cloaca obstruida%^RESET%^");
   set_long("Bajo tus pies ya no hay insectos y casi no hay agua, a pesar de "
            "esto aun no estas tranquilo. Se ve bastante bien, te preguntas "
            "si habra una salida. \n");

   add_item("suelo", "Ves el suelo casi seco.\n");
   add_item("pared", "En la pared ves manchas de sangre.\n");
   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. "
   "\n");


   add_clone(CLOACABICHO+"murcielago",2);

   add_exit("norte", CLOACAS+"c28", "corridor");
   add_exit("sur", CLOACAS+"c18", "corridor");

   set_light(30);
}
