#include <const.h>

// \todo This is quick hack code, and shouldn't be taken too seriously.
// A decent pouring function is still needed.
// 05-20-2003 (Kasey) - Changed "Can't do it" error message

string query_action_name( mixed *action ) {
   return "Pour";
}

void on_accept( mixed params );
void on_reject( mixed params );

int main( string param ) {
   string a, b;
   object ob_src, ob_dest, *ob_list;
   object ob;
   string contents;
   int total_volume;
   int result;
   mapping shape;

   if( !param ) {
      notify_fail( "Pour what into what?\n" );
      return 0;
   }

   if (sscanf(param, "out %s", a) == 1 || sscanf(param, "%s out", a) == 1) {
      ob_list = all_present( a, this_player() );
      if( !ob_list ) {
         notify_fail("I don't understand what you are trying to pour.\n");
         return 0;
      }
      ob_src = ob_list[0];
      if( ob_src->query_liquid() ) {
         ob_src = environment(ob_src);
      }
      result = 0;
      foreach( ob : all_inventory(ob_src)) {
         result++;
         ob->move( environment( this_player() ) );
      }
      if (!result) {
         notify_fail(capitalize(ob_src->query_specific()) + " is already empty.\n");
         return 0;
      }
      ob_src->on_pour_out( this_player(), -1 );
      return 1;
   }// end: if pouring 'out'

   if( sscanf(param, "%s into %s", a, b) == 2 ) {
      object accept;
      ob_list = all_present( a, this_player() );
      if( !ob_list ) {
         notify_fail("I don't understand what you are trying to pour.\n");
         return 0;
      }
      ob_src = ob_list[0];
      ob_list = all_present( b, this_player() );
      if( !ob_list )
         ob_list = all_present( b, environment(this_player()) );
      if( !ob_list ) {
         notify_fail("I don't understand what you want to pour it into.\n");
         return 0;
      }
      ob_dest = ob_list[0];

      /*if( environment(ob_dest)->query_is_player() && environment(ob_dest) != this_player() ) {
         notify_fail( "You may not pour into a container in another player's inventory.\n" );
         return 0;
      }*/

      accept = clone_object("/obj/accept");
      if( environment(ob_dest)->query_is_player() && environment(ob_dest) != this_player() ) {
         mixed* params = ({ ob_list, ob_src, ob_dest, shape, total_volume, result, contents, a, this_player() });
         set_actor( this_player() );
         set_target( environment(ob_dest) );
         set_listener( environment(ob_dest) );
         msg_object(environment(ob_dest),"~Name offers to pour ~CCOM"+ob_src->query_name()+"~CDEF into your "+ob_dest->query_name()+".");
         set_listener( this_player() );
         msg("You offer to pour ~CCOM"+ob_src->query_name()+"~CDEF into ~npot "+ob_dest->query_name()+".");

         if( environment(ob_dest)->query_env_var("Tautotake") ) {
            msg_object(environment(ob_dest),"You automatically accept (autotake is enabled).");
            msg(environment(ob_dest)->query_cap_name()+" accepts.");
         } // end: if they autotake
		 else if( environment(ob_dest)->query_trust(this_player()->query_name()) ) {
            msg_object(environment(ob_dest),"You automatically accept ("+this_player()->query_cap_name()+" is trusted).");
            msg(environment(ob_dest)->query_cap_name()+" trusts you, pour accepted.");
         } // end: if the target trusts the pourer
		 else {
            accept->set_verb(this_object());
            accept->set_yes( "on_accept", params );
            accept->set_no( "on_reject", params );
            accept->start(environment(ob_dest));
         } // end: if pouring into non-trusting player's inventory
         environment(ob_dest)->on_offer( ob_src, this_player() );
      }// end: if pouring into another player's inventory
      else {
         on_accept( ({ob_list, ob_src, ob_dest, shape, total_volume, result, contents, a, this_player()}) );
      }// end: normal pour into case
   }// end: if pour 'into'
   else {
      notify_fail( "Pour what into what?\n" );
      return 0;
   }
   return 1;
}// end: main

