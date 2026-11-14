// Tamedhon MUDlib
//
// std/transport.c -- Standard Transporter
//
// $Date: 2005/05/21 18:40:00 $
/* $Revision: 4.0 $
 * $Log: transport.c,v $
 * Revision 4.0  1997/06/25 18:40:00  Serii
 * AddRoute() nimmt jetzt auch closures fuer 'stay' und 'next'
 *
 * Revision 3.1  1997/06/25 11:35:35  Woody
 * _query_route() und _set_route(),
 * P_ENTERFAIL/P_LEAVEFAIL duerfen auch closures sein
 *
 * Revision 3.0  1997/03/13 03:18:35  Woody
 * prepared for revision control
 *
 * Revision 2.10  1995/03/30  13:48:56  Rumata
 * ???
 *
 * Revision 2.9  1995/02/06  19:44:14  Jof
 * RCS-Logs aufgeraeumt (leere Logs raus usw)
 *
*/


inherit "std/thing/moving";
inherit "std/room";

#include <properties.h>
#include <moving.h>
#include <defines.h>
#include <language.h>

/* transport.c
 * Hates und Rumatas generisches Transport Objekt
 * MorgenGrauen 15.2.93
 *
 * Dokumentation in /doc/std/transport
 */

/********************** Variablen **********************/

mixed *route;	/* Liste der Haltepunkte. */
int rpos;	/* Momentane position in obiger Liste. */
string roomCode;/* Code des aktuellen Raumes (oder 0). */
string short;	/* ==  P_SHORT */
int transparent; /* == P_TRANSPARENT */

/********* Management der builtin-properties ***********/

string _set_short(string str )
{ return short = str; }

string _query_short()
{
  if ( roomCode ) return short; 
  return 0;
}

int _set_transparent(int val )
{ return transparent = val; }

int _query_transparent()
{
  if ( roomCode ) return transparent;
  return 0;
}

mixed* _set_route(mixed *r)
{ return route = r; }

mixed* _query_route()
{ return route[0..]; }

/***************** Zugriffsfunktionen ****************/

void Halt();
void connect(string room, string code );
varargs void disconnect(int change, int change_time);

void Start(int pos )
{
  Halt();
  rpos = ( pos>=sizeof(route) ) ? -1 : pos-1;
  call_out( "changeHp", 0 );
}

void Halt()
{
  while (remove_call_out( "changeHp" )>-1);
  while (remove_call_out( "disconnect" )>-1);
}

nomask void AddRoute(string room, int stay, int next, string code )
{
  route += ({ ({ HP_ROOM, room, stay, next, code }) });
}

nomask void AddMsg(string msg, int next )
{
  route += ({ ({ HP_MSG, msg, next }) });
}

nomask void AddFun(string fun, int next )
{
  route += ({ ({ HP_FUN, fun, next }) });
}

nomask string QueryArrived()
{
  /* sollte es nich besser QueryRoom() heissen ? */
  return roomCode;
}

nomask mixed QueryPosition()
{
  return ({ route[rpos][1], route[(rpos+1)<sizeof(route)?(rpos+1):0][1] });
}

nomask object *QueryPassengers()
{
  mixed *livings;
  object ob;

  livings = ({});
  for ( ob = first_inventory(ME); ob; ob = next_inventory( ob ) )
    if ( living(ob) ) livings += ({ ob });

  return livings;
}

nomask void RemoveRoute()
{
  Halt();
  route = ({ });
  rpos = 0;
}

int Enter()
{
  mixed msgs;
  int maxpassengers;

  if ( environment(this_player()) == ME )
  {
    write( "Da bist Du bereits.\n" );
    return 1;
  }

  if( !roomCode )
    return 0;

  maxpassengers = QueryProp( P_MAX_PASSENGERS );
  if ( maxpassengers && sizeof(QueryPassengers()) >= maxpassengers )
  {
    if ( pointerp( msgs = QueryProp(P_ENTERFAIL) ) )
    {
      say( this_player()->name(WER,2) + " " + msgs[1] + ".\n" );
      msgs = msgs[0];
    } else if (closurep(msgs)) {
      funcall(msgs);
      return 1;
    }
    write( msgs + ".\n" );
    return 1;
  }
  if ( !pointerp( msgs = QueryProp(P_ENTERMSG) ) )
    msgs = ({ 0,0 });
  return this_player()->move( ME, M_GO, 0, msgs[0], msgs[1] );
}

