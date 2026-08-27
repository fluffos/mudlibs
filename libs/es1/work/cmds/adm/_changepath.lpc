//#pragma save_binary
// _changepath.c
// Used to change another player's path. Can only be used by admins. Objects
// with root permissions can also alter another player's path variable.

#include <uid.h>
#include <mudlib.h>

inherit DAEMON ;

int cmd_changepath(string str) {
   object act_ob, player;
   string *path, tmp, default_path;
   string pname, str2 ;
   int i, add_path = 0;

   act_ob = previous_object();
   seteuid(ROOT_UID);

   if(!str)
	 return notify_fail("You need to supply a name, and a new path.\n") ;

   if (!member_group(geteuid(this_player(1)),"admin"))
	 return notify_fail("Only admins can change other player's paths.\n") ;

   if( sscanf(str,"-a %s %s",pname,str2)==2 )
     add_path = 1;
   else if( sscanf(str,"%s %s",pname,str2)!=2 )
	 return notify_fail("Usage: changepath <player name> <new path>\n") ;

   player = find_player(pname) ;
   if (!player)
     return notify_fail("No such player.\n") ;
   path = explode(str2,":");

   for(i = 0; i < sizeof(path); i++)
      if(file_size(path[i]) != -2)
         return notify_fail("Error in path statement. " + 
		   path[i] + " is not a directory.\n");
   
   if( add_path ) {
     default_path = player->query("PATH");
     player->set("PATH", default_path + ":" + str2 );
   } else
     player->set("PATH", str2);

   write("Path now set to:\n   "+player->query("PATH")+"\n");
   return 1;
}

int help() {
   write ("Usage: changepath [-a] <player> <newpath>\n\n"+
"This command lets you change the path of another player. Only admins may\n"+
"use it. The player must be logged on at the time. newpath should consist\n"+
"of command directories seperated by colons, ie '/cmds/std:/cmds/file'.\n"+
"One should never remove /cmds/std from anyone's path. You can alter your\n"+
"own path (as opposed to someone else's) by using the path command, which\n"+
"is available to any wizard. You can see what a player's path is by typing\n"+
"\"checkpath <player>\". By the way, -a means to add the path.\n"+
"\nSee also: path, checkpath\n") ;
	return 1 ;
}
