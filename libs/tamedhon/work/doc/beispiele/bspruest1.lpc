/*
** Eine Beispielruestung
** (von Boing)
*/

inherit "std/armour";

#include <properties.h>
#include <combat.h>
#include <language.h>

create()
{
  if (!clonep(this_object()))
     return;
  ::create();   /* WICHTIG!!! */

/* Standardkonfiguration, genaueres siehe /doc/beispiele/bspwaffe1.c    */
  SetProp(P_SHORT, "Ein grauer Umhang");
  SetProp(P_LONG, "Es ist ein langer grauer Umhang aus einem feinen Material.\n");
  SetProp(P_NAME, "Umhang");
  SetProp(P_GENDER, MALE);
  AddId("umhang");
  SetProp(P_WEIGHT, 250);
  SetProp(P_VALUE, 200);

/* Zur Waffe fehlt nicht mehr viel, nur noch die Ruestungsklasse (AC)    */
/* setzen und einen Ruestungstyp setzen. Die Typen sind in sys/combat.h  */
/* definiert. Richtlinien zu Ruestungsklassen der verschiedenen Typen    */
/* stehen momentan in /players/boing/waffen.                             */

  SetProp(P_ARMOUR_TYPE, AT_CLOAK);
  SetProp(P_AC, 8);
}
