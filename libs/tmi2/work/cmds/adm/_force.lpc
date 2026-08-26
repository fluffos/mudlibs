 
//	File	:  /cmds/adm/_force.c
//	Creator	:  Buddah@TMI  (2-19/92)
//	Redone	:  Watcher@TMI (4-15-93)
//
//	This is the standard force command. It is presently restricted
//	to Admin use, tho you may wish to move it to the xtra directory
//	to lift this restriction. 

#include <mudlib.h>
#include <logs.h>

inherit DAEMON ;

#define SYNTAX	"Syntax: force <object> [to] <command>\n"
 
int cmd_force(string str) {
   object ob;
   string who, what;
 
   notify_fail( SYNTAX );

   if(!str || str == "" || (sscanf(str, "%s to %s", who, what) != 2 &&
      sscanf(str, "%s %s", who, what) != 2))
	return 0;
 
   if(!adminp(geteuid(this_player(1)))) {
   notify_fail("Force: You aren't authorized to force anyone.\n");
   return 0; }
 
   ob = get_object( who = lower_case(who) );
 
   if(!ob) {
   write("Force: No such living object found.\n");
   return 1; }
 
   if(!living(ob)) {
   write("Force: " + identify(ob) + " is not a living object.\n");
   return 1; }
 
#ifdef FORCE_LOG
   if(!ob->query("npc"))
   log_file(FORCE_LOG, wrap((string)this_player()->query("cap_name") +
	" forced " + (string)ob->query("cap_name") + " to \"" + what +
	"\" [" + extract(ctime(time()), 4, 15) + "]"));
#endif
 
   tell_object(ob, (string)this_player()->query("cap_name") + " forced you " +
	"to: " + what + "\n");
 
   ob->force_me( what );

   write("Ok.\n");
 
return 1; }

string help() {
 
   return( SYNTAX + "\n" +
"This command lets you force a player or monster to execute a specified\n"+
"command. You can only force living objects to do commands that are\n"+
"in their current paths or added by add_actions.\n") ;
 
 }
 
