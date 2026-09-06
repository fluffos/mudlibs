string query_action_name() {
  return "Install";
}

int main(string param) {
   mixed ob, person;
   string a, b;

   if( !param ) {
      notify_fail("You could 'install item' or 'install item on place'.\n");
      return 0;
   }

   if( sscanf(param, "%s on %s", a, b) == 2 ||
       sscanf(param, "%s in %s", a, b) == 2 ) {
      ob = single_present(a,this_player());
      if( !ob )
         ob = single_present(a,environment(this_player()));
      if( !ob ) {
         notify_fail("I don't understand what "+a+" is.\n");
         return 0;
      }
      person = single_present(b,environment(this_player()));
      if(!(person)) {
         notify_fail(b+" isn't in the room with you.\n");
         return 0;
      }

      // WALK_ACTION_PARAM( 750, ob, person );
      WALK_ACTION_PARAM( 750, person, ob );
      // note the stupid ordering... sigh. This is so we walk to the target
      // in order to perform the installation in stead of trying to do it
      // the other way around - al [5-3-05]

	  /*
      this_player()->push_action( ({ 750,
                                     this_object(),
                                     ob,
                                     ST_STANDING,
                                     person }) );
      */
      return 1;
   }
   else {
      ob = single_present(param,this_player());
      if( !ob )
         ob = single_present(param,environment(this_player()));
      if( !ob ) {
         notify_fail("I don't understand what "+param+" is.\n");
         return 0;
      }

      WALK_ACTION( 750, ob );

      /*
      this_player()->push_action( ({ 750,
                                     this_object(),
                                     ob,
                                     ST_STANDING,
                                     0 }) );
      */
      return 1;
   }
}

void on_action(object ob, mixed param) {
  // ob is item to use
  // param is what to use it on
  if( objectp(param) ) {
     // dumb hack to make this work as a walking action
     object tmp = param;
     param = ob;
     ob = tmp;
     // end dumb hack
     if( !(ob->on_install(param)) ) {
       set_actor(ob);
       set_listener(this_player());
       set_target(param);
       msg("~CWRNYou can't install ~name on ~targ.~CDEF");
     }
  } else {
     if( !(ob->on_install()) )
        msg("~CWRNYou can't install "+ob->query_specific()+".~CDEF");
  }
}
