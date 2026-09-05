/*
 *      File:                   /wiz/bin/secure/_rm.c
 *      Function:               RM command
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2006 Earwax (David Halek)
 *                                      All Rights Reserved.
 *      Source:                 08/01/06
 *      Notes:                  See wizhelp files for 'rm' 'paths'
 *      Change History:
 */

#include "/sys/security.h"
#include "/sys/logs.h"
#include "/sys/files.h"

/* Prototype declarations */


/* 
 * Function name:  cmd_rm
 * Description:    Function called by command hook.
 * Arguments:      string arg - what the user typed in
 * Returns:        status - 0 is failure, 1 success
 */

nomask status cmd_rm(string arg) 
{
  mixed *files;
  string what_to_log, temp;
  int i, siz, success;

  if ((string)this_player()->query_level() < CREATE) return 0;
  
  if (arg) arg = (string)file_arg_check(arg);  
  
  if(!arg)
  {
    notify_fail("Usage: 'rm <file>'\nSee 'man rm' and 'man paths' for more info.\n");
    file_arg_check("");
    return 0;
  }

  seteuid(geteuid());

  arg = normalize_path(arg);
  
  i = file_size(arg);
  
  /* Single file to be deleted */
  if (i > -1) 
  {
    printf("RM: Deleting %s ... ", arg);
    
    if (!rm(arg)) /* It failed */
    {
      write("Failed.\n");
    }
    else
    {
      write("Deleted.\n");
      what_to_log = sprintf("%s: %-11s (RM) %s\n", ctime()
      , (string)this_player()->query_real_name(), arg);
      log_file(MODIFY, what_to_log);
      log_file(FILE_MOVE, what_to_log);
    }
  }
  else /* It's a pattern or path */ 
  {  
    siz = sizeof(files = get_dir(arg, GETDIR_PATH|GETDIR_SIZES));
    
    /* No files found: invalid path or insufficient privileges */
    if (!siz)
    {
      printf("RM: Invalid path or insufficient privileges: %s\n", arg);
    }
    else
    {
      printf("RM: Deleting: %s\n", arg);
      what_to_log = sprintf("%s: %-11s (RM) %s\n", ctime()
      , (string)this_player()->query_real_name(), arg);
      log_file(MODIFY, what_to_log);
      log_file(FILE_MOVE, what_to_log);
      printf("<%-78'-'s>", "");
      success = 0;
      
      for (i = 0; i < siz; i +=2 )
      {
        if (files[i+1] >= 0)
        {
          temp = (string)files[i];
          printf("\n--> %s ... ", temp);
          
          if (rm(temp))
          {
            write("Deleted.");
            success++;
            what_to_log = sprintf("(RM) --> %s\n", temp);
            log_file(MODIFY, what_to_log);
            log_file(FILE_MOVE, what_to_log);
          }
          else
          {
            write("Failed.");
          }
        }
      }
  
      printf("<%-78'-'s>", "");
      printf("RM: Successfully deleted %d files.\n", success);
    }
  }
        
  file_arg_check(0);
  return 1;
}
