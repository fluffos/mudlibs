/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: stinking_poop.c,v 1.1 1998/01/06 04:20:30 ceres Exp $
 * $Log: stinking_poop.c,v $
 * Revision 1.1  1998/01/06 04:20:30  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "body.smell.poop".
 * <p>
 * Describe the arguments in here.
 * @classification body.smell.poop
 * @see help::effects
 */
#include <effect.h>

/** @ignore yes */
void beginning( object player, int time, int id ) {
   tell_object( player, "You are scared so badly you soil yourself!\n" );
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
   tell_object( player, "The noxious cloud surrounding you disappears.\n" );
} /* end() */
 
void make_stink( object player, int time, int id ) {
   tell_object( player, "A disgusting smell wafts from your lower "+
         "portions.\n" );
   player->remove_hide_invis( "hiding" );
   tell_room( environment( player ),  "A foul odour emanates from "+
         (string)player->short() +"'s nether regions.\n", player );
} /* make_stink() */

/** @ignore yes */
string query_classification() { return "body.smell.poop"; }

string smell_string( object player, int time ) { 
   return "the disgusting smell of your lower portions";
} /* smell_string() */
