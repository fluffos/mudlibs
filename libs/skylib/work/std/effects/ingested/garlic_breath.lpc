/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: garlic_breath.c,v 1.1 1998/01/06 04:14:00 ceres Exp $
 * $Log: garlic_breath.c,v $
 * Revision 1.1  1998/01/06 04:14:00  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "mouth.smell.garlic".
 * <p>
 * Describe the arguments in here.
 * @classification mouth.smell.garlic
 * @see help::effects
 */
#include <effect.h>

/** @ignore yes */
void beginning( object player, int time ) {
   player->submit_ee( "make_smell", ({ 20, 20 }), EE_CONTINUOUS );
   player->submit_ee( 0, time, EE_REMOVE );
} /* beginning() */

/** @ignore yes */
int merge_effect( object player, int time1, int time2 ) {
   player->submit_ee( 0, time1 + time2 - (int)player->expected_tt(),
         EE_REMOVE );
   return time1 + time2;
} /* merge_effect() */
 
/** @ignore yes */
void end( object player, int time ) {
   tell_object( player, "Your breath seems fresher.\n" );
} /* end() */
 
void make_smell( object player ) {
   tell_object( player, "A garlicky smell wafts out as you exhale.\n" );
   tell_room( environment( player ),  "The strong smell of garlic reaches "+
         "you as "+ (string)player->short() +" exhales.\n", player );
} /* make_smell() */

/** @ignore yes */
string query_classification() { return "mouth.smell.garlic"; }
