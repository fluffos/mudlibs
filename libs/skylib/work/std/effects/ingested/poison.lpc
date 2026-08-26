/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: poison.c,v 1.3 1999/10/27 09:42:21 taffyd Exp $
 * $Log: poison.c,v $
 * Revision 1.3  1999/10/27 09:42:21  taffyd
 * Fixed typo
 *
 * Revision 1.2  1999/07/19 19:04:01  macchirton
 *  Forcibly unlocked by ceres
 *
 * Revision 1.1  1998/01/06 04:14:00  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "body.poison".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification body.poison
 * @see help::effects
 */
#include "path.h"
#include <effect.h>

#define MIN_TIME 60

string *wretch_msg = ({
    "Your stomach turns inside out, and you lose your lunch.\n",
    "You double over in pain.\n"
  });

string *room_msg = ({
    " convulses violently, and you're presented with a grand view"
      " of a recent meal.\n",
    " groans and doubles over.\n",
    " turns a variety of colours.\n"
  });

/** @ignore yes */
string query_classification() { return "body.poison"; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS + "poison"; }

/** @ignore yes */
int beginning( object player, int time, int id ) {
    if (time < MIN_TIME) {
        player->submit_ee( 0, 0, EE_REMOVE );
        return 0;
    }
    player->submit_ee("wretch", ({ 30, 60 }), EE_CONTINUOUS);
    player->submit_ee( 0, time, EE_REMOVE );
    player->set_active("poison");
    tell_object(player, "You suddenly don't feel very well.  Maybe it " +
                "was something you ate.\n");
    return time;
} /* beginning() */

/** @ignore yes */
int merge_effect( object player, int time1, int time2 ) {

    player->set_active("poison");
    player->submit_ee( 0, time1 + time2 - (int)player->expected_tt(),
                      EE_REMOVE );
    return time1 + time2;
} /* merge_effect() */
 
/** @ignore yes */
void end( object player, int time, int id ) {

    // No message for "short" effects
    if (time < MIN_TIME) return;
    tell_object( player, "You feel better now.\n" );
    player->set_inactive("poison");
} /* end() */
 
void wretch(object player, int time, int id) {
    int msg_no;

    msg_no = random(sizeof(wretch_msg));
    tell_object(player, wretch_msg[msg_no]);
    tell_room(environment(player), (string)player->short() +
              room_msg[msg_no], player);
    player->adjust_hp(-(int)player->query_hp()/10);
}
