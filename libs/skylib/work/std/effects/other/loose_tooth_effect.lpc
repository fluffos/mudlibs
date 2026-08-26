/**
 * This effect is used in a quest in the Dwarf bread museum.  Simulates
 * a loose tooth that will be knocked out elsewhere.  Added from eating
 * dwarf bread.
 * <p>
 * The effect does not time out.  The argument is an integer of how many
 * 'stages' to advance the looseness of the tooth.  If arg is -1, effect
 * will end with a tooth dropping out if old arg was over 5.
 * <p>
 * @author Wonko
 * @classification body.loose.tooth
 * @see help::effects
 */
#include <effect.h>

#define TO this_object()
#define AUDIENCE environment( player )
#define PLYRNAME player->the_short()
#define PLYRPRON player->query_pronoun()
#define PLYRPOSS player->query_possessive()
#define PLYROBJE player->query_objective()

/** @ignore yes */
string query_classification() { return "body.loose.tooth"; }

/** @ignore yes */
int query_indefinite() { return 1; }

/** @ignore yes */
void beginning( object player, int stages ) {
   player->add_property( "body.loose.tooth", 1, 60 + random( 30 ) );
   player->submit_ee( "start_mess", 2, EE_ONCE );
   player->submit_ee( "rand_mess", ({ 60, 90 }), EE_CONTINUOUS );
   player->submit_ee( 0, stages * 600 , EE_REMOVE );
} /* beginning() */

/** @ignore yes */
int merge_effect( object player, int stages, int newstages ) {
   int *enums, timeout;

   if( newstages == -1 ) {
     if( stages > 5 ) {
       player->submit_ee( 0, 0, EE_REMOVE );
       return newstages;
     }
     return stages;
   }
   stages += newstages;
   player->add_property( "body.loose.tooth", 1, 60 + random( 30 ) );   
   player->submit_ee( "merge_mess", 2, EE_ONCE );
   enums = player->effects_matching( "body.loose.tooth" );
   if( !sizeof( enums ) ) return stages;
   timeout = player->expected_tt( 1, enums[ 0 ] ) + 600;
   if( timeout > 3000 ) timeout = 3000;
   player->submit_ee( 0, timeout, EE_REMOVE );
   return stages;
} /* merge_effect() */

/** @ignore yes */
void merge_mess( object player, int stages ) {
   switch( stages ) {
     case 2 :
       tell_object( player, "Your loose tooth seems a bit looser.\n" );
       break;
     case 3 :
       tell_object( player, "That tooth is now quite loose.\n" );
       break;
     case 4 :
       tell_object( player, "Your loose tooth is really wiggling about quite "
         "a lot.\n" );
       break;
     case 5 :
       tell_object( player, "That tooth can't be hanging in there by very "
         "much now.\n" );
       break;
     default :
       tell_object( player, "You guess one good jolt will cause that loose "
         "tooth to come out.\n" );
   }
   tell_room( AUDIENCE, PLYRNAME + " appears to have something wrong with "
     + PLYRPOSS + " mouth.\n", player );
} /* merge_mess() */

/** @ignore yes */
void start_mess( object player ) {
   tell_object( player, "You notice that dwarf bread has loosened a tooth "
     "slightly.\n" );
   tell_room( AUDIENCE, PLYRNAME + " seems to be have noticed something "
     "unpleasant in " + PLYRPOSS + " mouth.\n", player );
} /* start_mess() */

/** @ignore yes */
void end( object player, int stages ) {
   object tooth;
   if( !player->query_property( "dead" ) && stages == -1 ) {
     tell_object( player, "That jolt finally frees your loose tooth, which "
       "flies out of your mouth and bounces around in a rather sickening "
       "manner.\n" );
     tell_room( AUDIENCE, "A tooth is jolted from " + PLYRPOSS + " mouth and "
       "it bounces around a bit.\n", player );
     tooth = clone_object( "/std/object" );
     tooth->set_name( "tooth" );
     tooth->set_short( "human tooth" );
     tooth->add_adjective( "human" );
     tooth->add_plural( ({ "human teeth", "teeth" }) );
     tooth->set_long( "This is a tooth from a human.\n" );
     tooth->add_property( "DBM owner", player->query_name() );
     tooth->move( AUDIENCE );
     return;
   }
   if( !player->query_property( "dead" ) )
     tell_object( player, "You try to ignore that annoying loose tooth.\n" );
   
} /* end() */

/** @ignore yes */
void rand_mess( object player ) {
   switch( random( 5 ) ) {
     case 0 :
       tell_object( player, "You prod your loose tooth with your tongue.\n" );
       break;
     case 1 :
       tell_object( player, "You reach into your mouth and wiggle the loose "
         "tooth around a bit.\n" );
       break;
     case 2 :
       tell_object( player, "Your loose tooth makes you wonder vaguely about "
         "dwarf dentistry.\n" );
       break;
     case 3 :
       tell_object( player, "You can't help from inspecting your loose tooth "
         "with your tongue.\n" );
       break;
     case 4 :
       tell_object( player, "You wonder if eating more dwarf bread would help "
         "loosen your tooth further.\n" );
       break;
   }
} /* rand_mess() */
