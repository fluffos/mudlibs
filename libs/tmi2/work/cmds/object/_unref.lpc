#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;
inherit REF_D;

#define SYNTAX "Syntax: unref <ref_name>\n"

int cmd_unref( string a )
{
  mapping refs;

  if( !a ) { notify_fail( SYNTAX ); return 0; }
  refs = this_player()-> query( "ref" );
  if( !refs ) refs = ([ ]);
  if( undefinedp( refs[a] ) )
  {
    notify_fail( "\"" + a + "\" is not a reference.\n" );
    return 0;
  }
  map_delete( refs, a );
  refs = this_player()-> set( "ref", refs );
  write( "Reference \"" + a + "\" deleted.\n" );
  return 1;
}

int help() 
{
  write( SYNTAX +
    "Effect: unsets reference <ref_name>\n"+
  "" );
  return 1;
}
