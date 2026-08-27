
//	File	:  /adm/daemons/purge.c
//	Creator	:  Watcher@TMI-2  (5/93)
//
//	This daemon allows admins to delete user characters that are
//	older than the inputed integer time value. Wizards can be
//	deleted by defining flag = 1, and both the wizard and its
//	directory by defining flag = 2. If test if true, the directories
//	and user files will not be deleted, only flagged.

#include <uid.h>
#include <config.h>
#include <daemons.h>
#include <mudlib.h>

inherit DAEMON;

protected int sweep_dir(string dir, int when, int verbose, int flag, int test);
protected int fail_test(string dri, string what, int when, int flag);
protected int remove_user(string where, int verbose, int flag, int test);

object link;
int total, busy;

int process_users(int when, int verbose, int flag, int test) {
  string *main;
  int loop;

   //	Check time length and caller's permissions.

   if(!when || !intp(when) || (geteuid(previous_object()) != ROOT_UID &&
      !member_group(geteuid(previous_object()), "admin")))
	return 0;

   seteuid(getuid(this_object()));

   //	Check to see if the daemon is presently in use ... If so
   //	tell the caller to try again later (shouldn't really have
   //	repeated calls anyways).

   if(busy)  return 0;

   busy = 1;

   //	If there isn't a this_player(), then any write()s will get
   //	dumped to the syslog ... would be messy ... so block it. :)

   if(!this_player())  verbose = 0;

   //	Check to make sure the flags are acceptable.

   if(flag < 0)  flag = 0;
   if(flag > 2)  flag = 2;

   //	Create temporary link connection object for restoring data.

   link = new(CONNECTION);
   total = 0;

   //	Get subdirectory listing from user save directory.

   main = get_dir( PDATA_DIR + "/" );

   if(!main || !sizeof(main))  return 0;

   if(verbose)
	write(underscore("Initiating user character " +
	      (test ? "test " : "") + "purge") + "\n" +
	      "Last login prior to " + ctime(time()) + ".\n\n");

   //	Loop through directory contents using a catch() to catch
   //	the "Too large evaluation" errors, then backup and do the
   //	failed directory again until you finish it.

   for(loop=0; loop<sizeof(main); loop++)
   if(catch(sweep_dir(PDATA_DIR + "/" + main[loop] + "/", when, verbose,
      flag, test))) {
   if(verbose)  write("Error occurred: Restarting subdir sweep.\n");
   loop--;
   }

   //	We're all done ... destruct the working link.

   destruct(link);

   if(this_player())
   write((verbose ? "\n" : "") + "Processing complete ... " + total +
	 " users " + (test ? "flagged" : "deleted") + ".\n");

   busy = 0;

return 1; }


//  This function sweeps through each of the user save subdirectories
//  and check each user to see if they match the purge criteria.

protected int sweep_dir(string dir, int when, int verbose, int flag, int test) {
   string *contents;
   int loop;

   if(!directory_exists(dir))  return 0;

   if(verbose)  write(bold("Sweeping: " + dir) + "\n");

   contents = get_dir(dir);

   if(!contents || !sizeof(contents))  return 0;

   //	Loop through contents of the subdirectory check for compliance.

   for(loop=0; loop<sizeof(contents); loop++)
	if(fail_test(dir, contents[loop], when, flag))
		remove_user(contents[loop], verbose, flag, test);

return 1; }

protected int fail_test(string dir, string what, int when, int flag) {
   string name;

   //	Parse off the user's name ...

   if(!what || !file_exists(dir + what) ||
      sscanf(what, "%s" + SAVE_EXTENSION, name) != 1)  return 0;

   //	Reset the link's properties for the next user.

   reload_object(link);

   seteuid(name);
   export_uid(link);
   seteuid(ROOT_UID);

   link->set("name", name);

   if(!link->restore())  return 0;

   if(!flag && (int)link->query("wizard"))  return 0;

   if((int)link->query("last_on") < when)  return 1;

return 0; }

protected int remove_user(string where, int verbose, int flag, int test) {
   string name, wiz_dir, tmp;

   sscanf(where, "%s" + SAVE_EXTENSION, name);
   wiz_dir = HOME_DIRS + extract(name, 0, 0) + "/" + name + "/";
   total++;

   tmp = capitalize(name);

   if(flag == 2 && directory_exists(wiz_dir)) {
      if(!test)  CLEAN_D->clean_dir(wiz_dir);
      tmp += " and " + wiz_dir + " " + (test ? "flagged" : "deleted") + ".\n";
   }
   else tmp += " " + (test ? "flagged" : "deleted") + ".\n";

   if(!test) {
     rm(DATA_DIR + "/std/user/" + name[0..0] + "/" + name + SAVE_EXTENSION);
     rm(PDATA_DIR + "/" + name[0..0] + "/" + name + SAVE_EXTENSION);
   }

   if(verbose)  write(tmp);

return 1; }

int query_busy() {  return busy;  }
