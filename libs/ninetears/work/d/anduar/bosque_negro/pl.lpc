#include "../path.h"

inherit "/std/outside";

int n, init=0;
void saca_salidas()
{
   int tipo, i;

   n=random(8);
   for (i=0; i<n; i++)
   {
      tipo=random(8);
      switch (tipo)
      {
         case 0: remove_exit("norte");
                 renew_exits();
                 break;
         case 1: remove_exit("sur");
                 renew_exits();
                 break;
         case 2: remove_exit("este");
                 renew_exits();
                 break;
         case 3: remove_exit("oeste");
                 renew_exits();
                 break;
         case 4: remove_exit("noreste");
                 renew_exits();
                 break;
         case 5: remove_exit("noroeste");
                 renew_exits();
                 break;
         case 6: remove_exit("sudeste");
                 renew_exits();
                 break;
         case 7: remove_exit("sudoeste");
                 renew_exits();
                 break;
      }
   }
}
