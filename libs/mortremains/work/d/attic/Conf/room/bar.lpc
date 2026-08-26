// Bar - chat room

#include <mudlib.h>

inherit ROOM;

void create()
{
  ::create();
  seteuid(getuid());

  set( "light", 1 );
  set( "short", "The Conference Bar" );
  set( "long", wrap(
"From the variety of half-full bottles scattered about, you can tell this"+
" must be the bar thoughtfully provided by the conference organisers so"+
" that the attendees have a place to relax and chat about nothing in"+
" particular. The gathering centre is to the south.  Private rooms are north."+
" There's a sign on the wall you could look at."+
  "" ) );
  set ("item_desc", ([ "sign" :
"The sign says:\n"+
"Have a drink! All you have to do is \"pour\" it. If you have a few too\n"+
"many drinks, the bathroom is at the end of the north hall.\n"
]) ) ;
  set( "exits", ([
    "south" : "/d/Conf/room/centre",
    "north" : "/d/Conf/room/0,0.hall",
  ]) );
// if want can set an exit_msg
  
  call_other( "/d/Conf/boards/bar", "frog" );
}

void init()
{
  add_action( "cmd_pour", "pour" );
}

int cmd_pour( string a )
{
  object drink;
  string drink_name;

  if( !a )
  {
    notify_fail( "Syntax: pour <drink>\neg \"pour vodka\".\n" );
    return 0;
  }
  if( !sscanf( a, "a %s", drink_name  ) ) drink_name = a;
  if( sscanf( drink_name, "an %s", a ) ) drink_name = a;
  drink = new( "/d/Conf/obj/drink" );
  drink-> set_type( drink_name );
  drink-> move( this_player() );
  drink_name = article( drink_name ) + " " + drink_name;
  write( "You pour yourself " + drink_name + ".\n" );
  say( sprintf( "%s pours %s %s.\n",
    this_player()-> query( "cap_name" ),
    possessive( this_player() ),
    drink_name,
  ) );
  return 1;
}
