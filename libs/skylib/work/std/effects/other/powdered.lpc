/**
 * This effect has a classification
 * of "body.look.powered".
 * <p>
 * @author Shaggy
 * @classification body.look.powdered
 * @see help::effects
 */
#include <effect.h>

#define TO this_object()

/** @ignore yes */
string query_classification() { return "body.look.powdered"; }

/** @ignore yes */
mixed beginning( object player, string colour ) {
   player->submit_ee( 0, 600, EE_REMOVE );
   player->add_extra_look( TO );

   return ({ colour });
} /* beginning() */

/** @ignore yes */
mixed merge_effect( object player, mixed oldcol, string newcol ) {
   int newtime;

   newtime = 600 + player->expected_tt();
   if( newtime > 1200 ) newtime = 1200;
   if( newtime < 0 ) newtime = 0;
   player->submit_ee( 0, newtime, EE_REMOVE );
   if (member_array(newcol,oldcol)==-1) oldcol+=({ newcol });
   return oldcol;
} /* merge_effect() */

void restart( object player ) {
   player->add_extra_look( TO );
} /* restart() */

/** @ignore yes */
void end( object pl, mixed arg, int id ) {
   pl->remove_extra_look(this_object());
} /* end() */

/** @ignore yes */
string extra_look( object pl ) {
   int *enums;

   enums = pl->effects_matching( "body.look.powdered" );
   if ( !sizeof( enums ) ) return "";
   if (pl->query_room_size())  
     return "Someone has sprinkled "
       +query_multiple_short(pl->arg_of(enums[0]))+
       " around here.\n";
   
   return pl->query_pronoun()+" is dusted with "
      +query_multiple_short(pl->arg_of(enums[0]))+".\n";
}/* extra_look() */











