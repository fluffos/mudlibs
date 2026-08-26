 
//	File	:  /cmds/std/_whisper.c
//	Creator	:  Watcher@TMI-2  (4/11/93)
//
//	Ghosts can try to whisper ... but don't meet with much success.
 
#include <mudlib.h>
 
inherit DAEMON ;
 
#define SYNTAX	"Syntax: whisper [who] [message]\n"
 
int cmd_whisper(string str) {
   object target;
   string who, message;
 
   notify_fail( SYNTAX );
 
   if(!str || sscanf(str, "%s %s", who, message) != 2)
	return 0;

   if (environment(this_player())) 
       target = present( who, environment(this_player()) );
 
   if(!target) {
   write("There is no one named " + capitalize(who) + " here.\n");
   return 1; }
 
   if(!interactive(target)) {
   write("I don't think that object can understand you.\n");
   return 1; }
 
   if(target == this_player()) {
   write("You mutter to yourself.\n");
   return 1; }
 
   write("You try to whisper to " + capitalize(who) + " but aren't very " +
	 "successful.\n");
 
   tell_object(target, "A breath of air seems to tickle your ear.\n");
 
return 1; }
 
int help() {
 
   write( SYNTAX + "\n" +
      "This command allows the user to speak with another player in the\n" +
      "same room, without other present hearing the message.\n");
   write("\nSee also: wreply.\n");
 
return 1; }
 
