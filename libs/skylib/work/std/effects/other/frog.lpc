/**
 * This effect has a classification
 * of "pie.cream".
 * <p>
 * @author Wonko
 * @classification pie.cream
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
string query_classification() { return "pie.cream"; }

/** @ignore yes */
void beginning( object player, int time ) {
  //   player->submit_ee( "start_mess", 2, EE_ONCE );
   player->submit_ee( "rand_mess", ({ 35, 50 }), EE_CONTINUOUS );
   player->submit_ee( "lick_check", ({ 15, 30 }), EE_CONTINUOUS );
   player->submit_ee( 0, time, EE_REMOVE );
   player->add_extra_look( TO );
} /* beginning() */

/** @ignore yes */
int merge_effect( object player, int time1, int time2 ) {
   int newtime;

   newtime = time2 + player->expected_tt();
   if( newtime > 900 ) newtime = 900;
   if( newtime < 0 ) newtime = 0;
   player->submit_ee( 0, newtime, EE_REMOVE );
   return newtime;
} /* merge_effect() */

/** @ignore yes */
void start_mess( object player ) {
   tell_object( player, "Sugary cream and crumbs begin to slowly slither "
     "down your face.\n" );
   tell_room( AUDIENCE, "Sugary cream begins to slide gracelessly down " +
     PLYRNAME + "'s face.\n", player );
} /* start_mess() */

void restart( object player ) {
   player->add_extra_look( TO );
} /* restart() */

/** @ignore yes */
void end( object player, int time ) {
   if( !player->query_property( "dead" ) )
     tell_object( player, "You are finally freed of cream and crumb bits.\n" );
   player->remove_extra_look( TO );
} /* end() */

/** @ignore yes */
void rand_mess( object player ) {
   switch( random( 8 ) ) {
     case 0 :
       tell_object( player, "You watch a dollop of cream slide down your "
         "nose.\n" );
       tell_room( AUDIENCE, PLYRNAME + " goes cross-eyed as " + PLYRPRON +
         " watches a blob of cream slide down " + PLYRPOSS + " nose.\n",
         player );
       break;
     case 1 :
       tell_object( player, "You feel a piece of cream slide over your eye, "
                    "so you wipe it off.\n");
       tell_room( AUDIENCE, PLYRNAME + " wipes off a piece of cream that " 
                  "slides down over " + PLYRPOSS + " eye.\n", player );
       break;
     case 2 :
       tell_object( player, "Cream oozes into one of your ears.\n" );
       tell_room( AUDIENCE, PLYRNAME + " squirms uncomfortably as cream "
         "oozes into " + PLYRPOSS + " ears.\n", player );
       break;
     case 3 :
       tell_object( player, "You feel a little like a birthday cake.\n" );
       tell_room( AUDIENCE, PLYRNAME + "'s brow furrows in a bout of "
         "introspection.\n", player );
       break;
     case 4 :
       tell_object( player, "Warm, melting cream trickles down your "
         "spine.\n" );
       tell_room( AUDIENCE, PLYRNAME + " shudders as warm cream runs down " +
         PLYRPOSS + " back.\n", player );
       break;
     case 5 :
       tell_object( player, "A blob of cream falls off you, landing with a "
         "\"plut!\" sound.\n" );
       tell_room( AUDIENCE, "A dollop of cream drops from " + PLYRNAME +
         " onto the ground.\n", player );
       break;
     case 6 :
       tell_object(player, "You wipe some cream off your hands and throw it "
                   "on the ground.\n");
       tell_room(environment(player), player->short() + " wipes some cream off " +
                 player->query_possessive() + " hands and throws it on the "
                 "ground.\n", player);       
       break;
     default :
       tell_object( player, "You know it will take ages to wash this cream "
         "out of your hair.\n" );
       tell_room( AUDIENCE, PLYRNAME + " brushes some crumbs from " +
         PLYRPOSS + " hair.\n", player );
       break;
   }
} /* rand_mess() */

/** @ignore yes */
void lick_check( object player ) {
   object *creamlovers;
   object licker;

   creamlovers = match_objects_for_existence( "dogs& cats& fruitbats", environment( player ) );
   creamlovers -= ({ player });
   if( sizeof( creamlovers ) ) {
     licker = creamlovers[random( sizeof( creamlovers ) )];
     switch( random( 3 ) ) {
       case 0 : licker->do_command( ":joyfully licks some cream off " +
         PLYRNAME + "." );
         break;
       case 1 : licker->do_command( ":skillfully fields a large dollop of "
         "cream as it falls off " + PLYRNAME + "." );
         break;
       default : licker->do_command( ":greedily slurps at the cream sliding "
         "off " + PLYRNAME + "." );
     }
     TO->merge_effect( player, 0, -( 20 + random( 11 ) ) );
     return;
   }
} /* lick_check() */

/** @ignore yes */
string extra_look( object player ) {
   int *enums;

   enums = player->effects_matching( "pie.cream" );
   if ( !sizeof( enums ) ) return "";
   switch( player->expected_tt( 1, enums[ 0 ] ) ) {
     case 0..60 :
       return capitalize( PLYRPRON + " has a little bit of cream and a few "
         "crumbs on " + PLYRPOSS + " face.\n" );
     case 61..120 :
       return capitalize( PLYRPOSS + " face is smeared with creamy biscuit "
         "crumbs.\n" );
     case 121..200 :
       return capitalize( PLYRPRON + " looks to have taken a cream pie in "
         "the face.\n" );
     case 201..380 :
       return capitalize( PLYRPOSS + " head and shoulders are covered in "
         "mounds of cream and biscuit crumbs.\n" );
     case 381..560 :
       return capitalize( PLYRPRON + " has the contents of several cream "
         "pies splattered all over " + PLYROBJE + ".\n" );
     case 561..740 :
       return capitalize( PLYRPRON + " is barely recognisable under the "
         "thick layer of sugary, sticky cream covering " + PLYROBJE + ".\n" );
     default :
       return capitalize( PLYRPRON + " is covered in so much sticky cream "
         "and crumbs, " + PLYRPRON + " resembles a giant cake.\n" );
   }
}/* end query_extra_look() */
