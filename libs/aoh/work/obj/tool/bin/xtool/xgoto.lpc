#include <moving.h>
#include "../bincmd.h"

inherit BASICXCMD;

QueryAbrev() { return "xgo"; }

int main(string str ) {
  object obj, tmp;

  if ( str == "?" )
    return notify_fail( "xgo(to) [object]\n" ), 0;

  if ( ! str ) str = "~/workroom";
  if( ! ( obj = XFindObj( str, 1 ) ) ) {
    if ( ! ( str = XFindFile( str ) ) ) return 1;
    if(catch(call_other(str, "???"))) return 1;
    obj=find_object(str);
  }
  tmp=obj;
  while(obj&&living(obj)) obj=environment(obj);
  cloner->move(obj ? obj : tmp, M_TELEPORT );
  return 1;
}
