#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup()
{

 position = 1;
}



protected int cmd(string str, object me) {
   mapping m ;
   string s ;

   m = ([ ]) ;
   foreach( object ob in objects() )
    {
       if( clonep( ob ) && !environment( ob ) && inherits( "/std/object", ob ))
        {
           m[base_name( ob )]++ ;
        }
    }
   s = "" ;
   s += "leaked object list\n" ;
   foreach( string k, int v in m )
    {
      s += sprintf( "  %-40s : %d\n", k, v ) ;
    }
   tell_object( TP, s ) ;
   return 1 ;
}
