/*
 *      File:                   /wiz/bin/_cat.c
 *      Function:               Cat command
 *      Author(s):              
 *      Copyright:              Copyright (c) 
 *                                      All Rights Reserved.
 *      Source:                 
 *      Notes:                  
 *      Change History:
 */

#include <ansi.h>
#include <security.h>

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */

int cmd_cat(string path)
{
  if((int)this_player()->query_level() < EXPLORE)
    return 0;
  if(!path)
    notify_fail("Usage: 'cat <file>'\n");
  else if (file_size((path = resolve_path(path))) > 0)
  {
    cat(path);
    return 1;
  }
  else
    notify_fail("File does not exist or unreadable: "+path+"\n");
  
  return 0;
}
