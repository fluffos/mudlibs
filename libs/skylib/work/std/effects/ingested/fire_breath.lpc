#include <effect.h>

#define HEALTH_SKILL "other.health"
#define HIDING_SKILL "covert.hiding.person"

/* Removed - what's this actually here for?
void create() {
   seteuid( (string)"/secure/master"->
      creator_file( file_name( this_object() ) ) );
} */ /* create() */

void beginning( object player, int amount, int id ) {
   player->submit_ee( 0, 0, EE_REMOVE );
} /* beginning() */

void end( object player, int amount, int id ) {
   int damage, chance;
   float resist;
   object thing, *things;

   amount = amount * 5;

   tell_object( player, "Your mouth is on fire!  Flames and smoke pour from "
      "your mouth like a Klatchian volcano.\n" );

   damage = amount - player->query_ac( "gas", amount, "self" );
   if( player->query_property( "burnt mouth" ) )
      damage = damage * 3;
   player->add_property( "burnt mouth", 1, 10 );
   player->adjust_hp( -damage );
   if( player->query_hp() < 0 )
      player->attack_by( this_object() );

   if( !environment( player ) ) {
      tell_object( player, "The smoke clears.\n" );
      return;
   }

   things = all_inventory( environment( player ) );
   foreach( thing in things ) {
      if( !living( thing ) || thing == player )
         continue;

      resist = to_float( thing->query_skill_bonus( HEALTH_SKILL ) / 100 );
      resist = 100 * ( 16 / pow( 2, resist ) );
      chance = 16;
      if( thing->query_hide_invis()["hiding"] )
         chance += thing->query_skill_bonus( HIDING_SKILL ) / 25;
      chance = to_int( resist ) / chance;

      if( !pk_check( player, thing ) && random( amount ) < chance ) {
         tell_object( thing, "Vast amounts of fire and smoke billow from " +
            player->the_short() + " and you are forced, coughing and "
            "crying, out of the area.\n" );
         thing->run_away();
      } else {
         tell_object( thing, "Fire and smoke billow from " +
            player->the_short() + " but it doesn't seem to affect you.\n" );
      }
   }

   tell_room( environment( player ), "The smoke clears.\n" );
} /* end() */

string query_classification() { return "magic.smoke.choking"; }

string query_name() { return "really nasty pizza"; }
