// Work began on this file by Darkone on 2/20/93
#include <std.h>
inherit DAEMON;

int cmd_dirupdate(string str) {
  string file, tmp, *dir;
  object ob;
  int i;

  if(!str) {
    notify_fail("dirupdate <directory>\n");
    return 0;
  }
  seteuid("Root");
  file = resolv_path((string)this_player()->get_path(), str);
  if(file_size(file) != -2) {
    notify_fail(file + " is not a directory.\n");
    return 0;
  }
  dir = get_dir(file + "/");
  for(i = 0; i < sizeof(dir); i++) {
     ob = find_object(file +"/"+ dir[i]);
     if(ob == this_object()) continue;
     if(ob)
       destruct(ob);
     catch(call_other(file+"/"+dir[i], "???"));
     ob=find_object(file+"/"+dir[i]);
     if (!ob) write("Error in updating:"+file+"/"+dir[i]);
   }
   write("Update done.\n");
   return 1;
}

int help()
{
  write( @EndText
Syntax: dirupdate <directory>
Effect: updates all objects in <directory>
See also: update, dir
EndText
  );
  return 1;
}
