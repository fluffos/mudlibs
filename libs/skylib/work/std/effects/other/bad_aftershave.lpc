/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: bad_aftershave.c,v 1.3 2000/06/08 21:34:13 drakkos Exp $
 * $Log: bad_aftershave.c,v $
 * Revision 1.3  2000/06/08 21:34:13  drakkos
 * Made 'goat' into an array so it didn't choke when the results match_objects_for_existence() were assigned.
 *
 * Revision 1.2  2000/06/08 03:13:45  pinkfish
 * Remove references to find_match.
 *
 * Revision 1.1  1998/01/06 04:20:30  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "mind.avoidance".
 * <p>
 * Describe the arguments in here.
 * @classification mind.avoidance
 * @see help::effects
 */
/*  Bad Aftershave  *
 *     Mariana      *
 *     Gototh       *
 *    09/11/97      */

#include <effect.h>

/**
 * @ignore yes
 */
/** @ignore yes */
void beginning(object player, int time, int) {
  tell_object(player, "You are surrounded by a distinct "
    "odour of goat!\n");
  player->submit_ee("make_stink", ({ 20, 20 }), EE_CONTINUOUS);
  player->submit_ee(0, time, EE_REMOVE );
} /* beginning() */

/**
 * @ignore yes
 */
/** @ignore yes */
int merge_effect(object player, int time1, int time2, int id) {
  player->submit_ee(0, time1 + time2 - player->expected_tt(), EE_REMOVE);
  return time1 + time2;
} /* merge_effect() */

/**
 * @ignore yes
 */
/** @ignore yes */
void end(object player, mixed *args, int id) {
  tell_object(player, "The distinct odour of goat fades away.\n");
} /* end() */
 
void make_stink(object player, int, int) {
  object *goat;
  tell_object(player, 
    "The distinct odour of goat wafts around you.\n");
  player->remove_hide_invis("hiding");
  tell_room(environment(player), 
    "The distinct odour of goat wafts from "
    +player->the_short()+".\n", player);
  goat = match_objects_for_existence("goat", ({ environment(player) }));
  if(sizeof(goat)) {
    goat->fall_in_love(player);
  }
} /* emit_scent() */

/**
 * @ignore yes
 */
/** @ignore yes */
string query_classification() { 
  return "body.smell.badaftershave";
} /* query_classification() */

string smell_string(object player, mixed *args) {
  return "the distinct odour of goat";
} /* smell_string() */

