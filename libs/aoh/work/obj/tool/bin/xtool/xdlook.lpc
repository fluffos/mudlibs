#include "../bincmd.h"

inherit BASICXCMD;

QueryAbrev() { return "xdl"; }

void DeepPrintShort(object env, int indent, string pre) {
  int i;
  object item;

  if(!env) return;
  for(i=indent; i--; ) tell_object( cloner,"  ");
  i++;
  if(pre) tell_object( cloner, pre);
  PrintShort("", env);
  for( item = first_inventory( env ); item; item = next_inventory( item ) ) 
    DeepPrintShort(item, indent+1, sprintf( "%4.4s",(++i)+". " ) );
}

int main( string str ) {
  object obj;

  if ( str == "?" )
    return notify_fail( "xdl(ook) [object]\n"),0;

  if ( ! str ) str = getuid( cloner );
  if ( obj = XFindObj(str) ) 
    DeepPrintShort( obj, 0, 0);

  return 1;
}




