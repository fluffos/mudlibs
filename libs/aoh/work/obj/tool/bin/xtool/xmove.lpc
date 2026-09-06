#include "../bincmd.h"

inherit BASICXCMD;

QueryAbrev() { return "xmov"; }

int main( string str ) {
  object obj1, obj2;
  string what, into;

  if ( (!str) || (str=="?") )
    return notify_fail( "xmov(e) <object> into <object>\n"), 0;

  if ( ( sscanf( str, "%s into %s", what, into ) == 2 ) &&
       ( obj1 = XFindObj( what ) ) &&
       ( obj2 = XFindObj( into ) ) )
    MoveObj( obj1, obj2, 0 );

  return 1;
}



