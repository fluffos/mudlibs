/*
** Ein Holzstock
** Wird vom stockautomat automatisch neu erzeugt. Ist eine Waffe, aber wertlos.
*/

inherit "std/weapon";

#include <properties.h>     /* Definition der Properties */
#include <combat.h>         /* Definition der kampfspezifischen Konstanten */
#include <language.h>       /* Definition von MALE, FEMALE, WER, ... */
#include <defines.h>
#include <moredef.h>

void create()
{
/* Wenn das Objekt kein Clone ist sondern die Blueprint (also das Original
 * von dem beim clonen Kopien gemacht werden), soll im Normalfall nichts
 * konfiguriert werden --> Speicher wird gespart
 */
  if (!clonep(this_object()))
     return;

  ::create();   /* WICHTIG!!! */

/* Kurzbeschreibung fuer Darstellung in inventories */
  SetProp (P_SHORT, "Ein Holzstock");

/* Beschreibung des Knueppels */
  SetProp (P_LONG, 
  "Dieser feste Holzstock ist eine einigermaßen brauchbare Waffe.\n"+
  "Am liebsten würdest Du damit auf eine Ratte eindreschen.\n");

/* Name und Geschlecht sind wichtig, jedes Objekt braucht das */
  SetProp (P_NAME, "Holzstock");
  SetProp (P_GENDER, MALE);

/* Jedes Objekt braucht eine oder mehrere Id's */
  AddId (({"stock", "holzstock", "\nholzstock"}));

/* Wert und Gewicht */
  SetProp (P_VALUE, 0);
  SetProp (P_WEIGHT, 500);   /* in Gramm */

/* Nun die wirklich Waffenspezifischen Dinge:                   */
/* Waffen- und Schadensarten sind in /sys/combat.h definiert    */
  SetProp (P_WEAPON_TYPE, WT_CLUB);
  SetProp (P_DAM_TYPE, DT_BLUDGEON);

/* Die Waffenklasse muss im Bereich zwischen 1 und 300 liegen   */
  SetProp (P_WC, 40);

/* Anzahl der benoetigten Haende, um die Waffe zu zuecken.      */
/* Waffen mit einer WC groesser 150, sollten auf jeden Fall     */
/* Zweihaender sein, bei Sonderfaellen bitte an den Erzmagier   */
/* fuer Waffen wenden. Wenn nichts gesetzt wird, ist die Waffe  */
/* ein Zweihaender.                                             */
  SetProp (P_NR_HANDS, 1);
  SetProp(P_NOSELL,"So ein Holzstock ist wertlos.\n");

  SetProp (P_MATERIAL, MAT_WOOD);
}


void reset()
{
  object ob;
  ::reset();
  ob=MENV;
  if (ob && !query_once_interactive(ob))
  {
    // if (ob->id("Raum"))
    if (ob->QueryProp(P_EXITS))
      tell_room (ob, "Der Stock zerfällt in seine Bestandteile.\n");
    call_out("remove", 0);
  }
}

