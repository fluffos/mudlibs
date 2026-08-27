#include "path.h"

#include "senda.h"

inherit "/std/outside";

void setup()
{
   set_long("Te hallas en una senda que hay en las colinas de "+COLINAS+"."
   " La montanya no es excesivamente alta, pero su pendiente "
   "es bastante pronunciada. Abajo al norte continua la senda y al horizonte "
   "se ve una gran fortaleza. Parece que este camino lleva hacia alli. "
   "Por lo que parece esta senda es de uso comun, ya que el terreno sobre "
   "el cual anda la gente esta totalmente falto de vegetacion.\n");
   add_exit("oeste", SENDA+"s53", "plain");
   add_exit("noreste", SENDA+"s55", "plain");
   TRAMO4->comun(TO);
   TRAMO4->npcs(2, TO);
}
