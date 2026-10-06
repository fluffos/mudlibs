/*
*  Author and date unknown ??
*  help() added 1/27/92   Brian@TMI
*  revised for greater speed by Buddha (8/23/92)
*/

#include <config.h>
#include <mudlib.h>

inherit DAEMON ;

// process_choice() and file_completion() were lifted almost verbatim from
// Watcher's shell code by Ed Murphy (Guardian@TMI-2) on 16 Sep 93 and
// slapped into the _cd.c code, in response to a suggestion that it allow
// wildcards.
//
// Maybe a user property should turn this file-completion attempt on/off, like
// the shell originally had it.

//	The function does the directory searches in an attempt
//	to complete the requested command's file path.
 
protected mixed *process_choice(string str) {
   mixed *dir, *tmp, *hold;
   string file, where, patt, dump;
   int loop;
 
   //	Obtain user's present active directory
 
   file = resolv_path("cwd", str);
 
   //	Obtain the requested file's root path
 
   tmp = explode(file, "/");
   where = "/" + implode(tmp[0..(sizeof(tmp)-2)], "/") + "/";
 
   //	Form file search pattern
 
   if(sscanf(tmp[sizeof(tmp)-1],"%s\\*",patt) == 1) patt += "%s";
 
   //	Get requested directory contents
 
   dir = get_dir(where);
 
   //	Get all possible filenames that would match requested pattern
 
   for(hold = ({}),loop=0; loop<sizeof(dir); loop++)
   if(sscanf(dir[loop], patt, dump) == 1)
   hold += ({ (where + dir[loop]) });
 
return hold; }

//      This function allows file path completion of sorts.
//	If the last character in the file path is a *, then the
//	shell will try to complete the path as best it can.
 
protected int file_completion(string str) {
   mixed *tmp, *result;
   string command;
 
   //   If last char isn't a *, then ignore
 
   if(str[strlen(str)-1] != '*') return 0;
 
   //	Break command into its word subsets and process last word
 
   tmp = explode(str, " ");
   result = process_choice(tmp[sizeof(tmp)-1]);
 
   //	Indicate ability to complete the file path
 
   if(!result || !sizeof(result))
   write("Unable to complete designated filename [" + 
	 tmp[sizeof(tmp)-1] + "]\n");
   else if(sizeof(result) > 1)
   write("Multiple possible filename completions [" +
	 tmp[sizeof(tmp)-1] + "]\n");
 
   //	Otherwise complete and initiate the command
 
   else { 
   tmp[sizeof(tmp)-1] = result[0];
   command = implode(tmp, " ");
   this_player()->force_me(command);  }
 
return 1; }

int
cmd_cd(string str) {
   int size;
   string name, path, hdir;
 
   path = this_player()->query("cwd");
   name = geteuid(this_player());
   seteuid(getuid());
 
   if(!str) {
      str = user_path(name);
 
      hdir = (string)this_player()->query("home_dir");
      if(hdir)  str = hdir;

      if(str[strlen(str)-1] == '/')  str = str[0..strlen(str)-2];
      if(!str || !directory_exists(str))  str = "/doc";
      this_player()->set("cwd", str);
      printf("%s\n", str);
      return 1;
   }
// Guardian's hack to access the wildcard code stolen from shsh.c
   if(file_completion(str)) return 1;

   str = resolv_path(path, str);
   replace_string("//", "/", str);
   if ((int)master()->valid_read(str, this_player()) == 0) {
      notify_fail(sprintf("%s:  permission denied\n", str));
      return 0;
   }
   size = file_size(str);
   if (size > -1) {
      notify_fail(sprintf("%s:  not a directory\n", str));
      return 0;
   }
   if (size == -1) {
      notify_fail(sprintf("%s:  no such file or directory\n", str));
      return 0;
   }
   this_player()->set("cwd", str);
    printf("%s\n", str);
   return 1;
}

string help() {
   return("Command: cd\nSyntax: cd <directory>\n"+
      "This command changes your current directory to the\n"+
      "one you specify.  If directory begins with a / then\n"+
      "the command will look from the root, otherwise it\n"+
      "will look in the child directories of your current\n"+
      "directory.  .. will back up to the parent of your\n"+
      "current directory.  Thus cd ../obj will attempt to\n"+
      "move to the directory obj which is a child of your\n"+
      "current parent directory.\n"+
      "cd with no arguments will move you to your home dir-\n"+
      "ectory if you are a student, or the /doc directory if\n"+
      "not.\n");
}
