/*  -*- LPC -*-  */
#include <cmdline.h>
#include <daemons.h>

int
main(string *argv, string *argv2)
{
  int verbose;

  if(!sizeof(argv2))
    return notify_fail("usage: rm [-v] <file1 ... >\n");

  verbose = flag("v");

  foreach(string file in argv2) {
    file = RESOLVE_PATH(file);
    
    switch(file_size(file)) {
    case -1:
      if( query_notify_fail() )
	write(query_notify_fail());
      else
	printf("rm: %s does not exist.\n", file);
      break;
    case -2:
      printf("rm: %s is a directory.\n", file);
      break;
    default:
      if(verbose) write(file + "\n");
      if( !rm(file) && query_notify_fail() )
        write(query_notify_fail());
    }
  }

  return 1;
}
