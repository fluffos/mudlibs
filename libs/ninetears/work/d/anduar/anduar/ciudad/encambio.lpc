// Cambio de moneda. Gestur'97
/* Broken down by Oskuro: Se come las monedas (Dimsdale el tragaperras). */

#include "../path.h"

inherit "/std/money_changer";

object segurata;

void setup()
{
   set_short("%^BOLD%^%^BLUE%^Oficina de cambio de moneda%^RESET%^");
   set_long ("Estas en la entrada de la oficina de cambio de moneda de "
   "Anduar. En varias cristaleras observas en varias jarras, ojos en formol "
   "mirandote en todo momento.\n");
   
   add_exit("este",  ANDUAR+"cambio", "door");
   add_exit("fuera", ANDUAR+"ae1019", "door");
   set_light(60);
}

void reset()
{
   ::reset();
   if(!segurata)
   {
 segurata=clone_object(ANDUAR+"npcs/segurata");
 segurata->move(this_object());
   }
}

void dest_me()
{
   if (segurata) segurata->dest_me();
   ::dest_me();
}
