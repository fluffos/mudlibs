//	File	:  /cmds/std/_wreply.c
//	Creator	:  Watcher@TMI-2   (01/93)
//
//	The whisper's equivalent of the reply command. It will
//	whisper back to the last person who whispered to the user.
 
#include <mudlib.h>

inherit DAEMON ;

#define SYNTAX  "Syntax: wreply <message>\n"

int cmd_wreply( string mess ) {
   string reply;
 
   notify_fail( SYNTAX );
 
   if(!mess || mess == "")  return 0;
 
   reply = (string) this_player()->query( "wreply" );
 
   if(!reply) {
   write("No one has whispered to you yet.\n");
   return 1; }
 
   reply = lower_case(reply);
 
   if(!environment(this_player()) ||
           !present(reply, environment(this_player()))) {
       write(capitalize(reply) + " is no longer here.\n");
       return 1;
   }
 
   this_player()->force_me( "whisper " + reply + " " + mess );
 
return 1;  }
 
int help() {
 
   write( SYNTAX + "\n" +
     "Allows you to whisper <message> to the last person who\n" +
     "previously whispered to you.\n\nSee also: whisper.\n");
 
return 1; }
 
