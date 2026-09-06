string query_action_name( mixed *action ) {
   if (action[B_PARAM] == 1)
      return "Closing " + action[B_TARGET]->query_specific();
   else
      return "Opening " + action[B_TARGET]->query_specific();
}

int main( string param ) {
   object ob, env;
   int open_ok;

   int CLOSE = 0;
   if ( query_verb() == "close" ) CLOSE = 1;

   if( CLOSE && !param ) return notify_fail( "Close what?\n" );
   else if( !param ) return notify_fail( "Open what?\n" );


   env = environment(this_player());
   if( !env ) env = this_player();

   ob = single_present( param, env, (:CLOSE-!!$1->query_closed():) );
   if( !ob ) ob = single_present( param, env );
   if( !ob ) ob = single_present( param, this_player() );
   if( !ob ) return notify_fail( "I can't find anything that matches '"+param+"'\n");

   WALK_ACTION_PARAM( 1000, ob, CLOSE );
   return 1;
}

void on_action( object ob, mixed CLOSE ) {
   if ( !ob ) return;

   int DEFAULT = 0;
   if ( CLOSE && !ob->on_close() ) DEFAULT = 1;
   else if ( !CLOSE && !ob->on_open() ) DEFAULT = 1;

   // if ob doesn't define its own special way of opening, this uses the default way
   if( DEFAULT ) {
     /**
      * The logic here is hopelessly flawed. Don't rely on it.
      * In order for these verbs to manipulate your objects, you MUST implement
      * an on_close() and on_open() event of your own.
      *
      * - Al [Jun 29, '06]
      */
     /** if( !ob->query_closed() ) { */
         if ( CLOSE ) msg("It can't be closed.\n");
         else msg("It can't be opened.\n");
     /**    return;
      }
      set_target( ob );
      ob->set_closed( CLOSE );
      if ( CLOSE ) this_player()->msg_local("~CACT~Name ~verbclose ~targ.~CDEF");
      else this_player()->msg_local("~CACT~Name ~verbopen ~targ.~CDEF");
      */
   }
}

/*
 * This was the old, non-walking version that could handle multiple objects
 * (so that "open all doors" would work, for example). It's here for if/when
 * we decide to reimplement the multiple-object capability.
 *                                                   -- Zarylse [2003-08-22]

int main( string param ) {
   object *oblist, env;
   int open_ok;

   if( !param ) {
      notify_fail( "Open what?\n" );
      return 0;
   }

   env = environment(this_player());
   if( !env ) env = this_player();

   oblist = ({ env->query_blocker_present(param) });
   if( !oblist[0] ) {
      oblist = all_present( param, env );
      if( !oblist ) oblist = all_present( param, this_player() );
      if( !oblist ) oblist = ({ });
      oblist += ({ all_present( "exit_" + param, env ) });
   }
   open_ok = 0;
   if( sizeof(oblist) ) {
      object ob;

      foreach( ob: oblist ) {
         if( !objectp(ob) ) continue;
         if( !ob->on_open() ) {
            set_target( ob );
            if ( !ob->query_closed() ) {
               notify_fail("It can't be opened.\n");
               continue;
            }
            ob->set_closed( 0 );
            open_ok = 1;
            this_player()->msg_local("~CACT~Name ~verbopen ~targ.~CDEF");
         } else open_ok = 1;
      }
   }
   else {
      notify_fail( "I can't find anything that matches '"+param+"'\n");
      return 0;
   }
   return open_ok;
}
*/
