inherit "std/thing";

#include <language.h>
#include <properties.h>

void create()
{
  if (!clonep(this_object())) return;
  ::create();
  SetProp(P_SHORT, "Ein Würfel");
  SetProp(P_LONG, "Ein Würfel mit 6 Seiten.\n");
  SetProp(P_NAME, "Würfel");
  SetProp(P_GENDER, MALE);
  SetProp(P_WEIGHT, 1);
  SetProp(P_VALUE, 1);
  AddId(({"wuerfel","würfel"}));
	AddCmd(({"wuerfel","würfel"}),"wuerfel");
}

int wuerfel()
{
  int zahl;

  zahl = random(6) + 1;
  write("Du würfelst eine " + zahl + ".\n");
  say(this_player()->name() + " würfelt eine " + zahl + ".\n");
  return 1;
}
