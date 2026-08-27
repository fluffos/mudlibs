#include "../../path.h"
inherit "/std/underground";

int n, init=0;

void base_desc()
{
   add_item("suelo", "El suelo esta totalmente embarrado.\n");                    
   set_light(65);
   set_zone("cantera");
}

void crea_bichos()
{
   int tipo, i;

   n=random(5);
   for (i=0; i<n; i++)
   {
      tipo=random(9);
      switch (tipo)
      {
         case 0: add_clone(CANTERABICHO+"bandido", 1);
                 break;
         case 1: add_clone(CANTERABICHO+"ladron", 1);
                 break;
         case 2: add_clone(CANTERABICHO+"bandido", 1);
                 break;
         case 3: add_clone(CANTERABICHO+"ladron", 1);
                 break;
         case 4: add_clone(CANTERABICHO+"ladron", 1);
                 break;
         case 5: add_clone(CANTERABICHO+"bandido", 1);
                 break;
         case 6: add_clone(CANTERABICHO+"ladron", 1);
                 break;
         case 7: add_clone(CANTERABICHO+"bandido", 1);
                 break;
         case 8: add_clone(CANTERABICHO+"ladron", 1);
                 break;
      }
   }
}

void destruye_bichos()
{
}

