#include "/include/mudlib.h"

status spew(string arg) {
  string buf;
  string* lines;
  int loop, i;

  if (!arg) {
    notify_fail("Usage: spew <filename>\n");
    return 0;
  }
  arg = __MASTER_OBJECT__->make_path_absolute(arg);
  if (file_size(arg) <= 0) {
    notify_fail("The file " + arg + " does not exist.\n");
    return 0;
  }
  buf = read_file(arg);
  if (!buf) {
    notify_fail("Error reading file " + arg + ".\n");
    return 0;
  }
  lines = explode(buf, "\n");
  i = sizeof(lines);
  for (loop=0; loop<i; loop++)
    write(lines[loop] + "\n");
  return 1;
}

