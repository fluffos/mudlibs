#include "path.h"

inherit CATACUMBAS+"secreto";

void setup()
{
   set_short("%^BLUE%^Pasillo secreto%^RESET%^");
   CATADESC->desc(6, this_object());
   add_exit("oeste", CATACUMBAS+"p4", "corridor");
   add_item("muro", "Esta hecho del mismo material que las paredes y el "
   "techo. A decir verdad es una prolongacion de ellos.\n");
}

string query_long()
{
   return ::query_long()+"Parece que aqui termina el tunel, debido al "
   "gran muro que tienes delante de ti.\n\n";
}
