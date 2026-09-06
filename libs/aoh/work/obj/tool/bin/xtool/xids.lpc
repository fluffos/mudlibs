#include "../bincmd.h"

inherit BASICXCMD;

QueryAbrev() { return "xid"; }

int main( string str) {
  object obj;

  if ( (!str) || (str=="?") )
    return notify_fail( "xid(s) <object>\n"), 0;

  if ( obj = XFindObj( str ) )
    tell_object( cloner,"UID=\""+getuid(obj)+"\" / EUID=\""+geteuid(obj)+"\"\n");
  return 1;
}



