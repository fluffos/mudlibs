// This must be run AFTER you install mail_package.c, data.c
//  and then update simul_efun.c
//

#define WHO	(find_player( "inspiral" ))
#define TELL(x)	if( WHO ) tell_object( WHO, x + "\n");
#include <mudlib.h>
#include <mailer.h>
inherit DAEMON;

int cmd_mesgfix( string x ) {
  int i;
  string *list;

  if( to_int( x ) < 0 || to_int( x ) > 9 ) 
	return notify_fail( "0 - 9 please.\n" );

  printf( "%s\n", x );
  list = get_dir( MESGDIR + x + "/*.o" );
  i = sizeof( list );
  while( i-- )
  call_out( "move_em", 2+ (2*i), list[i], x );
  return 1;
}

void move_em( string f, string dir ) {
  string x, y;

  x = MESGDIR + dir + "/" + f ;
  y = mail_mesg_file( f ) + __SAVE_EXTENSION__;
  TELL( "Moving: " + x + " to " + y );
  rename( x, y );
}

string help() {
  return(
"Command:  mesgfix\n"
"Syntax:   mesgfix [0-9]\n\n"
"This command moves mailmesg files (1.1.1 mailer form) to the new (1.1.2)\n"
"directory format.  This command should be run in such a fashion:\n\n"
"> mesgfix 0\n"
"(Wait until it is complete)\n"
"> mesgfix 1\n"
"...etc thru 9\n"
"\nIt is recommended that you set the WHO debug macro to the admin\n"
"initiating the command.\n" );
}
