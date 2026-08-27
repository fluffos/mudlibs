/*  -*- LPC -*-  */
// tail.c:  Tim McIntosh (astasia@iastate.edu)
//
// 04.13.96  Tim:  fixed to prevent tail'ing directories and typo in error msg
// 10.15.96  Tim:  changed due to the loss of the tail() efun

#include <command.h>

int
main(string file)
{
  int i;

  if( !file )
    return notify_fail("usage: tail <file>\n");

  file = RESOLVE_PATH(file);

  if ( !file_exists(file) )
    return notify_fail("tail: file does not exist.\n");
  else
    cat(file, ((i = file_length(file) - 19) > 0 ? i : 1), 20);

  return 1;
}
