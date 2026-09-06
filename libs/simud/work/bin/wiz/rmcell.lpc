#include <const.h>
#include <wizard.h>

int main( string param ) {
   string name;
   int x, y, z;

   WIZ_CHECK
   if( !param ) {
      notify_fail("==> [Format] rmcell x y [z]\n");
      return 0;
   }

   if( !environment(this_player())->query_is_area() ) {
      notify_fail("This function is for painting areas. You must be standing in an area for it to work.\n");
      return 0;
   }

   if( sscanf(param, "%d %d %d", x, y, z) != 3 ) {
      z = 0;
      if( sscanf(param, "%d %d", x, y) != 2 ) {
         notify_fail("==> [Error] Invalid coordinate\n");
         return 0;
      }
   }

   environment(this_player())->remove_cell(x, y, z, name);
   msg("OK.");
   return 1;
}