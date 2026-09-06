#include <const.h>
#include <const/battconst.h>

string query_action_name( mixed *action ) {
   mixed tgt = action[B_PARAM][0];

   mixed datum = "<invalid>";

   if (tgt) {
      datum = action[B_PARAM][0]->query_distant();
   }

   return "Get " + (stringp(datum) ? datum : "<unknown>");
}

varargs object container_of( object ob, object player ) {
   object env;

   env = ob;
   if( !player ) player = this_player();
   if( !player ) return ob;
   while( env && environment(env) != environment(player) ) env = environment(env);
   if( env ) return env;
   return ob;
}

// Verb for picking up objects.

int distance(object obj) {
  float dx = this_player()->query_x() - obj->query_x();
  float dy = this_player()->query_y() - obj->query_y();
  int d = (int)(sqrt( pow(dx,2) + pow(dy,2) ));

  debug("distance to "+(string)obj+" = "+(string)d);

  return d;
}

int main( string str ) {
   object ob, env, env2, *list;
   string a, b = 0;
   int i, have_it = 0, is_self = 0, cant_get = 0;

   if( !str ) {
      notify_fail(capitalize(query_verb()) + " what?\n");
      return 0;
   }

   env = environment(this_player());
   env2 = 0;
   if( sscanf(str, "%s from %s", a, b) ) {
      list = all_present( b, env );
      if( list ) {
         env = list[0];
         list = all_present( b, this_player() );
         if( list ) env2 = list[0];
      }
      else {
         list = all_present( b, this_player() );
         if( !sizeof(list) ) {
            notify_fail("I can't figure out what you mean by '"+b+"', so I can't get anything from there.\n");
            return 0;
         }
         env = list[0];
      }
   }
   else a = str;

   list = all_present( a, env );
   if( !list && env2 )
      list = all_present( a, env2 );
   if( !list && !b )
      list = all_present( a, this_player() );

   if( list )
   foreach( ob : list ) {
      if( ob == this_player() ) {
         //debug( ob->query_name() + " is this_player()");
         list -= ({ ob });
         is_self = 1;
      } else if( environment(ob) == this_player() ) {
         //debug( ob->query_name() + " is already gotten");
         list -= ({ ob });
         have_it = 1;
      /*} else if( ob->query_is_exit() ) {
        // this case added by Al on 8/11
         debug( ob->query_name() + " is an exit" );
         list -= ({ ob });*/
     } else if( !ob->query_gettable() ) {
         //debug( ob->query_name() + " is ungettable" );
         list -= ({ ob });
         cant_get = 1;
      }
   }
   if( !sizeof(list) ) {
      if( str == "all" )
         notify_fail("There is nothing to get here.\n");
      else if( have_it )
         notify_fail("You already have it!\n");
      else if( cant_get )
         notify_fail("Picking that up would be a little bit impossible.\n");
      else if( is_self )
         notify_fail("That seems kinky somehow.\n");
      else
         notify_fail("I don't know what you mean by '"+str+"'.\n");
      return 0;
   }

   if( sizeof(list) > 1 )
      this_player()->set_pronoun( list );
   else
      this_player()->set_pronoun( list[0] );

   foreach( ob : list ) {
      ob->validate_position();
      // Hold quantity objects stable until they're gotten.
      ob->set_player_lock( this_player() );
   }

   WALK_ACTION_PARAM( 800, container_of(list[0]), list );

   return 1;
}

/* Get all adjacent objects in oblist, then walk to the
 * next remaining one if any.
 */
void on_action( object target, object *oblist ) {
   object ob, env, *obfound, *getfail, loc;
   int my_coord, flag, max_flag;

   max_flag = 0;

   // Very small readiness penalty to avoid looping problems.
   this_player()->add_readiness(-5);
   if( !(env = environment(this_player())) ) return;
   my_coord = this_player()->query_coord();
   obfound = ({ });
   oblist -= ({ 0 });
   foreach( ob : oblist ) {
      if( !valid_manipulate(this_player(), ob) || environment(ob) == this_player() )
         oblist -= ({ ob });
      else if( this_player()->query_adjacent(container_of(ob)) )
         obfound += ({ ob });
   }

   if( sizeof(obfound) ) {
      getfail = ({ });
      oblist -= obfound;
      foreach( ob : obfound ) {
         flag = ob->on_get();
         if( !(flag & MOVE_OK_FLAG) || (flag & MOVE_SILENCE_FLAG) ) obfound -= ({ ob });
         if( !(flag & MOVE_OK_FLAG) ) {
            if( !ob->query_is_living() )
               getfail += ({ ob });
         }
         else {
            object *oblimit = ({ ob });
            if( member(all_environment(ob), this_player()) < 0 )
               oblimit = limit_weight( oblimit, this_player()->query_weight_capacity() - this_player()->query_held_weight() );
            if( sizeof(oblimit) ) {
               ob = oblimit[0];
               loc = environment(ob);
               ob->move( this_player() );
            }
            else {
               getfail += ({ ob });
               obfound -= ({ ob });
               max_flag = 1;
            }
         }
      }
      if( sizeof(getfail) ) {
         if( !max_flag )
            msg("You fail to get " + inventory_string(getfail) + "." );
         else
            msg("You're carrying too much. You can't get " + inventory_string(getfail) + "." );
      }
      if( sizeof(obfound) ) {
         if( loc && loc != env ) {
           set_target( loc );
           this_player()->msg_local("~CACT~Name ~verbget " + inventory_string(obfound) + " from ~targ.~CDEF");
         } else {
           this_player()->msg_local("~CACT~Name ~verbget " + inventory_string(obfound) + ".~CDEF");
         }

      }
   }

   if( sizeof(oblist) ) {
      WALK_ACTION_PARAM( 800, container_of(oblist[0]), oblist );
   }
}
