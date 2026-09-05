/*
 *      File:                   cd.c
 *      Function:               Change present working directory
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2006 Earwax (David Halek)
 *                                      All Rights Reserved.
 *      Source:                 07/24/06
 *      Notes:                  
 *      Change History:
 */

#include <security.h>

/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */

nomask status cmd_cd(string arg)
{
  int level;
  
  if (!this_player())
  {
    return 0;
  }
  
  level = (int)this_player()->query_level();
  
  if (level < CREATE) 
  {
    write("CD: You cannot change directories.\n");
    return 1;
  }
  
  arg = (arg && arg != "" ? normalize_path(arg, this_player()) : sprintf("/players/%s/", 
    (string)this_player()->query_real_name()));
    
  if (file_size(arg) != -2)
  {
    printf("CD: Invalid path or insufficient read privileges: %s\n", arg);
    return 1;
  }
  
  if (level < ELDER && (arg == "/" || arg == "/players" || arg == "/players/"))
  {
    printf("CD: CD to '/' and '/players' not allowed: %s\n", arg);
    return 1;
  }
  
  if (arg[<1] != '/')
    arg = sprintf("%s/",arg);
    
  this_player()->set_pwd(arg);
  printf("CD: %s\n", arg);
  return 1;
}
