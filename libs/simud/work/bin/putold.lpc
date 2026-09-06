#include <const.h>

// Verb for putting objects onto/into things

int main( string str ) {
   object env, *superenv, *list;
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

   superenv = all_environment(env);

   move_count = 0;
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

   for( i = 0; i < sizeof(list); i++ ) {
      int flag;

      if( environment(list[i]) == env || member(superenv, list[i]) > 0 ) {
         list = list[..i-1] + list[i+1..];
         i--;
         continue;
      }

      if( !valid_manipulate(this_player(), env) )
         flag = 0;
      else {
         flag = list[i]->on_drop( this_player() );

         if( flag & MOVE_OK_FLAG ) {
            list[i]->move( env );
            move_count++;
         }
      }
      if( !(flag & MOVE_OK_FLAG) || (flag & MOVE_SILENCE_FLAG) ) {
         list = list[..i-1] + list[i+1..];
         i--;
      }
   }

   set_target( env );
   list -= ({ 0 });
   if( sizeof(list) )
      this_player()->msg_local("~CACT~Name ~verbput " + inventory_string(list) + " " + exps[ppos] + " ~targ.~CDEF");
   if( move_count == 0 ) {
      notify_fail("You can't do that.\n");
      return 0;
   }

   return 1;
}
