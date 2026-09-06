int main( string param ) {
   object building, tg, site;
   int direction, total, base, delay;
   mixed ingred, recipe;
   string skill;

//   notify_fail("Building is currently disabled.\n");
//   return 0;

   if( !param ) {
      notify_fail("You must specify a building to build.\n");
      return 0;
   }

   if( !environment(this_player())->query_can_build() ) {
      notify_fail("It's not possible to build anything here.\n");
      return 0;
   }

   if( param == "foundstone" && "/daemon/city"->get_city_by_room(get_location(environment(this_player()))) ) {
      notify_fail("This room is already claimed by a city.\n");
      return 0;
   }

   // Could do %s to the %s, but it ends up being nearly as much code and a bit
   // trickier to validate. Try it. Is probably worth it if you add non-cardinal
   // directions, though.
   direction = 0;
   if( sscanf(param, "%s to the north", param) == 1 ) direction = SMAKE_C(0,-1,0);
   if( sscanf(param, "%s to the west", param) == 1 ) direction = SMAKE_C(-1,0,0);
   if( sscanf(param, "%s to the east", param) == 1 ) direction = SMAKE_C(1,0,0);
   if( sscanf(param, "%s to the south", param) == 1 ) direction = SMAKE_C(0,1,0);

   tg = "/daemon/recipe"->get_building( param );
   if( !tg ) return 1; // Failure message already given.
   if( !this_player()->query_recipe(param) ) {
      set_target( tg );
      msg("You do not know how to build ~targ.\n");
      destruct( tg );
      return 1;
   }
   if( tg->check_direction(direction) == -1 ) {
      destruct( tg );
      return 1; // check_direction should give the failure message.
   }
   tg->set_name( param );
   site=clone_object( "/econ/site" );
   site->move( environment( this_player() ) );

   // calculate delay
   total = delay = base = 0;
   recipe = "/daemon/recipe"->query_recipe(param);
   foreach( ingred : recipe["ingredients"] )
      total += ingred[1];
   base = total;
   // perform skill checks to modify initial delay
   foreach( skill : recipe["skills"] ) {
      // Not inclined to give practices for laying out sites.
      if (!this_player()->skill_check("nopractice:" + skill, recipe["skills"][skill]))
         total += base / (2 * sizeof(recipe["skills"]));
   }
   delay = max( 1, total / 250 );
   site->set_construction_delay( delay );
   site->set_skills( recipe["skills"] );

   tg->move( site );
   tg->set_owner( this_player()->query_name() );
   if( !direction ) {
      site->set_x( this_player()->query_x() );
      site->set_y( this_player()->query_y() );
   }
   this_player()->msg_local( "~CACT~Name ~verblay out a construction site.~CDEF" );

   return 1;
}
