/*
// This file is part of the TMI Mudlib distribution.
// Please include this header if you use this code.
// Adapted by Buddha(1-18-91) from unknown source.
// Added check for existance of destination file. Plura 930120
*/

#include <std.h>
inherit DAEMON;

int cmd_mv(string str);
int help();


int
cmd_mv (string str) {
   string t1, t2, *tmp;
   string *dir, src_str;
   int i;

   seteuid(geteuid(previous_object())); /* set it to the caller's perms */
    if(this_player()->query_forced()) {
        write("Someone tried forcing you to mv "+str+"\n");
        return 1;
    }
   if(!str||sscanf(str,"%s %s",t1,t2)!=2) {
      /* We should add checks for flags here. */
      return help();  
   } else {
#if 0
      if(file_size(t2=resolv_path((string)this_player()->get_path(),t2)) > 0)
         {
            notify_fail("mv: "+t2+" already exists.\n");
            return 0;
         }
#endif
      t2=resolv_path((string)this_player()->get_path(),t2);
      if(file_size(t2) == -2 && sizeof(dir = get_dir(resolv_path(this_player()->
								 get_path(), 
								 t1))) >= 1) {
	i = sizeof(dir);
	tmp = explode(t1, "/");
	if(sizeof(tmp) > 1)
	  src_str = replace_string(t1, tmp[sizeof(tmp) - 1], "");
	else
	  src_str = "";
	while(i--) {
	  if(file_exists(t2+"/"+dir[i]) && !rm(t2+"/"+dir[i])) {
	    write(t2+"/"+dir[i]+": Already exists.");
	    continue;
	  }
	  if(file_size(resolv_path(this_player()->get_path(), 
		       src_str + dir[i])) == -2) {
	    write(t2+"/"+dir[i]+": Directory.");
	    continue;
	  }
	  if(!rename(resolv_path(this_player()->get_path(), src_str + dir[i]),
	 	 t2))
	    write(t2+"/"+dir[i]+": Move successful.");
	  else
	    write(t2+"/"+dir[i]+": Move failed.");
	}
	return 1;
      }
      rename(t1=resolv_path(this_player()->get_path(),t1),t2);
      if(file_size(t2) == -2) {
         tmp = explode(t1, "/");
         t2 += "/" + tmp[sizeof(tmp)-1];
        }
      write(
         ((file_size(t1)<0)&&(file_size(t2)!=-1)) ? t1+" -> "+t2+"\n"
         :"mv failed.\n");
   }
   return 1;
}

int help() {
   write(
      "Syntax:\nmv <file1> <file2|directory>\n" +
      "Renames a file or moves it into the directory specified.\n" +
      "It wont overwrite an existing file.\n");
   return 1;
}

/* EOF */
