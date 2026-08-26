/*
// Author (??)
// Help added by Brian (1/28/92)
// Converted to mudlib 0.9.0 by Mobydick on 9/19/92
// Kill monster option added by Watcher on 2/19/93
// Watcher added vision check, 4/13/93

// The MudOS mudlib permits player killing by default. It is not hard to
// modify the mudlib to prevent player killing, or permit it only in special
// rooms such as arenas. Instructions for doing this are found in the file
// /doc/mudlib/player_killing.
// If you prevent player_killing you should probably prevent players from
// stealing from one another also, since fights start when the victim detetcts
// a theft.
*/

#include <config.h>
#include <mudlib.h>

inherit DAEMON ;

string help();
string get_monster();

int cmd_kill(string str) {
   object victim, venv;
   int i;

   if(!str) {
      return write(help());
   }
 
   if(str == "monster")  str = get_monster();
 
	if ((int)this_player()->query("hit_points")<=0) {
      notify_fail("You're already dead!\n");
      return 0;
   }
   str = lower_case(str);
   venv = environment(this_player());
   if (!venv) {
      notify_fail("You can't kill anyone in the void!\n");
      return 0;
   }
 
   if(!this_player()->query("vision")) {
   write("Kill what?  You can't see a thing!\n");
   return 1; }
 
   victim = present(str, venv);
   if(!victim) {
      notify_fail("I don't see that here.\n");
      return 0;
   }
   if (!living(victim)) {
	notify_fail ("That is not something you should be attacking.\n") ;
	return 0 ;
   }
    if ((int)victim->query("no_attack")==1) {
	notify_fail("You are not permitted to attack that.\n") ;
   	return 0 ;
   }
   if ((int)victim->query("ghost")==1) {
	notify_fail ("I think the poor ghost has suffered enough.\n") ;
	return 0 ;
   }
   if(victim == this_player()) {
      notify_fail("Kill yourself?\n");
      return 0;
   }
 
   if(victim->query("linkdead")) {
    notify_fail("You cannot attack a linkdead player.\n");
   return 0; }
#ifdef NO_PKILL
	if(userp(victim)){
		write("We don't do that here.\n");
		return 1;
	}
#endif
 
   i = this_player()->kill_ob(victim) ;
   if (i==0) {
		write ("You are already trying to!\n") ;
#ifdef NO_PKILL
	} else if (i==2) {
		write("You are not allowed to attack when your no_attack property is on.\n");
#endif
	} else {
   write("You attack " + (string)victim->query("cap_name") + ".\n");
   say(this_player()->query("cap_name") + " attacks " + 
     victim->query("cap_name") + ".\n", victim);
	tell_object(victim,previous_object()->query("cap_name") + " attacks you!\n") ;
   }
	victim->set_heart_beat(1) ;
	return 1 ;
}

string get_monster() {
   mixed *env;
 
   env = all_inventory( environment(this_player()) );
   if(!env || !sizeof(env))  return 0;
 
   env = filter_array(env, "filter_npc", this_object());
   if(!env || !sizeof(env))  return 0;
 
return (string)env[0]->query("name"); }
 
int filter_npc(object obj) {  return (int)obj->query("npc");  }
 
string help() {
  return("Syntax: kill <monster>\n\n"+
        "This command is used to initiate combat with the\n"+
         "monster you specify.  Once combat begins you may\n"+
        "only end it by running away or if one of you dies.\n"+
        "Other players may also be attacked.\n");
}
/* EOF */
