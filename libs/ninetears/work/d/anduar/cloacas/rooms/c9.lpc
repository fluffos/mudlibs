// Cloaca. C9
// Errante'97

#include "path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Pasillo principal%^RESET%^");
   set_long("Te cuesta ya apartar los hierbajos que cuelgan del techo, ademas, "
            "cuandos los apartas se te enredan por los brazos. Parece que tengas las "
            "piernas dormidas por culpa del frio. Se puede ver un poco mejor debido "
            "a una grieta del techo. \n");

   add_item("suelo", "Solo ves agua. \n");
   add_item("grieta", "Es un simple agujerito. \n");
   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");
   add_exit("este", CLOACAS+"c8", "corridor");
   add_exit("oeste", CLOACAS+"c10", "corridor");

   set_light(0);
}
