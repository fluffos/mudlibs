#include "path.h"

#include "senda.h"

inherit "/std/outside";

void setup()
{
   set_long("Te hallas en una larga y sinuosa "
   "senda. Al sur continua la senda, al sudeste ves un un gran bosque y "
   "al este ves algo que parece un gran Castillo. La senda sigue hacia el "
   "norte, y se pierde en unas montanyas. Al sur a lo lejos se divisa una "
   "gran ciudad con carreteras a su alrededor. Parece que este camino lleva "
   "hacia aquella ciudad. Por lo que parece esta senda es de uso comun, "
   "ya que el terreno sobre el cual anda la gente esta totalmente falto de "
   "vegetacion.\n");
   add_exit("sur", SENDA+"s26", "plain");
   add_exit("norte", SENDA+"s28", "plain");
   TRAMO2->comun(TO);
   TRAMO2->npcs(2, TO);
}
