#include "../bincmd.h"

inherit BASICXCMD;

QueryAbrev() { return "xloa"; }

int is_player(object obj) {
  return obj&&obj==find_player(getuid(obj));
}

int main(string str ) {
  int i, f;
  object obj, *inv, vroom;
  string file, errlog, error, *strs;

  if ( ( ! str ) || ( str == "?" ) )
    return notify_fail( "xloa(d) <filename>\n" ), 0;

  if ( ! ( file = XFindFile( str ) ) ) return 1;

  errlog = "/players/"+getuid(cloner)+"/.err";
  if ( file_size( errlog ) > 0 ) 
    rm( errlog );

  if ( obj = find_object( file ) ) {
    if ( catch( call_other( "/std/void", "???" ) ) ) {
      tell_object( cloner, 
		   "Error: cannot find /std/void to rescue players.\n");
      return 1;
    } 
    else 
      vroom = find_object( "/std/void" );

    if ( inv = filter( all_inventory(obj), SF(is_player) ) )
      for( i=0; i<sizeof(inv); i++) MoveObj(inv[i], vroom, 1);

    Destruct(obj);
    tell_object( cloner, "Update and load: "+file+"\n" );
  } 
  else 
    tell_object( cloner, "Load: "+file+"\n" );

  // No catch, to get proper backtraces on errors.
  call_other( file, "???");
  if ( inv ) {
    obj = find_object( file );
    for(i=0; i<sizeof(inv); i++)
      if( inv[i]) MoveObj(inv[i], obj, 1);
  }
  return 1;
}
