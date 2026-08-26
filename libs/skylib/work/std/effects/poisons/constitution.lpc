/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: constitution.c,v 1.1 1998/01/06 04:21:18 ceres Exp $
 * $Log: constitution.c,v $
 * Revision 1.1  1998/01/06 04:21:18  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "poison.constitution".
 * <p>
 * Describe the arguments in here.
 * @classification poison.constitution
 * @see help::effects
 */
/*
 * Constitution poison:
 *
 *   An amount of 1600 will reduce the average human's temporary
 * constitution by one point. If more than seven points are deducted,
 * the player will die from shock.
 *
 */

#include <effect.h>

#define PLAYER capitalize( (string)player->the_short() )

void create() {
   seteuid( (string)"/secure/master"->
         creator_file( file_name( this_object() ) ) );
} /* create() */

/** @ignore yes */
void beginning( object player, int amount ) {
   player->submit_ee( 0, 1, EE_REMOVE );
} /* beginning() */

/** @ignore yes */
int merge_effect( object player, int amount1, int amount2 ) {
   return amount1 + amount2;
} /* merge_effect() */
 
/** @ignore yes */
void end( object player, int amount ) {
   int deduct;
   deduct = amount / 2 + random( amount );
   deduct /= (int)player->query_weight();
   if ( deduct > 8 )
      deduct = 8;
   player->adjust_tmp_con( -deduct );
   switch ( deduct ) {
      case 0 .. 1 :
         tell_object( player, "You briefly feel like you have been "+
               "punched in the stomach.\n" );
         tell_room( environment( player ), PLAYER +" looks slightly "+
               "winded.\n", player );
         break;
      case 2 .. 3 :
         tell_object( player, "You feel like someone has just punched "+
               "you in the stomach.\n" );
         tell_room( environment( player ), PLAYER +" doubles over looking "+
               "out of breath.\n", player );
         break;
      case 4 .. 5 :   
         tell_object( player, "You feel like you have been viciously "+
               "punched in the stomach.\n" );
         tell_room( environment( player ), PLAYER +" nearly "+
               "collapses.\n", player );
      case 6 .. 7 :
         tell_object( player, "You collapse with a feeling of your "+
               "life being drained.\n" );
         tell_room( environment( player ), PLAYER +" collapses with a "+
               "look of having had the stuffing knocked out of "+
               (string)player->query_objective() +".\n", player );
         break;
      default:
         tell_object( player, "You reel, and collapse with all your "+
               "health fleeing your body.\n" );
         tell_room( environment( player ), PLAYER +" collapses with a "+
               "face palid as the face Death would have if Death had "+
               "a face.\n", player );
         call_out( "shock_death", 0, player );
         break;
   }
} /* end() */

void shock_death( object player ) {
   if ( player ) {
      player->attack_by( this_object() );
      player->do_death();
   }
} /* shock_death() */

string query_name() { return "shock from constitution poisoning"; }

/** @ignore yes */
string query_classification() { return "poison.constitution"; }
