// Cloaca. C19
// Errante'97

#include "path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Pasillo principal%^RESET%^");
   set_long("Te cuesta apartar los hierbajos que cuelgan del techo, ademas, "
            "al apartarlos se te enredan por los brazos. Los insectos han aumentado "
            "su tamanyo. \n");

   add_item("suelo", "Solo ves agua. \n");
   add_item("pared", "Estan frias. \n");
    add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");

   add_exit("este", CLOACAS+"c10", "corridor");
   add_exit("oeste", CLOACAS+"c20", "corridor");

   set_light(0);
}
