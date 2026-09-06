inherit "/ai/module";

string query_module_name() {
   return "fire_lizard";
}

// Fire lizards eat lava :P
void on_tick() {
   int foodp, drinkp, wanderflag;

   if( !query_enabled() ) return;
   // Am I hungry?
   foodp = environment()->query_food() * 100 / environment()->query_food_capacity();
   drinkp = environment()->query_drink() * 100 / environment()->query_drink_capacity();
   // If not, this module doesn't need to run.
   if( foodp > 75 && drinkp > 75 ) return;
   if( foodp > 50 || drinkp > 50 )
      wanderflag = 1;

   if( present_clone("/scn/ground/lava", environment(environment())) ) {
      set_actor( environment() );
      environment()->msg_local("~CACT~Name ~verbtake a sip of the lava.~CDEF");
      environment()->add_food( 100 );
      environment()->add_drink( 100 );
   } else {
      wanderflag = 1;
   }

   if( wanderflag )
      environment()->wander();
}
