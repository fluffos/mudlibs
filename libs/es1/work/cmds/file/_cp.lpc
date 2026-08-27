//#pragma save_binary
//      File    :  /cmds/file/_cp.c
//      Creator :  Watcher@TMI  (3/15/93)
//      Updated :  Watcher@TMI  (4/9/93)  to allow silent cp mode and
//                  use get_dir() instead of the wildcard daemon so
//                  dotfiles may be properly processed.
//                 Robocoder@TMI (6/23/93) to use file lock daemon.
//
//      This is the standard wizard file cp command. It allows
//      wildcards, recursive directory tree cp's, and interactive
//      flag requests (blocking the default overwrite option).

#include <mudlib.h>
#include <daemons.h>
#include <flock.h>

inherit DAEMON ;

protected string get_path(string str, int dir_flag);
protected string get_file(string str);
protected int copy_file(string from, string to);
protected int cp_file(string from, string to, int rflag, int iflag, int silent);

#define SYNTAX  "Syntax: cp [-rsfi] [source] [destination]\n"

int cmd_cp(string str) {
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

   //   Check for use of "." for present dir copying

   if(to == ".")  to = (string)this_player()->query("cwd");

   //   Check to see if the dest path is a directory.

   if(to[strlen(to)-1] == '/')  dir_flag = 1;

   //   Check for a directory cp request.

   if(from[strlen(from)-1] == '/')  from += "*";

   //   Resolve paths of source and destination requests
   from = resolv_path("cwd", from);
   to   = resolv_path("cwd", to);
   //   Isolate source and destination directories

   fpath = get_path(from, 0);
   tpath = get_path(to ,dir_flag);

   //   Check for existence of source and dest directories

   if(!directory_exists(fpath)) {
   write("Cp: No such directory : " + fpath + "\n");
   return 1; }

   if(!directory_exists(tpath)) {
   write("Cp: No such directory : " + tpath + "\n");
   return 1; }

   //   Check user's permissions in source and dest directories

   if((int)master()->valid_read(fpath, previous_object(), "cp") == 0) {
   printf("Cp: Access denied in %s.\n",
          (fpath == "" ? "root directory" : fpath));
   return 1; }

   if((int)master()->valid_write(tpath, previous_object(), "cp") == 0) {
   printf("Cp: Access denied in %s.\n",
          (tpath == "" ? "root directory" : tpath));
   return 1; }

   //   Process request for wildcard entry

   files = get_dir(from);
   files -= ({ "." });  files -= ({ ".." });

   //   Check to see if any files match the pattern

   if(!files || !sizeof(files)) {
   write("Cp: No such pattern : " + from + "\n");
   return 1; }

   //   If multiple files, treat 'to' string as destination path

   if(sizeof(files) > 1) {

   if(tpath != "")   tpath = to + "/";

   if(!directory_exists(tpath)) {
   write("Cp: No such directory : " + tpath + "\n");
   return 1; }

   //  Check to see if source and dest paths are equal.

   if(tpath == fpath) {
   write("Cp: Requested destination is the same as source files.\n");
   return 1; }

   }

   //  Protect against silly users trying to recursively cp files
   //  farther down the same directory tree.  This would cause the
   //  cp command to try to copy files recursively until the disk
   //  space is filled. :(

   if(sscanf(tpath, fpath + "%s", tmp1) == 1 && tmp1 != "" && rflag) {
   write("Cp: Illegal to attempt recursive cp to same directory tree.\n");
   return 1; }

   //  If only one file selected ...

   if(sizeof(files) == 1) {

        if(!file_exists(fpath + files[0]) &&
           !directory_exists(fpath + files[0])) {
        write("Cp: " + fpath + files[0] + " does not exist.\n");
        return 1; }

        if(directory_exists(to))
          to += (tpath == "" ? "" : "/") + get_file(files[0]);

        cp_file(fpath + files[0], to, rflag, iflag, 0);

        this_player()->set("cwf", to);

   return 1; }

   //  Otherwise loop through the multiple file choices

   for(loop=0; loop<sizeof(files); loop++)
     cp_file(fpath + files[loop], tpath + files[loop], rflag, iflag, silent);

   if(silent)  write("Cp: File copy completed.\n");

return 1; }

