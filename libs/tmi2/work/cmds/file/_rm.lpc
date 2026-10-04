//      File    :  /cmds/file/_rm.c
//      Creator :  Watcher@TMI  (02/20/93)
//      Improved:  Watcher@TMI  (03/28/93)  Substituted get_dir() call
//                  for the wildcard() call so that 'dot' files can be
//                  processed as well. Thanks to Zak for the fix.
//                 Watcher@TMI  (04/11/93)  Added multiple line rms.
//                  (ie: rm a1 a2)
//                 Robocoder@TMI (06/23/93) to use file lock daemon
// 93-08-12 Artagel@tmi-2 Fixed bug re: deleting files in non-existant dirs.
//
//      This is the wizard remove file command.  It also responds to
//      wildcard inputs and recursive deletion flags.
 

#include <config.h>
#include <mudlib.h>
#include <daemons.h>
#include <flock.h>
#include <uid.h>

inherit DAEMON ;

#define SYNTAX  "Syntax: rm [-r] [file pattern] [..] [..]\n"
 
protected int remove_file(string file, int flag);

int cmd_rm(string str) {
   mixed *files, *path, *multi;
   string dir;
   int flag, loop;
 
   notify_fail( SYNTAX );
   if(!str || str == "")  return 0;
 
   seteuid(getuid(this_object()));
 
   if(sscanf(str, "-r %s", str) == 1)  flag = 1;
 
 
   //   Check for multiple file deletion request
 
   multi = explode(str, " ");

   if(multi && sizeof(multi) > 1) {

        for(loop=0; loop<sizeof(multi); loop++)
          cmd_rm( multi[loop] );

   return 1; }
 
 
   //  Check to see if the request is bad ("..*")

   if(str == "..*") {
   write("Rm: Illegal file pattern.\n");
   return 1; }
 
   str = resolv_path("cwd", str);
 
   //   Check the caller's write permissions in target directory
 
   path = explode(str, "/");
   
   dir = "/" + implode( path[0..sizeof(path)-2], "/" ) + "/";
   if(dir == "//")  dir = "";

   if((int)master()->valid_write(dir, previous_object(), "rm") == 0) {
   write("Rm: Permission denied in " + 
               (dir == "" ? "root directory" : dir) + ".\n");
   return 1; }
 
   //   Check for wildcards present in rm request
 
   files = get_dir(str);
 
   if(files) {
      files -= ({ "." });  files -= ({ ".." });
   }
 
   if(!files || !sizeof(files)) {
   write("Rm: No such pattern : " + str + "\n");
   return 1; }
 
   if(dir == "")  dir = "/";
 
   //   If only one selection match ...
 
   if(sizeof(files) == 1) 
        return remove_file(dir + files[0], flag);
 
   //   Otherwise loop through all the wildcard selections
 
   for(loop=0; loop<sizeof(files); loop++) 
        remove_file(dir + files[loop], flag);
 
return 1; }
 
//  This function removes individual files, and directories if
//  the flag passed returns a true value.
 
protected int remove_file(string file, int flag) {
   int try;
 
   //   Check callers permissions on specific file/dir removal
 
   if((int)master()->valid_write(file, previous_object(), "rm") == 0) {
   write("Rm: " + file + " : Permission denied.\n");
   return 1; }
 
   if(directory_exists(file)) {

        //  If no recursive directory deletion ...

        if(!flag) {
        write("Rm: " + file + " is a directory.\n");
        return 1; }

        seteuid(ROOT_UID);                      // Quickly set us to root
        
        try = CLEAN_D->clean_dir(file, 1);

        seteuid(geteuid(previous_object()));    // And set us back
 
        if(!try || !rmdir(file)) {
        write("Rm: " + file + "/ failed.\n");
        return 1; }
 
        write("Rm: " + file + " recursively removed.\n");
 
   return 1; }
 
   if (file_lock(file, F_LOCK))  {
       write(rm(file) ? "Rm: " + file + " removed.\n" :
                        "Rm: " + file + " remove failed.\n");
       file_lock(file, F_UNLOCK);
   } else
       write("Rm: File \"" + file + "\" busy; remove failed.\n");
 
return 1; }
 
string help() {
 
   return( SYNTAX + "\n" +
        "This command will erase any files with the specified file pattern\n"+
        "and the use of '*' as a wildcard is permitted. If the -r flag is\n" +
        "specified, then any subdirectories flagged will be recursively\n" +
        "deleted, otherwise subdirectories are ignored.  This command will\n" +
        "fail if you do not have the proper permission privileges to remove\n"+
        "the specified file pattern. Multiple file deletion is also possible\n"+
        "by separating the requests with spaces (ie: rm a1 b1).\n");
 
}
 