int Leave()
{
  mixed msgs;

  if ( environment(this_player()) != ME )
  {
		if( roomCode )
		{
			write( "Dafür müsstest Du erstmal dort sein.\n" );
			return 1;
		}
		return 0;
  }

  if( !roomCode )
  {
    if ( pointerp( msgs = QueryProp(P_LEAVEFAIL) ) )
    {
      say( this_player()->name(WER,2) + " " + msgs[1] + ".\n" );
      msgs = msgs[0];
    } else if (closurep(msgs)) {
      funcall(msgs);
      return 1;
    }
    write( msgs + ".\n" );
    return 1;
  }
  if ( !pointerp( msgs = QueryProp(P_LEAVEMSG) ) )
    msgs = ({ 0,0 });
  return this_player()->move( environment(), M_GO, 0,
			     msgs[0], msgs[1] );
}


/****************** Internal Functions ******************/

void create()
{
  ::create();
  route = ({});
  SetProp( P_ENTERCMDS, ({}) );
  SetProp( P_LEAVEFAIL, "Das geht jetzt nicht" );
  SetProp( P_ENTERFAIL, "Dort ist kein Platz" );
  AddId("Transporter");
}

varargs int remove()
{
  destruct( ME ); /* schoener waere "::remove();" */
  return 1;
}

/*changeHp()
{
  if ( ++rpos == sizeof(route) )
    rpos = 0;
  if ( route[rpos][0] == HP_MSG )
  {
    tell_room( this_object(), route[rpos][1] );
    call_out( "changeHp", route[rpos][2] );
  }
  else if ( route[rpos][0] == HP_FUN )
  {
    call_out( "changeHp", route[rpos][2] );
    call_other( ME, route[rpos][1] );
  }
  else // route[rpos][0] == HP_ROOM
  {
    connect( route[rpos][1], route[rpos][4] );
    call_out( "disconnect", route[rpos][2], 1, route[rpos][3] );
  }
}*/

nomask void changeHp()
{int next,stay;
  if ( ++rpos == sizeof(route) )
    rpos = 0;
  if ( route[rpos][0] == HP_MSG )
  {
    tell_room( this_object(), route[rpos][1] );
    if(closurep(route[rpos][2]))
    {
      next=funcall(route[rpos][2],0);
    }
    else
    {
      next=route[rpos][2];
    }
    call_out( "changeHp",next);
  }
  else if ( route[rpos][0] == HP_FUN )
  {
    if(closurep(route[rpos][2]))
    {
      next=funcall(route[rpos][2],0);
    }
    else
    {
      next=route[rpos][2];
    }
    call_out( "changeHp", next);
    call_other( ME, route[rpos][1] );
  }
  else /* route[rpos][0] == HP_ROOM */
  {
    if(closurep(route[rpos][2]))
    {
      stay=funcall(route[rpos][2]);
    }
    else
    {
      stay=route[rpos][2];
    }
    if(closurep(route[rpos][3]))
    {
      next=funcall(route[rpos][3]);
    }
    else
    {
      next=route[rpos][3];
    }
    connect( route[rpos][1], route[rpos][4] );
    call_out( "disconnect",stay, 1,next);
  }
}

void connect(string room, string code )
{
  mixed *arrivemsg;

  if ( roomCode ) disconnect();
  roomCode = code ? code : "";
  if ( catch(move( room , M_SILENT | M_NOCHECK )) )
  { /* Wenn der "Hafen" kein korrekter Raum ist ... */
    roomCode = 0;
    return;
  }
  arrivemsg = QueryProp(P_ARRIVEMSG);
  if ( pointerp(arrivemsg) )
  {
    tell_room( ME, process_string(arrivemsg[0]) );
    tell_room( room, process_string(arrivemsg[1]) );
  }
}

varargs void disconnect(int change, int change_time)
{
  object room;
  mixed *departmsg;

  departmsg = QueryProp(P_DEPARTMSG);
  if ( (room=environment()) && pointerp(departmsg) )
  {
    tell_room( ME, process_string(departmsg[0]) );
    tell_room( room, process_string(departmsg[1]) );
  }
  roomCode = 0;
  if (change)
	call_out("changeHp",change_time);
}

int clean_up(string arg)
{
  return 1;
}

void __restart(string funname)
{
  if(!funname||funname==""||(funname!="changeHp"&&funname!="disconnect"))
    return;
  while(remove_call_out(funname)!=-1);
  call_out(funname,funname=="changeHp"?15:5);
}

/*** noch nicht einbauen !!!
int _normalfunction(string str)
{
	if( !member(Query(P_EXITS),query_verb()) )
		return 0; // kein Exit
	if( environment(this_player()) != this_object() )
		return 0; // Spieler ausserhalb

	return room::_normalfunction(str);
}
***/
