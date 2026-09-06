#include <const.h>

// Verb for putting objects onto/into things

string query_action_name( mixed *action ) {
   return "Put";
}

int main( string str ) {
   object ob,  env, *list;
   string *exps, insert_msg;
   int i, ppos, move_count;

   if( !str ) {
      notify_fail("What do you want to put, and where do you want to put it?\n");
      return 0;
   }

   if( str[0..4] == "down " ) return "/bin/drop"->main( str[5..] );

   exps = regexplode( str, PREP_EXP );
   for( i = sizeof(exps); i--; ) exps[i] = trim(exps[i]);
   list = 0;
   if( sizeof(exps) > 1 )
      for( i = 0; i < sizeof(exps); i += 2 ) {
         list = all_present( implode(exps[i+2..], ""), this_player() );
         if( !list )
         list = all_present( implode(exps[i+2..], ""), environment(this_player()) );
         if( pointerp(list) )
            env = list[0];
         else
            continue;
         list = all_present( implode(exps[0..i], ""), this_player() );
         if( pointerp(list) ) break;
      }
   ppos = i + 1;
   if( !list ) {
      notify_fail("What do you want to put, and where do you want to put it?\n");
      return 0;
   }

   if( !env->query_container() || (insert_msg = env->query_prevent_insert()) ) {
      set_target(env);
      set_actor(this_player());
      set_listener(this_player());
      if( stringp(insert_msg) )
         notify_fail(process_codes(insert_msg));
      else
         notify_fail(process_codes("You can't put anything into ~targ.\n"));
      return 0;
   }

   foreach( ob : list )
      ob->set_player_lock( this_player() );

   WALK_ACTION_PARAM( 1000, env, list );

   return 1;
}

// temporary workaround to make sure that only keys and keyrings
// go in keyrings
//
// Is there a generic way to do this selective filtering?
// -gpfault
int valid_insert( object env, object ob ) {
   if( env->query_is_keyring() ) {
      if( ob->query_is_key() || ob->query_is_keyring() ) {
         return 1;
      }
      return 0;
   }
   return 1;
}

void on_action( object env, mixed param ) {
   object ob, *superenv;
   int move_count, max_flag;
   string prep;

   superenv = all_environment(env) + ({ env });
   move_count = 0;
   max_flag = 0;

   foreach( ob : param ) {
      int flag;

      // Error conditions: Not an object (destroyed?), it's already there,
      // or it's recursive (i.e. put the bag into the sack in the bag)
      if( !objectp(ob) || environment(ob) == env || member(superenv, ob) >= 0 ) {
         param -= ({ ob });
         continue;
      }

      if (ob->query_kept()) {
         param -= ({ ob });
         continue;
      }
      if( !valid_manipulate(this_player(), env) )
         flag = 0;
      else {
         flag = valid_insert(env, ob);

         if (flag) {
            flag = ob->on_drop( this_player() );
         } else {
            debug("valid_insert false");
         }

         if( flag & MOVE_OK_FLAG ) {
            object *oblist = ({ ob });
            // Check bulk
            if( env->query_bulk_capacity() )
               oblist = limit_bulk( ({ ob }), env->query_bulk_capacity() - env->query_held_bulk() );
            if( !sizeof(oblist) ) {
               param -= ({ ob });
               max_flag |= 1;
               continue;
            }
            if( env->query_weight_capacity() )
               oblist = limit_weight( ({ ob }), env->query_weight_capacity() - env->query_held_weight() );
            if( !sizeof(oblist) ) {
               param -= ({ ob });
               max_flag |= 2;
               continue;
            }
            ob->move( env );
            move_count++;
            // event fired on containers whenever they have something put into
         // them. - al [may 15, '05]
//         env->on_put( ob );
            // This isn't necessary, the on_insert event works fine and is MUCH more
            // general. - acius [aug '06]
         }
      }
      // Silent movement, or movement was not allowed
      if( !(flag & MOVE_OK_FLAG) || (flag & MOVE_SILENCE_FLAG) )
         param -= ({ ob });
   }

   set_target( env );
   param -= ({ 0 });
   prep = env->query_preposition();
   if( !prep ) prep = "in";
   if( sizeof(param) )
      this_player()->msg_local("~CACT~Name ~verbput " + inventory_string(param) + " "+prep+" ~targ.~CDEF");
   else if( max_flag & 1 )
      msg("There's not enough room " + prep + " ~targ for that.");
   else if( max_flag & 2 )
      msg("~Subt can't hold that much weight.");
   if( move_count == 0 )
      msg("You failed to put anything " + prep + " ~targ.");
}
