#include "../path.h"
inherit "/std/outside";

int n, init=0;

void crea_bichos()
{
   int tipo, i;

   n=random(3);
   for (i=0; i<n; i++)
   {
      tipo=random(8);
      switch (tipo)
      {
         case 0: add_clone(REAL+"npcs/bandido", 1);
                 break;
         case 1: add_clone(REAL+"npcs/mercader", 1);
                 break;
         case 2: add_clone(BASEMONSTER+"mercenary", 1);
                 break;
         case 3: add_clone(REAL+"npcs/viajero", 1);
                 break;
         case 4: add_clone(REAL+"npcs/guardian", 1);
                 break;
         case 5: add_clone(REAL+"npcs/mercader", 1);
                 break;
         case 6: add_clone(REAL+"npcs/mercader", 1);
                 break;
         case 7: add_clone("/d/dendara/npc/npc_camino", 1);
      }
   }
}

void destruye_bichos()
{
}

