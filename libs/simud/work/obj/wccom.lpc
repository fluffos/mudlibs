#include <object.h>

/* This object was created on September 17, 2006 by Acius.
 * The goal is to create an object which handles all the
 * 'magic' commands sent by the Walraven client -- stuff like
 * querying my current hit points and so on. A lot of these sorts
 * of things will actually be pushed from the server, but sometimes
 * the client may want to ask for things, and having it be
 * explicitly available through commands is good testing code.
 */

string query_name() { return "_wccom"; }
object id( string s ) { return s == "_wccom" ? this_object() : 0; }

int print_full_overlay();
int print_map();

void on_suspend() {
   destruct( this_object() );
}

void init() {
   ::init();
   if( !environment()->query_is_living() )
      return;
   environment()->set_client_code( "wclient" );
   add_action( "print_map", "_wmap" );
   add_action( "print_full_overlay", "_wfovr" );
   add_action( "walk_sequence", "_ww" );

   print_map();
   print_full_overlay();
}

void on_move( object src ) {
   if( src ) src->set_client_code( 0 );
}

int print_map() {
   string map = environment( environment() )->query_raw_map();
   if( !map )
      map = "0\n0\n";

   map = "map\n" + map;
   write( "\27W" + strlen(map) + "\n" + map );
   return print_full_overlay();
}

int print_full_overlay() {
   string overlay = environment( environment() )->query_full_overlay();
   if( !overlay ) overlay = "";

   overlay = "fovr\n" + overlay;
   write( "\27W" + strlen(overlay) + "\n" + overlay );
   return 1;
}

int walk_sequence( string where ) {
   mapping hotspots = ([]);
   object ob;

   foreach( ob : all_inventory(environment(environment())) ) {
      mapping spots = ob->query_hotspots();
      if( spots ) {
         int pos;
         foreach( pos : spots ) {
            hotspots[pos] = ob;
         }
      }
   }

   int x = environment()->query_x();
   int y = environment()->query_y();
   int some_update = 0;
   int newx, newy;
   object env = environment(environment());
   for( int i = 0; i < strlen(where); ++i ) {
      newx = x; newy = y;
      if( where[i] == 'n' ) newy--;
      if( where[i] == 's' ) newy++;
      if( where[i] == 'w' ) newx--;
      if( where[i] == 'e' ) newx++;
      if( env->query_path_cell(x,y) == env->query_path_cell(newx,newy) ) {
         x = newx;
         y = newy;
         some_update = 1;
         object hot_ob = hotspots[SMAKE_C(x,y,0)];
         if( hot_ob ) {
            environment()->set_coord( SMAKE_C(x,y,0) );
            hot_ob->on_hotspot( SMAKE_C(x,y,0) );
         }
      }
      else {
         // Bump! Do something on bumps maybe.
         object hot_ob = hotspots[SMAKE_C(newx,newy,0)];
         if( hot_ob ) {
            hot_ob->on_hotspot( SMAKE_C(newx,newy,0) );
         }
      }
   }
   if( some_update ) {
      environment()->set_coord( MAKE_C(x,y,0) );
   }
   return 1;
}
