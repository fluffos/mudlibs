#include "path.h"

#include "senda.h"

inherit "/std/outside";

void setup()
{
   set_long("Te hallas en una larga y sinuosa "
   "senda. Al sur continua la senda, al sudeste ves un un gran bosque y "
   "al este ves algo que parece un gran Castillo. Cerca de aqui al norte ves "
   "unas montanyas por las que la senda cruza. Si vas a cruzarlas tendras que "
   "subir parte de la montanya inevitablemente. Tambien ves un pequenyo "
   "poblado al pie de las colinas. Al sur en el horizonte se "
   "divisa una gran ciudad con carreteras a su alrededor. Parece que este "
   "camino lleva hacia aquella ciudad. Por lo que parece esta senda es de uso "
   "comun, ya que el terreno sobre el cual anda la gente esta totalmente "
   "falto de vegetacion.\n");
   add_exit("sudoeste", SENDA+"s36", "plain");
   add_exit("noreste", SENDA+"s38", "plain");
   TRAMO3->comun(TO);
   TRAMO3->npcs(1, TO);
}
