/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: hemp.c,v 1.1 1998/01/06 04:14:00 ceres Exp $
 * $Log: hemp.c,v $
 * Revision 1.1  1998/01/06 04:14:00  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "player.is.stoned".
 * <p>
 * Describe the arguments in here.
 * @classification player.is.stoned
 * @see help::effects
 */
#include <effect.h>

#define CURE 200

/** @ignore yes */
string query_classification() { return "player.is.stoned"; }

/** @ignore yes */
int beginning( object player, int arg, int sid ) {
   tell_object( player, "You begin to feel quite pleasantly stoned.\n" );
   tell_room( environment( player ), (string)player->the_short() + " peers at you through half-" 
                         "closed eyes.\n", player);
   player->submit_ee( "soul_reactions", ({ 10, 10 }), EE_CONTINUOUS );
   player->submit_ee( "sap_brains", ({ 100, 100 }), EE_CONTINUOUS );
   player->submit_ee( 0, arg, EE_REMOVE );
   return 0;
} /* beginning() */

/** @ignore yes */
void merge_effect() { return; }

/** @ignore yes */
void end( object player, int arg, int sid ) {
   if ( !player->query_property( "dead" ) )
      tell_object( player, "You get a sudden craving for jelly donuts.\n" );
} /* end() */

void soul_reactions( object player, int arg, int sid ) {
   switch ( random( 10 ) ) {
      case 0 :
         player->new_parser( "cough" );
         break;
      case 1 :
         tell_object( player, "You drone: Wow, man... Cool!.\n" );
         tell_room( environment( player ), (string)player->the_short() + " drones: " 
                         "Wow, man... Cool!\n", player);
         break;
      case 2 :
         tell_object( player, "Your eyes dilate and get redder.\n" );
         tell_room( environment( player ), (string)player->the_short() + " squints " 
                         "and seems uncomfortable in the light.\n", player);
         break;
      case 3 :
         tell_object( player, "You giggle mindlessly.\n" );
         tell_room( environment( player ), (string)player->the_short() + " giggles " 
                         "mindlessly.\n", player);
         break;
      case 4 :
         tell_object( player, "You become fascinated by your hands.\n" );
         tell_room( environment( player ), (string)player->the_short() + " seems " 
                          "to have forgotten what fingers are.\n", player);
         break;
      case 5 :
         player->new_parser( "wibble" );
         break;
      case 6 :
         tell_object( player, "You fall over backwards, giggling.\n" );
         tell_room( environment( player ), (string)player->the_short() + " falls " 
                         "over backwards, giggling.\n", player);
         break;
      case 7 :
         tell_object( player, "You feel very relaxed.\n" );
         tell_room( environment( player ), (string)player->the_short() + " smiles " 
                         "pleasantly at you.\n", player);
         break;
      case 8 :
         tell_object( player, "You start to say something, but forget what it was.\n" );
         tell_room( environment( player ), (string)player->the_short() + " starts to " 
                         "say something to you... forgets what it was and smiles goofily.\n", player);
         break;
      default :
         tell_object( player, "You blow the smoke out slowly, savouring the mellow flavour.\n" );
         tell_room( environment( player ), (string)player->the_short() + " blows a cloud of " 
                         "sweet-smelling smoke in your face.\n", player);
   }
   arg -= CURE / 10;
   if ( arg < 0 )
      arg = 0;
   player->set_arg_of( (int)player->sid_to_enum( sid ), arg );
} /* soul_reactions() */

void sap_brains( object player ) {
   tell_object( player, "You close your eyes... The room seems to spin.\n" );
   tell_room(environment(player),(string)player->the_short()
   + " seems a little dizzy.\n",player);
   player->adjust_tmp_int( -1 );
} /* sap_brains() */

int test_remove( object player, int arg, int enum, int bonus ) {
   arg += bonus;
   if ( arg > CURE )
      return 1;
   player->set_arg_of( enum, arg );
   return 0;
} /* test_remove() */
