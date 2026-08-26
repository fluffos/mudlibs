/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: dog_urinate.c,v 1.1 1998/01/06 04:20:30 ceres Exp $
 * $Log: dog_urinate.c,v $
 * Revision 1.1  1998/01/06 04:20:30  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "body.smell.urinate".
 * <p>
 * Describe the arguments in here.
 * @classification body.smell.urinate
 * @see help::effects
 */
#include <effect.h>

/** @ignore yes */
void beginning( object player, int time, int id ) {
   player->submit_ee( "make_stink", ({ 20, 20 }), EE_CONTINUOUS );
   player->submit_ee( 0, time, EE_REMOVE );
} /* beginning() */

/** @ignore yes */
int merge_effect( object player, int time1, int time2, int id ) {
   player->submit_ee( 0, time1 + time2 - (int)player->expected_tt(),
         EE_REMOVE );
} /* merge_effect() */
 
/** @ignore yes */
void end( object player, int time, int id ) {
   tell_object( player, "The noxious cloud surrounding you disappears.\n" );
} /* end() */
 
void make_stink( object player, int time, int id ) {
   tell_object( player, "A disgusting smell wafts up from your leg.\n");
   player->remove_hide_invis( "hiding" );
   tell_room( environment( player ),  "A foul odour emanates from "+
         (string)player->the_short() +"'s leg, like a dog has urinated on "+
         (string)player->query_objective() +".\n", ({ player }) );
} /* make_stink() */

/** @ignore yes */
string query_classification() { return "body.smell.urinate"; }

string smell_string( object player, int time ) {
   return "the stench of canine urine";
} /* smell_string() */
