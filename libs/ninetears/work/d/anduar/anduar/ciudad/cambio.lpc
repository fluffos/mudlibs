// Cambio de moneda. Gestur'97
/* Broken down by Oskuro: Se come las monedas (Dimsdale el tragaperras). */

#include "../path.h"

inherit "/std/money_changer";

object segurata, chupatintas;

void setup()
{
   set_short("%^BOLD%^%^BLUE%^Oficina de cambio de moneda%^RESET%^");
   set_long ("Estas en la oficina de cambio de moneda de Anduar. "
             "Ves unas arcas grandes con un cartel cada una que indica "
             "el tipo de moneda que contienen. \nDe momento estamos fuera de Servicio.\n");
   
   add_item(({"arca", "arcas"}), "Las arcas contienen monedas de todo tipo. "
   "Tienen un cartel que indica el tipo de moneda.\n");
   add_exit("oeste", ANDUAR+"encambio", "door");
   set_light(60);
}

void reset()
{
   ::reset();
   if (!chupatintas)
chupatintas=clone_object(ANDUAR+"npcs/cambiador");
chupatintas->move(this_object());
   if(!segurata)
   {
 segurata=clone_object(ANDUAR+"npcs/segurata");
       segurata->move(this_object());
   }
}

void dest_me()
{
   if (segurata) segurata->dest_me();
   if (chupatintas) chupatintas->dest_me();
   ::dest_me();
}
