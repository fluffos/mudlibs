/** This exit type is for outdoor (outer wall) exits that
 * cannot be closed (although they could be blocked if you stand
 * in front of them...).
 *
 * Notes: An unusual property of these exits is that they can be
 * set to 'invisible' -- they do this automatically when exit_shape
 * is queried, and the room type is a maproom, and there are no points
 * in the exit shape. An invisible exit gets itself off the exit list.
 */

#include <const.h>
#include <const/battconst.h>
inherit "/world/exit/twoway";

nosave int invis = -1;

/** The pattern for drawing the exit; actually on top of the walls.
 */
mapping exit_shape() {
   int ix, iy, xdim, ydim, env_pos, pass_flag;
   string map, dest;
   mapping adj, shape = ([ ]);
   object obdest, env = environment();

   invis = 0;

   if( env->query_map_room() ) {
      int i, delta, len, pos, cx, cy, cx2, cy2;

      switch( query_dir() ) {
      case "west":
         cx = 0;
         cy = 0;
         cx2 = -1;
         cy2 = 0;
         pos = MAKE_C(4096,4097,32);
         delta=MAKE_C(0,1,0);
         len = OVERWORLD_HEIGHT * 3;
         break;
      case "east":
         cx = OVERWORLD_WIDTH - 1;
         cy = 0;
         cx2 = OVERWORLD_WIDTH;
         cy2 = 0;
         pos = MAKE_C(OVERWORLD_WIDTH*5+4097,4097,32);
         delta=MAKE_C(0,1,0);
         len = OVERWORLD_HEIGHT * 3;
         break;
      case "south":
         cx = 0;
         cy = OVERWORLD_HEIGHT - 1;
         cx2 = 0;
         cy2 = OVERWORLD_HEIGHT;
         pos = MAKE_C(4097,OVERWORLD_HEIGHT*3+4097,32);
         delta=MAKE_C(1,0,0);
         len = OVERWORLD_WIDTH * 5;
         break;
      case "north":
         cx = 0;
         cy = 0;
         cx2 = 0;
         cy2 = -1;
         pos = MAKE_C(4097,4096,32);
         delta=MAKE_C(1,0,0);
         len = OVERWORLD_WIDTH * 5;
         break;
      default:
         return ([ ]);
      }
      shape = ([ ]);
      pass_flag = environment()->query_passable(cx, cy) && environment()->query_passable(cx2, cy2);
      for( i = 0; i < len; i++ ) {
         if( pass_flag )
            shape += ([ pos ]);
         pos += delta;
         if( CX(delta) && (i+1)%5 == 0 ) {
            cx += CX(delta);
            cx2 += CX(delta);
            pass_flag = environment()->query_passable(cx, cy) && environment()->query_passable(cx2, cy2);
         }
         if( CY(delta) && (i+1)%3 == 0 ) {
            cy += CY(delta);
            cy2 += CY(delta);
            pass_flag = environment()->query_passable(cx, cy) && environment()->query_passable(cx2, cy2);
         }
      }
      if( sizeof(shape) == 0 ) invis = 1;
      return shape;
   }

   map = env->query_small_map();
   xdim = env->query_small_map_xdim();
   ydim = env->query_small_map_ydim();
   if( !map ) return 0;
      // Check that things are set up correctly.

   obdest = get_destination();
   if( !obdest ) return 0;
   dest = obdest->query_name();
   if( !dest ) return 0;

   env_pos = SMAKE_C(0, 0, 0);
   shape = ([ ]);

   for( iy = 0; iy < ydim; iy++ )
   for( ix = 0; ix < xdim; ix++ ) {
      if( map[ix + iy * xdim] == '\255' ) continue;
      adj = env->query_adjacent_rooms( ix + iy * xdim );
//      write("obdest="+as_string(obdest)+", ix="+ix+", iy="+iy+", adj="+as_lpc(adj)+"\n");
      if( !adj ) continue;
      if( adj[0] == obdest )
      shape += ([
         MAKE_C(ix*5+6,iy*3+1,0) + env_pos,
         MAKE_C(ix*5+6,iy*3+2,0) + env_pos,
         MAKE_C(ix*5+6,iy*3+3,0) + env_pos
      ]);
      if( adj[1] == obdest )
      shape += ([
         MAKE_C(ix*5+1,iy*3,0) + env_pos,
         MAKE_C(ix*5+2,iy*3,0) + env_pos,
         MAKE_C(ix*5+3,iy*3,0) + env_pos,
         MAKE_C(ix*5+4,iy*3,0) + env_pos,
         MAKE_C(ix*5+5,iy*3,0) + env_pos
      ]);
      if( adj[2] == obdest )
      shape += ([
         MAKE_C(ix*5,iy*3+1,0) + env_pos,
         MAKE_C(ix*5,iy*3+2,0) + env_pos,
         MAKE_C(ix*5,iy*3+3,0) + env_pos
      ]);
      if( adj[3] == obdest )
      shape += ([
         MAKE_C(ix*5+1,iy*3+4,0) + env_pos,
         MAKE_C(ix*5+2,iy*3+4,0) + env_pos,
         MAKE_C(ix*5+3,iy*3+4,0) + env_pos,
         MAKE_C(ix*5+4,iy*3+4,0) + env_pos,
         MAKE_C(ix*5+5,iy*3+4,0) + env_pos
      ]);
   }

   return shape;
}

