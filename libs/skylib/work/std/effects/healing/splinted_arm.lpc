/**
 * This is the effect skelton docs.  This effect
 * has a classification of "body.damage.arm.splinted".
 * <p>
 *
 * To add a splint to a limb, pass add_effect() ({ limb, time })
 *   limb: (string) "left" or "right"
 *   time: (int) (optional) seconds until limb is healed.  Defaults
 *         to 45 minutes (!)
 *
 * To heal a limb prematurely, pass add_effect() ({ limb, time, 1 })
 *   limb: (string) "left" or "right"
 *   time: (int) seconds until limb is healed - usually 0
 *
 * NB: healing a broken limb does not remove the splint effect from
 *     the patient.
 *
 * To remove a splint, pass add_effect ({ limb, time, 2 })
 *   limb: (string) "left" or "right"
 *   time: (int) seconds until limb is healed - usually 0
 *
 * NB: removing a splint from an unhealed limb adds the broken arm
 *     effect to the patient.
 *
 * The following args are returned by beginning and merge:
 *   [0] left arm splinted  ?  1 : 0
 *   [1] left arm healed    ?  1 : 0
 *   [2] right arm splinted ?  1 : 0
 *   [3] right arm healed   ?  1 : 0
 *
 * NB: the splint effect is indefinite and is not removed when the
 *     limb underneath heals.
 *
 * <p>
 * This effect has a shadow associated with it, but it isn't used. :)
 * @classification body.damage.arm.splinted
 * @see help::effects
 */

#define THIS_EFF  "/std/effects/healing/splinted_arm"
#define BREAK_EFF "/std/effects/other/broken_arm"
#define CLASS     "body.damage.arm.splinted"
#define SHADOW    "/std/shadows/healing/splinted_arm"

#define HEAL         1
#define REMOVE       2
#define DEF_TIME  2700

#include <effect.h>

/** @ignore yes */
string query_classification() { return CLASS; }

/** @ignore yes */
mixed beginning( object player, mixed args ) {  int left_splint;    /* left splint status */
  int right_splint;   /* right splint status */
  string which;       /* which arm is being splinted? */
  int time;           /* how long before it heals? */

  which = args[0];
  time =  sizeof( args ) > 1 ? args[1] : DEF_TIME;

  player->add_extra_look( this_object() );
  player->adjust_bonus_dex( -2 );
  player->adjust_bonus_str( -2 );

  if( which == "left" )  left_splint = 1;
  if( which == "right" ) right_splint = 1;

  player->submit_ee( "heal_"+which, time, EE_ONCE );

  return ({ left_splint, 0, right_splint, 0 });
} /* beginning() */

/** @ignore yes */
void restart( object player, mixed args ) {
   player->add_extra_look( this_object() );
   player->adjust_bonus_dex(  ( args[0] + args[2] ) * -2 );
   player->adjust_bonus_str(  ( args[0] + args[2] ) * -2 );
} /* restart() */

/** @ignore yes */
mixed *merge_effect( object player, mixed oldargs, mixed newargs ) {
  string which;  /* which limb is being affected? */
  int action;    /* what's being done to it? */
  int time;      /* how long before it's healed? */

  which  = newargs[0];
  time   = sizeof( newargs ) > 1 ? newargs[1] : DEF_TIME;
  action = sizeof( newargs ) > 2 ? newargs[2] : 0;

  /* am I removing the splint from a limb?  If so, check for
     breaks and readjust dex penalties */

  if( action == REMOVE ) {
    if( time ) {
      player->submit_ee( "remove_"+which, time, EE_ONCE );
      return oldargs;
    }
    if( which == "left" ) {  /* is my left arm still broken? */
      player->adjust_bonus_dex( 2 );
      player->adjust_bonus_str( 2 );
      if( !oldargs[1] ) 

   /* thanks to Taffyd for this bit: */
        call_out( (: $1->add_effect( $2, $3 ) :), 1, 
                     player, BREAK_EFF, ({ "left" }) );

      oldargs[0] = 0;
      oldargs[1] = 0;
    }
    if( which == "right" ) { /* is my right arm still broken? */
      player->adjust_bonus_dex( 2 );
      player->adjust_bonus_str( 2 );
      if( !oldargs[3] ) 

   /* ditto above */
        call_out( (: $1->add_effect( $2, $3 ) :), 1, 
                     player, BREAK_EFF, ({ "right" }) );
      oldargs[2] = 0;
      oldargs[3] = 0;
    }
    /* have I got any splints left? If not, end effect */
    if( !oldargs[0] && !oldargs[2] ) 
      player->submit_ee( "", 0, EE_REMOVE );
    return oldargs;
  }

  /* am I healing? */
  if( action == HEAL ) {
    if( time ) {
      player->submit_ee( "heal_"+which, time, EE_ONCE );
      return oldargs;
    }
    if( which == "left" )  {
      if( !oldargs[1] )
        tell_object( player, "Your left arm feels whole again.\n" );
      oldargs[1] = 1;
    }
    if( which == "right" ) {
      if( !oldargs[3] )
        tell_object( player, "Your right arm feels whole again.\n" );
      oldargs[3] = 1;
    }
    return oldargs;
  }

  /* Not removing or healing - splint new limb. */
  /* If limb wasn't already splinted, decrease dex */

  if( which == "left" ) {
    if( !oldargs[0] ) player->adjust_bonus_dex( -2 );
    if( !oldargs[0] ) player->adjust_bonus_str( -2 );
    oldargs[0] = 1;
    oldargs[1] = 0;
  }
  if( which == "right" ) {
    if( !oldargs[2] ) player->adjust_bonus_dex( -2 );
    if( !oldargs[2] ) player->adjust_bonus_str( -2 );
    oldargs[2] = 1;
    oldargs[3] = 0;
  }
  player->submit_ee( "heal_"+which, time, EE_ONCE );
  return oldargs;
} /* merge_effect() */

/** @ignore yes */
void heal_left( object player, mixed args ) {
  player->add_effect( THIS_EFF, ({ "left", 0, HEAL }) );
}

/** @ignore yes */
void heal_right( object player, mixed args ) {
  player->add_effect( THIS_EFF, ({ "right", 0, HEAL }) );
}

/** @ignore yes */
void remove_left( object player, mixed args ) {
  player->add_effect( THIS_EFF, ({ "left", 0, REMOVE }) );
}

/** @ignore yes */
void remove_right( object player, mixed args ) {
  player->add_effect( THIS_EFF, ({ "right", 0, REMOVE }) );
}

/** @ignore yes */
void end( object player, mixed args ) {
  player->remove_extra_look( this_object() );
} /* end() */

/** @ignore yes */
string extra_look( object player ) {
   int *enums;     /* effect numbers */
   int *args;      /* effect args */
   string *which;  /* splinted limbs */
   string str;     /* place holder for messaging */

   enums = player->effects_matching( query_classification() );
   if ( !sizeof( enums ) ) return "";
   args = player->arg_of( enums[0] );

   which = ({ });
   if( args[0] ) which += ({ "left" });
   if( args[2] ) which += ({ "right" });
   if( !sizeof( which ) ) return "";
 
   str = sizeof( which ) > 1  ? "splints" : "a splint";
   return capitalize( (string)player->query_pronoun() ) +
     " has "+ str +" on "+ (string)player->query_possessive() +
     " "+ implode( which, " and " ) + " arm" +
     ( sizeof( which ) == 1 ? "" : "s" ) + ".\n";
} /* extra_look() */

/** @ignore yes */
int query_indefinite() { return 1; }

/** @ignore yes */
//string query_shadow_ob() { return SHADOW; }

