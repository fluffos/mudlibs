#include <rooms.h>
#include <properties.h>

inherit "/std/room";

compile_object( string file ) {
  object ob;
  
  ob = clone_object( "/players/mica/test2" );
  dtell( "mica", sprintf( "OB0: [%O]\n", ob ) );
  return ob;
}

testit( string arg ) {
  object ob;
  ob = clone_object( "/secure/login#" );
  dtell( "mica", sprintf( "OB1: [%O]\n", ob ) );
  ob->create_player( environment( this_player() ) );
  destruct( ob );
  return 1;
}

create() {
  ::create();

  seteuid( getuid() );

  SetIntShort( "Testroom" );
  SetIntLong( "A testroom...\n" );
 
  AddRoomCmd( "testit", "testit" );
 
  Set( P_VMASTER, this_object() );
}
