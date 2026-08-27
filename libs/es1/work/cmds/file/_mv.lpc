//#pragma save_binary
// File     : /cmds/file/_mv.c
// 93-03-15 : Created by Watcher@TMI-2
// 93-04-09 : Updated by Watcher@TMI-2 to allow silent mv mode and use
//            get_dir() instead of the wildcard daemon so dotfiles may
//            be properly processed.
// 93-06-23 : Changed by Robocoder@TMI-2 to use file lock daemon
// 93-07-30 : Changed by Grendel@TMI-2 so the valid_write sends "rm"
//            as the funcition for the "from" - this is for t the benefit of
//            the quota deamon
//
//      This is the standard wizard file mv command. It allows
//      wildcards, recursive directory tree mv's, and interactive
//      flag requests (blocking the default overwrite option).

#include <mudlib.h>
#include <daemons.h>
#include <flock.h>

inherit DAEMON ;

protected string get_path(string str, int dir_flag);
protected string get_file(string str);
protected int mv_file(string from, string to, int rflag, int iflag, int silent);

#define SYNTAX  "Syntax: mv [-rsfi] [source] [destination]\n"

int cmd_mv(string str) {
   mixed *tmp, *files;
   string flags, tpath, fpath, from, to, tmp1, tmp2;
   int loop, rflag, iflag, silent, dir_flag;

   seteuid( getuid(this_object()) );

   notify_fail( SYNTAX );
   if(!str || str == "")  return 0;

   //  Check for user requested flags

   if(sscanf(str, "-%s %s", flags, str) == 2) {
        if(sscanf(" " + flags + " ", "%sr%s", tmp1, tmp2) == 2)  rflag = 1;
        if(sscanf(" " + flags + " ", "%si%s", tmp1, tmp2) == 2)  iflag = 1;
        if(sscanf(" " + flags + " ", "%sf%s", tmp1, tmp2) == 2)  iflag = 0;
        if(sscanf(" " + flags + " ", "%ss%s", tmp1, tmp2) == 2)  silent = 1;
   }

   //  Parse into source and destination

   if(sscanf(str, "%s to %s", from, to) != 2 &&
      sscanf(str, "%s %s", from, to) !=2)         return 0;

   //   Check for use of "." for present dir moving.

   if(to == ".")  to = (string)this_player()->query("cwd");

   //   Check to see if dest str is a directory.

   if(to[strlen(to)-1] == '/')  dir_flag = 1;

   //   Resolve paths of source and destination requests

   from = resolv_path("cwd", from);
   to   = resolv_path("cwd", to);

   //   Check for a directory move request

   if(from[strlen(from)-1] == '/') {
       from += "*";
       rflag = 1;
   } else if (rflag && directory_exists(from)) {
       from += "/*";
   }

   //   Isolate source and destination directories

   fpath = get_path(from, 0);
   tpath = get_path(to, dir_flag);

   //   Check for existence of source and dest directories

   if(!directory_exists(fpath)) {
   write("Mv: No such directory : " + fpath + "\n");
   return 1; }

   if(!directory_exists(tpath)) {
   write("Mv: No such directory : " + tpath + "\n");
   return 1; }

   //   Check user's permissions in source and dest directories

   if((int)master()->valid_write(fpath, previous_object(), "rm") == 0) {
   printf("Mv: Access denied in %s.\n",
          (fpath == "" ? "root directory" : fpath));
   return 1; }

   if((int)master()->valid_write(tpath, previous_object(), "mv") == 0) {
   printf("Mv: Access denied in %s.\n",
          (tpath == "" ? "root directory" : tpath));
   return 1; }

    //  Check to see if it's a renaming operation

    if (!directory_exists(to) && !rflag && from != to &&
          sscanf(tpath, fpath + "%*s") != 1 &&
          ( (directory_exists(from) && !file_exists(to)) ||
            file_exists(from) ) ) {
        mv_file(from, to, 0, iflag, 0);
        return 1;
    }

   //   Process request for wildcard entry

   files = get_dir(from);
   files -= ({ "." });  files -= ({ ".." });

   //   Check to see if any files match the desired pattern

   if(!files || !sizeof(files)) {
   write("Mv: No such pattern : " + from + "\n");
   return 1; }

   //   If multiple files, treat 'to' string as destination path

   if(sizeof(files) > 1) {

   if(tpath != "")   tpath = to + "/";

   if(!directory_exists(tpath)) {
   write("Mv: No such directory : " + tpath + "\n");
   return 1; }

   //  Check to see if source and dest paths are equal.

   if(tpath == fpath) {
   write("Mv: Requested destination is the same as source files.\n");
   return 1; }

   }

   //  Protect against silly users trying to recursively mv files
   //  farther down the same directory tree.  This would cause the
   //  mv command to try to move files recursively until the disk
   //  space is filled. :(

   if(sscanf(tpath, fpath + "%s", tmp1) == 1 && tmp1 != "" && rflag) {
   write("Mv: Illegal to attempt recursive mv to same directory tree.\n");
   return 1; }

   //  If only one file selected ...

   if(sizeof(files) == 1) {

	if (directory_exists(from))
	  if (file_exists(to)) {
	    write("Mv: insufficient magic to move a directory into a file.\n");
	    return 1;
	  } else if (directory_exists(to)) {
	    if (sscanf(to, from +"%*s") == 1) {
		write("Mv: Illegal to mv deeper into directory tree.\n");
		return 1;
	    }
	    to += (tpath == "" ? "" : "/") + get_file(files[0]);
	    mv_file(from, to, 0, iflag, 0);
	    return 1;
	  }
        if(!file_exists(fpath + files[0]) &&
           !directory_exists(fpath + files[0])) {
        write("Mv: " + fpath + files[0] + " does not exist.\n");
        return 1; }

        if(directory_exists(to))
          to += (tpath == "" ? "" : "/") + get_file(files[0]);

        mv_file(fpath + files[0], to, rflag, iflag, 0);

        this_player()->set("cwf", to);

   return 1; }

   //  Otherwise loop through the multiple file choices

   for(loop=0; loop<sizeof(files); loop++)
     mv_file(fpath + files[loop], tpath + files[loop], rflag, iflag, silent);

   if(silent)  write("Mv: File move complete.\n");

return 1; }

