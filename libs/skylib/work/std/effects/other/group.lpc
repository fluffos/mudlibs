/**
 * This is the effect added to a living when he becomes
 * a member of a group.
 * <p>
 * The argument should be a string designating the name of the
 * group.
 * @classification player.group
 * @see help::effects
 */

#include <effect.h>
#include <group_handler.h>

int survive_death() { return 1; }

string query_classification() { return "player.group"; }

string query_shadow_ob() { return SHADOW_OB; }

int query_indefinite() { return 1; }

void beginning( object player, string args, int sid ) {
   tell_creator( player, "[Group effect added.]\n" );
   player->group_membership_added( args );
} /* beginning() */


void restart( object player, string args, int sid ) {
   if( !GROUP->member_of( args, player ) ) {
      player->submit_ee( 0, 0, EE_REMOVE );
   }
} /* restart() */

void merge_effect( object player, string args, int sid ) {
   tell_creator( player, "[Group effect trying to merge.  Tough "
      "titty.]\n" );
} /* merge_effect() */

void end( object player, string args, int sid ) {
   if( GROUP->is_member( args, player ) ) {
      GROUP->remove_member( args, player );
   }
   tell_creator( player, "[Group effect removed.]\n" );
} /* remove_this_effect() */

