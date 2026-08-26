/*
//
//  File    :  _netmail.c
//  Author  :  Inspiral@Tabor
//  Created :  93-12-28
//  Purpose :  Admin command to view outgoing mail queues.
//  Usage   :  No args gives full list, arg of <mudname> gives
//                dump of oldest message in the queue for that mud.
//
*/


#include <mudlib.h>
#include <net/macros.h>
#include <mailer.h>

inherit DAEMON;

mixed * out_queue;
nosave string output;
int busy;
nosave object ob;


mapping pop_top( string mudname );
void begin_jumping();
void part_two( string *dir, string back );


int cmd_netmail( string mud ) {
  mixed text;

  if( !adminp(geteuid( this_player() )) )
    return 0;

  if( mud && mud != "" ) {
    if( !text = pop_top( mud ) )
	  write( "NETMAIL:  No outgoing mail in queue for " + mud + ".\n" );
   else printf( "%O\n", text );
  }  else  {
    if( busy )
      return notify_fail( "This command is currently busy, try later.\n" );
    write( "Beginning recursive scan of netmail directory.\n" );
  output = "";
  ob = this_player();
    busy = 1;
    begin_jumping();
  }
  return 1;
}


void begin_jumping() {
  string *one, *stuff;
  int i;
  
  one = get_dir( NETMAIL_DIR );
  i = sizeof( one );
  call_out( "part_three", 6 );
  message( "info", "NETMAIL:  Please wait 6 seconds.\n", ob );
  
  while( i-- )
    if( sizeof( stuff = get_dir( NETMAIL_DIR + one[i] + "/" ) ) )
      call_out( "part_two", 0, stuff, one[i] );
  
  return;
}


void part_two( string *dir, string base ) {
  int j;
  string mud;
  mapping info;
  
  if( !output ) output = "\n";
  
  j = sizeof( dir );
  
  while( j-- ) {
   sscanf( dir[j], "%s" __SAVE_EXTENSION__, mud );
    if( info = pop_top( mud ) ) {
    output = output +
      sprintf( "%4d  %-20s %s\n",
	 	info["size"], mud, format_time( time() - info["TIME"], 1 ) );
    }
  }
}


void part_three() {
  if( stringp( output ) && strlen( output ) && ob ) {
    output = 
	sprintf( "%-5s %-20s %s\n", "MSGS", "Mud Name", "Oldest Age" ) + output;
  message( "info", output, ob );
  }
    else message( "info", "\nNETMAIL:  No outgoing netmail found.\n", ob );

  busy = 0;
  ob = 0;
}


mapping pop_top( string mud ) {
  string file;
  
  out_queue = ({  });
  file = data_netmail_file( htonn( mud ) );
  
  if( !restore_object( file ) ) {
    write( "Problem restoring file.\n" );
    return 0;
  }

  if( !sizeof( out_queue ) ) {
	return 0;
  }

  out_queue[0] += ([ "size" : sizeof( out_queue ) ]);
  return out_queue[0];
}

int help() {
  write(
"Command:  netmail\n"
"Syntax :  netmail [<mudname>]\n\n"
"This command will allow an admin to scan the outgoing queue of\n"
"udp mail messages, and view statistics about the mail.\n\n"
"If supplied a mudname, the command will display the mail fields\n"
"for the top (oldest) mail in the queue for that particular mud\n"
"(if any exists).\n\n"
"This command is mainly provided as a starter kit for a larger\n"
"diagnostic package, in which admins may create in-house mail bouncing\n"
"mechanisms, or periodic mail deletions.\n"
  );
return 1;
}

/* EOF */
