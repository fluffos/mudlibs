#include "../../path.h"

#include "senda.h"

inherit "/std/outside";

void setup()
{
   set_long("Te hallas en el poblado de "+POBLADO+" observas que "
   "el pueblo es bastante pequenyo. Contara con una docena de cabanyas. "
   "Las cabanyas son de tamanyo mediano y por la calle se ve mas bien "
   "poca gente. Al sur ves una cabanya de la cual sale humo por la "
   "chimenea. Al este hay una gran senda. Al norte ves las colinas de "
   +COLINAS+", en las cuales unos enanos parecen estar trabajando "
   "afanosamente.\n");
   add_exit("este", SENDA+"p2", "plain");
   add_exit("oeste", SENDA+"p4","plain");
   add_exit("norte", REAL+"real51","plain");
  add_exit("southwest", REAL+"real50","plain");
   add_exit("dentro", SENDA+"taberna", "door");
   add_item("enano","Un enano que trabaja duramente escavando en las colinas");
   PUEBLO->comun(TO);
   PUEBLO->npcs(1, TO);
}
