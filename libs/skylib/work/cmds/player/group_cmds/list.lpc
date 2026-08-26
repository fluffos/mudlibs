#include <group_handler.h>

inherit GROUP_SUBCOMMAND_INHERITABLE;

string *leader_adjectives =
   ({
      "daring",
      "heroic",
      "brave",
      "bold",
      "courageous",
      "dauntless",
      "fearless",
      "intrepid",
      "valiant",
      "awesome",
      "stalwart"
   });

string *follower_messages =
   ({
      " and also includes",
      " and features such prominent figures as",
      ", whose supporters consist of",
      " and features such renowned names as",
   });


int do_list_groups();

void create() {
   ::create();
   add_group_sub_command( "list", "", (: do_list_groups() :) );
} /* create() */


int do_list_groups() {

   string group, *groups, prefix, suffix, message, adjective, colour, stats;
   object *members, leader;
   int num_groups, num_members;
   
   groups = GROUP->query_groups();

   num_groups = sizeof( groups );
   
   if( !num_groups )
   {
      return notify_fail( "There are currently no active groups.\n" );
   }
         
   prefix = "$I$+8,+0=  + ";
   suffix = "$I$-8,-0=\n";
   
   colour = this_player()->colour_event( GROUP_COLOUR_EVENT, "" );

   message = "";
   num_members = 0;
   
   foreach( group in groups )
   {
      leader = GROUP->leader_of( group );
      members = GROUP->members_of( group );
      
      if( !leader || !sizeof( members ) )
      {
         continue;
      }
      
      num_members += sizeof( members );
      
      message += prefix;
      
      message += colour + GROUP->query_group_short( group ) +
         "%^RESET%^ is led by ";
      
      members -= ({ leader });
      
      if( leader->query_name() == "tape" )
      {
         adjective = "infamous";
      }
      else
      {
         adjective = leader_adjectives[ random( sizeof(
            leader_adjectives ) ) ];
      }
      
      message += "the " + adjective + " %^BOLD%^" +
         leader->query_short() + "%^RESET%^";
      
               
      if( sizeof( members ) )
      {
         message += follower_messages[ random( sizeof( follower_messages )
            ) ] + " %^BOLD%^" + query_multiple_short( members, 0, 0, 1 ) +
            "%^RESET%^.";
      }
      else
      {
         message += " and has no other members.";
      }

      message += suffix;
      
   }

   switch( num_groups )
   {
      case 1:
         stats = "There is currently %^BOLD%^one%^RESET%^ active group, ";
      default:
         stats = "There are currently %^BOLD%^" + query_num( num_groups ) +
            "%^RESET%^ active groups, ";
   }
   
   stats += "with a total number of %^BOLD%^" +
      query_num( num_members ) + "%^RESET%^ persons:\n";

   tell_object( this_player(), stats + message );
   
   return 1;

} /* do_list_groups() */


string query_help_string_for( string sub ) {
   return "This command lets you list all currently active "
      "groups and their members and leaders.";
} /* query_help_string_for() */

