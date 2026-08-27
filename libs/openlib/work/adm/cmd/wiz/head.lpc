/*  -*- LPC -*-  */
// head.c:  Tim McIntosh (astasia@iastate.edu)

#include <command.h>

int
main(string file)
{
  if(!file)
    return notify_fail("usage: head <file>\n");

  file = RESOLVE_PATH(file);

  if (!cat(file, 1, 20))
    return notify_fail("head: file does not exists or isn't readable.\n");

  return 1;
}
