// File:        _ss.c
// Mudlib:      Nightmare (but see credits)
// Purpose:     Scans an object (See the "I" and "sc" commands)
// Credits:     see _refs.c

#include <daemons.h>
#include <std.h>

inherit DAEMON;
inherit REFS_D;

#define SYNTAX "Syntax: ss [<object>]\n"

int cmd_ss( string a ) 
{
  mixed ob, cont;
  object obj;
  int i;


  if( !a ) a = "here";
  ob = ref_ob( a );
  if( !objectp( ob ) )
  {
    notify_fail( wrap( "Could not identify " + identify( ob ) + 
      " as an object." ) );
    return 0;
  }
    write("Scanning: "+identify(ob)+" PRIVS: "+query_privs(ob));
  cont = all_inventory( ob );
  set_ref( "ss", cont );
  for( i = 0 ; i < sizeof( cont ) ; i++ )
  {
    obj = cont[i];
    write("  "+(i+1)+": "+identify(obj)+" PRIV: "+query_privs(obj));
  }
  set_ref( 0, ob );
  return 1;
}

int help()
{
  write( SYNTAX +
    "Effect: scans <object> (defaults to your environment)\n"+
    "See also: refs, sc, I\n"+
  "" );
}
    
