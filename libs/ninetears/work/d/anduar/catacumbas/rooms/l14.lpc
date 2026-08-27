#include "path.h"

inherit CATACUMBAS+"sala";

void setup()
{
   CATADESC->desc(1, TO);
   set_short("%^BLUE%^Entrada a las Catacumbas%^RESET%^");
   add_exit("este", CATACUMBAS+"l15", "corridor");
   add_exit("noreste", CATACUMBAS+"l10", "plain");
   add_exit("norte", CATACUMBAS+"l9", "plain");
   add_exit("noroeste", CATACUMBAS+"l8", "plain");
   add_exit("oeste", CATACUMBAS+"l13", "plain");
   add_exit("sudoeste", CATACUMBAS+"l18", "plain");
   add_exit("sur", CATACUMBAS+"l19", "plain");
   add_exit("sudeste", CATACUMBAS+"l20", "plain");
}

string query_long()
{
   return ::query_long()+"    Te encuentras en el final del pasillo y ves "
   "una gran sala que tiene todo el aspecto de ser unas catacumbas. La "
   "simple vista te produce panico y nauseas.\n\n";
}