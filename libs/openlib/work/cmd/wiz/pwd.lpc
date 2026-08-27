/*  -*- LPC -*-  */
// pwd.c:  Print working directory;  Tim McIntosh (astasia@iastate.edu)

#include <command.h>

int
main(string path)
{
  if(path)
    write(RESOLVE_PATH(path) +"\n");
  else
    write(this_player()->query_cwd() +"\n");
  return 1;
}
