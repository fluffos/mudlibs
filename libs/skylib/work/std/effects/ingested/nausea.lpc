#include <effect.h>

#define CURE 200

string query_classification() { return "disease.nausea"; }

/** @ignore yes */
int beginning( object player, int arg, int sid ) {
   tell_object( player, "You realise that your stomach feels queasy.\n" );
   tell_room( ENV( player ), (string)player->one_short()+" looks a little "
       "green in the face.\n", player );
   player->submit_ee("nausea_symptoms", ({ 30, 30 }), EE_CONTINUOUS );
   player->submit_ee("sap_dexterity", ({ 100, 100 }), EE_CONTINUOUS );
   player->submit_ee( 0, arg, EE_REMOVE );
   return 0;
} /* beginning() */

/** @ignore yes */
void merge_effect() { return; }

/** @ignore yes */
void end( object player, int arg, int sid ) {
   if( !player->query_property( "dead" ) )
       tell_object( player, "You realise that your stomach feels fine "
           "again.\n");
} /* end() */

/** @ignore yes */
void nausea_symptoms( object player, int arg, int sid ) {
   object ob;

   ob = TP;
   set_this_player(player);

   switch( random( 5 ) ) {
     case 0 :
       player->new_parser("puke");
     break;
     case 1 :
       player->new_parser("burp");
     break;
     case 2 :
       player->new_parser("puke all");
     break;
     case 3 :
       player->new_parser("moan");
     break;
     default :
       player->new_parser("fart");
   }

   set_this_player(ob);

   arg -= CURE / 10;
   if( arg < 0 )
       arg = 0;

   player->set_arg_of( (int)player->sid_to_enum( sid ), arg );

} /* nausea_symptoms() */

/** @ignore yes */
void sap_dexterity( object player ) {
   tell_object( player, "You clutch your stomach in agony and bend over.\n");
   tell_room( ENV(player),(string)player->one_short()+" bends over in "
       "agony.\n", player );
   player->adjust_tmp_dex( -1 );
} /* sap_dexterity() */

/** @ignore yes */
int test_remove( object player, int arg, int enum, int bonus ) {
   arg += bonus;
   if( arg > CURE )
       return 1;

   player->set_arg_of( enum, arg );
   return 0;

} /* test_remove() */
