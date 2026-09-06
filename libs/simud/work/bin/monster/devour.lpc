string query_action_name(mixed *action) {
   if( !action[B_TARGET] )
      return "Devour <target disappeared>";
   else
      return "Devour " + action[B_TARGET]->query_distant();
}

int main( string param ) {
   object victim;

   if( !param ) {
      notify_fail("What do you wish to devour?\n");
      return 0;
   }

   victim = single_present( param, environment(this_player()) );
   if( !victim ) {
      notify_fail("I have no idea what you're trying to devour.\n");
      return 0;
   }

   if( !victim->query_product_aspect() ) {
      notify_fail("There's no flesh to devour from that.\n");
      return 0;
   }

   WALK_ACTION( 500, victim );
   return 1;
}

void on_action(object target, mixed param) {
   object meat;
   if ( !target->query_product_quantity() ) {
      this_player()->msg_local( "~CACT~Name ~verbfinish devouring ~targ.~CDEF" );
      destruct( target );
      return;
   }
   this_player()->set_skill("craft.butcher", 100);
   meat = target->on_butcher();
   if ( meat ) {
      set_target( target );
      this_player()->msg_local( "~CACT~Name ~verbtear "+meat->query_specific()+" from ~targ.~CDEF");
      this_player()->add_readiness( -250 );
      if ( meat->query_is_edible() ) {
         meat->move( this_player() );
         if (!command( "eat "+meat->query_name(), this_player() )) {
            debug( "Unable to eat: " + query_notify_fail(), "ai");
            return;
         }
      } else {
         // destroy non-consumables
         destruct( meat );
      }
   }
   this_player()->push_action( ({ 500, this_object(), target, ST_STANDING, 0 }) );
}
