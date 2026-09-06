#include <desc.h>
#include <scenedesc.h>
#include <object.h>
#include <shape.h>
#include <coord.h>
#include <spots.h>
#include <saveload.h>

/** This is an array of *file names* for objects that should be
 * cloned when you mine this rock. The first object in the file
 * has a 50% chance of getting cloned, the second object has a
 * 25% chance, the third object has a 12.5% chance, etc. If there
 * are any 'leftover' probabilities, they are added onto the first
 * object (so if there are two objects, it'll be 75/25; if there are
 * three, it'll be 62.5/25/12.5). Put objects that you want to
 * be more rare toward the end of the array that you pass in
 * -- generally, I expect the array to be some fixed set of resources
 * for a given area. Repeat entries in the array are allowed to
 * tweak probabilities. Zeroes are also allowed, and imply that
 * the mining failed.
 */
string *resource_types;

NAME( "rock" )
DISTANT( "a wall of rock" )
SPECIFIC( "the wall of rock" )
ALT_NAME( ({ "wall of rock" }) )
PHRASE( sizeof(query_spots())? "The walls show signs of digging." : 0 )

void on_map_paint( object painter ) {
   int ipos;

   foreach( ipos : query_spots() ) {
      painter->paint( query_x() + CX(ipos),
         query_y() + CY(ipos),
         '#',
         0x03,
         LAYER_WALL );
   }
}

void set_resource_types( string *x ) {
   resource_types = x;
}

string *query_resource_types() {
   return resource_types;
}

void add_block( int pos ) {
   int ix, iy;
   for( iy = 0; iy < 3; iy++ )
   for( ix = 0; ix < 5; ix++ )
      add_spot( pos + MAKE_C(ix, iy, 0) );

   if( environment() ) environment()->clear_map();
}

string destructor( object ob ) {
   if( environment() ) environment()->clear_map();
   return ::destructor(ob);
}

int query_is_diggable() {
   return 1;
}

string query_action_name() {
   return "Dig";
}

/// Dig in the direction given in \a param, offsetting the player.
int on_dig( int param ) {
   string *res;
   int i, pos;
   object *picks;

   if( !param ) return 0; // Doesn't apply

   picks = filter(all_inventory(this_player()), (: ($1->query_held() && HAS_ASPECT($1, C_PICKAXE)) :));

   if ( !sizeof( picks )) {
      msg("You need to be holding a pickaxe.");
      return 0;
   }

   pos = OFFSET_C(this_player()->query_coord(), param);

   // Hmm ... this'll break horribly if there are multiple
   // diggable things in the room, but I can't think of
   // a good solution right now, since validity checking has
   // to be procrastinated.
   if( !query_has_spot(pos) ) {
      msg("Digging that direction didn't work.");
      return 0; // Action disappears if you moved.
   }

   this_player()->set_coord(pos);
   this_object()->remove_spot(pos);
   environment(this_player())->clear_map();
   this_player()->msg_local("~CACT~Name ~verbdig into the rock.~CDEF");
   this_player()->add_readiness( -500 );

   res = query_resource_types();
   if( res ) {
      object ob;
      i = 0;
      while( random(2) && i < sizeof(res) ) i++;
      if( i == sizeof(res) ) i = 0;
      if( !res[i] ) {
         msg("There was nothing interesting here.");
      }
      else {
         ob = clone_object( res[i] );
		 // TODO: chance of getting more of the item
		 // ob->set_quantity(result)
         ob->move( this_player() );
         set_target(ob);
         set_listener(this_player());
         msg("You get ~targ.");
		 // chance of digging a gem
		 if( random(200)-1 < 2*this_player()->query_skill("knowledge.geology") ) {
            string gemname = "/daemon/gemstone"->query_gem_name(ob->query_name());
            if( gemname ) {
               ob = clone_object( "/econ/gem/"+gemname );
               // TODO: chance of getting more than one in terribly rich veins
               ob->move(this_player());
               msg("You also got ~targ!");
            }
         }
      }
   }

   // this should probably be dependant on ob's durability,
   // but we don't have a stat for that
   picks[0]->add_condition(-1);

   if (sizeof(query_spots()) <= 0)
      destruct(this_object());

   return 1;
}
