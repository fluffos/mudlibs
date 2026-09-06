#include "../bincmd.h"

inherit BASICXCMD;

QueryAbrev() { return "xmor"; }

int main(string str ) {
  string *args, file;
  int line;

  notify_fail( "xmor(e) <filename> [start]\n" );
  if ( ( ! str ) || ( str == "?" ) )
    return 0;

  switch(sizeof((args=explode(str, " ")-({""})))) {
  case 1:
    moreoffset = 1;
    break;
  case 2:
    sscanf(args[1], "%d", line);
    moreoffset = (line > 0) ? line : 1;
    break;
  default:
    return 0;
  }

  if ( file = XFindFile(args[0]) )
    XMoreFile(file, 1);
  return 1;
}



