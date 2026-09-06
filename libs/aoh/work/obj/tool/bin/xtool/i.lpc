#include "../bincmd.h"

inherit BASICXCMD;

int main( string str ) {
  int i;
  object item;

  tell_object( cloner, "Inventory:\n" );
  for ( item=first_inventory( cloner ); item; item=next_inventory( item ) ) 
    PrintShort( sprintf( "%4.4s",(++i)+". " ), item );

  return 1;
}




