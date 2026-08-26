
//	File	:  /cmds/std/_biff.c
//	Creator	:  Watcher@TMI  (03/26/93)
//
//	Updated	:  Watcher@TMI  (07/31/93) to work with the new mailer.
//
//	This command allows you to toggle new mail notification. 
//	The flag defaults to the off position until reset and is 
//	saved after logoffs.

#include <mudlib.h>

inherit DAEMON ;

#define SYNTAX	"Syntax: biff [on/off]\n"
 
int cmd_biff(string str) {
   string biff;
 
   biff = ((int)this_player()->query_env("mail_notification") ? "on" : "off");
 
   notify_fail( SYNTAX );
 
   if(str != "on" && str != "off") {
   write("Your biff mail notification flag is " + biff + ".\n");
   return 0; }
 
   if(str == "on") {
   write("You toggle your biff mail notification on.\n");
   this_player()->set_env("mail_notification", 1);
   return 1; }
 
   write("You toggle your biff mail notification off.\n");
   this_player()->set_env("mail_notification", 0);
 
return 1; }
 
string help() {
 
   return (SYNTAX+"\n"+@HELP
This command allows you to toggle your new mail notification. It
defaults to "off" for new users, but any future settings are saved
after logout.

See also: mail
HELP
  );
}
 
