// File:        _sc.c
// Mudlib:      Nightmare (but see credits)
// Purpose:     Scans an object (See the "I" and "ss" commands)
// Credits:     see _refs.c

#include <daemons.h>
#include <std.h>

inherit DAEMON;
inherit "/adm/daemon/refs_d";

#define SYNTAX "Syntax: sc [<object>]\n"

string sc_object( object ob, string indent );

int cmd_sc( string a ) 
{
  mixed ob;
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
  write( wrap( "Deep Scanning: " + identify( ob ) + " EUID(" + geteuid( ob ) +
    ") UID(" + getuid( ob ) + ")" ) );
  sc_object( ob, "  " );
  set_ref( 0, ob );
  set_ref( "sc", deep_inventory( ob ) );
  return 1;
}

string sc_object( object ob, string indent )
{
  mixed obs;
  int i, s;

  obs = all_inventory( ob );
  s = sizeof( obs );
  for( i = 0 ; i < s ; i++ )
  {
    write( wrap( indent + (i+1) + ":  " + identify( obs[i] ) +
      " EUID(" + geteuid( obs[i] ) + ")" +
       " UID(" +  getuid( obs[i] ) + ")" +
     "" ) );
    sc_object( obs[i], "  "+indent );
  }
}

int help()
{
  write( SYNTAX +
    "Effect: does a recursive scan of <object> (defaults to your environment)\n"+
    "See also: refs, ss, I\n"+
  "" );
}
