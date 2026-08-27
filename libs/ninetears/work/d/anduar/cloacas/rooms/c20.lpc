// Cloaca. C20
// Errante'97

#include "path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Pasillo principal%^RESET%^");
   set_long("Las paredes tienes dibujados estranyos simbolos que parecen "
            "estar grabados a golpes, notas que el agua va disminuyendo, "
            "pero sigue estando helada. Un terrible frio te obliga a estar " 
            "un rato imovilizado. \n");

   add_item("suelo", "Solo ves agua. \n");
   add_item("pared", "La pared continua resbaladiza. \n");

    add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");

   add_clone(CLOACABICHO+"mobat",2);

   add_exit("este", CLOACAS+"c19", "corridor");
   add_exit("oeste", CLOACAS+"c21", "corridor");

   set_light(0);
}
