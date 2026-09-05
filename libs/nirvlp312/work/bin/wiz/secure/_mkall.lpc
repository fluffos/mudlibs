/*
 *      File:                   /wiz/bin/secure/_mkall.c
 *      Function:               MKALL command
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2006 Earwax (David Halek)
 *                                      All Rights Reserved.
 *      Source:                 08/01/06
 *      Notes:                  See wizhelp files for 'mkall' 'paths'
 *      Change History:
 */

#include "/sys/security.h"
#include "/sys/logs.h"
#include "/sys/files.h"

/* Prototype declarations */


/* 
 * Function name:  cmd_mkall
 * Description:    Function called by command hook.
 * Arguments:      string arg - what the user typed in
 * Returns:        status - 0 is failure, 1 success
 */

nomask status cmd_mkall(string arg) 
{
  mixed *files;
  string what_to_log, temp;
  int i, siz, success;

  if ((string)this_player()->query_level() < CREATE) return 0;
  
  
  if(!arg)
  {
   arg = (string)this_player()->query_pwd();
  }

  arg = normalize_path(arg);
  
  i = file_size(arg);
  
  /* Single file to be updated */
  if (i > -1) 
  {
    command(sprintf("mk %s", arg), this_player());
    return 1;
  }
  else /* It's a pattern or path */ 
  {  
    siz = sizeof(files = get_dir(arg, GETDIR_PATH|GETDIR_SIZES));
    
    /* No files found: invalid path or insufficient privileges */
    if (!siz)
    {
      printf("MKALL: Invalid path or insufficient privileges: %s\n", arg);
    }
    else
    {
      printf("MKALL: Remaking: %s\n", arg);
      printf("<%-78'-'s>\n", "");
      for (i = 0; i < siz; i += 2)
      {
        temp = sprintf("/%s", files[i]);
        if (files[i+1] < 1) continue;
        command(sprintf("mk %s", temp), this_player());
        printf("<%-78'-'s>", "");
      }
    }
  }
        
  return 1;
}
