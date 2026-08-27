#include "path.h"

#include "senda.h"

inherit "/std/outside";

void setup()
{
   set_long("Te hallas en el poblado de "+POBLADO+" observas que "
   "el pueblo es bastante pequenyo. Contara con una docena de cabanyas. "
   "Las cabanyas son de tamanyo mediano y por la calle se ve mas bien "
   "poca gente. Al este ves una cabanya de la cual sale humo por la "
   "chimenea y una gran senda. Al norte ves las colinas de "
   +COLINAS+".\n");
   add_exit("norte", BOSQUEELORAS+"b1", "plain");
   add_exit("este", SENDA+"p3", "plain");
   add_exit("puerta", "/d/clanes/the_falcons/rooms/main","door");
   modify_exit("puerta",({"function","do_west"}));
   PUEBLO->comun(TO);
   PUEBLO->npcs(1, TO);
}

int do_west()
{
 if(TP->query_group_name() !="The Falcons")
  {
   notify_fail("Poderosas fuerzas impiden tu acceso a este lugar, por "
   "lo que te retiras del mismo.\n");
   return 0;
  }
  else
  {
   write("Pasas dentro de las estancias del poderoso Clan The Falcons.\n");
   tell_room(TP->query_cap_name()+" entra dentro de las "
   "poderosas estancias del Clan The Falcons.\n");
   return 1;
  }
}
