// SilberLand MUDlib
//
// std/npc/guard.c -- Wachen, die nur durch umnieten zu entfernen sind
//
// $Date: 1997/03/13 01:22:37 $
/* $Revision: 1.3 $
 * $Log: guard.c,v $
 * Revision 1.3  1997/03/13 01:22:37  Woody
 * prepared for revision control
 *
 * Revision 1.2  1996/03/12  15:16:00  Mupfel
 * Defines geaendert
 *
 * Revision 1.1  1995/05/18  19:02:56  Rochus
 * Initial revision
*/

#pragma strong_types
#define NEED_PROTOTYPES
#include <thing/properties.h>
#include <npc/guard.h>

varargs mixed SetGuardProtection(int strength, int types) {
  // Setzt den Schutz eines Waechters vor Entfernen durch
  // irgendwelche Zaubersprueche.
  // strength = Staerke des Schutzes, dabei bedeutet 100,
  // dass der Waechter nie entfernt werden darf.
  // Wenn Typen angegeben sind, muss der Zauberspruch Waechter
  // von diesem Typ entfernen duerfen, sonst 100% Entfern-Verbot.
  if (types)
    return SetProp(P_GUARD,({strength,types}));
  return SetProp(P_GUARD,strength);
}

varargs int QueryGuardProtection(int arg) {
  // Wenn ein Zauberspruch z.B. auch Waechter entfernen koennen
  // darf, die einen normalen Gegenstand bewachen, dann
  // soll er mit QueryGuardProtection(GUARD_THING) testen
  // und falls der Wert unter 100 liegt darf der Waechter
  // entfernt werden.
  mixed res;

  if (!(res=QueryProp(P_GUARD))) return 0;
  if (intp(res)) return res;
  if (!pointerp(res)
      || sizeof(res)<2
      || !intp(res[0])
      || !intp(res[1]))
    return 100;      // Ungueltig, aber gesetzt => darf nicht entfernt werden
  if (~arg & res[1]) // Falls nicht alle Ausnahmen erlaubt sind
    return 100;      // 100% Entfern-Verbot
  return res[0];
}

