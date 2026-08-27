#include "path.h"

#include "senda.h"

inherit "/std/outside";

void setup()
{
   set_long("Te hallas en una larga y sinuosa "
   "senda. Al sur continua la senda, al sudeste ves un un gran bosque y "
   "al este ves algo que parece un gran Castillo. La senda sigue hacia el "
   "norte, y a primera vista parece larga, aunque se pierde en unas montanyas "
   "que hay al norte. Al sur se divisa una gran ciudad con una carretera en "
   "la que desemboca la senda. Por lo que parece esta senda es de uso comun, "
   "ya que el terreno sobre el cual anda la gente esta totalmente falto de "
   "vegetacion.\n");
   add_exit("sudoeste", SENDA+"s22", "plain");
   add_exit("noreste", SENDA+"s24", "plain");
   TRAMO2->comun(TO);
   TRAMO2->npcs(2, TO);
}
