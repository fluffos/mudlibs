 
//	File	:  /cmds/xtra/_clean.c
//	Creator	:  Unknown
//	Updated	:  Watcher@TMI   (4/10/93)
//
//	This command cleans the inventory of a selected object.
 
#include <mudlib.h>
 
inherit DAEMON;

#define SYNTAX	"Syntax: clean [-d] [object]\n"
 
int cmd_clean(string str) {
   object *obs, ob;
   int i, flag;
    
   if(!str || str == "")  str = "me";
 
   if(sscanf(str, "-d %s", str) == 1)  flag = 1;
 
   str = lower_case(str);
 
   ob = get_object( str );
 
   if(!ob) {
     notify_fail("Clean: Could not locate " + str + ".\n");
   return 0; }
 
   if(flag && interactive(ob) &&
      !adminp(geteuid(this_player()))) {
   	notify_fail("Clean: You do not have permissions to destruct " +
		    "that object.\n");
   return 0; }
 
   obs = all_inventory(ob);
 
   if(!obs || !sizeof(obs)) {
     notify_fail("Clean: " + identify(ob) + " has no inventory.\n");
   return 0; }
 
   write("Cleaning " + (flag ? "and destructing " : "") +
 	 identify(ob) + ".\n");
 
    for (i=0; i<sizeof(obs); i++) {
        if (!living(obs[i]) && !obs[i]->id("board")) {
            write ("  Destructing:  "+file_name(obs[i])+"\n");
            obs[i]->remove();
	    if(obs[i])  destruct(obs[i]);
        }
    }
 
   if(flag) {
     ob->remove();
     if(ob)  destruct(ob);
   }
 
return 1; }

int help() {
 
   write( SYNTAX + "\n" +
     "This command removes all non-living objects in the inventory of\n" +
     "requested object. If the \"d\" flag is used, it will also remove\n" +
     "the object after it has been cleaned. Only admins may use this\n"+
     "option on interactive objects. If no argument is given, the clean\n"+
     "command will clean the inventory of the command giver.\n");
 
return 1; }
 
