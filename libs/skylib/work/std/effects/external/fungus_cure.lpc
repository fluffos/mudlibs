/**
 * This is the effect skelton docs.  This effect
 * has a classification of "body.smell.fungus_cure".
 * <p>
 * Describe the arguments in here.
 * @classification body.smell.fungus_cure
 * @see help::effects
 */
/*
** fungus_cure - for curing the creeping fungus effect.
**
** Written by: Hastur - 7-5-98, based on Jeremys flea_cure
**
** 
*/
 
#include <effect.h>

int infested;
 
int cleanse( object thing, int bonus ) {
    int i, flag, *effnums;
    class effect *effs;
#ifdef DEBUG
    tell_object( thing, "Cure - in cleanse" );
#endif
    if ( !thing )
      return 0;
    if ( !living( thing ) )
      return 0;
    effnums = (int *)thing->effects_matching(
              "disease.infection.external.creeping_fungus");
    if ( !sizeof( effnums ) )
      return 0;
#ifdef DEBUG
    tell_object( thing, "Cure - found match" );
#endif
    effs = (class effect *)thing->query_effs();
    for ( i = sizeof( effnums ) - 1; i >= 0; i-- )
      if ( effs[ effnums[ i ] ]->ob_name->test_remove( thing,
          effs[ effnums[ i ] ]->arg, effnums[ i ], bonus ) ) {
#ifdef DEBUG
    tell_object( thing, "Cure - effect deleted" );
#endif
          thing->delete_effect( effnums[ i ] );
          flag = 1;
      }
    infested = flag;
    return flag;
} /* cleanse() */
 
/** @ignore yes */
void beginning( object player, int time ) {
   player->submit_ee( "make_smell", ({ 20, 30 }), EE_CONTINUOUS );
   call_out("cleanse", 0, player, time/10);
   //cleanse(player, time/10);
   player->submit_ee( 0, time, EE_REMOVE );
} /* beginning() */
 
/** @ignore yes */
int merge_effect( object player, int time1, int time2 ) {
   player->submit_ee( 0, time1 + time2 - (int)player->expected_tt(),
         EE_REMOVE );
   if (!infested)
       call_out("cleanse", 0, player, (time1+time2)/10);
   return time1 + time2;
} /* merge_effect() */
 
/** @ignore yes */
void end( object player, int time ) {
   tell_object( player, "The odd odour is gone now.\n" );
} /* end() */
 
void make_smell( object player ) {
    tell_object( player, "You notice a strange odour, like rotting mushrooms "
              "and mold, in the air.\n" );
    tell_room( environment( player ),  "A smell reminiscent of rotting mushrooms "+
              "and mold seems to emanate from "+
              (string)player->short() + ".\n", player );
} /* make_smell() */

/** @ignore yes */
string query_classification() { return "body.smell.fungus_cure"; }
 
string smell_string( object player, int time ) {
   return "the odd odour of rotting mushrooms and mold";
} /* smell_string() */