int query_invis() {
   if( invis == -1 )
      exit_shape();
   return invis;
}

void set_link( string x ) {
   ::set_link( x );
   environment()->clear_map();
}

/** Draw the exit. If you are writing your own exit type, you
 * should override this function
 */
void on_map_paint( object painter ) {
   int p;
   mapping draw_shape;


   draw_shape = exit_shape();
   if( !draw_shape ) return;
   foreach( p : draw_shape )
      painter->paint( CX(p)-4096, CY(p)-4096, (CX(p)+CY(p))%2==0?' ':'.', 8, LAYER_INVALID );
}

/** This actually causes the player to pass through the exit.
 * \a m is the mapping with the exit information; if you want information
 * about the player or the room, use this_player() and environment(this_player())
 * respectively. An error message is printed if the exit fails.
 *
 * A fair amount of error checking has already been done on \a m, so the core
 * information is most likely valid.
 *
 * \return True on success, false on failure.
 */
int exit_action() {
   string dir;
   object dest_room;
   mapping walk_dest;

   if( invis ) return 0;

   dir = query_dir();
   dest_room = get_destination();
   if( !dest_room ) {
      msg("Exit exists, but the destination does not exist. Report a bug.");
      return 0;
   }
   walk_dest = exit_shape();
   // Note that "unclipped" is set, since exits are outside of room boundaries.
   if( sizeof(walk_dest) )
      WALK_DAEMON->init_walk_action( exit_shape(), 0,
         ({ 0, this_object(), this_player(), ST_STANDING, 0 }), 1 );
   else
      this_object()->on_action(0);
   return 1;
}

/** Walk through an exit after arriving at it. The \a param contains the
 * exit information; if not, this action was incorrectly set up.
 */
void on_action( object target ) {
   object src_room, dest_room;
   string *messages;
   mapping m;
   int dx, dy;

   // Something else already moved me; quietly abort.
   if( environment(this_player()) != environment() )
      return;

   dest_room = get_destination();

   src_room = environment(this_player());
   // Adjust player room coordinates so they appear to have
   // "just come through" the given exit.
   // Special case area boundaries.
   if( environment(src_room) != environment(dest_room) ) {
      dx = dy = 0;
      switch( query_dir() ) {
         case "north": /*debug( query_dir(), "map");*/ dy = dest_room->query_map_ydim() - 2; break;
         case "south": /*debug( query_dir(), "map");*/ dy = -src_room->query_map_ydim() + 2; break;
         case "west": /*debug( query_dir(), "map");*/ dx = dest_room->query_map_xdim() - 2; break;
         case "east": /*debug( query_dir(), "map");*/ dx = -dest_room->query_map_xdim() + 2; break;
      }
      dx += this_player()->query_x();
      dy += this_player()->query_y();
//      debug( "dx="+dx+", dy="+dy+" (player is at "+this_player()->query_x()+", "+this_player()->query_y()+")", "map");
   }
   else {
      dx = this_player()->query_x() + (src_room->query_x() - dest_room->query_x()) * 5;
      dy = this_player()->query_y() + (src_room->query_y() - dest_room->query_y()) * 3;
   }

   this_player()->move_player( dest_room, "leave "+this_player()->query_movement_type()+"ing", query_dir() );

   if( dest_room->query_valid_square(dx, dy) ) {
      int closest;

      closest = dest_room->get_empty( dx, dy );
      this_player()->set_coord( closest );
   }

   // Don't waste time on room descs for NPC's, unless they're possessed.
   if( this_player()->query_is_player() || this_player()->query_possessor() )
      "/bin/look"->main();

}

string query_action_name( mixed *param ) {
   mixed m;

   if( query_dir() )
      return "Go " + query_dir();
   else
      return "Go";
}

mapping query_aspects() {
   if( invis ) return ([ ]);
   return ::query_aspects();
}

int query_is_exit() {
   return !query_invis();
}
