/*                  
 * Ein Hinweiszettel fuer Magier.
 *
 * Querolin fuer Tamedhon September 2000
 */

inherit "std/thing";

#include <properties.h>
#include <defines.h>

void create()
{
  if(IS_BLUE(ME)) return;
  ::create();
  SetProp(P_SHORT, "Ein Zettel mit Magier-Hinweisen");
  SetProp(P_LONG,
    "Ein kleiner Schummelzettel auf dem einige Dinge stehen die Du als "
    "Magier im Tamedhon beachten solltest. Mit 'lies zettel' kannst Du den "
    "Zettel lesen\n");
  SetProp(P_NAME,"Schummelzettel");
  SetProp(P_GENDER, MALE);
  SetProp(P_WEIGHT, 0);
  SetProp(P_NOBUY, 1);
  SetProp(P_NOSELL, 1);
  SetProp(P_MATERIAL,MAT_PAPER);
  AddId(({"zettel","hinweiszettel","schummelzettel"}));
  AddCmd(({"lies","lese"}), "_lesen");
}

int _lesen(string str)
{
  notify_fail("Was willst Du lesen ? Syntax: lies <etwas>.\n");
  if (!str) return 0;
  if (!id(str)) return 0;
  PL->more("/doc/TAME/anregung_fuer_neumagier.txt");
  return 1;
}