protected int mv_file(string from, string to, int rflag, int iflag, int silent) {
   mixed *tmp;
   int loop;


   //  Block if source and destination are equivalent

   if(from == to) {
   write("Mv: Requested destination is the same as source file.\n");
   return 1; }

   //  If source file request is a directory

   if(directory_exists(from)) {

        from += "/";

        if(!directory_exists(to)) {
            rename(from[0..strlen(from)-2], to);
            if(!silent && rflag)
                write("Mv: " + from + " directory moved to " + to + "\n");
            return 1;
        }

        to += "/";

	// destination directory already exists...move contents over
        tmp = get_dir(from);

        // destination directory already exists

        for(loop=0; loop<sizeof(tmp); loop++)
           mv_file(from + tmp[loop], to + tmp[loop], rflag, iflag, silent);

        rmdir(from[0..strlen(from)-2]);

        if(!silent)
            write("Mv: " + from + " directory moved to " + to + "\n");
        return 1;
    }

   //  If to file already exists and the iflag is set ... block move

   if(iflag && file_exists(to)) {
   if(!silent)  write("Mv: " + to + " already exists.\n");
   return 1; }

   //  Attempt to move the file to new location
   if (!file_lock(from, F_LOCK)) {
      if (!silent)
         write("Mv: File \"" + from + "\" busy.\n");
      return 0;
   }
   if (!file_lock(to, F_LOCK)) {
      file_lock(from, F_UNLOCK);
      if (!silent)
         write("Mv: File \"" + to + "\" busy.\n");
      return 0;
   }

   rename(from, to);

   if(file_exists(from) || !file_exists(to)) {
     if(!silent) write("Mv: Could not move " + from + " to " + to + "\n");
   }

   else if(!silent) write("Mv: " + from + " moved to " + to + "\n");

    file_lock(to, F_UNLOCK);
    file_lock(from, F_UNLOCK);

return 1; }

//  This function returns the file path of a passed file.

protected string get_path(string str, int dir_flag) {
   mixed *tmp;
   string path;

   if(str == "/")       return "";
   else if(dir_flag)    return str;
   else if(directory_exists(str))  return str + "/";

   tmp = explode(str, "/");
   path = "/" + implode( tmp[0..sizeof(tmp)-2], "/") + "/";

   if(path == "//")  path = "";

return path; }

//  This function returns the filename without the whole file path

protected string get_file(string str) {
   mixed *tmp;

   tmp = explode(str, "/");

return tmp[sizeof(tmp)-1]; }

//  This is the commands help function

int help() {

   write(SYNTAX @ENDHELP

This command can be used for moving a file or directory to a new location.
By using wildcards, this command can move many files and directories,
matching the specified pattern, at the same time.  Also, this command can
used for renaming a file or directory, where source is the old name, and
destination is the desired new name.

The following flags are recognized:
  f  - force overwriting files if they already exist (default; overrides 'i')
  i  - don't overwrite files if they already exist (historically "interactive")
  r  - "recursively" move the entire directory tree to the new location
  s  - silent "mv"; notifies only when operation has been completed

To move files to your present directory, simply use "." as the destination.
ENDHELP
    );
    return 1;
}
