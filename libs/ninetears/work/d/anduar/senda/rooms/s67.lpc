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
   add_exit("sudeste", SENDA+"s66", "plain");
   add_exit("norte", SENDA+"s68", "plain");
   TRAMO3->comun(TO);
   TRAMO3->npcs(2, TO);
}
