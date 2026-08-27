#include "path.h"

#include "senda.h"

inherit "/std/outside";

void setup()
{
   set_long("Te hallas en la parte mas alta del camino que hay en las colinas."
   " La montanya no es excesivamente alta, pero su pendiente "
   "es bastante pronunciada. Abajo al sur continua la senda. Al sur se ve "
   "un pequenyo poblado, y en el horizonte se divisa una gran ciudad "
   " con carreteras a su alrededor. Parece que este camino lleva hacia aquella"
   " ciudad. Al norte se ve una gran ciudad. Por lo que parece esta senda es "
   "de uso comun, ya que el terreno sobre el cual anda la gente esta "
   "totalmente falto de vegetacion.\n");
   add_exit("sur", SENDA+"s50", "plain");
   add_exit("este", SENDA+"s52", "plain");
   TRAMO4->comun(TO);
   TRAMO4->npcs(2, TO);
}
