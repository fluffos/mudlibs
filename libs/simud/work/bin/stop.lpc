#include <const/battconst.h>

int main(string arg) {
   set_actor(this_player());
   if (arg == "combat" || arg == "fighting") {
      this_player()->stop_combat();
      this_player()->msg_local("~CACT~Name ~verbstop fighting.~CDEF");
      msg("~CBRTTarget queue cleared.~CDEF");
      mixed actions = this_player()->query_actions();
      /*Due to complaints about meditation way back in the queue freezing you
       *I've changed this so only the current action's interrupt is called.
       *Snarky 1/6/06
         int i;
         for(i = 0; i < sizeof(actions); i++) {
            actions[i][B_FNAME]->on_interrupt(actions[i]);
         }
      */
      if(sizeof(actions)>0) {
         actions[0][B_FNAME]->on_interrupt(actions[0]);
      }
      this_player()->set_actions( 0 );
      msg("~CBRTAction queue cleared.~CDEF");
   } else if ( arg == "grappling" || arg == "grabbing" ) {
      mapping grappling = this_player()->query_env_var("grappling");
      if ( !sizeof(grappling) ){
         msg("~CBRTYou are not grappling with anyone right now ;)~CDEF");
      } else {
         int x;
         foreach ( x : m_indices(grappling) ) {
            object ob;
            foreach( ob : all_present("grapple_ob",grappling[x]) ) {
               if (ob->query_holder() == this_player())
                  ob->do_release();
            }
         }
         this_player()->msg_local("~CACT~Name ~verbstop grappling.~CDEF");
      }
   } else if ( arg ) {
      // Let it be known that I -really- don't like the potential for abuse
      // inherent in this sort of thing. If you can't figure it out, just
      // ask me. - Al [9/23/04]
      //msg("I am sorry, but you cannot clear individual actions from your queue. Complain to Allaryin.");
      // functionality restored after discussion on thread 2337 - Malap 2004-10-28
      mixed *before, *after = ({ });
      string name;
      int i;
      before = this_player()->query_actions();
      for( i = 0; i < sizeof(before); i++ ) {
         name = before[i][B_FNAME]->query_action_name(before[i]);

         if ( lower_case(arg) == lower_case(name) ||
              lower_case(arg) == lower_case(name[0..(strstr(name, " ") - 1)]) )
         {
            /*Added to call the on_inturrupt to any action that you remove   *
             *This means you can't "stop meditate" to avoid the paralysis    *
             *The code could easily be wrong, as I don't understand all of   *
             *this. The other solution is to just check "stop meditate"      *
             *above. See note above as to why this is commented out          */
            if(i == 0 && before[i]) {
               before[i][B_FNAME]->on_interrupt(before[i]);
            }
            continue;
         }
         after += ({ before[i] });
      }

      this_player()->set_actions( after );

      switch( sizeof(before) - sizeof(after) ) {
      case 0:
         return notify_fail("No action by that name to cancel.\n");
      case 1:
         msg("~CBRTAction removed from queue.~CDEF");
         break;
      default:
         msg("~CBRTActions removed from queue.~CDEF");
      }
      /**This is the source of "No actions waiting" when removing the **/
      /**last action.                                                 **/
      if(sizeof(this_player()->query_actions()) > 0) {
         "/bin/actions"->main();
      }
   } else {
      mixed action = this_player()->query_action(0);
      if (pointerp(action)) {
         this_player()->msg_local("~CACT~Name ~verbabort ~poss queued actions.~CDEF");
         if (action[B_FNAME]->query_is_interruptable())
            action[B_FNAME]->on_interrupt(action);
         this_player()->set_actions( 0 );
         msg("~CBRTAction queue cleared.~CDEF");
      } else {
         msg("You have no enqueued actions to stop.");
      }
   }

   return 1;
}
