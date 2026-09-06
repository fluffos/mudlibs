#include "../bincmd.h"

#define TRACE_LEVEL        (1|2|4|8)

inherit BASICXCMD;

QueryAbrev() { return "xtrac"; }

int main( string str ) {
  string file;
  object obj;

  if ( str == "?" )
    return notify_fail( "xtrac(e) <object>\n"), 0;

  if(!str) {
    trace(0);
    tell_object( cloner, 
		 "Ending trace ["+short_path("/"+traceprefix(0))+"].\n");
  } else if ( obj = XFindObj( str ) ) {
    PrintShort("Tracing: ", obj);
    file=object_name(obj);
    file=file[1..];
    traceprefix(file);
    trace(TRACE_LEVEL);
  }
  return 1;
}




