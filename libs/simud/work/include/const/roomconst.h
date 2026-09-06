#ifndef _ROOMCONST_H_
#define _ROOMCONST_H_

// Typical usage for 4x3 area with 2 floors:
//
// ROOM_MAP( 4, 3, 2,
// "aabb"
// "aaab"
// "aabb"
//
// "cccd"
// "cccd"
// "ccce" )
#define ROOM_MAP( width, height, floors, grid ) \
{ \
   int ix, iy, iz; \
   string g; \
   g = grid; \
   if( !stringp(g) || strlen(g) != width * height * floors ) \
      raise_error("ROOM_MAP: Invalid map, or the sizing is wrong."); \
   resize_grid( width, height, floors ); \
   for( ix = 0; ix < width; ix++ ) for( iy = 0; iy < height; iy++ ) for( iz = 0; iz < floors; iz++ ) {\
   int icell = ix + iy * width + iz * width * height; \
   set_cell( ix, iy, iz, g[icell..icell] ); \
   } \
}

// Typical usage (for the above set of junk)
//
// ROOM_KEY( "a", "start", "The entrance hall", "A small, stone entrance hall, leading into the parlor." )
// ... and so on for "b" through "e".
#define ROOM_KEY( index, name, short, long ) \
{ \
   int iroom; \
   object ob; \
   iroom = query_room_index( index ); \
   if( iroom < 0 ) raise_error( "ROOM_KEY: No such room to set up: " + as_lpc(index) + " as " + as_lpc(name) ); \
   set_grid_value( iroom, name ); \
   ob = clone_object("/world/room"); \
   ob->set_name( name ); \
   ob->set_short( short ); \
   ob->set_long( long ); \
   ob->move( this_object() ); \
}

#endif
