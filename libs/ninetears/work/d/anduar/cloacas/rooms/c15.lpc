// Cloaca. C15
// Errante'97

#include "path.h"

inherit "/std/underground";

void setup()
{
   set_short("%^BLUE%^Pasillo terciario%^RESET%^");
   set_long("Este pasillo es bastante negro, casi no distingues las paredes.\n");

   add_item("suelo", "Solo ves agua negra. \n");
   add_item("pared", "La pared es resbaladiza. \n");
   add_smell("cloaca","Sientes un hedor, que te marea, propio de las cloacas. \n");

   add_exit("este", CLOACAS+"c7", "corridor");
   add_exit("oeste", CLOACAS+"c14", "corridor");
   add_exit("abajo", NIVEL2+"ent","stairs");

   set_light(40);
}
