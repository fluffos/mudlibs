// Work began on this file by Darkone on 2/20/93
#include <std.h>
#include <security.h>
inherit DAEMON;

int cmd_dirupdate(string str) {
  string file, tmp, *dir;
  object ob;
  int i;

  if(!str) {
    notify_fail("dirupdate <directory>\n");
    return 0;
  }
  file = resolv_path((string)this_player()->get_path(), str);
  if(file_size(file) != -2) {
    notify_fail(file + " is not a directory.\n");
    return 0;
  }
  dir = get_dir(file + "/");
  seteuid(UID_FORCE);
  for(i = 0; i < sizeof(dir); i++) {
    catch(this_player()->force_me("update "+file+"/"+dir[i]));
   }
   seteuid(getuid());
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
