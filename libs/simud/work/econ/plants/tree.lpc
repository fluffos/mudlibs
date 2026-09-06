inherit "/econ/plant";
#include <const.h>

string query_wood_type() {
   raise_error( object_name() + " does not have a query_wood_type() override! You need to define a wood type for trees." );
}

int query_wood() {
   return 3;
}

int on_chop( object weapon ) {
   if( !HAS_ASPECT(weapon, C_AXE) )//|| query_size() < 1 )
      return 0;

   if ( random(400) < this_object()->query_size() )
      weapon->add_condition(-1);

   add_damage( this_player()->skill_check("combat.weapon.axe", 5, 10) + this_player()->query_strength() / 5 );

   if( query_damage() >= query_size() ) {
      object wood;

      set_target( this_object() );
      if (query_size() < 1)
        set_size(1);

      this_player()->msg_local( "~CACT~Name ~verbswing at ~targ with ~poss "+weapon->query_name()+". With a creaking finality, ~targ ~vertfall to the ground.~CDEF" );

      wood = clone_object( query_wood_type() );
      wood->move(environment());
      wood->set_coord(query_coord());
      wood->set_quantity( query_size() * query_wood() );

      this_player()->add_readiness( -1200 );
      environment()->clear_map(); // Rerender plants!
      debug("chopped tree, size was" + query_size(),"gptree");
      destruct(this_object());
      return 1;
   }
   else {
      set_target( this_object() );
      this_player()->msg_local( "~CACT~Name ~verbswing at ~targ with ~poss "+weapon->query_name()+".~CDEF" );
      this_player()->add_readiness( -300 );
      return 1;
   }
}

int query_max_size() {
   return 60;
}

int query_crowded( int fertility ) {
   //if( query_y() < 4 || query_x() < 3 || query_y() >= environment()->query_map_ydim() - 2 || query_x() >= environment()->query_map_xdim() - 4 )
   //   return 1;
   return ::query_crowded( fertility );
}

void on_map_paint( object painter ) {
   switch( query_size() ) {
      case 0..2: painter->paint( query_x(), query_y(), '.', 0x8A, LAYER_ITEMS ); break;
      case 3..10: painter->paint( query_x(), query_y(), '^', 0x8A, LAYER_LIVING ); break;
      default: painter->paint( query_x(), query_y(), 'T', 0x8A, LAYER_LIVING ); break;
   }
}

void on_grow() {
   // trees grow right slow, they do
   // so always take crowding penalties but skip half the growing
   if (random(2)) {
      ::on_grow();
   } else {
      int fertility = query_fertile();

      if( query_crowded(fertility) )
         add_energy( -10 ); // Overcrowding decay.

      if( fertility <= 0 )
         add_energy( -1 ); // If no fertility, should kill plant eventually.
   }
}
