/*
// The "demote" command.
// Brought to you by Jubal.
// Notification and logging added by Huma (4/25/92)
// Revised to communicate with a modified Domains daemon by Buddha, and
// also allow you to demote someone who is not logged in at the
// moment (1/23/93)
// Part of the TMI mudlib.
// 06-04-95 Leto changed logs to use logs.h
*/


#include <mudlib.h>
#include <login_macros.h> 
#include <daemons.h>
#include <domains.h>
#include <logs.h>

inherit             DAEMON;

int
cmd_demote(string arg)
{
    string              domain, target;
    object              tmp, myLink, targetLink;
    int                 myLev, targetLev;

    if (!arg || sscanf(arg, "%s %s", target, domain) < 2) {
	notify_fail("Usage: demote <name> <domain>\n");
	return 0;
    }
    if (member_array(domain, DOMAIN_LIST) == -1) {
	notify_fail("No such domain.\n");
	return 0;
    }
    tmp = previous_object();
    if (!interactive(tmp))
	return 0;
    //no security hole here...
      myLink = (object) tmp->query_link();
    myLev = member_array(
		      (string) DOMAIN_D->query_domain_level(myLink, domain),
			 LEVEL_LIST);
 /* If the command giver is an admin...well, let them do whatever. */
    if (adminp(geteuid(myLink)))
	myLev = sizeof(LEVEL_LIST);
    if (myLev < MIN_SPONSOR_LEVEL) {
	notify_fail(
		    "You must be at least " +
		    LEVEL_LIST[MIN_SPONSOR_LEVEL] +
		    " level in the domain to demote someone.\n");
	return 0;
    }
 /*
  * Ask the finger daemon to get a link for us, so that if they are not on at
  * the time, we can still do this. 
  */
    targetLink = FINGER_D->restore_data(target);
    if (!targetLink) {
	notify_fail("No such user.\n");
	return 0;
    }
    targetLev = member_array(
		  (string) DOMAIN_D->query_domain_level(targetLink, domain),
			     LEVEL_LIST);
    if (targetLev >= myLev) {
	write((string) targetLink->CAP_NAME +
	      " is too high a level for you to demote.\n");
	return 1;
    } else if (targetLev < ENTRY_LEVEL) {
	write((string) targetLink->CAP_NAME + " is not in that domain.\n");
	return 1;
    }
    targetLev--;
    if (DOMAIN_D->set_domain(targetLink, domain,
			     LEVEL_LIST[targetLev], geteuid(myLink))) {
	tmp = find_player(target);
	if (targetLev == 1) {
	    if (tmp)
		tell_object(tmp, (string) myLink->CAP_NAME +
		       " has removed you from the " + domain + " domain.\n");
	    write("Removed from domain.\n");
	    log_file("DEMOTE_LOG", (string) myLink->CAP_NAME +
		     " removed " + capitalize(target) +
		     " from the " + domain + " domain.\n");
	} else {
	    if (tmp)
		tell_object(tmp, (string) myLink->CAP_NAME +
			    " has demoted you to " + LEVEL_LIST[targetLev] +
			    " in the " + domain + " domain.\n");
	    write("Level set to " + LEVEL_LIST[targetLev] + ".\n");
	    log_file("DEMOTE_LOG", (string) myLink->CAP_NAME +
	    " demoted " + capitalize(target) + " to " + LEVEL_LIST[targetLev] +
		     " in the " + domain + " domain.\n");
	}
    } else {
	write("Failed to set level.\n");
    }
 /*
  * This will force a save, and if the user is not on, a remove() as well. 
  */
    targetLink->clean_up();

    return 1;
}


int 
help()
{
    write(
	  "Command: demote\n" +
	  "Syntax:  demote <name> <domain>\n" +
	  "  The demote command lowers the level of <name> in domain <domain> by\n" +
       "one.  If <name>'s level is lowered below novice, he/she will be\n" +
    "removed from the domain.  You must be of at least initiate level to\n" +
     "demote people, and you can only demote people of lower level than\n" +
	  "yourself.\n" +
	  "  See also: domains, sponsor\n");
    return 1;
}

/* EOF */
