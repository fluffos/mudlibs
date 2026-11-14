/*
** Eine Beispielwaffe
** (von Boing)
*/

inherit "std/weapon";

#include <properties.h>     /* Definition der Properties */
#include <combat.h>         /* Definition der kampfspezifischen Konstanten */
#include <language.h>       /* Definition von MALE, FEMALE, WER, ... */

create()
{
/* Wenn das Objekt kein Clone ist sondern die Blueprint (also das Original
 * von dem beim clonen Kopien gemacht werden), soll im Normalfall nichts
 * konfiguriert werden --> Speicher wird gespart
 */
  if (!clonep(this_object()))
     return;

  ::create();   /* WICHTIG!!! */

/* Kurzbeschreibung fuer Darstellung in inventories */
  SetProp(P_SHORT, "Ein Knueppel");

/* Beschreibung des Knueppels */
  SetProp(P_LONG, 
  "Dieser Knueppel ist ziemlich normal, er ist aus festem Holz gefertigt und\n"+
	  "man kann ihn als Waffe benutzen.\n");

/* Name und Geschlecht sind wichtig, jedes Objekt braucht das */
  SetProp(P_NAME, "Knueppel");
  SetProp(P_GENDER, MALE);

/* Jedes Objekt braucht eine oder mehrere Id's */
  AddId("knueppel");

/* Wert und Gewicht */
  SetProp(P_VALUE, 300);
  SetProp(P_WEIGHT, 1250);   /* in Gramm */

/* Nun die wirklich Waffenspezifischen Dinge:                   */
/* Waffen- und Schadensarten sind in /sys/combat.h definiert    */
  SetProp(P_WEAPON_TYPE, WT_CLUB);
  SetProp(P_DAM_TYPE, DT_BLUDGEON);

/* Die Waffenklasse muss im Bereich zwischen 1 und 200 liegen   */
  SetProp(P_WC, 125);
  
/* Anzahl der benoetigten Haende, um die Waffe zu zuecken.      */
/* Waffen mit einer WC groesser 150, sollten auf jeden Fall     */
/* Zweihaender sein, bei Sonderfaellen bitte an den Erzmagier   */
/* fuer Waffen wenden. Wenn nichts gesetzt wird, ist die Waffe  */
/* ein Zweihaender.                                             */
  SetProp(P_NR_HANDS, 1);
}
