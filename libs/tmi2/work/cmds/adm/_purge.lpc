 
//	File	:  /cmds/adm/_purge.c
//	Creator	:  Watcher@TMI-2  (5/15/93)
//
//	This command is used to instruct the purge daemon to delete
//	users who have not been active since the inputted date.

#include <uid.h>
#include <mudlib.h>
#include <daemons.h>
 
inherit DAEMON;
 
#define SYNTAX	"Syntax: purge [-dtvw] [date integer]\n"
 
int cmd_purge(string str) {
   string qual, tmp1, tmp2;
   int flag, date, test, verbose;
 
   //	Check to ensure the user has admin permissions.
 
   if(!adminp(geteuid(previous_object())))  return 0;
 
   notify_fail(SYNTAX);
 
   if(!str || str == "")  return 0;
 
   //	Check to see if the user has requested any flag modifications.
 
   if(sscanf(str, "-%s %d", qual, date) == 2) {
 
	if(sscanf(" " + qual + " ", "%sw%s", tmp1, tmp2) == 2) flag = 1;
	if(sscanf(" " + qual + " ", "%sd%s", tmp1, tmp2) == 2) flag = 2;
	if(sscanf(" " + qual + " ", "%st%s", tmp1, tmp2) == 2) test = 1;
	if(sscanf(" " + qual + " ", "%sv%s", tmp1, tmp2) == 2) verbose = 1;

   }
 
   //	Otherwise try to parse out the date integer from the string.
 
   else if(sscanf(str, "%d", date) != 1)  return 0;

   seteuid(getuid(this_object()));
 
   //	If the requested date is less than zero, or greater than the
   //	present time integer, it is obviously invalid.
 
   if(date < 0 || date > time()) {
    write("Purge: Invalid date value request.\n");
   return 1; }
 
   //	Check to see if the purge daemon is presently busy.

   if((int)PURGE_D->query_busy()) {
    write("Purge: A purge operation is already running.\n");
   return 1; }
 
   //	Okay ... double check the user's request. Just in case. :)
 
   write("A " + (test ? "flagging" : "purge") + " of all users inactive " +
	 "since " + bold(extract(ctime(date), 4)) + " has been requested.\n");
   if(flag || verbose)
   write("Parameters: " + (flag ? "Including all wizards" +
	 (flag == 2 ? " and their directories" : "") : "") +
	 (verbose ? (flag ? ", and " : "") + "verbose mode" : "") + "\n");
   write("Are you sure you wish to initiate this " +
	 (test ? "test" : "purge") + "? [y/n] ");
 
   input_to("purge_check", 0, date, test, flag, verbose);
 
return 1; }
 
 
//  This function completes the purge depending on the answer to the
//  confirmation request ... the user will be informed of any errors.
 
protected int purge_check(string str, int date, int test, int flag, int verbose) {

   if(!str || member_array(lower_case(str), ({ "yes", "y" })) == -1) {
   write("Purge: Request aborted.\n");
   return 1; }
 
   if(catch(PURGE_D->process_users(date, verbose, flag, test))) 
   write("Purge: Could not conduct process.\n");
 
return 1; }
 
string help() {

   return(SYNTAX + "\n" +
     "This command can be used by Admin to purge out all inactive users in\n" +
     "the mud's database. All wizards and their directories are protected\n" +
     "by default, unless overridden by the command flags, w and d. The w\n" +
     "flag requests that the purge protection on wizards be lifted, and the\n"+
     "d flag specifies the deletion of the wizard's directory as well. If\n" +
     "the t flag is requested, the users will only be flagged...not purged.\n"+
     "The v flag specifies a verbose output where all users are displayed\n" +
     "as they are flagged or deleted.\n");

}
 