void on_accept( mixed params ) {
   object ob, *ob_list=params[0], ob_src=params[1], ob_dest=params[2], giving_player=params[8];
   mapping shape=params[3];
   int total_volume=params[4], result=params[5];
   string contents=params[6], a=params[7];

   if( ob_src->query_liquid() ) {
      ob_src = environment(ob_src);
   }
   if( !ob_dest->query_container() ) {
      msg( capitalize(ob_dest->query_name()) + " is not a container." );
      return;
   }

/*    if( !giving_player->query_touchable(ob_dest) ) {
         msg( "You're not close enough to pour anything into that. Walk to it first.");
         return;
      }
*/

   // ADDED 03.06.23
   if( shape = ob_dest->query_border() ) {
      WALK_DAEMON->init_walk_action(
        shape, ob_dest->query_coord(),
        ({ 0, this_object(), ob_dest, ST_STANDING, 0 })
      );
   } else {
      WALK_DAEMON->init_walk_action(
        WALK_DAEMON->shape_adjacent(),
        ob_dest->query_coord(),
        ({ 0, this_object(), ob_dest, ST_STANDING, 0 })
      );
   }// end: funky shape buildage

   ob_list = ({ });
   total_volume = 0;
   foreach( ob : all_inventory(ob_src) ) {
      if( ob->query_liquid() ) {
         ob_list += ({ ob });
         total_volume += ob->query_bulk();
      }
   }// end: foreach object in ob_Src

   if( total_volume == 0 ) {
      msg("No liquid to pour out of there.\n");
      return;
   }

   result = 0;
   if( ob_dest->query_name() != "construction" &&
       total_volume >= ob_dest->query_bulk_capacity() - ob_dest->query_held_bulk() ) {
      int i, new_vol;
      float percent = (ob_dest->query_bulk_capacity() - ob_dest->query_held_bulk()) / (float) total_volume;
      for( i = sizeof(ob_list); i--; ) {
         new_vol = (int) (ob_list[i]->query_quantity() * percent);
         if( new_vol == 0 ) ob_list[i] = 0;
         else ob_list[i]->split_quantity( new_vol );
      }
      ob_list -= ({ 0 });
      result = -1;
   } // end: if destination is a building site

   foreach( ob : ob_list) {
      ob->move( ob_dest );
   }
   ob_list -= ({ 0 });
   if( !sizeof(ob_list) ) {
      if( result < 0 ) {
         set_target( ob_dest );
         set_listener( this_player() );
         msg( process_grammar("~Subt is too full already."));
         return;
      }
      else {
         msg( capitalize(a->query_name()) + " cannot be poured.");
         return;
      }
   }// end: if no suitable objects were identified

   contents = inventory_string( ob_list );

   set_target( environment( ob_dest ) );
   if( result < 0 ) {
      if( environment( ob_dest )->query_is_player() && environment( ob_dest ) != giving_player )
         giving_player->msg_local( "~CACT~Name ~verbpour "+contents+" into ~npot "+ob_dest->query_name()+", filling it up completely.~CDEF" );
      else
         giving_player->msg_local( "~CACT~Name ~verbpour "+contents+" into "+ob_dest->query_name()+", filling it up completely.~CDEF" );
   } else
      if( environment( ob_dest )->query_is_player() && environment( ob_dest ) != giving_player )
         giving_player->msg_local( "~CACT~Name ~verbpour "+contents+" into ~npot "+ob_dest->query_name()+".~CDEF" );
      else
         giving_player->msg_local( "~CACT~Name ~verbpour "+contents+" into "+ob_dest->query_name()+".~CDEF" );
   ob_dest->on_pour_into( giving_player,total_volume );
   ob_src->on_pour_out( giving_player,total_volume );
   return;

   msg("Sorry, must use valid objects for pour.");
}// end: on_accept()

void on_reject( mixed* params ) {
   set_actor(this_player());
   set_target(params[8]);
   set_listener(params[8]);
   msg_object(params[8], "~Name ~verbhave rejected ~npot offer.");
   set_listener(this_player());
   msg_object(this_player(), "~Name ~verbhave rejected ~npot offer.");
}
