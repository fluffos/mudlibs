/*
 *      File:                   /wiz/bin/_tail.c
 *      Function:               Tail command
 *      Author(s):              Nirvana
 *      Copyright:              Copyright (c) 2005 Nirvana
 *                                      All Rights Reserved.
 *      Source:                 11/06/05
 *      Notes:                  See 'wizhelp tail' 
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

int cmd_tail(string x)
{
 if (!x)
 {
   notify_fail("Usage: 'tail <file>'\n");
   return 0;
 }
 
 x = resolve_path(x);
 if (file_size(x) < 0)
 {
   notify_fail("File does not exist or unreadable: "+x+"\n");
   return 0;
 }
 
 if (tail(x))
   return 1;
   
 notify_fail("Usage: 'tail <file>'\n");
 return 0;
}
