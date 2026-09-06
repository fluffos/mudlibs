inherit "/ai/module";

string query_module_name() {
   return "forage";
}

void on_tick() {
   int foodp, drinkp, wanderflag;
   object *graze_list;

   if( !query_enabled() ) return;
   // Am I hungry?
   foodp = environment()->query_food() * 100 / environment()->query_food_capacity();
   drinkp = environment()->query_drink() * 100 / environment()->query_drink_capacity();
   // If not, this module doesn't need to run.
   if( foodp > 75 && drinkp > 75 ) return;
   // But if I am, check if there's anything grazable here.
   if( foodp <= 75 ) {
      graze_list = all_inventory(environment(environment()));
      graze_list = filter( graze_list, (: $1->query_is_edible() :) );
      if( sizeof(graze_list) && random(10) ) {
         string graze_name = graze_list[random(sizeof(graze_list))]->query_name();
         command( "eat " + graze_name, environment() );
      }
      else wanderflag = 1;
   }
   if( drinkp <= 75 ) {
      graze_list = all_inventory(environment(environment()));
      graze_list = filter( graze_list, (: $1->query_is_drinkable() :) );
      if( sizeof(graze_list) && random(10) ) {
         string graze_name = graze_list[random(sizeof(graze_list))]->query_name();
         command( "drink " + graze_name, environment() );
      }
      else wanderflag = 1;
   }
   if( wanderflag )
      environment()->wander();
   else if( random(100) < 25 )
      command( "walk random", environment() );
}
