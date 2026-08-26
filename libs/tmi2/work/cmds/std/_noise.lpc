 
//	File	:  /cmds/std/_noise.c
//	Creator	:  Watcher@TMI-2  (04/25/93)
//
//	This command allows users to decide how much noise from 
//	an ongoing battle the user will hear.
 
#include <mudlib.h>
 
inherit DAEMON;
 
#define SYNTAX	"Syntax: noise [off | low | high]\n"
 
int cmd_noise(string str) {
   int noise;
 
   //	Get the user's present noise earmuff level
 
   noise = (int)this_player()->query("noise_level");
 
   if(!str || member_array(str, ({ "off", "low", "high" })) == -1) {
 
	if(!noise) 
	  notify_fail("Your noise earmuffs are presently inactive.\n" + SYNTAX);
	else if(noise == 1)
	  notify_fail("Your noise earmuffs are set on low.\n" + SYNTAX);
	else 
	  notify_fail("Your noise earmuffs are set on high.\n" + SYNTAX);

   return 0; }
 
   if(str == "off") {
 
	if(!noise) {
	write("Your noise earmuffs are already off.\n");
	return 1; }
 
	this_player()->set("noise_level", 0);
	write("You remove your noise earmuffs.\n");

   return 1; }
 
   if(str == "low") {

	if(noise == 1) {
	write("Your noise earmuffs are already on low.\n");
	return 1; }

	this_player()->set("noise_level", 1);
	write("You set your noise earmuffs on low.\n");

   return 1; }
 
   if(noise > 1) {
   write("Your noise earmuffs are already on high.\n");
   return 1; }
 
   this_player()->set("noise_level", 2);
   write("You set your noise earmuffs on high.\n");
 
return 1; }
 
string help() {
 
   return( SYNTAX + "\n" +
     "This command allows you to filter out unimportant background noise,\n" +
     "such as selected battle message results. If your noise earmuffs are\n" +
     "set on low, then you will not hear any battle messages which indicate\n" +
     "a battle blow that has missed. If your noise earmuffs are on high, it\n" +
     "will have the same effect as low for those involved in the battle, and\n"+
     "will not display any battle messages if you are not in the battle.\n");
 
}
 
