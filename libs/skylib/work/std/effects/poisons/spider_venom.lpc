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

string *wretch_msg = ({
    "Your stomach turns inside out, and you lose your lunch.\n",
    "You double over in pain.\n"
  });

string *room_msg = ({
    " convulses violently, and you're presented with a grand view " +
    "of a recent meal.\n",
    " groans and doubles over.\n",
    " seethes in agony.\n"
  });

/** @ignore yes */
string query_classification() { return "body.poison"; }

/** @ignore yes */
/* No need for a shadow
 * string query_shadow_ob() { return SHADOWS + "poison"; }
 */

/** @ignore yes */
int beginning( object player, int time, int id ) {
  player->submit_ee("wretch", ({ 30, 60 }), EE_CONTINUOUS);
  player->submit_ee( 0, time, EE_REMOVE );
  player->adjust_bonus_con( -5 );
  player->adjust_bonus_dex( -2 );
  tell_object(player, "Seething pains radiate from the wounds "
              "inflicted upon you by "+previous_object(1)->one_short()+".\n");
  return time;
} /* beginning() */

/** @ignore yes */
int merge_effect( object player, int time1, int time2 ) {
    player->submit_ee( 0, time1 + time2 - (int)player->expected_tt(),
                      EE_REMOVE );
    return time1 + time2;
} /* merge_effect() */

int restart( object player, int time, int id ) {
   player->adjust_bonus_con( -5 );
   player->adjust_bonus_dex( -2 );
   return time;
} /* restart() */

/** @ignore yes */
void end( object player, int time, int id ) {
   player->adjust_bonus_con( 5 );
   player->adjust_bonus_dex( 2 );
   tell_object( player, "You feel better now.\n" );
} /* end() */

void wretch(object player, int time, int id) {
    int msg_no;

    msg_no = random( sizeof( wretch_msg ) );
    tell_object( player, wretch_msg[ msg_no ] );
    tell_room( environment( player ), (string)player->the_short() +
              room_msg[ msg_no ], player);
    player->adjust_hp( -(int)player->query_hp() / 10 );
    HEALTH_H->monitor_points(player, 1);
} /* wretch() */
