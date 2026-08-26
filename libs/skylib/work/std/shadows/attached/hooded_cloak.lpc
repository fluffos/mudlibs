#include "path.h"

inherit "/std/effect_shadow";

int query_hooded() { return 1; }

int query_disguised() { return 1; }

/*
 * This is all wrong!  Ick!
int new_parser( string words ) {
   int which;
   object *things;
   if ( sscanf( words, "raise %s", words ) )
      which = 0;
   else
      if ( sscanf( words, "lower %s", words ) )
         which = 1;
      else
         return (int)player->new_parser( words );
   sscanf( words, "hood of %s", words );
   things = find_match( words, player );
   if ( !sizeof( things ) )
      return notify_fail( "Syntax: "+ ( which ? "lower" : "raise" ) +
            " [hood of] <object>\n" );
   if ( member_array( EFFECTS +"hooded_cloak",
         (string *)things[ 0 ]->query_wear_effects() ) == -1 )
      return notify_fail( (string)things[ 0 ]->the_short() +" does not have "+
            "a hood to "+ ( which ? "lower" : "raise" ) +".\n" );
   if ( which != arg() )
      return notify_fail( (string)things[ 0 ]->the_short() +"'s hood is "+
            "already "+ ( which ? "lowered" : "raised" ) +".\n" );
   write( "You"+ ( which ? " lower " : " raise " ) +
         (string)things[ 0 ]->the_short() +"'s hood.\n" );
   say( (string)player->one_short() + ( which ? " lowers " : " raises " ) +
         "the hood of "+ (string)things[ 0 ]->poss_short() +".\n" );
   if ( !which )
      all_inventory( environment( player ) )->print_messages();
   set_arg( !which );
   return 1;
} / * new_parser() * /
 */

string query_determinate( object thing ) {
   if ( arg() )
      return "a ";
   return (string)player->query_determinate( thing );
} /* query_determinate() */

string pretty_short( object thing ) {
   if ( !arg() )
      return (string)player->pretty_short();
   if ( objectp( thing ) )
      if ( creatorp(thing) )
         return "hooded stranger ("+ (string)player->query_name() +")";
   return "hooded stranger";
} /* pretty_short() */

string pretty_plural( object thing ) {
   if ( !arg() )
      return (string)player->pretty_short();
   if ( objectp( thing ) )
      if ( creatorp(thing) )
         return "hooded strangers ("+ (string)player->query_name() +")";
   return "hooded strangers";
} /* pretty_plural() */

void now_removed( object thing ) {
   player->now_removed( thing );
   if ( member_array( EFFECTS +"hooded_cloak",
         (string *)thing->query_wear_effects() ) != -1 )
      remove_this_effect();
} /* now_removed() */
string extra_score() {
   if ( arg() )
      return "Your identity is occulted by a hood.\n"+
            (string)player->extra_score();
   return (string)player->extra_score();
} /* extra_score() */
