// SilberLand MUDlib
//
// sys/daemon.h -- daemon's header
//
// $Date: 2004/01/16 15:11:00 $
/* $Revision: 1.8 $
 * $Log: daemon.h,v $
 * Revision 1.8  2004/01/16 15:11:00  Feyaria
 * corpsed.h hinzugefuegt
 *
 * Revision 1.7  2000/03/21 13:11:23  Zordan
 * HomePage Daemon mit hinzugefuegt
 *
 * Revision 1.6  1999/05/09 21:43:22  Woody
 * shipd.h includen
 *
 * Revision 1.5  1998/09/20 15:11:19  Woody
 * fingerd und itemd eingetragen
 *
 * Revision 1.4  1997/03/31 12:43:55  Woody
 * prepared for revision control
 *
 * Revision 1.3  1997/01/21  Woody
 * townd.h includen
 *
 * Revision 1.2  1994/09/23  21:46:22  Hate
 * *** empty log message ***
 *
 * Revision 1.1  1994/03/20  17:07:28  Hate
 * Initial revision
 *
 */
 
#ifndef __DAEMON_H__
#define __DAEMON_H__

#include "/p/daemon/channel.h"          // channel handling
#include "/p/daemon/html.h"             // HTML codes
#include "/p/daemon/object.h"           // persistent object handling
#include "/p/daemon/townd.h"            // town daemon
#include "/p/daemon/fingerd.h"          // finger daemon
#include "/p/daemon/itemd/itemd.h"      // item daemon
#include "/p/daemon/shipd.h"            // ship daemon
#include "/p/daemon/homepaged.h"        // Homepage Daemon
#include "/p/daemon/corpsed/corpsed.h"  // corpse daemon

#endif // __DAEMON_H__

