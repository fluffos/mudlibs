#include <group_handler.h>

inherit GROUP_SUBCOMMAND_INHERITABLE;

int do_assist( object *members, int list, string group );

void create() {

   ::create();

   add_group_sub_command( "assist", "<indirect:living'member'>",
      (: do_assist( $1, 0, $6 ) :) );
   add_group_sub_command( "assist", "list",
      (: do_assist( 0, 1, $6 ) :) );

   set_membership_required( "assist", 0, 1 );

} /* create() */

int do_assist( object *members, int list, string group ) {

   object *assisting, member;

   assisting = TP->query_assisting();

   if( list ) {
      if( sizeof( assisting ) ) {
         tell_object( TP, "You are currently "
            "assisting " + query_multiple_short( assisting ) +
            ".\n" );
         return 1;
      }
      else {
         tell_object( TP, "You are currently "
            "assisting noone.\n" );
         return 1;
      }
   }

   if( !sizeof(members) ) {
      return notify_fail( "You have to assist someone.\n" );
   }

   if( sizeof(members) > 1 ) {
      return notify_fail( "Try assisting one group mate at a time.\n" );
   }

   member = members[ 0 ];

   if( member == TP ) {
      return notify_fail( "You cannot assist yourself.\n" );
   }

   if( !GROUP->is_member( group, member ) ) {
      return notify_fail( member->the_short() + " is not a "
         "member of your group.\n" );
   }
   
   if( member->query_assisters() &&
      member_array( TP, member->query_assisters() ) != -1 ) {
      member->remove_assister( TP );
      add_succeeded_mess( ({ "You stop assisting " + member->the_short() +
         ".\n", "" }) );
      return 1;
   }
   
   if( sizeof( assisting ) >= MAX_PEOPLE_YOU_CAN_ASSIST ) {
      return notify_fail( "You can not assist anymore people.\n" );
   }

   TP->add_succeeded_mess( member, "$N begin$s keeping a close "
      "eye on $D.\n" );
   
   member->add_assister( TP );
   
   return 1;
   
} /* do_assist() */


string query_help_string_for( string sub ) {
   return "With this command you can guard a group member.  If the "
      "person you're guarding gets attacked, you will automatically "
      "join the fight after a delay.  The length of the delay depends "
      "on how many people you're guarding at the moment.  Use "
      "\"list\" to see who you are currently assisting.  To stop "
      "assisting someone, use \"group assist <someone>\" again "
      "on that person.\n";
} /* query_help_string_for() */

