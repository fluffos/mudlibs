// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit CMD;

private void main(string* arg) {
  if (mkdir(arg[0]))
     outf("Ok.\n");
  else
     //outf("Failed to make directory: %s\n", arg[0]);
     outf("建立目录 %s 失败。\n", arg[0]);
}
