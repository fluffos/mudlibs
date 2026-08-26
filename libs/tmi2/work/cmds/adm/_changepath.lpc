// _changepath.c
// Used to change another player's path. Can only be used by admins. Objects
// with root permissions can also alter another player's path variable.

#include <uid.h>
#include <mudlib.h>

inherit DAEMON ;

int cmd_changepath(string str) {
   object act_ob, player;
   string *path, tmp;
   string pname, str2 ;
   int i, add_path;

   act_ob = previous_object();
   seteuid(ROOT_UID);

   if(!str) {
	notify_fail ("You need to supply a name, and a new path.\n") ;
	return 0 ;
   }

   if (!adminp(geteuid(this_player(1)))) {
	notify_fail ("Only admins can change other player's paths.\n") ;
	return 0 ;
   }

   if (sscanf(str,"%s %s",pname,str2)!=2) {
	notify_fail ("Usage: changepath <player name> <new path>\n") ;
	return 0 ;
   }

   player = find_player(pname) ;
   if (!player) {
notify_fail ("No such player.\n") ;
	return 0 ;
   }
   path = explode(str2,":");

   for(i = 0; i < sizeof(path); i++) {
      if(file_size(path[i]) != -2) {
         notify_fail("Error in path statement. " + 
		path[i] + " is not a directory.\n");
         return 0;
      }
   }
   
   player->set("PATH", str2);

   write("Path now set to:\n   "+player->query("PATH")+"\n");
   return 1;
}

string help() {
   return ("Usage: changepath <player> <newpath>\n\n"+
"This command lets you change the path of another player. Only admins may\n"+
"use it. The player must be logged on at the time. newpath should consist\n"+
"of command directories seperated by colons, ie '/cmds/std:/cmds/file'.\n"+
"One should never remove /cmds/std from anyone's path. You can alter your\n"+
"own path (as opposed to someone else's) by using the path command, which\n"+
"is available to any wizard. You can see what a player's path is by typing\n"+
"\"checkpath <player>\".\n"+
"\nSee also: path, checkpath\n") ;
}


