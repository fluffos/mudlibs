// SilberLand MUDlib
//
// /p/daemon/shipd.h -- Definitionen fuer den Ship Daemon
//
// $Date: 2001/07/26 17:58:29 $
/* $Revision: 1.2 $
 * $Log: shipd.h,v $
 * Revision 1.2  2001/07/26 17:58:29  Woody
 * QueryHarbours() wg. Konflikt mit std/transport in QueryAllHarbours() umbenannt
 *
 * Revision 1.1  1999/05/11 11:37:09  Woody
 * Initial revision
 *
 */

#ifndef __SHIPD_H__
#define __SHIPD_H__

// Der Ship Daemon
#define SHIPD          "/p/daemon/shipd"
#define SHIPD_SAVEFILE "/p/daemon/save/shipd"

#ifdef NEED_PROTOTYPES
#ifndef __SHIPD_H_PROTO__
#define __SHIPD_H_PROTO__

public void AddHarbour(object ship, string harbour);
public void RemoveShip(object ship);
public varargs mixed HasShip(object harbour, string ship);
public mixed RouteExists(object ship, string dest);
public mapping QueryShips();
public mapping QueryAllHarbours();

#endif // __SHIPD_H_PROTO__

#endif // NEED_PROTOTYPES

#endif // __SHIPD_H__

