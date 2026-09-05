/*
 *      File:                   /wiz/bin/_tail.c
 *      Function:               Tail command
 *      Author(s):              
 *      Copyright:              Copyright (c) 
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

nomask int cmd_tail(string path)
{
  if((int)this_player()->query_level() < EXPLORE)
    return 0;
  if(!path)
    notify_fail("Usage: 'tail <file>'\n");
  else if (file_size((path = normalize_path(path))) > 0)
  {
    tail(path);
    return 1;
  }

  notify_fail(sprintf("TAIL: File does not exist or unreadable: %s\n", path));
  return 0;
}
