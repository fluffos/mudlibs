string query_action_name( mixed * action ) {
   return "Plant";
}

int main( string param ) {
   object ob, *oblist;
   int success, reason;

   if( !param ) {
      notify_fail("What would you like to plant? Usually, you need some seeds to do planting.\n");
      return 0;
   }

   oblist = all_present( param, this_player() );
   if( !oblist ) {
      notify_fail("You aren't holding anything that matches '"+param+"'.\n");
      return 0;
   }

   foreach( ob : oblist ) {
      if( member(all_environment(ob), this_player()) < 0 )
         oblist -= ({ ob });
   }

   if( !sizeof(oblist) ) {
      notify_fail("You must be holding it in order to plant it. Get it first.\n");
      return 0;
   }

   {
      int quantity;

      quantity = oblist[0]->query_quantity();

      debug("Planting quantity: " + quantity);

      oblist[0]->set_player_lock( this_player() );
   }

   WALK_ACTION( 1000, oblist[0] );

   return 1;
}

void on_action(object ob, mixed param) {
   ob->move( environment(this_player()) );
   this_player()->add_readiness( -500 );

   if( !ob->on_plant( this_player()->query_coord() ) ) {
      notify_fail("That didn't seem to have any effect.\n");
      return 0;
   }
   else {
      set_target( ob );
      this_player()->msg_local( "~CACT~Name ~verbplant ~targ.~CDEF" );
      if( ob->query_quantity() <= 1 )
         destruct( ob );
      else
         ob->add_quantity( -1 );
   }

   if (ob) {
      if( environment(ob) != this_player() ) {
         debug("Relocating object back to player inventory...");
         ob->move( this_player() );
      }
   }
}
