#include <const.h>
#include <const/battconst.h>

/** This daemon has utility functions for calculating coordinates,
 * shapes, and other similar problems related to path-finding and
 * walking. Since coordinates are unsigned, and since the coordinate
 * shapes are deltas, it is desirable to have negative numbers in the
 * coordinates. This is done by placing the "origin" at (4096,4096,32).
 * To test a coordinate, add MAKE_C(4096,4096,32), offset it by the
 * relevant amount (the center of the shape's coordinate), and then
 * test against the mapping given here.
 */

/** This shape contains a single point at the origin.
 */
mapping shape_point() {
   return ([ MAKE_C(4096, 4096, 32) ]);
}

/** This shape contains four cells centered directly around the origin plus
 * the origin itself. This is probably the most-used shape.
 */
mapping shape_adjacent() {
   return ([ MAKE_C(4096 - 1, 4096,     32),
             MAKE_C(4096,     4096 - 1, 32),
             MAKE_C(4096 + 1, 4096,     32),
             MAKE_C(4096,     4096 + 1, 32),
             MAKE_C(4096,     4096,     32) ]);
}

/** This shape has 8 cells around its center, forming a hollow square.
 */
mapping shape_square() {
   return ([ MAKE_C(4096 - 1, 4096 - 1, 32),
             MAKE_C(4096,     4096 - 1, 32),
             MAKE_C(4096 + 1, 4096 - 1, 32),
             MAKE_C(4096 - 1, 4096,     32),
             MAKE_C(4096 + 1, 4096,     32),
             MAKE_C(4096 - 1, 4096 + 1, 32),
             MAKE_C(4096,     4096 + 1, 32),
             MAKE_C(4096 + 1, 4096 + 1, 32) ]);
}

/// A filled-in box, \a width by \a height cells in dimension.
mapping shape_box( int width, int height ) {
   mapping box;
   int ix, iy;

   box = ([ ]);
   for( iy = height; iy--; )
   for( ix = width; ix--; )
      box += ([ MAKE_C(ix + 4096, iy + 4096, 32) ]);

   return box;
}

/** Offset a shape by origin, with the "zero" point being at
 * (4096, 4096, 32). If you offset by that much, the shape is
 * unchanged. So an origin of 4095, 4096, 32 would offset x by
 * -1, etc. The offset shape is returned.
 */
mapping shape_offset( mapping shape, int origin ) {
   mapping offs;
   int p;

   offs = ([ ]);
   foreach( p : shape )
      offs += ([ MAKE_C(CX(p) + CX(origin) - 4096,
                        CY(p) + CY(origin) - 4096,
                        CZ(p) + CZ(origin) - 32) ]);

   return offs;
}

int find_closest( mapping target_area, int target_coord, int unclipped, object actor ) {
   int closest, curr_node, closest_dist, curr_dist, player_coord;

   closest = 0;
   if( !actor ) actor = this_player();
   player_coord = actor->query_coord();

   foreach( curr_node : target_area ) {
      if( !unclipped && curr_node != player_coord + MAKE_C(4096,4096,32) &&
         !member(FLOOR_CHARS,environment(actor)->get_tiletype(CX(curr_node)+CX(target_coord)-4096, CY(curr_node)+CY(target_coord)-4096))  ) {
//         write(MAKE_CSTR(curr_node) + " is " + environment(actor)->get_tiletype(CX(curr_node)-4096, CY(curr_node)-4096) +
//         ", no can do. (PC is "+MAKE_CSTR(player_coord)+")\n");
         continue;
      }
      curr_dist = abs(CX(curr_node) + CX(target_coord) - (CX(player_coord) + 4096)) +
                  abs(CY(curr_node) + CY(target_coord) - (CY(player_coord) + 4096)) +
                  abs(CZ(curr_node) + CZ(target_coord) - (CZ(player_coord) + 32));
//      msg("curr_dist is "+curr_dist);
      if( !closest || curr_dist < closest_dist ) {
         closest = curr_node;
         closest_dist = curr_dist;
      }
   }
   if( !closest ) return -1;

   return MAKE_C(CX(target_coord) + CX(closest) - 4096,
                 CY(target_coord) + CY(closest) - 4096,
                 CZ(target_coord) + CZ(closest) - 32);
}

