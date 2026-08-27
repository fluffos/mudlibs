//#pragma save_binary
#include <move.h>
#include <mudlib.h>
#include <daemons.h>
#include <logs.h>
#include <uid.h>

inherit DAEMON;
inherit REF_D;

#define SYNTAX "Syntax: move <object1> to <object2>\n"

int cmd_move( string a )
{
  mixed o1, o2, tmp;
  string str;
  int ret;

  if( !a || ( sscanf( a, "%s to %s", o1, o2 ) < 2 ) )
    { notify_fail( SYNTAX ); return 0; }

  seteuid( geteuid( previous_object() ) );

  o1 = ref_ob( o1 );
  if( !objectp( o1 ) )
  {
    notify_fail( wrap( "Could not identify " + identify( o1 ) +
      " as an object." ) );
    return 0;
  }
  o2 = ref_ob( o2 );
  if( !objectp( o2 ) )
  {
    notify_fail( wrap( "Could not identify " + identify( o2 ) +
     " as an object." ) );
    return 0;
  }
  set_ref( "default", o2 );
  write( wrap( "Moving " + identify( o1 ) + " to " + identify( o2 ) + "..." ) );
  ret = o1-> move( o2 );
  switch( ret )
  {
    case MOVE_OK:		str = "Move OK.\n"; break;
    case MOVE_NOT_ALLOWED:	str = "Move not allowed.\n"; break;
    case MOVE_NO_ROOM:		str = "No room in object2 for object1\n"; break;
    case MOVE_DESTRUCTED:	str = "Move destructed\n"; break;
    case MOVE_NO_DEST:		str = "object2 is not a destination\n"; break;
    case MOVE_TOO_HEAVY:	str = "object1 too heavy for object2\n"; break;
    case MOVE_DOOR_CLOSED:	str = "The door is closed.\n"; break;
  }
#ifdef MOVE_LOG
	seteuid(ROOT_UID);
	if( !member_group(geteuid(this_player()), "admin") )
		log_file(MOVE_LOG, "************\n" +
		  extract(ctime(time()), 4, 15) +
		   " [" + geteuid(this_player()) + "] move'd: " + identify(o1)
		   + "\n to " + identify(o2) + "\n");
#endif

// do this first in case something bombs out below
	seteuid( geteuid( previous_object() ) );
	
  if( ret == MOVE_OK ) { write( str ); return 1; }
  return notify_fail( str ); 
}

int help()
{
  write( SYNTAX +
    "Effect: Moves object1 to inside object2\n"+
  "" );
  return 1;
}
