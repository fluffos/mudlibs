/**
 * This is the effect skelton docs.  This effect
 * has a classification of "body.drunk".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification body.drunk
 * @see help::effects
 */

#include "path.h"
#include <effect.h>
#include <living.h>
#include <position.h>

/* The effects of being drunk */
/* The initial arg (to add_effect()) is roughly the alcohol volume
 * from the old system.  It is converted to seconds of duration via
 * 2*arg/query_con().  For the other routines, the arg is a 2-element
 * array: the duration, and the max duration over the lifetime of the
 * effect (for use in end()).
 */
/** @ignore yes */

#define HANGOVER 1000
mapping compass = ([ "north" : 1, "northeast" : 1, "east" : 1, "southeast" : 1,
                     "south" : 1, "southwest" : 1, "west" : 1, "northwest" : 1
                    ]);
void come_around( object person );

/** @ignore yes */
string query_classification() { return "body.drunk"; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS + "drunk"; }

int counter( object person, int bonus ) {
    // This effect will counteract "knurd" and, to some extent, "hungover"
    // (note that since these effects don't yet exist, this function may
    // not be tested :).
    int i, *effnums, b;
    class effect *effs;

    if ( !person ) return 0;
    if ( !living( person ) ) return 0;
    b = bonus;
    effs = (class effect *)person->query_effs();
    // Knurd
    effnums = (int *)person->effects_matching( "body.knurd" );
    for ( i = sizeof( effnums ) - 1; i >= 0; i-- ) {
        b -= effs[ effnums[ i ] ]->ob_name->test_remove( person,
            effs[ effnums[ i ] ]->arg, effnums[ i ], b );
        if ( !b ) {
            person->submit_ee( 0, 0, EE_REMOVE );
            return 0;
        }
    }
    // Hungover
    effnums = (int *)person->effects_matching( "body.hungover" );
    for ( i = sizeof( effnums ) - 1; i >= 0; i-- ) {
        b -= effs[ effnums[ i ] ]->ob_name->test_remove( person,
            effs[ effnums[ i ] ]->arg, effnums[ i ], b/10 ) * 10;
        if ( !b ) {
            person->submit_ee( 0, 0, EE_REMOVE );
            return 0;
        }
    }
    return b;
} /* counter() */

/** @ignore yes */
int *beginning( object person, int extent, int ) {
  int x, c;

  // The duration should be similar to the old /global/player drunk
  // effect, ie, time = 2*extent/query_con().
  person->submit_ee( "drunk_behaviour", ({ 10, 60 }), EE_CONTINUOUS );
  if (c = person->query_con())
    x = 2 * extent / c;
  else
    x = 2 * extent;
  x = counter( person, x );
  person->submit_ee( 0, x, EE_REMOVE );
  return ({ x, x });
} /* beginning() */

/** @ignore yes */
int *merge_effect( object person, int *old_extent, int new_extent ) {
  int extent, c, m;

  if ( !(c = person->query_con()) )
    c = 1;
  extent = 2*new_extent/c + person->expected_tt();
  extent = counter( person, extent );
  person->submit_ee( 0, extent, EE_REMOVE );
  m = old_extent[1];
  if( extent > m )
      m = extent;

  return ({ extent, m });

} /* merge_effect() */

/** @ignore yes */
void end( object person, int *extent ) {
  if( person->query_property( PASSED_OUT ) )
      come_around( person );
  if( extent[1] > 60 )
      tell_object( person, "As the features of the world become painfully "
                "clear, you realize you are once again sober.\n" );
  if( ( extent[1] > HANGOVER) || ( extent[1] > random( HANGOVER ))) {
      // Put hangover effect here
  }
} /* end() */

