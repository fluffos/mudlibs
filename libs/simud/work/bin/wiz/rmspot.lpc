#include <const.h>
#include <wizard.h>

int main( string param ) {
   object ob;
   string obname;
   int ix, iy, x, y, w, h;

   WIZ_CHECK
   if( !param ) {
      notify_fail("==> [Format] rmspot scenery [x,y[,w,h]]\n");
      return 0;
   }

   if( sscanf(param, "%s %d,%d,%d,%d", obname, x, y, w, h) != 5 ) {
      w = 1;
      h = 1;
      if( sscanf(param, "%s %d,%d", obname, x, y) != 3 ) {
         x = this_player()->query_x();
         y = this_player()->query_y();
         obname = param;
      }
   }

   ob = find_thing( obname );
   if( !ob ) {
      notify_fail("==> [Error] Can't find '"+obname+"'\n");
      return 0;
   }
   if( w > 80 || h > 30 ) {
      notify_fail("Sorry, no insane values of w and h allowed.\n");
      return 0;
   }
   for( ix = 0; ix < w; ix++ )
   for( iy = 0; iy < h; iy++ )
      ob->remove_spot( MAKE_C(x+ix,y+iy,0) );
   environment(ob)->clear_map();

   return 1;
}