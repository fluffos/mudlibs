#include "path.h"

#include "senda.h"

inherit "/std/outside";

void setup()
{
   set_long("Te hallas en el extremo de lo que parece una larga y sinuosa "
   "senda. Al sur se ve un camino y al este un gran bosque que te impide ver "
   "que hay mas alla. La senda va hacia el norte y a primera vista parece "
   "muy larga y se pierde en unas montanyas que hay al norte a lo lejos.\n");
   add_exit("sur", CARRETERA+"c20", "plain");
     add_exit("west", CULTIVOS+"senda15", "plain");
//   add_exit("norte", SENDA+"s2", "plain");
//    add_exit("norte", SENDA+"s2", "plain");
   TRAMO1->comun(TO);
   TRAMO1->npcs(4, TO);
}
