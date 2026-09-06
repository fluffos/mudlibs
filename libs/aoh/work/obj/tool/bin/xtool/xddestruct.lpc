#include "../bincmd.h"

inherit BASICXCMD;

QueryAbrev() { return "xdd"; }

int main( string str ) {
  object obj;

  if ( (!str) || (str=="?") )
    return notify_fail( "xdd(es) <object>\n" ), 0;

  if ( obj = XFindObj( str ) ) {
    PrintShort("Deep destruct: ", obj);
    filter(deep_inventory(obj), SF(Destruct) );
    Destruct(obj);
  }
  return 1;
}



