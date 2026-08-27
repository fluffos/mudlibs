inherit "/std/outside";
#include "../../path.h"

int n, init=0;

void crea_bichos()
{
   int tipo, i;

   n=random(5);
   for (i=0; i<n; i++)
   {
      tipo=random(2);
      switch (tipo)
      {
         case 0: add_clone(CANTERABICHO+"bandido", 1);
                 break;
         case 1: add_clone(CANTERABICHO+"ladron", 1);
                 break;
      }
   }
}

void destruye_bichos()
{
}
