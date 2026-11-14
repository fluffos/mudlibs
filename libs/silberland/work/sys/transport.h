// SilberLand MUDlib
//
// sys/transport.h -- transporter header
//
// $Date: 2003/10/07 12:17:17 $
/* $Revision: 1.4 $
 * $Log: transport.h,v $
 * Revision 1.4  2003/10/07 12:17:17  Cirion
 * 'extra' Argument fuer AddFun
 *
 * Revision 1.3  2001/07/26 17:16:18  Woody
 * Neuer Prototyp fuer QueryHarbours()
 *
 * Revision 1.2  1999/05/11 11:21:31  Woody
 * P_MAX_PASSENGERS geaendert, neu: P_TRAVEL_INFO, P_ROUTE, neu: prototypes
 *
 * Revision 1.1  1997/03/31 13:44:47  Woody
 * prepared for revision control
 *
 */

#ifndef __TRANSPORT_H__
#define __TRANSPORT_H__

#define P_ENTERMSG      "entermsg"
#define P_LEAVEMSG      "leavemsg"
#define P_LEAVEFAIL     "leavefail"
#define P_ENTERFAIL     "enterfail"
#define P_ARRIVEMSG     "arrivemsg"
#define P_DEPARTMSG     "departmsg"
#define P_ENTERCMDS     "entercmds"
#define P_LEAVECMDS     "leavecmds"
#define P_MAX_PASSENGERS "max_passengers"
#define P_TRAVEL_INFO   "travel_info"
#define P_ROUTE         "route"

#define HP_MSG  "hpMsg"
#define HP_ROOM "hpRoom"
#define HP_FUN  "hpFun"

#ifdef NEED_PROTOTYPES

#ifndef __TRANSPORT_H_PROTO__
#define __TRANSPORT_H_PROTO__

// prototypes

public void Start(int pos);
public void Halt();
public mixed HasRoute(string dest);
public varargs void AddRoute(string room, int stay, int next,
                             string code, mixed dest, string deststr);
public void AddMsg(string msg, int next);
public varargs void AddFun(string fun, int next, mixed extra);
public string QueryArrived();
public string *QueryPosition();
public object *QueryPassengers();
public varargs string *QueryHarbours(int textflag);
public void RemoveRoute();
public varargs int Enter(object who);
public varargs int Leave(object who);

#endif // __TRANSPORT_H_PROTO__

#endif // NEED_PROTOTYPES

#endif // __TRANSPORT_H__
