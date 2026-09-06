#include <inven.h>
#include <coord.h>
#include <object.h>
#include <const.h>

int state;
nosave int crowded;

TASTE( "It tastes like roughage." )

mapping query_border();
int query_fertile();
int query_size();

create() {
   ::create();
   __FLIST -= ({ "_destructor_saveload" });
   state = 0;
}

string destructor( object ob ) {
   if( environment() ) environment()->clear_map();
   ::destructor();
   _destructor_saveload();
   return 0;
}

string query_name() {
   return "plant";
}

string query_specific() {
   return "the plant";
}

string query_distant() {
   return "a plant";
}

string query_plural() {
   return "plants";
}

string query_look() {
   return "It's just a plant.";
}

string query_taste() {
   return this_object()->query_default_taste();
}

string *query_alt_name() {
   return ({ });
}

string *query_alt_plural() {
   return ({ });
}

int query_is_plural( string str ) {
   return str == query_plural() || member(query_alt_plural(), str) >= 0;
}

int query_scenery() {
   return 1;
}

int query_is_plant() {
   return 1;
}

int query_max_size() {
   return 10;
}

object id( string s ) {
   if( s == query_name() || s == query_distant() ||
      s == query_plural() || s == query_specific() ||
      member(query_alt_name(), s) >= 0  ||
      member(query_alt_plural(), s) >= 0 )
      return this_object();
   else
      return 0;
}

/** A utility function for treating an integer \a val as a bitmask. This fetches
 * a range of bits for you. \a pos refers to the position of the rightmost
 * (i.e. least significant) bit to fetch, and \a count refers to the number of
 * bits to fetch.
 */
int query_bits( int val, int pos, int count ) {
   if( count >= 32 ) return (val & (0xFFFFFFFF << pos)) >> pos;
   // Argh, it won't let me use overflow.
   if( count == 31 ) {
      if( pos >= 1 ) return (val & 0xFFFFFFFE) >> 1;
      else return val & 0x7FFFFFFF;
   }
   return (val & (((1 << count) - 1) << pos)) >> pos;
}

/** The counterpart to query_bits(). Note that it just returns the new value,
 * it doesn't actually set anything, so it should be used something like
 * mybits = set_bits( mybits, 3, 8, 10); (Set bits 3..10 of mybits to 10).
 * It is supposed to handle overflow reasonably gracefully, but who knows?
 * This kind of code's a pain to write. If setval is too high, it will
 * allow overflow (which means incrementing endlessly might have an
 * unexpected effect!)
 */
int set_bits( int val, int pos, int count, int setval ) {
   if( count >= 32 ) return (val & ((1 << pos) - 1)) | (setval << pos);
   // Argh, it won't let me use overflow.
   setval &= (1 << count) - 1;
   if( count == 31 ) {
      if( pos >= 1 ) return (val & ((1 << pos) - 1)) | (setval << pos);
      else return (val & 0x80000000) | setval;
   }
   return (val & ((1 << pos) - 1)) | (val & (0xFFFFFFFF << (pos+count))) | (setval << pos);
}

void set_size( int x ) {
   if( x > 255 ) x = 255;
   if( x < 0 ) x = 0;
   state = set_bits( state, 0, 8, x );
   call_out( "delayed_clear", 2 );
}

/** Call it with a call_out. The reason for it is that if you're looping
 * through many plants, if many of them change size, it causes a whole
 * lot of map clearing (because growth uses the map). Delaying the clear
 * a bit saves a huge amount of time.
 */
void delayed_clear() {
   if( environment() )
      environment()->clear_map();
}

int query_size() {
   return query_bits( state, 0, 8 );
}

void add_size( int x ) {
   set_size( query_size() + x );
}

void set_fruit( int x ) {
   if( x > 63 ) x = 63;
   if( x < 0 ) x = 0;
   state = set_bits( state, 8, 6, x );
}

int query_fruit() {
   return query_bits( state, 8, 6 );
}

void add_fruit( int x ) {
   set_fruit( query_fruit() + x );
}

void set_energy( int x ) {
   if( x > 63 ) x = 63;
   if( x < 0 ) x = 0;
   state = set_bits( state, 14, 6, x );
}

int query_energy() {
   return query_bits( state, 14, 6 );
}

void add_energy( int x ) {
   set_energy( query_energy() + x );
}

int query_damage() {
   return query_bits( state, 20, 8 );
}

void set_damage( int x ) {
   if( x > 255 ) x = 255;
   if( x < 0 ) x = 0;
   state = set_bits( state, 20, 8, x );
}

void add_damage( int x ) {
   set_damage( query_damage() + x );
}

