#include "../path.h"
inherit "/std/outside";

int n, init=0;

void crea_bichos()
{
   int tipo, i;

   n=random(3);
   for (i=0; i<n; i++)
   {
     tipo=random(151);
      switch (tipo)
      {
         case 0..14: add_clone(REAL+"npcs/bandido", 1);
                 break;
         case 15..24: add_clone(REAL+"npcs/mercader", 1);
                 break;
         case 25..39: add_clone(BASEMONSTER+"mercenary", 1);
                 break;
         case 40..59: add_clone(REAL+"npcs/viajero", 1);
                 break;
         case 60..74: add_clone(REAL+"npcs/guardian", 1);
                 break;
         case 75..89: add_clone(REAL+"npcs/mercader", 1);
                 break;
         case 90..104: add_clone(REAL+"npcs/mercader", 1);
                 break;
         case 105..139: add_clone(NPC+"ladron", 1);
                 break;
       case 140..150: add_clone(NPC+"antipaladin", 4);
break;
      }
   }
}

void destruye_bichos()
{
}
