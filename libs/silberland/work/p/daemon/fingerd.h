// SilberLand MUDlib
//
// /p/daemon/fingerd.h -- Definitionen fuer den Finger Daemon
//
// $Date: 2000/01/22 14:11:22 $
/* $Revision: 1.2 $
 * $Log: fingerd.h,v $
 * Revision 1.2  2000/01/22 14:11:22  Zordan
 * FF_NOWIZARD, FF_NOMISC, FF_NOLONG eingefuehrt
 *
 * Revision 1.1  1998/09/20 13:18:34  Woody
 * Initial revision
 *
 */

#ifndef __FINGERD_H__
#define __FINGERD_H__

// Der Finger Daemon
#define FINGERD        "/p/daemon/fingerd"

// Die Flags
#define FF_NOPLAN       1     // zeige .plan nicht an
#define FF_NOFAMILY     2     // zeige Sponsor/Nachfolger nicht an
#define FF_NOWIZARD     4     // zeige Magier-Info nicht an
#define FF_NOMISC       8     // zeige Misc/E-Mail/Projekt nicht an
#define FF_NOLONG      16     // zeige Kurzversion des Finger an

#endif

