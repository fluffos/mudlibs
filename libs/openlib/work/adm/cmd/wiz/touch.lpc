/*  -*- LPC -*-  */
// touch.c:  Created by Tim 8/26/96
// a very limited version...creates zero length files
#include <command.h>

int
main(string file)
{
  if( !file )
    return notify_fail("usage: touch <file>\n");
  
  file = RESOLVE_PATH(file);
  
  if( write_file(file, "") )
    message("system", "Ok.\n", this_player());
  else
    return notify_fail("Failed.\n");

  return 1;
}
