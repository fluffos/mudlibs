// A inherit tree with memory_info
#include <cmd.h>
inherit CMD_BASE;

private object SearchObject( string name ) {
  if ( !name ) return 0;
  catch( name -> trams() );
  return find_object( name );
}

private void WriteObject( string str, object ob ) {
  if ( ob ) {
    string *Inherits = inherit_list( ob );
    int i = sizeof( Inherits );
    
    while ( i-- ) {
      int Mem = memory_info( SearchObject( Inherits[ i ] ) );
      printf( "%-45s %6d Bytes\n", str + Inherits[ i ], Mem ); 
      WriteObject( "  " + str , SearchObject( Inherits[ i ] ) );
    }
  }
}

int cmd(string str, object me) {
  if ( str ) {
    printf( "%-45s %6d Bytes\n", str, 
           memory_info( SearchObject( str ) ) );
    WriteObject( "  ", SearchObject( str ) );
  }
  return 1;
}
