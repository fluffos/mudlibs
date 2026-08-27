#include "path.h"

#include "senda.h"

inherit "/std/outside";

void setup()
{
   set_long("Te hallas en una larga y sinuosa "
   "senda. Al sur se divisa un camino y al este un gran bosque que te impide "
   "ver que hay mas alla. La senda sigue hacia el norte y el sur, y a primera "
   "vista parece muy larga y se pierde en unas montanyas que hay al norte a "
   "lo lejos, mientras que por el sur parece terminar pronto en lo que "
   "parece una carretera. Por lo que parece esta senda es de uso comun, ya "
   "que el terreno sobre el cual anda la gente esta totalmente falto de "
   "vegetacion.\n");
   add_exit("sur", SENDA+"s12", "plain");
   add_exit("oeste", SENDA+"s14", "plain");
   TRAMO1->comun(TO);
   TRAMO1->npcs(2, TO);
}
