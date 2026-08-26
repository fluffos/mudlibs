// _invis.c
// Command to allow wizards to become invisible.
// Two levels of invisibility are offered: invisibility to player and
// invisibility to wizards. Admins can always see you regardless of you
// invisibility level
// Written by Mobydick@TMI-2, 10-3-92. Loosely based on an existing
// version whose original author is unknown.
// Modified by Wark@TMI-2, 12-4-92 to allow saving of prompts.
// Modified by Pallando 93-02-13 to delete oldprompt when not needed and
// 				 to include your oldprompt in the new one.
// Modified by Watcher 93-03-27 to allow number arguments, adding in
//	mvis and minvis display messages, and doing a general cleanup.

#include <mudlib.h>

inherit DAEMON;

#define SYNTAX	"Syntax: invis [none | players | wizards]\n"

varargs int cmd_invis(string str) {
   object act_ob;
   string olprompt;
   int i, invis;
   
   act_ob = previous_object();
 
   notify_fail( SYNTAX );
 
   if(!str || str == "") {
 
	invis = (int)act_ob->query("invisible");
 
	if(invis == 2)
	  write("You are presently invisible to wizards.\n");
	else if(invis == 1) 
	  write("You are presently invisible to players.\n");
	else write("You are not presently invisible.\n");
 
   return 0; }
 
   if(str == "none") {
 
	if((int)act_ob->query("invisible") < 1) {
	write("You are not presently invisible.\n");
	return 1; }
 
	act_ob->remove_env("prompt");
	olprompt = (string)act_ob->getenv("oldprompt");
	if(olprompt)  act_ob->setenv("prompt", olprompt);
	act_ob->remove_env("oldprompt");
 
 	act_ob->set("invisible", 0);
	act_ob->do_new();
 
	write("You are now visible.\n");
	say((string)act_ob->query_mvis() + "\n", ({ act_ob }));
 
   return 1; }
 
   if(str == "players" || str == "1") {
 
	if((int)act_ob->query("invisible") < 1) {
	  olprompt = (string)act_ob->getenv("prompt");
	  if(olprompt)  act_ob->setenv("oldprompt", olprompt);
	  say((string)act_ob->query_minvis() + "\n", ({ act_ob }));
	}
	else olprompt = (string)act_ob->getenv("oldprompt");
 
	act_ob->set("invisible", 1);
	act_ob->setenv("prompt", (olprompt ? ("PI " + olprompt) : "PI>"));
	act_ob->do_new();
 
	write("You are now invisible to players.\n");

   return 1; }
 
   if(str == "wizards" || str == "wiz" || str == "2") {
 
	if((int)act_ob->query("invisible") < 1) {
	  olprompt = (string)act_ob->getenv("prompt");
	  if(olprompt)  act_ob->setenv("oldprompt", olprompt);
	  say((string)act_ob->query_minvis() + "\n", ({ act_ob }));
	}
	else olprompt = (string)act_ob->getenv("oldprompt");
 
	act_ob->set("invisible", 2);
	act_ob->setenv("prompt", (olprompt ? ("WI " + olprompt) : "WI>"));
	act_ob->do_new();
 
	write("You are now invisible to wizards.\n");
 
   return 1; }
 
return 0; }

int help() {

   write( SYNTAX + "\n" +
     "The invis command controls your character's invisibility. By typing\n" +
     "\"invis players\", you become invisible to players, while typing\n" +
     "\"invis wizards\" will make you invisible to both players an wizards.\n"+
     "By typing \"invis none\", you become visible to all users. Admins can\n"+
     "see you regardless of your invisibility setting.\n");
 
return 1; }
 
