/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: knurd.c,v 1.1 1998/01/06 04:14:00 ceres Exp $
 * $Log: knurd.c,v $
 * Revision 1.1  1998/01/06 04:14:00  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "body.knurd".
 * <p>
 * Describe the arguments in here.
 * @classification body.knurd
 * @see help::effects
 */
#include <drinks.h>
#include <effect.h>
#include <living.h>
#include <move_failures.h>
#include <player.h>

/* The effects of being knurd (opposite of drunk) */

/** @ignore yes */
string query_classification() { return "body.knurd"; }

int counter( object person, int bonus ) {
    // This effect will counteract "drunk".
    int i, *effnums, b;
    class effect *effs;

    if ( !person ) return 0;
    if ( !living( person ) ) return 0;
    b = bonus;
    effs = (class effect *)person->query_effs();
    effnums = (int *)person->effects_matching( "body.drunk" );
    for ( i = sizeof( effnums ) - 1; i >= 0; i-- ) {
        b -= effs[ effnums[ i ] ]->ob_name->test_remove( person,
            effs[ effnums[ i ] ]->arg, effnums[ i ], b );
        if ( !b ) {
            person->submit_ee( 0, 0, EE_REMOVE );
            return 0;
        }
    }
    return b;
} /* counter() */

/** @ignore yes */
int *beginning( object person, int extent, int id ) {
  int x, c;

  // The duration should be similar to the old /global/player drunk
  // effect, ie, time = 2*extent/query_con().
  person->submit_ee( "knurd_behaviour", ({ 10, 60 }), EE_CONTINUOUS );
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
  if (extent > m) {
      m = extent;
  }
  return ({ extent, m });
} /* merge_effect() */

/** @ignore yes */
void end( object person, int *extent ) {
  if ( extent[1] > 60 )
    tell_object( person, "You feel yourself slip back into blessed "
                "ignorance.\n" );
} /* end() */

void knurd_behaviour( object person, int *extent ) {
  int intox, selector;

  intox = (int)person->expected_tt();
  selector = random( intox ) / person->query_con() / 5;
  switch ( selector ) {
    case 0 :
    case 1 :
      switch ( random( 4 ) ) {
        case 0 :
          person->new_parser( "wonder" );
          break;
        case 1 :
          person->new_parser( "frown" );
          break;
        case 2 :
          person->new_parser( "puzzle" );
          break;
        default :
          person->new_parser( "whimper" );
          break;
      }
      break;
    case 2 :
      switch ( random( 2 ) ) {
        case 0 :
          tell_object( person, "You suddenly realise something shocking; "+
                      "you stop to think about it.\n" );
          tell_room( environment( person ),
                    capitalize( (string)person->the_short() ) +" suddenly "+
                    "goes wide-eyed, and freezes with a thoughtful look on "+
                    (string)person->query_possessive() +" face.\n", person );
          break;
        default :
          person->new_parser( "scream" );
          break;
      }
      break;
    default :
  }
} /* drunk_behaviour() */

int test_remove( object player, int arg, int enum, int bonus ) {
    // The return value is the amount used to counteract this effect.
    // Note that drunk does the same thing.
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
