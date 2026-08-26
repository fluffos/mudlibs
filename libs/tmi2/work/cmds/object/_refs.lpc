#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;
inherit REF_D;

string ref_help;

int cmd_refs( string a )
{
  mapping refs;
  string *k;
  int i, s;

  refs = this_player()-> query( "ref" );
  if( !mapp(refs) || !(k=keys(refs)) || !(s=sizeof(k)) )
  {
    write( "You have no references set.\n" );
    return 1;
  }
  if( -1 != member_array( "default", k ) )
  {
    k -= ({ "default" });
    k = ({ "default" }) + k; // Make sure the default gets displayed first.
  }
  for( i = 0 ; i < s ; i++ )
    write( wrap( sprintf( "%-15s%s", k[i], identify( refs[k[i]] ) ) ) );
  return 1;
}

int help()
{
  if( !ref_help ) ref_help = read_file( "/doc/wizhelp/refs" );
  write( ref_help );
  return 1;
}
