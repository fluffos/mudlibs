/*
 *      File:                   /wiz/bin/_dump.c
 *      Function:               Dump command
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) Earwax (David Halek)
 *                                      All Rights Reserved.
 *      Source:                 
 *      Notes:                  
 *      Change History:
 */

#include "/sys/temp.h"
#include <ansi.h>
#include <security.h>

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */

nomask int cmd_dump(string path)
{
  int i, pos, numlines;
  if((int)this_player()->query_level() < EXPLORE)
    return 0;
  if(!path)
    notify_fail("Usage: 'dump <file>'\n");
  else if (file_size((path = normalize_path(path))) > 0)
  {
    pos = 1;
    numlines = 0;

    do
    {
      i = cat(path, pos, 49);
      numlines += i;
      pos += 49;
    }
    while(i);

    printf("DUMP: %d lines displayed of file %s\n", numlines, path);
    return 1;
  }

  notify_fail(sprintf("DUMP: File does not exist or unreadable: %s\n", path));
  return 0;
}
