// rmdir.c:  Remove directory;  Tim McIntosh (astasia@iastate.edu)

#include <command.h>

#define USAGE "rmdir <dir-name>"

int
main(string dir)
{
  if(!dir)
    return notify_fail("usage: "+ USAGE +"\n");

  dir = RESOLVE_PATH(dir);

  if(file_size(dir) != -2)
    return notify_fail("rmdir: non-existent or not a directory.\n");

  if(!rmdir(dir))
    return notify_fail("rmdir: directory not empty or other failure.\n");

  return 1;
}

