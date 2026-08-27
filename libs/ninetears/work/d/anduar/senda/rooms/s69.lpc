#include "path.h"

#include "senda.h"

inherit "/std/outside";

void setup()
{
   set_long("Te hallas en una senda en las llanuras de "+LLANURAS+"."
   " Al norte la senda sigue y al horizonte "
   "se ve una gran fortaleza. Parece que este camino lleva hacia alli. Al "
   "sur cerca de aqui estan las colinas de "+COLINAS+". "
   "Por lo que parece esta senda es de uso comun, ya que el terreno sobre "
   "el cual anda la gente esta totalmente falto de vegetacion.\n"
   "En lo alto de las colinas observas una construccion de piedra negra, de "
   "una edad incalculable.\n");

   add_exit("sudoeste", SENDA+"s68", "plain"); 
   add_exit("noreste", "/d/dendara/rooms/camino/s90", "plain");
    add_exit("oeste", "/d/anduar/torre_negra/osti_3","hidden");
   TRAMO3->comun(TO);
   TRAMO3->npcs(2, TO);
}
