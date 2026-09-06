#include <object.h>
#include <scenedesc.h>
#include <desc.h>
#include <shape.h>
#include <coord.h>
#include <inven.h>
#include <const.h>
#include <container.h>

int progress; // A counter for building progress. When zero, building has not started yet.
int construction_delay = 2; // number of seconds per % of building

object query_building();
object *get_blocking_objects();

DISTANT( "a construction site" )
SPECIFIC( "the construction site" )
PLURAL( "construction sites" )
ALT_NAME( ({ "construction site", "site" }) )
ALT_PLURAL( ({ "sites" }) )
TASTE( "They were digging a new foundation in Manhattan." )

/** The construction site needs to keep track of all the information about
 * the building being built. To make a new building type buildable, you need
 * to inherit /econ/site and modify it to match your new building type.
 *
 * Things that must be checked here:
 *
 *  - Is it possible to build here? There needs to be a sufficiently large
 *    piece of clear ground.
 *  - Is there anything in the way?
 */

void create() {
   ::create();
/* OBJEDIT { */
   set_position( "here" );
   set_name( "construction" );
/* } OBJEDIT */
   call_out("construction_tick", construction_delay ); // Resume construction, if in progress.
}

// Sites eventually disappear.
int site_decay = 0;

void reset() {
   site_decay++;
   if( site_decay > 30 ) {
      destruct(query_building());
      destruct(this_object());
   }
}

/*
int on_push( int dir ) {
   if( !dir ) {
      msg( "Which way do you want to move the site?" );
      return 1;
   }
   set_coord( OFFSET_C(query_coord(), dir) );
   msg( "Site moved." );
   return 1;
}
*/

void set_coord( int pos ) {
   object ob;
   if( ob = query_building() )
      ob->set_coord(pos);
}

int query_is_site() {
   return 1;
}

/** Ugly hack! This is so that objects will use their own coordinates
 * instead of relying on their environment for coordinates. I don't
 * *really* have a map, so this could cause ugly problems later.
 */
int query_has_map() {
   return previous_object() == query_building();
}

int query_coord() {
   object ob;
   if( ob = query_building() )
      return ob->query_coord();
   else
      return 0;
}

string query_look() {
   object *contents;
   string desc;

   contents = all_inventory() - ({ query_building() });
   desc = "This is the construction site for " + query_building()->query_distant() + ".";
   if( sizeof(contents) )
      //desc += " Right now, " + comma_list(map(contents, (: $1->query_distant() :))) + " are lying around on the site, ready for the building to begin.";
      desc += " Right now, " + inventory_string(contents) + " are lying around on the site, ready for the building to begin.";
   else if( progress )
      desc += " The site is currently under construction, and is " + progress + "% complete.";
   else
      desc += " A few sticks and scratches are all that mark it out at the moment, since none of the building materials have been put here yet.";
   if( sizeof(contents = get_blocking_objects()) )
      desc += " The site is currently obstructed by " + inventory_string(contents) + ".";
   return desc;
}

int query_construction_delay() { return construction_delay; }
void set_construction_delay(int x) {
  //debug("construction_delay = "+x);
  construction_delay = x;
}
void add_construction_delay(int x) {
  set_construction_delay( query_construction_delay() + x );
}

int query_progress() {
   return progress;
}

void set_progress( int x ) {
   progress = x;
}

void add_progress( int x ) {
   progress += x;
}

/** \return The default shape for a building, which is a 5x3 box.
 * For large or oddly shaped buildings, you should override this.
 */
mapping query_shape() {
   object ob = query_building();
   if( !ob ) return ([ ]);
   return ob->query_shape();
}

mapping query_border() {
   object ob = query_building();
   if( !ob ) return ([ ]);
   return ob->query_border();
}

/** The area which must be clear for this building's site to be constructed.
 * This should include some blank area around the building to make sure that
 * pathing is preserved without blocking anything off. The default value for
 * this is usually fine.
 */
mapping query_build_shape() {
   return query_shape() + query_border();
}

object *get_blocking_objects() {
   object *block_list;

   if( !environment() ) return ({ });
   block_list = environment()->get_region( query_coord(), query_shape() );
   if( !block_list ) return ({ });
   block_list -= ({ this_object() });
   return filter( block_list, (: !$1->query_is_landscape() && !$1->query_invis() :) );
}

mapping get_zbuf_block() {
   mapping shape_res, border_res, layers;
   object env, bldg;

   env = environment();

   bldg = query_building();
   this_object()->move(find_object("/obj/void"));
   shape_res = env->get_empty_shape( query_coord(), query_shape(), 1, bldg->query_legal_layers() );
   layers = bldg->query_legal_border_layers();
   if( !layers ) layers = bldg->query_legal_layers();
   border_res = env->get_empty_shape( query_coord(), query_border(), 1, layers );
   this_object()->move(env);
   if( !mappingp(shape_res) ) shape_res = ([ ]);
   if( !mappingp(border_res) ) border_res = ([ ]);
   return query_build_shape() - (shape_res + border_res);
}

