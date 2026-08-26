/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: rat_reincarnation.c,v 1.1 1998/01/06 04:20:30 ceres Exp $
 * $Log: rat_reincarnation.c,v $
 * Revision 1.1  1998/01/06 04:20:30  ceres
 * Initial revision
 * 
*/
/*  Rat Effect  *
 *    Gototh    *
 *   10/12/97   */

#include "path.h"
#include <effect.h>

string query_classification() {
  return "reincarnation.rat";
} /* query_classification() */

string query_shadow_ob() {
  return SHADOWS+"rat_reincarnation";
} /* query_shadow_ob() */

int beginning(object player, int time) {
  player->add_alias("rat");
  player->add_property("determinate", "a ");
  if(time) {
    player->submit_ee(0, time, EE_REMOVE);
  }
  return time;
} /* beginning() */

int merge_effect(object player, int time1, int time2) {
  int duration;
  duration = time2 + player->expected_tt();
  player->submit_ee(0, duration, EE_REMOVE);
  return duration;
} /* merge_effect() */

void end(object player, int time) {
  player->add_property("determinate", "");
  player->remove_alias("rat");
  tell_object(player,
    "Your fear of cats, longing for cheese, and conpulsion "
    "to wriggle your nose subsides.\n");
} /* end() */

