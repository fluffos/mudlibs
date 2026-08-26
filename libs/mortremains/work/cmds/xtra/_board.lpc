#include <mudlib.h>
#include <uid.h>

inherit DAEMON ;
  mapping *messages;

int cmd_board(string arg) {
   object ob;

	seteuid( getuid( environment( this_player() ) ) );

	write( "EUID: " + geteuid( this_object() ) + "\n" );
	if( !ob = present( "board", environment( this_player() ) ) ) {
		notify_fail( "No board here.\n" );
		return 0;
	}

	write( ob -> query_save_file() + "\n" );
  write( restore_object( (string) ob -> query_save_file() ) + "\n" );
	write( sizeof( messages ) + "\n" );
   return 1;
}

void help() {
	write( "None.\n" );
}
