#include "../bincmd.h"

inherit BASICXCMD;

QueryAbrev() { return "xdc"; }

int is_not_player(object obj) {
  return obj&&obj!=find_player(getuid(obj));
}

void DeepClean(object obj) {
  if(!obj) return;
  filter(filter(deep_inventory(obj), SF(is_not_player) ),
               SF(Destruct) );
  if(is_not_player(obj)) Destruct(obj);
}

int main( string str ) {
  object env;

  if ( str == "?" )
    return notify_fail( "xdc(lean) [object]\n"), 0;

  if ( ! str ) 
    env = environment(cloner);
  else 
    env = XFindObj(str);

  if ( env ) {
    PrintShort("Deep cleaning: ", env);
    filter( filter( all_inventory(env), SF(is_not_player) ),
		  SF( DeepClean ) );
  }
  return 1;
}




