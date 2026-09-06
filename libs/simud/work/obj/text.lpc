#include <item.h>
#include <desc.h>
#include <object.h>
#include <saveload.h>
#include <const.h>
#include <literacy.h>

ICON( '\"', 3, LAYER_ITEMS )

string *pages = ({ "" });

int query_page_count() {
   return sizeof(pages);
}

string query_page( int x ) {
   x--;
   if( x < 0 || x >= sizeof(pages) ) return 0;
   return pages[x];
}

int on_read( int page_num ) {
   string page;

   if( !page_num ) {
      if( query_page_count() == 1 )
         page_num = 1;
      else return 0;
   }
   page = query_page( page_num );
}

NAME( "text" )
DISTANT( "a piece of text" )
SPECIFIC( "the piece of text" )
PLURAL( "texts" )
ALT_PLURAL( ({ "pieces of text" }) )
GETTABLE( 1 )
DROPPABLE( 1 )
WEIGHT( 500 )
BULK( 200 )
LOOK( "A rather plain piece of text" )
