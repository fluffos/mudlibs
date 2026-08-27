/*  -*- LPC -*-  */
// cat.c:  Tim McIntosh (astasia@iastate.edu)

#include <command.h>

int
main(string file)
{
  if(!file)
    return notify_fail("usage: cat <file>\n");

  file = RESOLVE_PATH(file);

  switch(file_size(file)) {
  case -1 :
    return notify_fail("cat: file does not exist.\n");
  case -2 :
    return notify_fail("cat: is a directory.\n");
  default :
    cat(file);
  }

  return 1;
}