protected int cp_file(string from, string to, int rflag, int iflag, int silent) {
   mixed *tmp;
   int loop;

   //  Block if source and destination are equivalent

   if(from == to) {
   write("Cp: Requested destination is the same as source file.\n");
   return 1; }

  //   Check to see if source file/dir does exist
  //   Shouldn't need this ... but just in case. :)

   if(file_size(from) == -1) {
   write("Cp: " + from + " does not exist.\n");
   return 1; }

   //  If source file request is a directory

   if(directory_exists(from)) {

        from += "/";  to += "/";

        if(rflag) {
        tmp = get_dir(from);

        if(!directory_exists(to))
           mkdir( to[0..strlen(to)-2] );        // Strip tailing '/'

        for(loop=0; loop<sizeof(tmp); loop++)
           cp_file(from + tmp[loop], to + tmp[loop], rflag, iflag, silent);
        }

        else {
        if(!silent)  write("Cp: " + from + " is a directory.\n");
        return 1; }

        rmdir( from[0..strlen(from)-2] );

        if(!silent)
        write("Cp: " + from + " directory copied to " + to + "\n");
        return 1; }

   //  If to file already exists and the iflag is set ... block copy

   if(iflag && file_exists(to)) {
   if(!silent) write("Cp: " + to + " already exists.\n");
   return 1; }

   //  Attempt to copy the file to new location

   if(!copy_file(from, to))  {
   if(!silent)  write("Cp: Could not copy " + from + " to " + to + "\n");
   }

   else if(!silent)  write("Cp: " + from + " copied to " + to + "\n");

return 1; }

//  This function does the actual file copying

protected int copy_file(string from, string to) {
   string str;
   int size;

    file_lock(to,F_UNLOCK);
#if 0
    // May want to restore this line if you plan to daemonize this command
    // for massive cpu sucking recursive file copying
    if (file_lock(from, F_LOCK)) {
#else
    {
#endif
        if (file_lock(to, F_LOCK)) {
            size = file_size(from);

            str = read_file(from);

            if (!str || str == "") {
                file_lock(to, F_UNLOCK);
#if 0
                file_lock(from, F_UNLOCK);
#endif
                return 0;
            }

            if (file_exists(to))  rm(to);

            if (!write_file(to, str) || !file_exists(to)
                  || file_size(to) != size) {
                if(file_exists(to))  rm(to);
                file_lock(to, F_UNLOCK);
#if 0
                file_lock(from, F_UNLOCK);
#endif
                return 0;
            }
            file_lock(to, F_UNLOCK);
#if 0
            file_lock(from, F_UNLOCK);
#endif
            return 1;
        }
        write("Cp: File \"" + to + "\" busy.\n");
#if 0
        file_lock(from, F_UNLOCK);
#endif
        return 0;
    }
    write("Cp: File \"" + from + "\" busy.\n");
    return 0;
}


//  This function returns the file path of a passed file.

protected string get_path(string str, int dir_flag) {
   mixed *tmp;
   string path;

   if(str == "/")       return "";
   else if(dir_flag)    return str;
   else if(directory_exists(str)) return str + "/";

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

   write(SYNTAX + "\n" +
    "This command copys the inputed source file to the destination\n" +
    "location. The command allows the use of wildcards to copy many\n" +
    "files, matching the desired pattern, at the same time. The command\n" +
    "also follows the r,f, and i flags. If the r flag is used, the cp\n" +
    "command will copy the entire directory tree to the new location.\n" +
    "The command defaults with overwriting files if they already exist\n" +
    "at the new location. Overwriting can be avoided by using the i flag.\n" +
    "The f flag forces overwriting and overrides the i flag. To move\n" +
    "files to your present directory, simply use \".\" as the destination.\n" +
    "The s flag can be used when you want to silent copy multiple files.\n");

return 1; }
