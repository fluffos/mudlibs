/**
 * This is the effect skelton docs.  This effect
 * has a classification of "body.wetness".
 * <p>
 * Describe the arguments in here.
 * @classification body.wetness
 * @see help::effects
 */
#include "path.h"
#include <effect.h>
#include <weather.h>

#define MAX_EFFECT 200
#define MAX_DURATION 120
#define MAX_STRENGTH 240
#define MIN_STRENGTH 20

/** @ignore yes */
string query_classification() { return "body.wetness"; }

/** @ignore yes */
int beginning( object player, int wetness, int id ) {
  int dryness;

  if(!ENV(player)->query_water())
   tell_object( player, "Squelch.\n" );
  player->submit_ee( "squelch", ({ 20, 20 }), EE_CONTINUOUS );
  player->add_extra_look( this_object() );

  // check for magical (or other) protection from the rain.
  if(dryness = (int)player->check_dryness())
    wetness -= dryness;

  if ( wetness > (int)player->query_weight() )
    wetness = (int)player->query_weight();

  return wetness;
}

/** @ignore yes */
void restart( object player ) {
  player->add_extra_look( this_object() );
}

/** @ignore yes */
int merge_effect( object player, int new_wetness, int old_wetness, int id ) {
  int wetness, dryness;

  wetness = new_wetness + old_wetness;

  // check for magical (or other) protection from the rain.
  if(dryness = (int)player->check_dryness())
    wetness -= dryness;

  if ( wetness > (int)player->query_weight() )
      wetness = (int)player->query_weight();

  if ( wetness <= 0 )
    player->submit_ee(0, 0, EE_REMOVE );

  return wetness;
}

// End the effect
/** @ignore yes */
void end( object player, int strength, int id ) {
  tell_object(player, "You feel dry now.\n");
  player->remove_extra_look( this_object() );
}

void squelch(object player, int wetness, int id) {
  string loc;
  object env;
  int bingle;

  env = environment(player);

  if(!env)
    return;

  loc = (string)env->query_property("location");

  if(loc == "outside" && (int)WEATHER->query_temperature(env) > 0) {
    bingle = (int)WEATHER->query_temperature(env) / 2 +
      env->query_property("warmth");
  } else if(loc == "inside")
    bingle = (20 / 2) + env->query_property( "warmth" );

  if(player->query_personal_temp() / 3 > bingle)
    bingle -= (player->query_personal_temp() / 3);

  if(bingle > 0)
    wetness -= bingle;

  if(player->query_property("dead"))
    player->submit_ee(0, 0, EE_REMOVE );
  
  //player is underwater (don't squelch or remove)
  if(env->query_water())
     return;

  if(wetness <= 0)
    player->submit_ee(0, 0, EE_REMOVE );

  if (wetness > 10 && !random(3) )
    tell_object(player, "Squelch.\n" );
  /*
  if ( ( ( 100 * wetness ) > ( 80 * (int)player->query_weight() ) ) &&
      !random( 1440 ) && !( creatorp(player) ) )
    player->add_effect( "/std/effects/disease/common_cold", wetness);
  */
  player->set_arg_of(player->sid_to_enum(id), wetness);

}

string extra_look( object player ) {
  string desc;
  int wetness;
  int *enums;

  enums = (int *)player->effects_matching( "body.wetness" );
  if ( !sizeof( enums ) )
    return "";

  wetness = (int)player->arg_of(enums[0]);

  if (!intp(wetness)) {
     wetness = 0;
     player->submit_ee(0, 0, EE_REMOVE );
  }

  switch ( ( wetness * 100 ) / ( 1 +
      (int)player->query_weight() ) ) {
    case 1 .. 5 :
      desc = "looks slightly wet.\n";
      break;
    case 6 .. 10 :
      desc = "looks rather wet.\n";
      break;
    case 11 .. 30 :
      desc = "looks wet and bedraggled.\n";
      break;
    case 31 .. 80 :
      desc = "is soaked, and doesn't look that well at all.\n";
      break;
    case 81 .. 100 :
      desc = "looks like "+ (string)player->query_pronoun() +
          " has just been dunked in a lake.\n";
      break;
    default :
      return "";
  }
  return capitalize( (string)player->query_pronoun() ) +" "+ desc;
} /* extra_look() */