int query_adjacent( int pos, object ob ) {
   debug(as_string(previous_object()) + " called query_adjacent(), which is broken, don't use it!");
   mapping edge;

   if( !environment(ob)->query_zbuf() ) return 1; // Always adjacent if no map!
   if( abs(ob->query_x() - CX(pos)) <= 1 && abs(ob->query_y()-CY(pos)) <= 1 )
      return 1;
   edge = ob->query_border();
   if( mappingp(edge) && member(edge, pos) ) return 1;
   return 0;
}

/// \return a random coordinate adjacent to \param ob
int query_random_adjacent( object ob ) {
   object r = environment(ob);
   mapping adj;
   if (ob->query_has_map() || !r || !r->query_has_map())
      return -1;
   adj = shape_offset(shape_adjacent(), ob->query_coord());
   adj -= ([ ob->query_coord() ]);
   //debug(as_lpc(adj));
   while (sizeof(adj)) {
      int c = m_indices(adj)[random(sizeof(adj))];
      if (r->get_empty(CX(c), CY(c), CZ(c)))
         return c;
      else
         adj -= ([ c ]);
   }
   return -1;
}

/// \return the manhattan distance between \param one and \param two
int query_distance( object one, object two ) {
   int x1 = one->query_x();
   int y1 = one->query_y();
   int x2 = two->query_x();
   int y2 = two->query_y();
   int dx = abs( x1 - x2 );
   int dy = abs( y1 - y2 );
   return dx + dy;
}

/** Sets up a walking action. There's a manual page which explains this in more
 * detail.
 *
 * \param target_area A shape in a mapping; use the shape_ functions in this
 * file, or build your own. If 0, then the walking step is skipped and the
 * action is immediately performed.
 * \param target_coord an offset coordinate for the given shape; generally the
 * coordinate of the object you're trying to reach. If target_coord is -1,
 * then the walk action calculation is put off until the action reaches
 * the front of the queue, at which point it becomes the player's current
 * target.
 * \param arrive_action An action (array of length 5). Read the manual page
 * on actions for more information on how to build one.
 * \param unclipped (Optional) Either true or false (false being the default).
 * The unclipped option allows you to find a path to areas that lie outside
 * of the room boundaries, such as finding a path to an exit. Usually you
 * want clipping turned on, as it makes sure that the destination is always
 * in a valid place. Having clipping turned off is faster, unless
 * the amount that would be clipped is very large.
 * \param prepush (Optional) An obscure little flag that, if set, is used to make
 * init_walk_action push the action onto the front of the queue, instead of
 * the back. This is used for combat actions with unspecified targets, which
 * are a strangely handled case.
 */
varargs void init_walk_action( mapping target_area, int target_coord, mixed arrive_action, int unclipped, int prepush, object actor ) {
   int dest_coord;

   if( !actor ) actor = this_player();

   // Interesting special case for combat walking -- coordinate means 'current target'.
   // This will evaluate when the on_action actually triggers.
   if( target_coord == -1 ) {
      actor->push_action(
         ({ 700, this_object(), actor, ST_STANDING, ({ target_area, -1, arrive_action, -1, unclipped }) }) );
      return;
   }

   // Early exit case for invalid shapes and invaild room maps.
   if( !target_area || !environment(actor)->query_zbuf() ) {
      if( prepush )
         actor->set_action( -1, arrive_action );
      else
         actor->push_action( arrive_action );
      return;
   }

   // Early exit for "already there" -- saves some grief.
   foreach( dest_coord : target_area ) {
//      write("Local check: dest_coord="+MAKE_CSTR(dest_coord)+", tp()+targ="+MAKE_CSTR(actor->query_coord()+target_coord)+"\n");
      if( CX(dest_coord) + CX(target_coord) - 4096 == actor->query_x() &&
         CY(dest_coord) + CY(target_coord) - 4096 == actor->query_y() ) {
         if( prepush )
            actor->set_action( -1, arrive_action );
         else
            actor->push_action( arrive_action );
         actor->pop_action();
         return;
      }
   }

   // Make sure they're not entangled or grappling
   if( single_present("grapple_ob", actor) ) {
      msg("You can't walk while grappled!");
      return;
   } else if ( sizeof(actor->query_env_var("grappling")) ) {
      msg("You can't walk while grappling!");
      return;
   } else if ( single_present("entangle_ob", actor) ) {
      msg("You are being prevented from walking right now.");
      return;
   }

   // First off, find where we're walking to.
//   msg("Shape to seek to is: "+as_lpc(map(environment(actor)->get_empty_shape(target_coord, target_area), (: MAKE_CSTR($1) :))));
//   msg("target_coord is " + MAKE_CSTR(target_coord) + ", target_shape is " + as_lpc(map(target_area, (: MAKE_CSTR($1) :))) );
   if( !unclipped )
      target_area = environment(actor)->get_empty_shape( target_coord, target_area );
//   msg("target_area is " + as_lpc(map(target_area, (: MAKE_CSTR($1) :))) );
   dest_coord = find_closest( target_area, target_coord, unclipped, actor );

   if( dest_coord == -1 ) {
      msg("You can't get there from here.");
      return;
   }

   // Find the triply nested data-structure! It's like hunting gold fish
   // with a fork, isn't it?
   if( prepush )
      actor->set_action( -1,
         ({ 700,
         this_object(),
         actor,
         ST_STANDING,
         ({ target_area, dest_coord, arrive_action, target_coord, unclipped })
         }) );
   else
      actor->push_action(
         ({ 700,
         this_object(),
         actor,
         ST_STANDING,
         ({ target_area, dest_coord, arrive_action, target_coord, unclipped })
         }) );
}