// If you want other "crowded" definitions, you should override this in your
// plant and modify it however you like.
int query_crowded( int fertility ) {
   object ob;

   if( fertility == 0 ) fertility = query_fertile();
   fertility *= 2;
   if( fertility == 0 ) fertility = 1;
   foreach( ob: filter(all_inventory(environment()), (: $1->query_is_plant() :)) ) {
      if( ob == this_object() ) continue;
      /* We calculate distance between plants via rectilinear or Manhattan
       * distance (ie, |dx| + |dy|). This is done for various reasons, none of
       * which am I completely privy to. However, my guess is that two of them
       * are: 1 - ease of calculation on the part of players
       *      2 - savings of cpu time
       * Do NOT change this. Acius will go all rabid weasel on you if you do.
       *                                                             - al */
       // changed to add the two sizes together
       // avoids paradoxical cases where newer saplings are crowding out
       // old farts but don't themselves get croded - gp
      if( abs(ob->query_x() - query_x()) + abs(ob->query_y() - query_y()) <= (query_size()+ob->query_size()) / fertility + 4 ) {
         // Too close! Die off.
         return 1;
      }
   }

   foreach( ob: filter(all_inventory(environment()), (: !$1->query_is_landscape() :)) ) {
      mapping shape, border, myshape;
      int mypos = SMAKE_C(query_x() - ob->query_x(), query_y() - ob->query_y(), 0);

      myshape = ([
         mypos,
         OFFSET_C(mypos, SMAKE_C(-1,-1,0)),
         OFFSET_C(mypos, SMAKE_C(1,-1,0)),
         OFFSET_C(mypos, SMAKE_C(1,1,0)),
         OFFSET_C(mypos, SMAKE_C(-1,1,0)) ]);

      if( ob == this_object() ) continue;
      shape = ob->query_shape();
      if( !mappingp(shape) ) continue;
      border = ob->query_border();

      if( sizeof(myshape-shape) != 5 || (mappingp(border) && sizeof(myshape-border) != 5) ) {
         return 1;
      }
   }

   return 0;
}

int query_fertile() {
   if( !environment() ) return 0;
   return environment()->query_fertile( query_coord() );
}

void set_crowded(int c) {
   crowded = c;
}

void crowding_check() {
   int fertility = query_fertile();

   if( query_crowded(fertility) ) {
      crowded = 1;
   }
}

void on_grow() {
   int fertility = query_fertile();

   if( crowded ) {
      crowded = 0;
      add_energy( -10 ); // Overcrowding decay.
   } else if (fertility) {
      add_energy( fertility * 1 ); // Based on soil fertility
   } else {
      // tree is starving
      add_energy( -1 );
   }

   if( query_size() >= query_max_size() / 2 && query_energy() > 15 && query_fruit() < query_size() / 2 ) {
      // Grow fruit
      add_fruit(1);
      add_energy( -5 );
   }
   else {
      // Grow larger
      if( query_size() < query_max_size() && query_energy() > 10 && query_damage() == 0 ) {
         add_size( 1 );
         add_energy( -10 );
         if (query_size() == 5) {

         }
         call_out( "delayed_clear", 8 );
      }
   }
   // Heal damage
   if( query_energy() > 30 && query_damage() > 0 ) {
      add_energy( -20 );
      add_damage( -1 );
   }
   // Spread
   if( query_size() >= query_max_size() &&
      query_fruit() > query_size() / 3 &&
      (random(10) == 0)
   ) {
      // Find an exit to spread through
      /**But NOT a building... they'll die, and definatly not a closed door**/
      /**Snarky-1/5/06**/
      object *exits = filter( all_inventory(environment()),
                              (: $1->query_is_exit() &&
                               !($1->query_is_openable())
                               :) );
      if( sizeof(exits) ) {
         object vector, dest;

         vector = exits[random(sizeof(exits))];
         dest = vector->get_destination();
         if( dest ) {
            object new_plant = clone_object( load_name() );
            add_fruit( -query_size() / 4 );
            new_plant->move(dest);
            /**Changed this so seeds can't appear in walls - Snarky 1/5/06**/
            new_plant->set_x( random(dest->query_map_xdim() - 2) + 1);
            new_plant->set_y( random(dest->query_map_ydim() - 2) + 1);
            new_plant->set_energy( 0 );
            if( new_plant )
               new_plant->on_grow();
            if( new_plant ) "/daemon/counter"->add_count( "plant_spread_ok", 1 );
            else "/daemon/counter"->add_count( "plant_spread_die", 1 );
         }
      }
   }

   if( query_energy() == 0 ) {
      call_out( "delayed_clear", 8 );
      destruct(this_object());
//     delayed_clear();
      return;
   }
}

int query_hp() {
   return query_size() - query_damage();
}

int query_max_hp() {
   return query_size();
}

string query_fruit_type() {
   raise_error( object_name() + " does not have a query_fruit_type() override! You need to define a fruit type for plants (even if it's just seeds)." );
}

int on_pick( string type, int quantity ) {
   object fruit;
   if( query_fruit_type()->id(type) ) {
      if( query_fruit() < 1 ) {
         msg("There are no "+query_fruit_type()->query_plural()+" growing on "+query_specific()+"! Wait for some to grow.");
         return 1;
      }
      if( query_fruit() < quantity ) quantity = query_fruit();
      add_fruit( -quantity );
      fruit = clone_object(query_fruit_type());
      fruit->set_quantity( quantity );
      fruit->move(this_player());
      set_target( fruit );
      if( query_fruit() )
         this_player()->msg_local("~CACT~Name ~verbpick ~atar from "+query_specific()+".~CDEF");
      else
         this_player()->msg_local("~CACT~Name ~verbpick the last of the "+query_fruit_type()->query_plural()+" from "+query_specific()+".~CDEF");
      return 1;
   }
   msg("Nothing of that sort on "+query_specific() + ".");
   return 1;
}

mapping query_border() {
   return ([ MAKE_C(4095, 4096, 32),
      MAKE_C(4096, 4097, 32),
      MAKE_C(4097, 4096, 32),
      MAKE_C(4096, 4095, 32) ]);
}

mapping query_shape() {
   return ([ MAKE_C(4096, 4096, 32) ]);
}

void set_coord( int pos ) {
   ::set_coord(pos);
   if( environment() ) environment()->clear_map();
}

mapping query_aspects() {
   return ([ C_PLANT ]);
}
