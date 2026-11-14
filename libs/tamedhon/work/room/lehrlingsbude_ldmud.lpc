/* Lehrlingsbude und gemeinsames Home der Lehrlinge
 * Samtpfote@Tamedhon, Sat 13 Jan 2001 10:19:33 AM CET
 */
#include <properties.h>
#include <config.h>

inherit "/std/def_workroom";

void create()
{
  ::create();
  SetProp(P_INT_SHORT, "Die Lehrlingsbude von "+MUDNAME);
  SetProp(P_INT_LONG, break_string(
	"Das ist die Lehrlingsbude von "+MUDNAME+". Sie wirkt recht "+
	"spartanisch eingerichtet, erfüllt aber ihren Zweck. Eigentlich "+
	"ist der Raum mit Betten vollgestopft, wo die Lehrlinge gemütlich "+
	"schlafen können, und einen Tisch samt einen großen Regal "+
	"voller Dokumentation über das MUD."
  ));
  
  AddExit("süden", "/room/kreuzung");
}
