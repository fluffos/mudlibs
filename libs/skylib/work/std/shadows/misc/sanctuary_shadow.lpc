/*
 * A shadow to make a player immune to some stuff after being raised.
 */

#include <player.h>

object player;
int remove;

void setup_shadow( object thing ) {
   shadow( thing, 1 );
   player = thing;
   call_out( "dest_sanctuary_shadow", 60 * 15 );
} /* setup_shadow() */

void dest_sanctuary_shadow() { destruct( TO ); }

int query_sanctuary() { return 1; }

void zap_sanctuary_shadow() {
   if( !remove ) {
       tell_object( player, "You lose the protection of the gods.\n" );
       call_out("dest_sanctuary_shadow", 1 );
       remove = 1;
    }
} /* zap_sanctuary_shadow() */

int adjust_hp( int number, object thing, object weapon, string attack ) {
   if( ( number > 0 ) || !thing || !pk_check(thing, player ) || player == TP )
      return (int)player->adjust_hp( number, thing, weapon, attack );
   return (int)player->query_hp();
} /* adjust_hp() */

int set_hp( int number, object thing ) {
   int current;
   current = (int)player->query_hp();
   if ( ( number > current ) || !thing || !thing->query_property( PKER ) )
      return (int)player->set_hp( number, thing );
   return current;
} /* set_hp() */

int attack_by( object thing ) {
   if ( !thing->query_property( PKER ) )
      return (int)player->attack_by( thing );
   tell_object( thing, (string)player->the_short() +
         " cannot be attacked right now.\n" );
   thing->stop_fight( player );
   return 0;
} /* attack_by() */

int attack_ob( object thing ) {
   zap_sanctuary_shadow();
   return (int)player->attack_ob( thing );
} /* attack_ob() */

int no_offense() {
   zap_sanctuary_shadow();
   return (int)player->no_offense();
} /* no_offense() */

mixed query_property( string word ) {
   if ( word == PKER )
      return 0;
   return (mixed)player->query_property( word );
} /* query_property() */

int command_shadowed( string verb, string args ) {
   if ( member_array( verb, ({ "cast" }) ) == -1 )
      return (int)player->command_shadowed( verb, args );
   zap_sanctuary_shadow();
   return (int)player->command_shadowed( verb, args );
} /* command_shadowed() */
