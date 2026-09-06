#include <wizard.h>
#include <const.h>

int main( string obj ) {
   object ob;
   int x, nx, y, ny, z, nz, c, cval;
   string mymap, name, oldcol, currcol;

   if( !obj ) {
      notify_fail("==> [Format] showmap obj\n");
      return 0;
   }

   if( !(ob = find_thing(obj)) ) {
      notify_fail("==> [Error] Cannot find '"+obj+"'.\n");
      return 0;
   }

   nx = ob->query_xdim();
   ny = ob->query_ydim();
   nz = ob->query_zdim();
   if( nx <= 0 || ny <= 0 || nz <= 0 ) {
      notify_fail("==> [Error] This object has no grid (It may not be initialized).\n");
      return 0;
   }
   if( nx * ny * nz > 800 ) {
      notify_fail("==> [Error] Map is too big! The showmap command doesn't handle this yet, sorry.\n");
      return 0;
   }

   // c = cell
   mymap = "~CTITMap of "+ob->query_name()+"\n  ~CBRT";
   for( x = 0; x < nx; x++ )
      mymap += pad( "" + x, 3, JUST_RIGHT );
   mymap += "\n";
   for( z = 0; z < nz; z++ ) {
      for( y = 0; y < ny; y++ ) {
         oldcol = "";
         mymap += "~CBRT" + pad( "" + y, 2, JUST_RIGHT );
         for( x = 0; x < nx; x++ ) {
            c = ob->query_cell_index( x, y, z );
            cval = c % 15 + 1;
            if( c == 254 ) {
               currcol = "~CDRK";
               if( currcol != oldcol )
                  mymap += "~CDRK ..";
               else
                  mymap += " ..";
            }
            else {
               currcol = "~["+(cval/10)+(cval%10)+"0";
               if( currcol != oldcol )
                  mymap += currcol + "   ";
               else
                  mymap += "   ";
               mymap[<2] = '0' + (c / 26);
               mymap[<1] = 'A' + (c % 26);
            }
            oldcol = currcol;
         }
         mymap += "\n";
      }
   }

   // c = column
   c = (this_player()->query_term_width() - 1) / 21;
   mymap += "~CLABKey:~CDEF";
   y = 0;
   for( x = 0; x < 256; x++ ) {
      name = ob->query_grid_value(x);
      if( name ) {
         if( y % c == 0 ) mymap += "\n";
         mymap += " ~CBRT  ";
         mymap[<2] = '0' + (x / 26);
         mymap[<1] = 'A' + (x % 26);
         mymap += "~CDEF " + pad( name, 17, JUST_LEFT );
         y++;
      }
   }
   mymap += "\n";
   msg_bare( mymap );
   return 1;
}