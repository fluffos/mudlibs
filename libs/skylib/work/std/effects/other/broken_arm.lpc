/*
 * This is the effect skelton docs.  This effect
 * has a classification of "body.damage.arm.broken".
 * <p>
 * 
 * The argument returned is an array:
 *   (*string) Arg[0] - a list of limbs which are broken
 * 
 * To add a new break: add_effect( player, ({ limb }) ), where limb
 *   is a string, usually "right" or "left".
 *
 * This effect has a shadow associated with it.
 * @classification body.damage.arm.broken
 * @see help::effects
 */

#define CLASS  "body.damage.arm.broken"
#define SHADOW "/std/shadows/other/broken_arm"

#include "/std/effects/other/path.h"
#include <effect.h>

/** @ignore yes */
string query_classification() { return CLASS; }

/** @ignore yes */
void beginning( object player, string *which ) {
  int handicap;
  object item;

  if( !playtesterp(player) ) return;

  player->add_extra_look( this_object() );

  handicap = (int)player->query_real_dex();
  handicap = ( sizeof( which ) * handicap ) / ( 2 + sizeof( which ) );
  player->adjust_bonus_dex( -handicap );

  handicap = (int)player->query_real_str();
  handicap = ( sizeof( which ) * handicap ) / ( 2 + sizeof( which ) );
  player->adjust_bonus_str( -handicap );

  if( member_array( "right", which ) != -1 ) {
    item = player->query_holding()[0];
    if( item ) {
      tell_object( player, sprintf( "You drop %s.\n",
          item->the_short() ) );
      item->move( environment( player ) );
    }
  }

  if( member_array( "left", which ) != -1 ) {
    item = player->query_holding()[1];
    if( item ) {
      tell_object( player, sprintf( "You drop %s.\n",
          item->the_short() ) );
      item->move( environment( player ) );
    }
  }

} /* beginning() */

/** @ignore yes */
void restart( object player, string *which ) {
  int handicap;
  player->add_extra_look( this_object() );

  handicap = (int)player->query_real_dex();
  handicap = ( sizeof( which ) * handicap ) / ( 2 + sizeof( which ) );
  player->adjust_bonus_dex( -handicap );

  handicap = (int)player->query_real_str();
  handicap = ( sizeof( which ) * handicap ) / ( 2 + sizeof( which ) );
  player->adjust_bonus_str( -handicap );

} /* restart() */

/** @ignore yes */
string *merge_effect( object player, string *which1, string *which2 ) {
  int i, handicap;
  object item;
  string *which;

  handicap = (int)player->query_real_dex();
  handicap = ( sizeof( which1 ) * handicap ) / ( 2 + sizeof( which1 ) );
  player->adjust_bonus_dex( handicap );

  handicap = (int)player->query_real_str();
  handicap = ( sizeof( which1 ) * handicap ) / ( 2 + sizeof( which1 ) );
  player->adjust_bonus_str( handicap );

  which = which1;

  for ( i = 0; i < sizeof( which2 ); i++ )
    if ( member_array( which2[ i ], which ) == -1 )
      which += ({ which2[ i ] });

  handicap = (int)player->query_real_dex();
  handicap = ( sizeof( which ) * handicap ) / ( 2 + sizeof( which ) );
  player->adjust_bonus_dex( -handicap );

  handicap = (int)player->query_real_str();
  handicap = ( sizeof( which ) * handicap ) / ( 2 + sizeof( which ) );
  player->adjust_bonus_str( -handicap );

  if( member_array( "right", which ) != -1 ) {
    item = player->query_holding()[0];
    if( item ) {
      tell_object( player, sprintf( "You drop %s.\n",
          item->the_short() ) );
      item->move( environment( player ) );
    }
  }

  if( member_array( "left", which ) != -1 ) {
    item = player->query_holding()[1];
    if( item ) {
      tell_object( player, sprintf( "You drop %s.\n",
          item->the_short() ) );
      item->move( environment( player ) );
    }
  }

  return which;
} /* merge_effect() */

/** @ignore yes */
void end( object player, string *which ) {
  int handicap;
  player->remove_extra_look( this_object() );
  handicap = (int)player->query_real_dex();
  handicap = ( sizeof( which ) * handicap ) / ( 2 + sizeof( which ) );
  player->adjust_bonus_dex( handicap );
  handicap = (int)player->query_real_str();
  handicap = ( sizeof( which ) * handicap ) / ( 2 + sizeof( which ) );
  player->adjust_bonus_str( handicap );
} /* end() */

/** @ignore yes */
string extra_look( object player ) {
  int *enums;
  string *which;
  enums = (int *)player->effects_matching( CLASS );

  if ( !sizeof( enums ) ) return "";

  which = (string *)player->arg_of( enums[ 0 ] );
  return capitalize( (string)player->query_pronoun() ) +" has broken "+
      (string)player->query_possessive() +" "+
      query_multiple_short( which ) +" arm"+
      ( sizeof( which ) == 1 ? "" : "s" ) +".\n";
} /* extra_look() */

/** @ignore yes */
int query_indefinite() { return 1; }

/** @ignore yes */
string query_shadow_ob() { return SHADOW; }


int query_theft_command() { return 1; }
