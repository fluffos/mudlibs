//#pragma save_binary
 
//	File	:  /cmds/adm/_dewiz.c
//	Creator	:  Watcher@TMI  (4/9/93)
//
//	93-07-14 Grendel added removing of channels
//      93-07-15 Grendel rewired channel code for new system
//      93-08-21 Grendel added the call to disable_me()
//	93-08-27 Mobydick fixed channel-removing for the new channels
//
//	This is the admin command which allows an admin to dewiz
//	a wizard to the normal player level.
 
#include <config.h>
#include <channels.h>
#include <mudlib.h>
#include <uid.h>
#include <daemons.h>

inherit DAEMON;
 
#define SYNTAX	"Syntax: dewiz [wizard]\n"

#define PLAYER_CHANS ({ })
 
void clear_channels(object player) ;

int cmd_dewiz(string str) {
   object act_ob, player, link;
   int i, add_path;

   act_ob = previous_object();
   notify_fail( SYNTAX );
   if(!str || str == "")  return 0;

   //	Check for admin permissions in user
   if(!member_group(geteuid(act_ob), "admin")) {
   write("Dewiz: Only admin may dewiz a wizard.\n");
   return 1; }

   str = lower_case(str);
 
   //	Check to see if the target user actually exists
   if( !user_exists(str) ) {
     write("Dewiz: No such player.\n");
     return 1;
   }
 
   //	Prevent admins from being dewizzed ... just in case. :)
   if(member_group(str, "admin")) {
   write("Dewiz: You cannot dewiz an admin.\n");
   return 1; }
 
   //	Check to see if the user is presently online
 
   player = find_player(str);
 
   if( player ) link = player->query_link();
 
   //	Otherwise create the user's connection object 
   if( !link ) FINGER_D->restore_data(str);

   //	Check to see if the user is already a player
   if( !link->query("wizard") ) {
   write("Dewiz: " + capitalize(str) + " is not a wizard.\n");
   return 1; }
   
   //	If user isn't online, restore body to update path
   if( !player ) {
   	link->restore_body();
   	player = link->query("body_ob");
   }
 
   //	Deactivate wizard flag
   seteuid(ROOT_UID);
   link->set("wizard", 0);
   player->set("wizard", 0) ;
   player->disable_me();

   // clear channels
   clear_channels(player);
 
   //	Update users path to exclude wizard command pathways
   player->set("PATH", USER_CMDS);
 
   // 	clean his domains.
   DOMAIN_D->clean_domains(link);
   
   //	Reset his access right.
   PROMOTION_D->remove_wiz_list(str);
   PROMOTION_D->reset_access(link);
   
   //	Save updated user and connection data
   player->save_data();
   link->save_data();
   write("You have dewizzed " + capitalize(str) + ".\n");
 
   tell_object(player, 
	"Your wizhood has been removed by " +
	(string)previous_object()->query("name") + ".\n");
 
   if(!interactive(player))
	player->remove();
 
return 1; }

int help() {
 
   write( SYNTAX + "\n" +
    "This command allows admins to remove the wizhood from a user. It\n" +
    "zeros their wiz bit and sets their PATH to the standard user path.\n");
 
return 1; }
 
void clear_channels(object player) {

    mapping chans ;
    string *chan_names ;
    int i ;

   chan_names = player->query("channels/toggle") ;
    for (i=0;i<sizeof(chan_names);i++) {
	if (member_array(chan_names[i],PLAYER_CHANS)==-1)
	CHANNELS_D->register_channel(chan_names[i],this_player(),KIL,1) ;
    }
    player->set("channels/toggle", PLAYER_CHANS) ;
    return ;
}
