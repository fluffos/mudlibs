//#pragma save_binary

//	File	:  /cmds/file/_rmdir.c
//	Creator	:  Sulam@TMI  (1-8-92)
//	Updated	:  Watcher@TMI (2-20-93) for recursive wiping of
//		   directory and a few other improvements.
//
//	This is the wizard rmdir command.  If the -r flag is used it
//	will also recursively clean the contents of the directory.

#include <mudlib.h>
#include <daemons.h>
#include <uid.h>

inherit DAEMON ;

#define SYNTAX	"Syntax: rmdir [-r] [directory]\n"

int cmd_rmdir(string str) {
   int wipe;

   notify_fail( SYNTAX );
   if(!str || str == "")  return 0;

   seteuid(geteuid(previous_object()));

   if(sscanf(str, "-r %s", str) == 1)  wipe = 1;

   str = resolv_path("cwd", str);

   switch( file_size(str) ) {
	case -1 :	notify_fail("Rmdir: No such directory.\n");
			return 0;  break;
	case -2 :	break;
  	default :	notify_fail("Rmdir: Not a directory.\n");
			return 0; break;
   }

   if((int)master()->valid_write(str, geteuid(this_object())) == 0) {
   notify_fail("Rmdir: Permission denied.\n");
   return 0; }

   if(wipe) {
   write("Are you sure you wish to remove \"" + str + "/\"? [y/n] ");
   input_to("remove_directory", 0, str);
   return 1; }

   if(sizeof( get_dir(str + "/") )) {
   notify_fail("Rmdir: Directory is not empty.\n");
   return 0; }

   write(rmdir(str) ? "Rmdir: Directory removed.\n" :
		      "Rmdir: Could not remove directory.\n");

return 1; }

protected int remove_directory(string str, string dir) {

   if(str != "y" && str != "yes") {
   write("Rmdir: Directory removal aborted.\n");
   return 1; }

   if((int)CLEAN_D->clean_dir(dir, 1) == 0 || !rmdir(dir)) {
   write("Rmdir: Directory removal failed.\n");
   return 1; }

   write("Rmdir: Directory recursively removed.\n");

return 1; }

int help() {

   write( SYNTAX + "\n" +
	"This command allows you to remove the specified directory. If\n" +
	"the -r flag is used, it will recursively clean the directory of\n" +
	"all files and subdirectories before completing the removal.\n");

return 1; }
