 
//	File	:  /cmds/std/_track.c
//	Creator	:  Watcher@TMI  (02/01/93)
//
//	This command allows one user to trace another user or mobile
//	based upon the tracker's "tracking" skill. 
 
#include <mudlib.h>

inherit DAEMON ;
 
#define SYNTAX	"Syntax: track [target | off]\n"

int cmd_track(string str) {
   object target, trackee;
 
   notify_fail( SYNTAX );
 
   //	Check to see if user is presently tracking anyone.

   trackee = (object)this_player()->query_temp("track");
 
   if(!str || str == "") {
     if(!trackee)  write("You are not presently tracking anyone.\n");
     else write("You are presently tracking " +
		(string)trackee->query("cap_name") + ".\n");
   return 0; }
 
   //	If request stop tracking, clear tracking variable.

   if(str == "off" || str == "stop") {
     if(!trackee)  write("You are not presently tracking anyone.\n");
     else {
	write("You stop tracking " +
		(string)trackee->query("cap_name") + ".\n");
	say((string)this_player()->query("cap_name") + " stops tracking.\n",
	    ({ this_player() }));
	}
     this_player()->delete_temp("track");
   return 1; }
 
   //	Check to see if the user can actually see.
 
   if(!this_player()->query("vision")) {
   write("Track what?  You can't see a thing!\n");
   return 1; }
 
   //	Try to locate requested object in user's environment.

   if (environment(this_player())) 
     target = present( lower_case(str), environment(this_player()) );
   
   if(!target) {
   write("There is no such living object here.\n");
   return 1; }

   //	You can't track yourself ... would be rather silly. :)
 
   if(target == this_player()) {
   write("You cannot track yourself.\n");
   return 1; }
 
   //	Tracking a rock would be even sillier. <grin>
 
   if(!living(target)) {
   write("Non living objects are not likely to move.\n");
   return 1; }
 
   this_player()->set_temp("track", target);

   write("You begin to track " + (string)target->query("cap_name") + ".\n");
   say((string)this_player()->query("cap_name") + " begins to track " +
       (string)target->query("cap_name") + ".\n",
       ({ this_player(), target }));
   tell_object(target, (string)this_player()->query("cap_name") +
	       " begins to track you.\n");
 
return 1; }
 
int help() {

   write( SYNTAX + "\n" +
     "This command allows you to attempt to track and follow another\n" +
     "living object.  The success of the tracking attempt depends on\n" +
     "your tracking skill, which increases with practice.  You can stop\n" +
     "tracking by using \"off\" as an argument.\n");

return 1; }
 