void on_paint( object painter ) {
   int ipos;

   if( progress == 0 ) {
      object ob;
      mapping blocked_area;
      int layer;

      blocked_area = ([ ]);
      foreach( ob: filter(get_blocking_objects(), (:!$1->query_is_player():)) ) {
         mapping shape;
         int pos;

         if( ob->query_is_living() ) continue;
         shape = ob->query_shape();
         if( !shape ) shape = ([ MAKE_C( 4096, 4096, 32 ) ]);
         pos = ob->query_coord();
         blocked_area += SHAPE_OFFSET( shape, pos + MAKE_C(4096, 4096, 32));
      }
      blocked_area += get_zbuf_block();
      // Draw building
      layer = query_building()->query_site_layer();
      if( !layer ) layer = LAYER_BRIDGE;
      foreach( ipos : SHAPE_OFFSET(query_shape(), query_coord() + MAKE_C(4096,4096,32)) ) {
         if( member(blocked_area, ipos) )
            painter->paint( CX(ipos)-4096, CY(ipos)-4096, 'X', 9, LAYER_OVERLAY );
         else
            painter->paint( CX(ipos)-4096, CY(ipos)-4096, '#', 10, layer );
      }
      // Draw border
      foreach( ipos : SHAPE_OFFSET(query_border(), query_coord() + MAKE_C(4096,4096,32)) ) {
         if( member(blocked_area, ipos) )
            painter->paint( CX(ipos)-4096, CY(ipos)-4096, 'X', 9, LAYER_OVERLAY );
         else
            painter->paint( CX(ipos)-4096, CY(ipos)-4096, '#', 6, layer );
      }
   }
   else {
      mapping mshape;
      mshape = query_shape();

      foreach( ipos : SHAPE_OFFSET(mshape, query_coord() + MAKE_C(4096,4096,32)) )
         painter->paint( CX(ipos)-4096, CY(ipos)-4096, ':', 3, LAYER_INVALID );

      if( member(mshape,SMAKE_C(1,1,0)) && member(mshape,SMAKE_C(2,1,0)) && member(mshape,SMAKE_C(3,1,0)) ) {
         painter->paint( query_x() + 1, query_y() + 1, '%', 15, LAYER_INVALID );
         painter->paint( query_x() + 2, query_y() + 1, '0' + progress / 10, 15, LAYER_INVALID );
         painter->paint( query_x() + 3, query_y() + 1, '0' + progress % 10, 15, LAYER_INVALID );
      }
   }
}

object query_building() {
   object ob;
   foreach( ob : all_inventory() )
      if(ob->query_is_building()) return ob;
   return 0;
}

void finish_construction() {
   object site = query_building(), *env_list;
   string buildstr = site->query_distant();
   int ienv;

   site->move(environment());
   site->on_build();
   env_list = all_inventory(environment());
   for( ienv = sizeof(env_list); ienv--; ) {
      if( env_list[ienv] != site && program_name(env_list[ienv]) == program_name(site) ) {
         env_list[ienv]->move(environment());
      }
      env_list[ienv]->on_built( site );
   }
   environment()->clear_map();
   msg_room( environment(), "~CACTConstruction of "+buildstr+" is complete.~CDEF" );

   destruct(this_object());
}

void construction_tick() {
   if( progress == 0 ) return;
      progress++;
   if( progress < 100 )
      call_out( "construction_tick", construction_delay);
   else
      finish_construction();
}

mapping skills;
mapping query_skills() { return skills; }
void set_skills(mapping m) { skills = m; }

void start_construction() {
   object ob, who;
   string skill, owner;
   int mod;
   if( progress > 0 ) return;
   progress = 1;
   environment()->clear_map();
   foreach( ob: all_inventory() ) {
      if( !ob->query_is_building() ) {
         ob->move(environment());
         ob->set_coord(query_coord());
         ob->validate_position();
      }
   }
   // final skill checks
   owner = query_building()->query_owner();      // roads, signs, etc. don't have an owner
   if ( owner )
   who = find_player(owner);
   if (!who) {
      // assume if the owner is not online that they failed all checks
      mod = sizeof(skills);
   } else {
      mod = 0;
      foreach( skill : skills ) {
         if (!who->skill_check(skill, skills[skill]))
            mod++;
      }
   }
   mod = (int)floor( 100.0 * query_construction_delay() * mod / max(sizeof(skills), 1) / 200.0 );
   add_construction_delay(mod);

   call_out("construction_tick", 1);
}

void on_insert(object ob) {
   if( progress ) return;
   call_out( "check_start_construction", 8 );
}

//In here after my update to the raze verb --Snarky 1-4-06
int query_is_building() {
   return 1;
}

// anyone can raze a construction site
int query_is_razable( object who ) {
   return 1;
}

int on_raze() {
   object inv;

   if( query_progress() ) return 0;
   set_target( this_object() );
   if( sizeof(all_inventory() - ({ query_building() })) != 0 ) {
      msg( "You can't raze a site with materials already in it. Take them out first." );
      return 1;
   }
   this_player()->msg_local( "~CACT~Name ~verbraze ~targ.~CDEF" );
   destruct( query_building() );
   destruct( this_object() );
   return 1;
}

void check_start_construction() {
   object *blist;

   remove_call_out( "check_start_construction" );
   /* Removed this_player exemption to avoid getting stuck in a solid site */
   if( sizeof(blist = get_blocking_objects() ) ) {
      msg_room( environment(), "Contruction cannot start because the site is blocked by " + inventory_string(blist) + "." );
      call_out( "check_start_construction", 20 );
      return;
   }
   if( sizeof(get_zbuf_block()) ) {
      set_actor( query_building() );
      msg_room( environment(), "~Name can't be built there, because there's not enough room. It may be too close to the room edge, a mountain, rough terrain, or something similar. The site has been removed.");
      destruct(query_building());
      destruct(this_object());
      return;
   }
   int material_count;
   if( material_count = "/daemon/recipe"->check_resources(query_building()->query_name(), all_inventory(), query_building()) ) {
      object who = find_player( query_building()->query_owner() );
      string skill;
      if( who )
      foreach( skill : skills )
         who->practice_skill( skill, material_count / 25 );
      set_actor( query_building() );
      msg_room( environment(), "~CACTConstruction has started for ~name.~CDEF" );
      start_construction();
   }
}
