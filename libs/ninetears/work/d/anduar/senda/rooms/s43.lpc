#include "path.h"

#include "senda.h"

inherit "/std/outside";

void setup()
{
   set_long("Te hallas en el este del poblado de "+POBLADO+" observas que "
   "el pueblo es bastante pequenyo. Contara con una docena de cabanyas. "
   "Las cabanyas son de tamanyo mediano y por la calle se ve mas bien "
   "poca gente. Al sur continua la senda, al sudeste ves un un gran bosque y "
   "un gran Castillo. Al norte enseguida empieza la ascension a las colinas "
   "de "+COLINAS+". Si vas a cruzarlas tendras que subir parte de la montanya "
   "inevitablemente. Al sur en el horizonte se divisa una gran ciudad con "
   "carreteras a su alrededor. Parece que este camino lleva hacia aquella "
   "ciudad. Por lo que parece esta senda es de uso comun, ya que el terreno "
   "sobre el cual anda la gente esta totalmente falto de vegetacion.\n");
   add_exit("sudeste", SENDA+"s42", "plain");
   add_exit("noroeste", SENDA+"s44", "plain");
   PUEBLO->comun(TO);
   PUEBLO->npcs(1, TO);
}
