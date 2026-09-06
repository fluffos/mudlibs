inherit "/econ/plants/patch";

TASTE( "Fungal.")
string query_name() { return "mushroom patch"; }
string query_distant() { return "mushroom patch"; }
string query_specific() { return "the mushroom patch"; }
string *query_alt_name() { return ({ "mushroom", "patch" }); }

string query_look() {
   return "It is a small patch of 'edible' mushrooms."+(query_fruit()?" One or two look ready for the eating.":" None look big enough to eat.");
}

string query_fruit_type() {
   return "/econ/seed/mushroom";
}

// funky growth since these live where other plants die
void on_grow() {
   object ob, env = environment();
   int x = query_x(),
       y = query_y();
   int xdim = env->query_map_xdim(),
       ydim = env->query_map_ydim();
   int rate = 5, plants = 0;
   // growth rate is constant as long as it's not crowded
   if (!env->query_valid_square(x-1,y)) rate--;
   if (!env->query_valid_square(x+1,y)) rate--;
   if (!env->query_valid_square(x,y-1)) rate--;
   if (!env->query_valid_square(x,y+1)) rate--;
   // lose one growth for every plant adjacent
   foreach( ob : filter(all_inventory(environment()), (: $1->query_is_plant() :)) ) {
      if( ob == this_object() ) continue;
      plants++;
      if( abs(ob->query_x() - query_x()) + abs(ob->query_y() - query_y()) <= 1 )
         rate--;
   }

   // die if super crowded
   if( rate < 5 && plants > xdim * ydim ) {
      add_energy( -10 );
      if( query_energy() == 0 ) {
         call_out( "delayed_clear", 8 );
         destruct(this_object());
      }
      return;
   }

   add_energy( rate );

   if( query_size() < query_max_size() && query_energy() > 15 ) {
      add_size(1);
      add_energy( -10 );
      call_out( "delayed_clear", 8 );
   }
   if( query_size() >= query_max_size() / 2 && query_energy() > 15 && query_fruit() < query_size() / 2 ) {
      add_fruit(1);
      add_energy( -5 );
   }

   // spread
   if( query_energy() >= query_size() * 6 && rate > 0) {
      int obx = x, oby = y;
      ob = clone_object(load_name());
      if( rate > 3 ) { // within room
         while( obx == x && oby == y ) {
            obx = x - 1 + random(3);
            oby = y - 1 + random(3);
         }
         ob->move(env);
         debug("rate = "+rate+", spreading to "+obx+","+oby);
      } else if( rate > 1) { // infect the neighbors ;) muahahaha
        object *exits = filter( all_inventory(environment()), (: $1->query_is_exit() :) );
        if( sizeof(exits) ) {
           object exit = exits[random(sizeof(exits))];
           object dest = exit->get_destination();
           if( dest ) {
              obx = random(dest->query_map_xdim());
              oby = random(dest->query_map_xdim());
              ob->move(dest);
              debug("rate = "+rate+", spreading to "+dest->query_name());
           } else {
              destruct(ob);
              return;
           }
        }
      } else {
         destruct(ob);
         return;
      }
      if( ob )
         ob->on_grow();
      if( ob ) {
         ob->set_x(obx);
         ob->set_y(oby);
         ob->set_energy( query_energy() / 2 );
         ob->set_size( query_size() / 2 );
         ob->set_fruit( query_fruit() / 2 );
         "/daemon/counter"->add_count( "mushroom_spread_ok", 1 );
         add_energy( -ob->query_energy() );
         add_size( -ob->query_size() );
         add_fruit( -ob->query_fruit() );
      } else
         "/daemon/counter"->add_count( "mushroom_spread_die", 1 );
   }

   if( query_energy() == 0 ) {
      call_out( "delayed_clear", 8 );
      destruct(this_object());
      return;
   }
}

int query_is_edible() {
   return (query_fruit()?1:0);
}

int on_consume( int max ) {
   if( query_fruit() ) {
      object ob = clone_object(query_fruit_type());
      ob->on_consume();
      set_actor(this_player());
      set_target(this_object());
      this_player()->msg_local("~CACT~Name ~verbnibble on ~targ.~CDEF");
      add_fruit( -1 );
   } else
      msg( "There aren't any mushrooms big enough for consumption there." );
   return 1;
}

mapping query_aspects() {
   return ([ C_GRAZE ]);
}
