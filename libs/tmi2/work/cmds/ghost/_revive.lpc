// _revive.c
// This command notifies the ghost that he must go the cemetery and pray
// there, unless he's a wizard, in which case he gets revived and, since
// we're friendly, set to full hit points :)
// Written by Mobydick, 11-22-92. Beat the weenies.
// Modified by Watcher, 03-28-93 for the new body system.

#include <mudlib.h>

inherit DAEMON ;

int cmd_revive() {

	int res ;
 
	if (!wizardp(this_player())) {
	write("You must make your way to the cemetery, and pray to be "+
	      "revived.\n");
	return 1; }
 
	this_player()->revive();
 
	res = this_player()->query("max_hp");
	this_player()->set("hit_points", res);
 
return 1; }
 
int help() {

   if(wizardp(this_player())) 
   write("Simply type \"revive\" to return to life.\n");

   else write("You must make your way to the cemetery to be revived.\n");

return 1; }
 
