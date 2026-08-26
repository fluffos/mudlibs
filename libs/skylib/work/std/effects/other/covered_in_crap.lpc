/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: covered_in_crap.c,v 1.2 2000/05/01 08:32:55 drakkos Exp $
 * $Log: covered_in_crap.c,v $
 * Revision 1.2  2000/05/01 08:32:55  drakkos
 * Fixed a pyto.
 *
 * Revision 1.1  1998/01/06 04:20:30  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "body.smell.crap".
 * <p>
 * Describe the arguments in here.
 * @classification body.smell.crap
 * @see help::effects
 */
#include <effect.h>

/** @ignore yes */
void beginning( object player, int time, int id ) {
   tell_object( player, "You are covered in festering excrement!\n" );
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
   tell_object( player, "The disgusting stink is drowned out by "
                        "other less offensive bodily odours.\n" );
} /* end() */
 
void make_stink( object player, int time, int id ) {
   tell_object( player, "A disgusting smell wafts from your "
         "excrement smeared body.\n" );
   player->remove_hide_invis( "hiding" );
   tell_room( environment( player ),  "A foul yet familiar odour "
         "emanates from "+(string)player->short() +".\n", player );
} /* make_stink() */

/** @ignore yes */
string query_classification() { return "body.smell.crap"; }

string smell_string( object player, int time ) { 
   return "the disgusting smell of your lower portions";
} /* smell_string() */