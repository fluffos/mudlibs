/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: rock-mite_infestation.c,v 1.1 1998/01/06 04:08:27 ceres Exp $
 * $Log: rock-mite_infestation.c,v $
 * Revision 1.1  1998/01/06 04:08:27  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "disease.hypothermia".
 * <p>
 * Describe the arguments in here.
 * @classification disease.hypothermia
 * @see help::effects
 */
/* Flea infestation, use 10000 as standard severity  -*- LPC -*-
 */
#include <effect.h>
#include <disease.h>
inherit SIMPLE_DISEASE;

void setup() {
   set_name( "Fleas" );
   set_classification( "disease.parasite.external.rock-mite" );
   set_infection_chance( 1 );
   /* Something can catch fleas if it's alive, and */
   set_infection_check( (: living( $1 ) &&
         /* is an NPC that is not unique or */
               ( ( !userp( $1 ) && !$1->query_property( "unique" ) ) ||
         /* is a mature player, and is not dead. */
               $1->query_mature() ) && !$1->query_property( "dead" ) :) );
} /* setup() */

int disease_start( object player, int arg, int sid ) {
   string race_ob;

   race_ob = (string)player->query_race_ob();
   /* Only trolls have rockmites. */
   if ( ( (string)race_ob->query_name() != "troll" ) ||
         player->query_property( "no fleas" ) ) {
      player->submit_ee( 0, 0, EE_REMOVE );
      return 0;
   }
   return arg;
} /* disease_start() */


void disease_action( object player, int arg, int sid ) {
   switch( random( 3 ) ) {
      case 0 :
         tell_object( player, "Something itches.  You scratch yourself.\n" );
         tell_room( environment( player ),
               capitalize( (string)player->short() ) +" scratches "+
               (string)player->query_objective() +"self.\n", player );
         break;
      case 1 :
         tell_object( player, "Ouch!  Something bit you!\n" );
         tell_room( environment( player ),
               capitalize( (string)player->short() ) +" starts as "+
               "if bitten.\n", player );
         player->adjust_hp( -10 - random( 10 ) );
         break;
      default :
         tell_object( player, "You notice a small, dusty hole in your "+
               "skin.\n" );
   }
} /* mite_effects() */

int test_remove( object player, mixed arg, int id, int bonus ) {
   log_file( "OLD_CURE", file_name( previous_object() ) +" "+
            file_name( this_object() ) +"\n" );
   if ( bonus < 30 )
      return 0;
   return 1;
} /* test_remove() */
