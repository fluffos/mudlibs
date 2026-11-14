/* SilberLand MUDlib
 *
 * /secure/udp/man.c -- UDP man handling
 *
 * $Date: 1997/05/19 16:39:29 $
 * $Revision: 1.2 $
 * $Log: man.c,v $
 * Revision 1.2  1997/05/19 16:39:29  Woody
 * remote man handling
 *
 * Revision 1.1  1997/03/16 00:12:32  Woody
 * prepared for revision control
 *
 */

#include <udp.h>

#ifdef ZEBEDEE
#include <system.h>
#elif !defined(INETD)
#define INETD	"/secure/inetd"
#endif


void _udp_man(mapping data)  
// Funktionierende MAN -r Version... von Querolin deaktiviert.
// zum aktivieren den "_" vor der funktion entfernen und die neue
// Funktion unten loeschen.           Querolin im September 2000
{
  string x;
  x = "/obj/manbuf"->query_man(0, ({data[DATA]}), 1);
  if (!x || x=="") {
    x="man@" + LOCAL_NAME + ": No match for \'"+data[DATA]+"\' found.\n";
  } else {
    x="man@" + LOCAL_NAME + ":\n" + x;
  }
  INETD->send_udp(data[NAME], ([
      REQUEST: REPLY,
      RECIPIENT: data[SENDER],
      ID: data[ID],
      DATA: x
  ]) );
}

void udp_man(mapping data)
{
  string x;
  x = "rman Abfrage ist im Tamedhon abgeschalten....\n";
  INETD->send_udp(data[NAME], ([
      REQUEST: REPLY,
      RECIPIENT: data[SENDER],
      ID: data[ID],
      DATA: x
  ]) );
}

