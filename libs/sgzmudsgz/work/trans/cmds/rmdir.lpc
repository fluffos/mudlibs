// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit CMD;

private void main(mixed *arg) {
  string dir;
  foreach(dir in arg[0])
    {
      if (rmdir(dir))
        //outf("Removed directory: %s.\n", dir);
        outf("删除目录 %s 成功。\n", dir);
      else
        outf(//"Failed to remove directory: %s.\n"
             "删除目录 %s 失败。\n", dir);
    }
 
}
