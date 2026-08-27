#include "path.h"

#include "senda.h"

inherit "/std/outside";

void setup()
{
   set_long("Te hallas en el poblado de "+POBLADO+" observas que "
   "el pueblo es bastante pequenyo. Contara con una docena de cabanyas. "
   "Las cabanyas son de tamanyo mediano y por la calle se ve mas bien "
   "poca gente. Por el oeste ves una cabanya de la cual sale humo por la "
   "chimenea. Al este hay una gran senda. Al norte ves las colinas de "
   +COLINAS+".\n");
   add_exit("este", SENDA+"s42", "plain");
   add_exit("oeste", SENDA+"p2","plain");
   PUEBLO->comun(TO);
   PUEBLO->npcs(1, TO);
}
