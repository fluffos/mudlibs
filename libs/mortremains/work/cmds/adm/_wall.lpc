 
//	File	:  /cmds/adm/_wall.c
//	Creator	:  Buddha@TMI  (Sometime in 1992)
//	Updated	:  Mobydick@TMI  (11-30-92) to add admin-permissions check.
//		   Watcher@TMI  (2-25-93) added daemon originating support.
//		   Watcher@TMI	(4-4-93)  added wizard only broadcast.
//
//	This command allows an admin to all broadcast a message to
//	users or specifically only wizards, if the -w flag is used.

#include <mudlib.h>
#include <uid.h>

inherit DAEMON ;
 
#define SYNTAX	"Syntax: wall [-w] <message>\n"

int cmd_wall(string str, int wiz) {
   mixed *who;
   string foo, type;
   int loop, daemon;

   if (!adminp(geteuid(previous_object())) &&
     geteuid(previous_object()) != ROOT_UID) {
	notify_fail ("Only admins can broadcast system messages.\n") ;
        return 0 ;
   }
   
   notify_fail( SYNTAX );

   if(!str || str == "")  return 0;

   if(sscanf(str, "-w %s", str) == 1) {
     type = "Wizard ";  
     wiz = 1;
   }
   else type = "";
 
   if(geteuid(previous_object()) == ROOT_UID) {	  //  Assume root daemon call

   daemon = 1;
   foo = "System " + type + "message from " + capitalize(mud_name()) + 
         " at " + ctime(time()) + ":\n" + wrap("     " + str);
   }
 
   else foo = "System " + type + "message from " +
	(string)this_player()->query("cap_name") + " at " + ctime(time()) +
	":\n" + wrap("     " + str);
 
   if(!wiz)  shout(foo);
 
   else {

	who = users();
	who = filter_array(who, "filter_wizards", this_object());
 
	for(loop=0; loop<sizeof(who); loop++)
	   tell_object(who[loop], foo);

   }
 
   if(!daemon)  write(foo);
 
return 1; }

int filter_wizards(object obj) {  
   return (wizardp(obj) && obj != this_player());  }
 
string help() {
 
   return( SYNTAX + "\n" +
     "The wall command allows admin to broadcast a message to all logged\n" +
     "on users.  If the -w flag is used, then it will only broadcast the\n" +
     "message to all logged on wizards. Only admin or root daemons may\n" +
     "use the command.\n");
 
}
 
