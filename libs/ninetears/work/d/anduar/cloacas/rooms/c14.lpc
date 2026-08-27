// Cloaca. C14
// Errante'97

#include "path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Pasillo terciario%^RESET%^");
   set_long("Te cuesta ya apartar los hierbajos que cuelgan del techo, ademas, "
            "cuando los apartas se te enredan por los brazos. Parece que tengas las "
            "piernas dormidas por culpa del frio. \n");

   add_item("suelo", "Solo ves agua. \n");
   add_item("pared", "La pared es resbaladiza, y esta llena de insectos.\n");

    add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");

   add_clone(CLOACABICHO+"murcielago",3);

   add_exit("este", CLOACAS+"c15", "corridor");
   add_exit("oeste", CLOACAS+"c13", "corridor");

   set_light(0);
}
