// mkdir.c:  Make directory;  Tim McIntosh (astasia@iastate.edu)

#include <command.h>

#define USAGE "mkdir <dir-name>"

int
main(string dir)
{
  if(!dir)
    return notify_fail("usage: "+ USAGE +"\n");

  dir = RESOLVE_PATH(dir);

  if(file_size(dir) != -1)
    return notify_fail("mkdir: file/dir exists.\n");

  if(!mkdir(dir))
    return notify_fail("mkdir: failed to create directory.\n");

  return 1;
}

