#include <object.h>
#include <scenedesc.h>
#include <desc.h>
#include <gridsnap.h>
#include <inven.h>
#include <shape.h>

/** A base-class implementation of walls. Other types of walls
 * should inherit this.
 */

// foundstones need this
int query_is_wall() {
   return 1;
}

mapping query_shape() {
   int w, h, pos;
   if( shape ) return shape;
   shape = ([ ]);
   w = max(this_object()->query_tile_width(), 1);
   h = max(this_object()->query_tile_height(), 1);
   foreach( pos : query_spots() )
      shape += SHAPE_OFFSET( SHAPE_BOX(w, h), SMAKE_C(CX(pos), CY(pos), CZ(pos)) );
   return shape;
}

/// Hack to make building adjacent to things possible.
mapping query_border() {
   if( environment() && environment()->query_is_site() ) return query_shape();
   return ::query_border();
}

mapping query_legal_layers() {
   return FLOOR_CHARS - ([ LAYER_ROUGH + '0' ]);
}

void add_spot( int pos ) {
   ::add_spot(pos);
   shape = border = 0;
}

void remove_spot( int pos ) {
   ::remove_spot(pos);
   shape = border = 0;
}

int query_is_building() {
   return 1;
}

int on_raze() {
   int old_size, offpos;
   mapping spot_offs;

   spot_offs = ([
      SMAKE_C(0,0,0),
      SMAKE_C(0,1,0),
      SMAKE_C(1,0,0),
      SMAKE_C(0,-1,0),
      SMAKE_C(-1,0,0) ]);

   old_size = sizeof(query_spots());
   foreach( offpos : spot_offs ) {
      remove_spot(OFFSET_C(this_player()->query_coord(), offpos));
      if( sizeof(query_spots()) < old_size ) {
         this_player()->msg_local( "~CACT~Name ~verbraze a patch of " + query_specific() + "~CDEF" );
         environment()->clear_map();
         if( sizeof(query_spots()) == 0 )
            destruct(this_object());
         return 1;
      }
   }
   return 0;
}

// Inherited by everything (even things you might not expect, like
// roads...), but not currently a valid wall type on its own.

int get_mask( int point, mapping wallmap ) {
   int mask, w = query_tile_width(), h = query_tile_height();

   mask = 0;
   if( member(wallmap, MAKE_C(CX(point)+w, CY(point), CZ(point))) ||
      (CX(point) + w + 1 >= environment()->query_map_xdim()) )
      mask |= 0x1;
   if( member(wallmap, MAKE_C(CX(point), CY(point)-h, CZ(point))) ||
      (CY(point) < h + 1) )
      mask |= 0x2;
   if( member(wallmap, MAKE_C(CX(point)-w, CY(point), CZ(point))) ||
      (CX(point) < w + 1) )
      mask |= 0x4;
   if( member(wallmap, MAKE_C(CX(point), CY(point)+h, CZ(point))) ||
      (CY(point) + h + 1 >= environment()->query_map_ydim()) )
      mask |= 0x8;

   return mask;
}

// A simple direction clause for where to build this chunk of wall/road.
// Fails if it's off the map or on non-walkable ground.
int check_direction( int dir ) {
   int pos;
   int tile;
   int ix, iy, nx, ny;
   mapping walkable;

   nx = query_tile_width();
   ny = query_tile_height();

   if( !dir ) dir = SMAKE_C(0,0,0);
   dir = SMAKE_C(SCX(dir) * nx, SCY(dir) * ny, 0);
   pos = OFFSET_C(this_player()->query_coord(), dir);
   // Snap to grid...
   pos = MAKE_C((CX(pos)-1)/nx*nx+1, (CY(pos)-1)/ny*ny+1,0);

   walkable = FLOOR_CHARS;

   for( iy = 0; iy < ny; iy++ )
   for( ix = 0; ix < nx; ix++ ) {
      tile = environment(this_player())->get_tiletype(CX(pos)+ix, CY(pos)+iy);
      if( !tile || !member(FLOOR_CHARS, tile) ) {
         msg( "You have to build in empty spaces." );
         return -1;
      }
   }

   add_spot( pos );
   return 0;
}

void on_build() {
   object ob;

   foreach( ob: all_inventory(environment()) - ({ this_object() }) )
   if( load_name() == load_name(ob) ) {
      int ispot;
      foreach( ispot : query_spots() )
        ob->add_spot(ispot);
      destruct(this_object());
      return;
   }
}

// Ugly starfield wall. Override this for a prettier one.
string *query_wall_tiles() {
   string onetile;
   string *all_tiles;
   int i;

   onetile = tab( "*", query_tile_width() * query_tile_height() );
   all_tiles = allocate(16);
   for( i = 0; i < 16; i++ ) all_tiles[i] = onetile;
   return all_tiles;
}

int query_paint_color( int pos, int tile ) {
   return 0x87;
}

int query_paint_zbuf( int pos, int tile ) {
   return 0x87;
}

//   B
//  C A  mask pattern
//   D

void on_map_paint( object painter ) {
   int point, ix, iy;
   mapping wallmap;
   string *wall_tiles;

   wallmap = query_spots();
   wall_tiles = query_wall_tiles();

   foreach( point : wallmap ) {
      string shape_pattern;
      int ch, col, width, mask, itile;

      shape_pattern = wall_tiles[mask = get_mask(point, wallmap)];

      width = query_tile_width();
      itile = 0;
      for( iy = 0; iy < query_tile_height(); iy++ )
      for( ix = 0; ix < width; ix++ ) {
         ch = shape_pattern[itile];
         col = query_paint_color(itile, mask);
         painter->paint( ix + CX(point), iy + CY(point), ch, col, query_paint_zbuf(itile, mask) );
         itile++;
      }
   }
}