void on_action( object target, mixed param ) {
   object env, iob;
   int cost, step, nstep, xend, yend, oldpos, abort, haspath;

   // Delayed processing for this odd case.
   if( param[1] == -1 && param[3] == -1 ) {
      if( !target->query_target() ) // Not fighting anything, action is discarded.
         return;
      init_walk_action( param[0], target->query_target()->query_coord(), param[2], param[4], 1 );
      return;
   }

   env = environment(target);
   if( !env ) return;
   if( !env->query_has_map() ) {
      // Map disappeared somehow. This is almost never going to happen, but shrug :-)
      target->set_action( -1, param[2] );
      // Allows for instantaneous events if readiness is high enough.
      target->pop_action();
      return;
   }
   if( !pointerp(param) ) {
      debug("Bug in /daemon/walk, param not an array -- it's " + as_lpc(param));
   }

   haspath = 0;
   while( !haspath && sizeof(param[0]) ) {
      xend = CX(param[1]);
      yend = CY(param[1]);
      haspath = env->query_can_reach(
         target->query_x(),
         target->query_y(),
         xend,
         yend );
      if( !haspath ) {
         mapping old_coord;
         int ix, iy;
         if( this_player()->query_is_player() )
            debug(as_string(this_player()) + ": Finding path from " + target->query_x() + ", " + target->query_y() + " to " + xend + ", " + yend + " fails.", "map" );
         // Yuck, have to reverse the mangling to remove it from the list.
         old_coord = ([ ]);
         for( iy = -(sizeof(param[0]) / 4); iy <= sizeof(param[0])/4; iy++ )
            old_coord += ([
               MAKE_C( CX(param[1]) - CX(param[3]) + 4096,
               CY(param[1]) - CY(param[3]) + 4096 + iy,
               CZ(param[1]) - CZ(param[3]) + 32 ),
            ]);
         for( ix = -(sizeof(param[0]) / 4); ix <= sizeof(param[0])/4; ix++ )
            old_coord += ([
               MAKE_C( CX(param[1]) - CX(param[3]) + 4096 + ix,
               CY(param[1]) - CY(param[3]) + 4096,
               CZ(param[1]) - CZ(param[3]) + 32 ),
            ]);
         param[0] -= old_coord;
         param[1] = find_closest( param[0], param[3], param[4], this_player() );
         if( param[1] == -1 ) break;
      }
   }

   if( !haspath ) {
      msg( "The path is blocked." );
      return;
   }

   // Move to end of path.
   oldpos = target->query_coord();
   nstep = abs( target->query_x() - xend ) + abs( target->query_y() - yend );
   target->set_x( xend );
   target->set_y( yend );
   abort = 0;
   if( environment(target) )
   foreach( iob: all_inventory(environment(target)) )
      abort |= iob->on_walk( target, oldpos, MAKE_C(xend, yend, 0) );
   cost = 8 + (target->query_combat_mode() * 12);
   target->add_readiness( -cost * nstep );

   if( abort ) return;

   target->set_action( -1, param[2] );
   // Allow it to happen now if ready
   target->pop_action();
}

string query_action_name( mixed *param ) {
   if( !pointerp(param) || !pointerp(param[B_PARAM]) || !pointerp(param[B_PARAM][2]) ||
      !param[B_PARAM][2][B_FNAME] ) return "(Unknown walk action)";
   return param[B_PARAM][2][B_FNAME]->query_action_name(param[B_PARAM][2]);
}
