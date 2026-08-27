#include "path.h"

inherit CARRETERA+"base";

void setup()
{
   base_desc();
   add_exit("west",CARRETERA+"c23","road");
   add_exit("north",LADRONES+"entrada","door");
//   add_exit("northeast", "/d/clanes/marmion/rooms/sala","hidden");
   crea_bichos();
   new(NPC+"bandido")->move(this_object());
   new(NPC+"bandido")->move(this_object());
   new(NPC+"bandido")->move(this_object());
   new(NPC+"bandido")->move(this_object());
}

void dest_me()
{
   destruye_bichos();
   ::dest_me();
}
