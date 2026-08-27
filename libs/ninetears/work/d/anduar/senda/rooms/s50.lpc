#include "path.h"

#include "senda.h"

inherit "/std/outside";

void setup()
{
   set_long("Te hallas al pie de las colinas de "+COLINAS+" observas que "
   "la montanya que estas subiendo no es excesivamente alta, pero su pendiente "
   "es bastante pronunciada. Abajo continua la senda, al sudeste ves un gran "
   "bosque y un gran Castillo. Al sur se ve un pequenyo poblado, y en el horizonte se divisa una gran ciudad "
   " con carreteras a su alrededor. Parece que este camino lleva hacia aquella"
   " ciudad. Por lo que parece esta senda es de uso comun, ya que el terreno "
   "sobre el cual anda la gente esta totalmente falto de vegetacion.\n");
   add_exit("abajo", SENDA+"s49", "plain");
   add_exit("norte", SENDA+"s51", "plain");
   TRAMO4->comun(TO);
   TRAMO4->npcs(2, TO);
}
