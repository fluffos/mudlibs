/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: rubbish_smell.c,v 1.1 1998/01/06 04:20:30 ceres Exp $
 * $Log: rubbish_smell.c,v $
 * Revision 1.1  1998/01/06 04:20:30  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "body.smell.rubbish".
 * <p>
 * Describe the arguments in here.
 * @classification body.smell.rubbish
 * @see help::effects
 */
#include <effect.h>

/** @ignore yes */
void beginning( object player, int time, int id ) {
   tell_object( player, "You become aware of an embarassingly strong "
         "smell similar to rotting rubbish coming from your body.\n" );
   tell_room( environment( player ), "The revolting smell of rotting rubbish "
         "starts to reek from "+ (string)player->one_short() +
         "'s body.\n", player );
   player->submit_ee( "make_stink", ({ 20, 20 }), EE_CONTINUOUS );
   player->submit_ee( 0, time, EE_REMOVE );
} /* beginning() */

/** @ignore yes */
int merge_effect( object player, int time1, int time2, int id ) {
   player->submit_ee( 0, time1 + time2 - (int)player->expected_tt(),
         EE_REMOVE );
   return time1 + time2;
} /* merge_effect() */
 
/** @ignore yes */
void end( object player, int time, int id ) {
   tell_object( player, "The terrible rubbish smell finally fades away.\n" );
} /* end() */
 
void make_stink( object player, int time, int id ) {
   tell_object( player, "The smell of rotting rubbish wafts from your "
         "body.\n" );
   tell_room( environment( player ), "The revolting smell of rotting "
         "rubbish wafts over to you from "+ (string)player->one_short() +
         ".\n", player );
} /* make_stink() */

/** @ignore yes */
string query_classification() { return "body.smell.rubbish"; }

string smell_string( object player, int time ) {
   return "the horrible rubbish smell";
} /* smell_string() */
