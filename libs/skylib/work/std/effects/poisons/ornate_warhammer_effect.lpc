/**
 * Modified by Venom for the use of the ORNATE WARHAMMER.
 * 22/11/97
 *
 * This is the effect skelton docs.  This effect
 * has a classification of "body.poison.warhammer".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has no shadow associated with it.
 * @classification body.poison
 * @see help::effects
 */
#include "path.h"
#include <effect.h>

void create() {
   seteuid( (string)"/secure/master"->
         creator_file( file_name( this_object() ) ) );
} /* create() */

string *wretch_msg = ({
    "Your face feels very chilled all of a sudden.\n",
    "There is a slight twinge in your chest.\n",
    "You fall down and writhe in pain.\n"
  });

string *room_msg = ({
    "'s face turns a greenish hue.\n",
    " has some trouble breathing.\n",
    " screams in agony.\n"
  });

/** @ignore yes */
string query_classification() { return "body.poison.warhammer"; }

/** @ignore yes */
string query_death_reason() { return "ornate warhammer's poison"; }


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
  tell_object(player, "Seething pains radiate from the poison seeped from "
              "the ornate warhammer.\n");
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
    int damage;

    damage = ( (int)player->query_hp() / 20 );
    damage -= (int)player->query_ac( "poison", damage );

    if( damage < 1 )
      return;

    msg_no = random( sizeof( wretch_msg ) );
    tell_object( player, wretch_msg[ msg_no ] );
    tell_room( environment( player ), (string)player->the_short() +
              room_msg[ msg_no ], player);
    player->adjust_hp( -damage );
    if ( (int)player->query_hp() < 0 )
      player->attack_by( this_object() );

} /* wretch() */

