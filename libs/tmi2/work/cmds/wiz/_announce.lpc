 
//	Mud login/logout announcement toggle
//	Created by Glenn Ferguson (Watcher@TMI)  09/26/92
//
//	User command to toggle entry/exit announcements
 
#include <mudlib.h>

inherit DAEMON ;
 
#define STATUS	(mixed *) act_ob->query("announce")
 
string announce_help();
 
object act_ob;
 
int cmd_announce(string str) {
 
   act_ob = this_player();

   notify_fail(announce_help());
   if(!str || str == "")  return 0;
 
   if(STATUS == 0)  act_ob->set("announce", ({ }));
 
   if(str == "on") {
	
   if(STATUS == ({ "ON" })) {
   write("Your announcer flag is already active.\n");
   return 1; }

   write("You set your flag on global announcements.\n");
   act_ob->set("announce", ({ "ON" }));
   return 1; }
 
   if(str == "off") {
   
   if(STATUS == 0 || STATUS == ({})) {
   write("Your announcer flag is already inactive.\n");
   return 1; }
 
   write("You clear and deactivate your announcer flag.\n");
   act_ob->set("announce", ({}));
   return 1; }
 
   if(member_array(lower_case(str),STATUS) != -1) {
   write("You remove " + capitalize(str) + " from your announcer flag.\n");
   act_ob->set("announce", STATUS - ({ lower_case(str) }));
   return 1; }
 
   if(member_array("ON", STATUS) != -1) {
   act_ob->set("announce", ({}));
   write("Global announcement flag has been cleared.\n");  }
 
   write("You add " + capitalize(str) + " to your announce flag.\n");
   act_ob->set("announce", STATUS + ({ lower_case(str) }));
 
return 1; }
 
string announce_help() {
   mixed *who;
   string fail;
   int loop;
 
   fail = "Your announcer flag is presently ";
   who = STATUS;
 
   if(who == 0 || who == ({}))  fail += "inactive.\n";
   else if(member_array("ON", who) != -1)  
	fail += "set on global announcements.\n";
   else {
   fail += "monitoring ";

   for(loop=0; loop<sizeof(who); loop++) {
   fail += capitalize(who[loop]);
   if(loop == sizeof(who) - 2)  fail += ", and ";
   if(loop < sizeof(who) - 2)  fail += ", "; }

   fail = wrap(fail + ".");  }
 
   fail += "Usage: announce [on / [name] / off]\n";

return fail; }
 
int help() {
	write ("Usage: announce [on/off/player name]\n\n"+
"The announce command will cause you to be notified when anyone logs\n"+
"in or out, if you set it to on. You can also set it to notify you of\n"+
"entry and exit of specific players, eg \"announce Buddha\" will let you\n"+
"know if Buddha logs in or out.\n"+
"With no argument, it will tell you who is being announced to you.\n") ;
	return 1 ;
}
