#include "../bincmd.h"

inherit BASICXCMD;

QueryAbrev() { return "xloo"; }

void PrintObj(object obj) {
  object item, tmp;
  string str;
  int i;

  if( !obj ) return;

  PrintShort( "Short: ", obj );

  tell_object( cloner, "Long :\n" );

  if(str=(string)obj->QueryIntLong());
  else if(str=(string)obj->QueryLong());
  else str="- no long description -\n";
  tell_object( cloner, str );
 
  for( item = first_inventory(obj);item;item=next_inventory(item) ) {
    if ( !i ) 
      tell_object( cloner, "Content:\n");
    PrintShort( sprintf( "%4.4s",(++i)+". " ), item);
  }
}

int main(string str ) {
  object obj;
  string st;

  if ( str == "?" )
    return notify_fail( "xloo(k) [object]\n" ), 0;

  if ( str ) {
    if ( obj = XFindObj( str ) ) 
      PrintObj( obj );
  } else {
    obj=environment(cloner);
    PrintObj(obj);
  }
  return 1;
}



