inherit "/ai/module";

string query_module_name() {
   return "lair";
}

int lair_seen;

void on_move( object src ) {
   object ob, lair;
   int hungry;

   if( !query_enabled() ) return;

   // Am I hungry?
   foodp = environment()->query_food() * 100 / environment()->query_food_capacity();
   drinkp = environment()->query_drink() * 100 / environment()->query_drink_capacity();
   if( foodp < 75 && drinkp < 75 ) hungry = 1;
   else hungry = 0;

   lair_seen++;
   // Am I in a lair?
   if( environment() && environment(environment()) && environment(environment())->query_is_lair() ) {
      lair = environment(environment());
      if( hungry ) lair->on_exit(environment());
      lair_seen = 0;
   }
   else {
      // Is there a lair here?
      foreach( ob : all_inventory(environment()) )
      if( ob->query_is_lair() && lair->query_animal_type() == environment()->query_name() ) {
         lair_seen = 0; // Found one.
         lair = ob;
         break;
      }
      // If I'm not hungry, and there's a lair, maybe go inside.
      if( !hungry && lair && random(2) ) {
         lair->on_enter( environment() );
      }
   }
   if( lair_seen > 10 && !hungry ) {
      // It's been a while since I've seen a lair. Build one.

   }
}

void on_tick() {
   if( !query_enabled() ) return;
   if( random(4) == 0 )
   environment()->wander();
}