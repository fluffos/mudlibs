// _checkpath.c
// Used to check another player's path. Can only be used by admins.

#include <uid.h>
#include <mudlib.h>

inherit DAEMON ;

int cmd_checkpath(string str) {
   object act_ob, player;
   string *path, tmp;
   string pname, str2 ;
   int i, add_path;

   act_ob = previous_object();
   seteuid(ROOT_UID);

   if(!str) {
	notify_fail ("You need to supply a name.\n") ;
	return 0 ;
   }

   if(!adminp(geteuid(act_ob))) {
	notify_fail ("Only admins can check other player's paths.\n") ;
	return 0 ;
   }

   player = find_player(str) ;
   if (!player) {
	notify_fail ("checkpath: "+str+" is not on this mud\n") ;
	return 0 ;
   }
   write (player->query("cap_name")+"'s path is: "+player->query("PATH")+"\n") ;

   return 1;
}

string help() {
	return ("Usage: checkpath <player>\n\n"+
"The checkpath command will show you the path of another player. Only\n"+
"admins may use it. You can show your own path, or alter it, using the\n"+
"path command, and you can alter another player's path (if you're an admin)\n"+
"using the changepath command.\n") ;
}
