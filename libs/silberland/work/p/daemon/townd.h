// SilberLand MUDlib
//
// /p/daemon/townd.h -- Definitionen fuer den Town Daemon
//
// $Date: 2001/02/16 21:02:06 $
/* $Revision: 1.3 $
 * $Log: townd.h,v $
 * Revision 1.3  2001/02/16 21:02:06  Woody
 * T_UNRESOLVED log nach /log/daemon/ verlegt
 *
 * Revision 1.2  1997/03/16 02:38:28  Woody
 * prepared for revision control
 *
 * Revision 1.1  1996/07/31 22:11:21  Hadra
 * Initial revision
 *
 */

#ifndef __TOWND_H__
#define __TOWND_H__

#define TOWND          "/p/daemon/townd"
#define T_SAVEFILE     "/p/daemon/save/townd"
#define T_UNRESOLVED   "daemon/town.unresolved"
#define T_DUMP_TOP     "/p/daemon/save/TOWN.TOP"
#define T_DUMP_NET     "/p/daemon/save/TOWN.NET"
#define T_DUMP_COUNTRY "/p/daemon/save/TOWN.COUNTRY"
#define TOWN           0
#define DESCRIPTION    1
#define COUNTRY        2
#define UNKNOWN        "Unbekannt"
#define LOCALHOST      ({"Wien","Der Mudrechner","at"})

#endif

