/* Author (??)
 * Help added by Brian (1/28/92)
 * rehack to check kill_ob first before continuing with kill and PK labeling
 * by Valodin, Feb 13, 1993
 * minor changes by Bohemund, Jan 22, 1993
 * notify victim of attack (duh...) Bohemund March 9. 1994
 */

#include <std.h>

inherit DAEMON;
 
int help();
 
int cmd_kill(string str) {
   object victim;
   int retvalue;   /* return value */
   int i;
 
   if(!str) {
      return help();
   }
   if((string)this_player()->query_name() == "guest") {
      notify_fail("Guests should not be so violent!\n");
      return 0;
   }
   if(this_player()->query_ghost()) {
      notify_fail("You're already dead!\n");
      return 0;
   }
   if(environment(this_player())->query_property("no attack")) {
      notify_fail("Greater powers prevent your malice.\n");
      return 0;
   }
   str = lower_case(str);
   victim = present(str, environment(this_player()));
   if(!victim) {
      notify_fail("You don't see that here.\n");
      return 0;
   }
   if(victim == this_player()) {
      notify_fail("Kill yourself?\n");
      return 0;
   }
 
   if(!living(victim)) {
      notify_fail("That is not a living foe.\n");
      return 0;
   }
   /* check for an okay hit before we actually continue, Val */
   if (!(retvalue = (int)this_player()->kill_ob(victim))) return 1;
 
   write("%^RED%^%^BOLD%^You attack "+(string)victim->query_cap_name() + "!");
   say(this_player()->query_cap_name() + " attacks " +
     victim->query_cap_name() + "!", victim);
   tell_object(victim, "%^RED%^%^BOLD%^"+
	       (string)this_player()->query_cap_name()+
	       " attacks you!");
   return retvalue;
}
 
int help() {
  write("Command: kill\nSyntax: kill <living>\n"
        "This command is used to initiate combat with the "
	"living being you specify.  Once combat begins you may "
        "only end it by running away or if one of you dies. "
        "Other players may also be attacked.\n"
        "See book on playerkilling in library\n"
        "See \"help death\"\n"
        "See also: wimpy, wimpydir, follow, party\n");
  return 1;
}
/* EOF */
