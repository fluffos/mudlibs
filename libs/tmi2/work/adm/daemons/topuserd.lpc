 
//	File	:  /adm/daemons/topuserd.c
//	Creator	:  Watcher@TMI-2  (7/1/93)
//
//	This daemon produces an output of the top ranking users
//	according to their saved skill statistics.
 
//	PLEASE NOTE: Depending on the size of your user database,
//	running this system can cause a large lag for about 10
//	minutes, thus it may be adviseable to schedule the daemon
//	to produce it early in the morning with the event daemon.
 
#include <daemons.h>
#include <mudlib.h>
#include <config.h>
#include <uid.h>

inherit DAEMON;
 
#define RANK_NUM	25	//  Number of ranking positions displayed
#define INCLUDE_WIZS	1	//  Include wizards in the ranking list ?
#define MIN_SCORE	5	//  Any score below this are not ranked
 
#define OUTPUT_FILE	"/log/top_user_list"
 
protected int create_shell();
protected int create_list();
protected int scan_dir(string dir);
protected int process_user(string who);

mixed	*list;
 
object	shell;
int	active;

 
void create() {  
	seteuid(getuid(this_object()));
}
 
 
//  This function creates the user shell from which the user's 
//  skill stat system. If it cannot create a shell, it will
//  terminate the top user list production cycle.
 
protected int create_shell() {
   string err;
 
   err = catch( shell = new(USER_OB) );

   if(err) {
   write("Error: Could not generate shell for top user list.\n       " + err );
   return 0; }
 
return 1; }
 
 
//  This function begins the production of the top user list.
//  It will block the call if it is not a ROOT or Admin request.
 
int produce_list() {
   object who;
   string *main;
   int loop;

   //	Check permissions of caller ... block if not ROOT or admin
 
   if(geteuid(previous_object()) != ROOT_UID &&
      !adminp(geteuid(previous_object())))  return 0;

   //	Is there already a list being produced? If so return -1
   //	to inform the caller that one is already being produced.
 
   if(active) return -1;
 
   //	Create the user data shell for processing.
 
   if(!create_shell())  return 0;
 
   active = 1;
 
   //	Wipe clean and setup list data array
 
   list = ({ });
 
   //	Note the calling user's object pointer.
 
   if(this_player())  who = this_player();
 
   //	Get an array of all the character data subdirectories
   //	to process the individual user.o files.
 
   main = get_dir( CDATA_DIR + "/" );

   if(!main || !sizeof(main))  return 0;
 
   //	Loop through and check each user subdirectory.

   for(loop=0; loop<sizeof(main); loop++)
	scan_dir(CDATA_DIR + "/" + main[loop] + "/");
 
   //	Okay, done with the shell ... destruct it.

   if(shell)  destruct(shell);
 
   //	Sort the user list into descending ranking order
 
   list = sort_array(list, "rank_list", this_object());
 
   //	Now that the rank array is done ... produce the ranking list.
 
   create_list();
 
   //	Ranking sweep is no longer active ... so remove the flag.
 
   active = 0;
 
   //	Now if the command initiator exists, inform them that the
   //	list creation is done. You may wish to make this into a
   //	shout-like announcement, to inform all mudders of the 
   //	updated user rankings. 
 
   if(who)  tell_object(who, "Top user list creation complete.\n");
 
return 1; }
 
 
//  This function does the actual scanning of the individual 
//  user subdirectories, and processes each of the user.o files
//  for its skill stat value rankings.
 
protected int scan_dir(string dir) {
   string *files;
   int loop;
 
   //	Get an array of the individual user.o files.  If none exist
   //	in this subdirectory, go to the next one.
 
   files = get_dir(dir);

   if(!files || !sizeof(files))  return 0;

   //	Loop through each file and pass it to the processing function
   //   The compartmentalization allows admins to easily change the
   //	the specific requirements for ranking which is generally
   //	mudlib dependent and varies. :)
 
   for(loop=0; loop<sizeof(files); loop++)
	process_user(dir + files[loop]);

return 1; }
 
 
//  This function does the actual character processing and stores 
//  the user's skill statistic score (or whatever mudlib dependent
//  statistic system) for ranking.
 
protected int process_user(string who) {
   mapping skills;
   string *askills, *junk, name;
   int loop, count;
 
   //	Double check to see if the user file actually exists, and
   //	parse out the user's name from the file name.
 
   if(!who || !file_exists(who) ||
      sscanf(who, "%s" + __SAVE_EXTENSION__, name) != 1)  return 0;
 
   junk = explode(name, "/");
   name = junk[sizeof(junk)-1];
 
   //	Prepare and setup the user shell for data request.
 
   reload_object(shell);

   seteuid(name);
   export_uid(shell);
 
   if(!shell->restore_body())  return 0;
 
   //	Set the daemon's euid back to ROOT
 
   seteuid(ROOT_UID);
 
   //	Get the skill statistics from selected user
 
   skills = (mapping)shell->query_skill_stats();
   
   if(!skills || !mapp(skills))  return 0;
 
   askills = keys(skills);
 
   // 	Loop through the skills and add em up

   for(loop=0; loop<sizeof(askills); loop++)
	count += skills[askills[loop]];
 
   //	If the score is less than the defined MIN_SCORE, don't 
   //	include it in the ranking mapping.
 
   if(count < MIN_SCORE)  return 0;
 
   //	Check to see if wizards are included and if user is a wizard.
 
   if(!INCLUDE_WIZS && shell->query("wizard"))  return 0;
 
   //	Okay, the score qualifies, so add it to the ranking array.
 
   list += ({ ({ name, count }) });
 
return 1; }
 
 
//  This function returns a copy of the ranked list of user scores.
 
mixed *query_list() {  return list;  }
 
 
//  This function is used to sort the ranking array.
 
protected int rank_list(mixed *part1, mixed *part2) {
	return (part2[1] - part1[1]);  }
 
 
//  This function produces the top user list output file. You may 
//  wish to customize it to your own mudlib's needs and format.
 
protected int create_list() {
   string dump;
   int loop;
 
   //  	Create the list output header information
 
   dump = "\t\t\tTOP RANKING USER LIST\n\t\t\t=====================\n\n" +
	  "   Created: " + ctime(time()) + "\tActive users: " + sizeof(list) +
	  "\n\n";

   //	Loop through the ranking array and tack on top set to list.
 
   for(loop=0; (loop<25 && loop<sizeof(list)); loop++) {
	dump += sprintf("  %-5s%-11s%-10s",
		(loop<9 ? " [" + (loop+1) + "]" : "[" + (loop+1) + "]"),
		capitalize(list[loop][0]), 
		list[loop][1] + " skill points");
	if(loop % 2)  dump += "\n";  else  dump += "\t";
   }
 
   dump += "\n";
 
   //	Okay ... create the actual ranking output file.
 
   if(file_exists(OUTPUT_FILE))  rm(OUTPUT_FILE);
   write_file(OUTPUT_FILE, dump);
 
return 1; }
 
