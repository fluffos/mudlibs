#include <sys/rtlimits.h>

/* Area import/export format.
 * obj /world/maparea name
 * begin
 * var look=look desc
 * var short=etc.
 * end
 */

string buf;
int indent;
int recurse_areas;

#define IND tab("\t", indent)

void write_grid( object ob ) {
   int xdim, ydim, zdim, ix, iy, iz;

   xdim = ob->query_xdim();
   ydim = ob->query_ydim();
   zdim = ob->query_zdim();
   if( xdim <= 0 || ydim <= 0 || zdim <= 0 ) return;
   buf += IND + "grid\n";
   indent++;
   for( iz = 0; iz < zdim; iz++ )
   for( iy = 0; iy < ydim; iy++ ) {
      buf += IND;
      for( ix = 0; ix < xdim; ix++ ) {
         int tile;
         tile = ob->query_cell_index( ix, iy, iz );
         if( tile == 254 ) buf += ".. ";
         else buf += "0123456789"[tile/26..tile/26] + "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[tile%26..tile%26] + " ";
      }
      buf += "\n";
   }
   indent--;
   buf += IND + "end grid\n";

   if( !ob->query_is_world_map() ) {
      int i;
      string *grid_values;

      buf += IND + "gridkey\n";
      indent++;
      grid_values = ob->query_grid_values();
      for( i = 0; i < sizeof(grid_values); i++ ) {
         buf += IND + "0123456789"[i/26..i/26] + "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[i%26..i%26] + " ";
         buf += grid_values[i] + "\n";
      }
      indent--;
      buf += IND + "end gridkey\n";
   }
}

void write_exit( object ob ) {
   buf += IND + "exit " + load_name(ob) + "\n";
   indent++;
   buf += IND + "dir " + ob->query_dir() + "\n";
   buf += IND + "link " + ob->query_link() + "\n";
   indent--;
   buf += IND + "end exit " + load_name(ob) + "\n";
}

void write_var( object ob, string var ) {
   mixed val = call_other( ob, "query_" + var );
   if( !stringp(val) ) return;
   if( strstr(val, "\n") >= 0 ) {
      buf += IND + "longstring " + var + "\n";
      indent++;
      buf += IND + implode( explode(val, "\n"), "\n" + IND) + "\n" + IND + "end longstring\n";
      indent--;
   }
   else buf += IND + "string " + var + " " + val + "\n";
}

void write_obj( object ob ) {
   object iroom;

   buf += IND + "obj " + load_name(ob) + " " + ob->query_name() + "\n";
   indent++;
   write_grid( ob );
   write_var( ob, "look" );
   write_var( ob, "short" );
   write_var( ob, "long" );
   write_var( ob, "distant" );
   write_var( ob, "specific" );
   foreach( iroom : all_inventory(ob) ) {
      if( iroom->query_is_room() || (iroom->query_is_area() && recurse_areas) )
         write_obj( iroom );
      if( iroom->query_is_exit() )
         write_exit( iroom );
   }
   indent--;
   buf += IND + "end obj " + load_name(ob) + " " + ob->query_name() + "\n";
}

void export_area( object ob, string filename, int recurse ) {
   buf = "";
   indent = 0;
   recurse_areas = recurse;
   limited( (: write_obj(ob) :), LIMIT_UNLIMITED, 0 );
   rm( filename );
   write_file( filename, buf );
}
