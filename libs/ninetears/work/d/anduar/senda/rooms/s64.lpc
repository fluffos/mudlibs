#include "path.h"

#include "senda.h"

inherit "/std/outside";

void setup()
{
   set_long("Te hallas en una senda en las llanuras de "+LLANURAS+"."
   " Al norte la senda sigue y al horizonte "
   "se ve una gran fortaleza. Parece que este camino lleva hacia alli. Al "
   "sur cerca de aqui estan las colinas de "+COLINAS+"."
   "Por lo que parece esta senda es de uso comun, ya que el terreno sobre "
   "el cual anda la gente esta totalmente falto de vegetacion.\n");
add_exit("sudeste", "/d/anduar/camino_real2/real_b_2", "plain");
   add_exit("noroeste", SENDA+"s65", "plain");
   TRAMO3->comun(TO);
   TRAMO3->npcs(2, TO);
}
