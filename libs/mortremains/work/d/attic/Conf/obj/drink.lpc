// Generic drink!

#include <mudlib.h> 

inherit OBJECT;

void create()
{
  seteuid(getuid());

  set( "long", "The drink of your desire.\n" );
}

void init()
{
  add_action( "cmd_drink", "drink" );
}

int cmd_drink( string a )
{
  if( !id( a ) )
  {
    notify_fail( "You wish to drink what?\nNB \"drink drink\" will work.\n" );
    return 0;
  }
  write( "You drink your " + query( "name" ) + ".\n" );
  say( sprintf( "%s drinks %s %s.\n",
    (string)this_player()-> query( "cap_name" ),
    possessive( this_player() ),
    query( "name" ),
  ) );
  call_out( "remove", 0 );
  return 1;
}

void set_type( string a )
{
  set( "id", ({ "drink", a }) );
  set( "name", a );
  set( "short", article( a ) + " " + a );
}
