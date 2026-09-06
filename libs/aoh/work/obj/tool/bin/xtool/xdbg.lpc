#include "../bincmd.h"

inherit BASICXCMD;

QueryAbrev() { return "xdb"; }

int main( string str ) {
  object obj;

  if ( ( !str ) || ( str == "?" ) )
    return notify_fail( "xdb(g) <object>\n"), 0;

  if ( obj = XFindObj( str ) ) {
    debug_info(1, obj);
    debug_info(0, obj);
  }
  return 1;
}