void drunk_behaviour( object person, int *) {
  int i, intox, damage, selector;
  object thing, *things, tp;

  intox = (int)person->expected_tt();

  if( person->query_property( PASSED_OUT ) ) {
      switch ( random ( 4 ) ) {
        case 0 :
          tell_room( ENV(person), person->the_short()+" snores "
              "contentedly.\n", person );
        break;
        case 1 :
          tell_room( ENV(person), person->the_short()+" mutters something "
              "about "+person->HIS+" mother.\n", person );
        break;
        default :
          tell_room( ENV(person), person->the_short()+" opens "+
              person->HIS+" eyes, looks around stupidly, and passes out"
              " again.\n", person );
      }
      return;
  }

  selector = random( intox ) / person->query_con() / 5;

  tp = TP;
  set_this_player( person );

  switch ( selector ) {
    case 0 :
      break;
    case 1 :
    case 2 :
      switch ( random( 4 ) ) {
        case 0 :
          person->new_parser("hiccup");
          break;
        case 1 :
          person->new_parser("burp");
          break;
        case 2 :
          person->new_parser("trip");
          break;
        default :
          person->new_parser("stagger");
          break;
      }
    break;
    case 3 :
      tell_object( person, "You trip over and fall on your "+
                  "face.\n" );
      tell_room( ENV(person), person->the_short()+" trips over and "+
          "falls on "+person->HIS+" face.\n", person );
    break;
    case 4 :
      person->new_parser( "puke" );
    break;
    case 5 :
      switch( random( 2 ) ) {
        case 0 :
          things = INV( person );
          while( sizeof( things ) && !thing ) {
              i = random( sizeof( things ) );
              if( !things[ i ]->short() || things[ i ]->query_worn() ) {
                  things = delete( things, i, 1 );
                  continue;
              }
              if( things[ i ]->move( ENV(person) ) ) {
                  things = delete( things, i, 1 );
                  continue;
              }
              thing = things[ i ];
          }

          if( !thing )
              break;
          tell_object( person, "Oops, butterfingers, you have dropped "+
              thing->poss_short()+".\n");
          tell_room( ENV(person), person->the_short()+" stumbles "+
              "and drops "+thing->a_short()+".\n", person );
        break;
        case 1 :
          tell_object( person, "You fall heavily, bruising yourself "+
              "nicely.\n" );
          tell_room( ENV(person), person->the_short()+" falls heavily.  "
              "You wince in sympathy.\n", person );
          damage = random( (int)person->query_weight() / 10 );
          damage -= person->query_ac("blunt", damage );
          person->adjust_hp( -damage );
          break;
      }
      break;
    default :
      if( intox > 0 ) {
          switch ( random( 2 ) ) {
            case 0 :
              tell_object( person, "The world goes black.  You have "+
                  "passed out.\n" );
              tell_room( ENV(person), person->the_short()+" looks ill, "
                  "then falls over and lies there with a blank look on "+
                  person->HIS+" face.\n", person );
              person->add_property( PASSED_OUT, 1 );
              person->submit_ee("come_around", ({ 50, 80 }), EE_ONCE );
              // Silently make them lie down.
              LYING_CMD->position( person, 1 );
            break;
            case 1 :
              person->submit_ee("wander_about", 3, EE_ONCE );
            break;
          }
      }
  }

  set_this_player(tp);

} /* drunk_behaviour() */

void come_around( object person ) {
  tell_object( person, "Something blurry appears before you.  You "+
      "realise it's the multiverse and pick yourself up.\n" );
  tell_room( ENV(person),
      capitalize( (string)person->the_short() ) +" blinks "+
      (string)person->query_possessive() +" eyes blearily and "+
      "picks "+ (string)person->query_objective() +"self up.\n",
      person );
  person->remove_property( PASSED_OUT );
} /* come_around() */

void wander_about( object person ) {
  int i, flag;
  string *direcs;

  if( person->query_property( PASSED_OUT ) || !ENV( person ) )
      return;
  if( random( 4 ) )
      person->submit_ee( "wander_about", ({ 5, 5 }), EE_ONCE );
  direcs = (string *)ENV( person )->query_direc();
  while ( sizeof( direcs ) && !flag ) {
    i = random( sizeof( direcs ) );
    if( /* !ENV( person )->query_obvious_exit( direcs[ i ] ) || */
        !ENV( person )->query_door_open( direcs[ i ] ) ) {
        direcs = delete( direcs, i, 1 );
        continue;
    }
    person->add_property( UNKNOWN_MOVE, 1 );
    if ( compass[direcs[i]] )
      flag = person->exit_command( 0, ({ direcs[ i ],
          "$N stumble$s off towards the $T." }) );
    else
      flag = person->exit_command( 0, ({ direcs[ i ], "$N stumble$s off." }) );
    tell_object(person, "You stumble around a bit.\n");
    person->remove_property( UNKNOWN_MOVE );
    if ( !flag )
      direcs = delete( direcs, i, 1 );
  }
} /* wander_about() */

int test_remove( object player, int, int enum, int bonus ) {
    // The return value is the amount used to counteract this effect.
    // Note that knurd and hungover will have to do the same thing.
    int narg, *extent;

    narg = player->expected_tt(1, enum);
    if ( narg <= bonus ) {
        player->submit_ee2( enum, 0, 0, EE_REMOVE );
        return narg;
    } else {
        extent = player->arg_of( enum);
        player->set_arg_of( enum, ({ narg - bonus, extent[1] }));
        player->submit_ee2( enum, 0, narg - bonus, EE_REMOVE );
        return bonus;
    }
}
