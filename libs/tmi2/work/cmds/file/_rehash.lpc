 
//	File	:  /cmds/file/_rehash.c
//	Creator	:  Sulam@TMI  (12/1991)
//	
//	Updated for TMI-2 mudlib by Watcher@TMI-2 (5/93)
//
//	This command is used to update a user's command lookup
//	table for a specified directory.
 
#include <daemons.h>
#include <mudlib.h>

inherit DAEMON ;

#define SYNTAX "Syntax: rehash [path]\n"

int cmd_rehash(string path) {
   
   notify_fail("Rehash: Could not locate requested path.\n");
 
   if(!path || path == "")   path = this_player()->query("cwd");
   else path = resolv_path("cwd", path);
 
   if(CMD_D->rehash(path)) {
    write("Rehash: " + path + " command table updated.\n");
   return 1; }
 
return 0;  }

string help() {

   return( SYNTAX + "\n" +
     "This command updates the given path's entry in the command parsing\n" +
     "lookup tables. If no path is given, it will default to your present\n" +
     "active directory.\n");
 
}
 
