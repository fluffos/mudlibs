#include <sys/regexp.h>
inherit "/ai/module";

mixed com_queue = ({ });

void heart_beat() {
   string curr_com;

   if( sizeof(com_queue) == 0 ) {
      set_heart_beat(0);
      return;
   }

   curr_com = com_queue[0];
   com_queue = com_queue[1..];

   if ( closurep( curr_com ) )
      funcall( curr_com );
   else if( stringp(curr_com) )
      command( curr_com, environment() );
   else debug( "Garbage response " + as_lpc(curr_com) + " in " + as_lpc(environment()) );
}

string query_module_name() {
   return "talk";
}

varargs void do_response( mixed response, varargs mixed *args ) {
   if( pointerp(response) ) {
      int i;
      for( i = 0; i < sizeof(response); i++ ) {
         if( closurep(response[i]) )
            com_queue += ({ (: apply(response[i], args) :) });
         else
            com_queue += ({ response[i] });
      }
   }
   else {
      if( closurep(response) )
         com_queue += ({ (: apply(response, args) :) });
      else
         com_queue += ({ response });
   }
   set_heart_beat( 1 );
}

void on_talk( string text, object actor, object target ) {
   mixed response;

   if( actor == environment() ) return;
   if( target == environment() || !target ) {
      text = lower_case( text );
      text = regreplace( text, "[^a-z_ ]", "", RE_GLOBAL );
      if( response = environment()->parse_talk(text, actor, target) ) {
         if( actor && stringp(response) )
            response = implode( explode(response, "$(SPEAKER)"), actor->query_cap_name() );
         if( actor && pointerp(response) )
            response = map(response, (: stringp($1)?implode(explode($1, "$(SPEAKER)"), actor->query_cap_name()):$1 :) );

         do_response( response, text, actor, target );
      }
   }
}

void on_show( object ob, object actor, object target ) {
   mixed response, condition;

   response = environment()->query_show_response();
   if( !response ) return;
   condition = environment()->query_show_condition();
   if( condition && !funcall(condition, ob, actor, target) ) return;
   do_response( response, ob, actor, target );
}

void on_sight( object ob, object source ) {
   mixed response, condition;

   response = environment()->query_sight_response();
   if( !response ) return;
   condition = environment()->query_sight_condition();
   if( condition && !funcall(condition, ob, source) ) return;
   do_response( response, ob, source );
}

void on_depart( object who, string moveverb, string direction, object destination ) {
   mixed response, condition;

   response = environment()->query_depart_response();
   if( !response ) return;
   condition = environment()->query_depart_condition();
   if( condition && !funcall(condition, who, moveverb, direction, destination) ) return;
   do_response( response, who, moveverb, direction, destination );
}
