#include "../bincmd.h"

inherit BASICXCMD;

QueryAbrev() { return "xde"; }

int main(string str ) {
  object obj;

  if ( ( ! str ) || ( str == "?" ) )
    return notify_fail( "xde(s) <object>\n" ), 0;

  if ( obj = XFindObj( str ) ) {
    PrintShort("Destruct: ", obj);
    Destruct(obj);
  }
  return 1;
}





