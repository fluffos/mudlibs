#include "../../path.h"

inherit "/std/underground";

int n, init=0;

void crea_bichos()
{
   int tipo, i;

   n=random(4);
   for (i=0; i<n; i++)
   {
      tipo=random(5);
      switch (tipo)
      {
         case 0: add_clone(CLOACABICHO+"murcielago",1);
                 break;
         case 1: add_clone(CLOACABICHO+"ho_rata",1);
                 break;
         case 2: add_clone(CLOACABICHO+"desuellamentes",1);
                 break;
         case 3: add_clone(CLOACABICHO+"rata",1);
                 break;
         case 4: add_clone(CLOACABICHO+"mobat",1);
                 break;
      }
   }
}

void destruye_bichos()
{
}
