#include "../bincmd.h"

inherit BASICXCMD;

QueryAbrev() { return "xcle"; }

int is_not_player(object obj) {
  return obj&&obj!=find_player(getuid(obj));
}

int main(string str) {
  object env;

  if ( str == "?" )
    return notify_fail( "xcle(an) [object]\n" ), 0;

  if ( ! str ) 
    env = environment(cloner);
  else 
    env = XFindObj(str);

  if ( env ) {
    PrintShort( "Cleaning: ", env );
    filter( filter( all_inventory( env ), 
				SF( is_not_player ) ),
		  SF( Destruct ) );
  }
  return 1;
}




