#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;
inherit REF_D;

#define SYNTAX "Syntax: ss [<object>]\n"

int cmd_ss( string a ) 
{
  mixed ob, cont;
  object obj;
  int i;

  seteuid( geteuid( previous_object() ) );

  if( !a ) a = "here";
  ob = ref_ob( a );
  if( !objectp( ob ) )
  {
    notify_fail( wrap( "Could not identify " + identify( ob ) + 
      " as an object." ) );
    return 0;
  }
  write( wrap( "Scanning: " + identify( ob ) + " EUID(" + geteuid( ob ) +
    ") UID(" + getuid( ob ) + ")" ) );
  cont = all_inventory( ob );
  set_ref( "ss", ([]) );
  for( i = 0 ; i < sizeof( cont ) ; i++ )
  {
    obj = cont[i];
    set_ref( "ss/" + (i+1), obj );
    write( wrap( "  " + (i+1) + ":  " + identify( obj ) + " EUID(" +
      geteuid( obj ) + ") UID(" + getuid( obj ) + ")" ) );
  }
  set_ref( "default", ob );
  return 1;
}

int help()
{
  write( SYNTAX +
    "Effect: scans <object> (defaults to your environment)\n"+
  "" );
}
    
