#include "../bincmd.h"

inherit BASICXCMD;

QueryAbrev() { return "xqu"; }

int main( string str ) {
  if ( str == "?" )
    return notify_fail( "xqu(it)\n"), 0;

  str=object_name(environment(cloner));
  if(member(str, '#')<0) cloner->SetHome(str);

  cloner->quit();
  return 1;
}



