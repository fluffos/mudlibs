/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: cum_poison.c,v 1.1 1998/01/06 04:14:00 ceres Exp $
 * $Log: cum_poison.c,v $
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

// This is a slow, cumulative poison.  It's mainly to keep people
// from gorging themselves on plants that have a healing effect.
// I'm writing this as if it could be parameterized, even though there's
// currently no way to do that, at least from an eat_effect.

// The default values will cause the effect to be dormant until the
// cumulative duration exceeds 10 minutes.

#define MIN_TIME 600
#define DEPLETION_TIME 60
#define DEPLETION_AMT 60
#define IDLE_TIME 120
#define HP_PCT 10

class arg_info {
    int min_time;
    int depletion_time;
    int depletion_amt;
    int idle_time;
    int hp_pct;
    int msg_flag;
    int time_left;
}

string *wretch_msg = ({
    "Your vision goes blurry and you begin to sweat.\n",
    "Your stomach turns inside out, and you lose your lunch.\n",
    "You double over in pain.\n"
  });

function *room_msg = ({
    (: $1->the_short() + " looks a little dazed.\n" :),
    (: $1->the_short() + " convulses violently, and you're "
     + "presented with a grand view of " + $1->query_possessive()
     + " most recent meal.\n" :),
    (: $1->the_short() + " groans and doubles over.\n" :),
    (: $1->the_short() + " turns a variety of colours.\n" :)
  });

/** @ignore yes */
string query_classification() { return "body.poison"; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS + "poison"; }

/** @ignore yes */
mixed beginning( object player, int time, int id ) {
    class arg_info arg;

    arg = new(class arg_info);
    arg->min_time = MIN_TIME;
    arg->depletion_time = DEPLETION_TIME;
    arg->depletion_amt = DEPLETION_AMT;
    arg->idle_time = IDLE_TIME;
    arg->hp_pct = HP_PCT;
    arg->time_left = time;
    if (time > arg->min_time) {
        player->submit_ee( "start_wretching", arg->idle_time,
                          EE_ONCE );
    }
    player->submit_ee("deplete", arg->depletion_time, EE_CONTINUOUS);
    return arg;
} /* beginning() */

/** @ignore yes */
mixed merge_effect( object player, class arg_info arg, int time1 ) {

    //printf("arg = %O\ntime1 = %O\n", arg, time1);
    arg->time_left += time1;
    if (!arg->msg_flag && (arg->time_left > arg->min_time)) {
        player->submit_ee( "start_wretching", arg->idle_time, EE_ONCE );
    }
    return arg;
} /* merge_effect() */
 
/** @ignore yes */
void end( object player, class arg_info arg, int id ) {

    // No message for "short" effects
    if (!arg->msg_flag) return;
    tell_object( player, "You feel better now.\n" );
    player->set_inactive("poison");
} /* end() */

void start_wretching( object player, class arg_info arg, int id ) {
    arg->msg_flag = 1;
    player->set_active("poison");
    player->submit_ee("wretch", ({ 30, 60 }), EE_CONTINUOUS);
    tell_object(player, "You suddenly don't feel very well.  Maybe it " +
                "was something you ate.\n");
}
    
void wretch(object player, class arg_info arg, int id) {
    int msg_no;

    msg_no = random(sizeof(wretch_msg));
    tell_object(player, wretch_msg[msg_no]);
    tell_room(environment(player), evaluate(room_msg[msg_no], player), player);
    player->adjust_hp(-(int)player->query_hp()/arg->hp_pct);
}

void deplete( object player, class arg_info arg, int id ) {
    arg->time_left -= arg->depletion_time;
    if (arg->time_left <= 0)
      player->submit_ee(0, 0, EE_REMOVE);
}
