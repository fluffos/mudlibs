#include <const.h>

// Verb for giving objects away.

string query_action_name() {
   return "Give";
}

int main( string str ) {
   object dest, *list;
   string a, b;

   if( !str ) {
      notify_fail("Give what to whom?\n");
      return 0;
   }

   dest = 0;
   if( sscanf(str, "%s to %s", a, b) == 2 )
   if( (list = all_present(b, environment(this_player()), ({ this_player() }))) && list[0]->query_is_living() ) {
      dest = list[0];
      str = a;
   }
   if( !dest && sscanf(str, "%s %s", a, b) == 2 )
   if( (list = all_present(a, environment(this_player()), ({ this_player() }))) && list[0]->query_is_living() ) {
      dest = list[0];
      str = b;
   }
   if( !dest || !valid_manipulate(this_player(), dest) ) {
      notify_fail("I don't understand who you want to give it to.\n");
      return 0;
   }

   WALK_ACTION_PARAM( 1000, dest, str );
//   WALK_DAEMON->init_walk_action( WALK_DAEMON->shape_adjacent(), dest->query_coord(),
//      ({ 1000, this_object(), dest, ST_ALL, str }) );
   return 1;
}

void on_action( object dest, string str ) {
   object env, *list, o;
   string a, b;
   int i, weight;

   env = this_player();

   // A little weird to say 'give the box from my bag to bob' but I don't mind letting it work.
   if( sscanf(str, "%s from %s", a, b) ) {
      list = all_present( b, env );
      if( !list ) list = all_present( b );
      if( !list ) {
         msg("I don't know what you mean by '"+b+"'.\n");
         return;
      }
      env = list[0];

      list = all_present( a, env );
   }
   else {
      list = all_present( str, env );
      if( !list ) list = all_present( str );
      if( !list ) {
         msg("I don't know what you mean by '"+str+"'.\n");
         return;
      }
   }

   foreach( o:list )
      weight += o->query_total_weight();

   if( weight + dest->query_held_weight() > dest->query_weight_capacity() ) {
         set_target(dest);
         this_player()->msg_local("~CACT~Targ cannot carry everything ~name ~verbis trying to give ~objt.~CDEF");
         return;
   }

   for( i = 0; i < sizeof(list); i++) {
      int flag = list[i]->on_give( this_player(), dest );
      if( !(flag & MOVE_OK_FLAG) ) {
         list = list[..i-1] + list[i+1..];
         i--;
      }
   }

   if( sizeof(list) ) {
      object ob;
      object accept = clone_object("/obj/accept");
      mixed param = ({ this_player(), dest, list });

      foreach( ob : list )
         ob->move(accept);

      set_actor( this_player() );
      set_target( dest );
      set_listener( dest );
      msg_object(dest,"~Name offers to give ~CCOM"+inventory_string(list)+"~CDEF to you.");
      set_listener( this_player() );
      msg("You offer to give ~CCOM"+inventory_string(list)+"~CDEF to ~targ.");

      if( dest->query_env_var("Tautotake") ) {
         msg_object(dest,"You automatically accept (autotake is enabled).");
         msg(dest->query_cap_name()+" accepts.");
         this_object()->on_accept(param);
      } else if( dest->query_trust(this_player()->query_name()) ) {
         msg_object(dest,"You automatically accept ("+this_player()->query_cap_name()+" is trusted).");
         msg(dest->query_cap_name()+" trusts you, item"+(sizeof(list)>1?"s":"")+" accepted.");
         this_object()->on_accept(param);
      } else {
         accept->set_verb(this_object());
         accept->set_yes( "on_accept", param );
         accept->set_no( "on_reject", param );
         accept->start(dest);
      }
      dest->on_offer( list, this_player() );
   } else
      msg("It is impossible to give that away.");
}

void on_accept(mixed param) {
   object actor = param[0];
   object target = param[1];
   object *list = copy(param[2]) - ({ 0 });
   int i;

   for( i = 0; i < sizeof(list); i++ ) {
      int flag = list[i]->on_give( actor, target );
      list[i]->move( target );
      if( flag & MOVE_SILENCE_FLAG || !list[i] ) {
         list = list[..i-1] + list[i+1..];
         i--;
      }
   }

   if( sizeof(list) == 0 ) return;
   set_target(target);
   actor->msg_local("~CACT~Name ~verbgive " + inventory_string(list) + "~CACT to ~targ.~CDEF");
}

void on_reject(mixed param) {
   object ob;

   foreach( ob : param[2] )
      ob->move( param[0] );
   set_target(param[0]);
   param[1]->msg_local("~CACT~Name ~verbreject ~npot offer.~CDEF");
}
