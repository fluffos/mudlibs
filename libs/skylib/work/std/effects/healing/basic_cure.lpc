/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: basic_cure.c,v 1.1 1998/01/06 04:13:03 ceres Exp $
 * $Log: basic_cure.c,v $
 * Revision 1.1  1998/01/06 04:13:03  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "fighting.warcry".
 * <p>
 * Describe the arguments in here.
 * @classification fighting.warcry
 * @see help::effects
 */
/* Basic file meant to be inherited by the cures for diseases.  -*- LPC -*-
 * Very much a work in progress
 * If you change this file, remember to update
 * /doc/creator/files/std.effects.healing.basic_cure as well if I've made 
 * it yet:)
 * Olorin
 */
#include <effect.h>

int do_setup;
string classification;

void set_classification( string str ) { classification = str; }
/** @ignore yes */
string query_classification() { return classification; }

void create() {
   classification = "cure.nothing";
   if ( !do_setup )
      this_object()->setup();
} /* create() */

void do_cure( object person, int power ) {
   int i, j;
   int *effnums, *tmpnums;
   class effect *effs;
   string *cure_class;
   
   cure_class = explode( classification, "." );
   cure_class[ 0 ] = "disease";
   effnums = ({ });
   effs = (class effect *)person->query_effs();
   for( i = 1 ; i < sizeof( cure_class ) ; i++ ) {
      tmpnums = (int *)person->effects_matching(
                     implode( cure_class[ 0 .. <i ], "." ) );
      tmpnums -= effnums;
      effnums = tmpnums + effnums;
   }
   j = sizeof( effnums );
   while ( j-- && ( power >= 0 ) ) {
      if ( function_exists( "cure", 
                           find_object( effs[ effnums[ j ] ]->ob_name ) ) ) {
         power = effs[ effnums[ j ] ]->ob_name->
            cure( person, classification, power, effnums[ j ]  );
         if ( power >= 0 ) {
            person->submit_ee2( effnums[ j ], 0, 0, EE_REMOVE );
         }
      }
   }
} /* do_cure() */
