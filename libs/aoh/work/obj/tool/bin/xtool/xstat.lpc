#include "/obj/tool/bin/bincmd.h"

inherit BASICXCMD;

int main( string str ) {
  object callobj;
  string res;

  if ( ( ! str ) ||
       ( str == "?" ) )
    return notify_fail( "xstat <object>\n" ), 0;

  if ( ! ( callobj = XFindObj( str ) ) ) 
    return 1;

  res = callobj->Status();
  if ( ! res )
    tell_object( cloner, "No status available.\n" );
  else
    tell_object( cloner, res+"\n" );

  return 1;
}
