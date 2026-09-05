/*
 *      File:                   /wiz/bin/secure/_mv.c
 *      Function:               MV command
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2006 Earwax (David Halek)
 *                                      All Rights Reserved.
 *      Source:                 08/01/06
 *      Notes:                  See wizhelp files for 'cp' 'mv' 'paths' 
 *      Change History:
 */

inherit "/players/earwax/wildcards";
 
#include "/sys/security.h"
#include "/sys/logs.h"

/* Prototype declarations */


/* 
 * Function name:  cmd_mv
 * Description:    Function called by command hook.
 * Arguments:      string arg - what the user typed in
 * Returns:        status - 0 is failure, 1 success
 */

nomask status cmd_mv(string arg) 
{
  string *source, *destination;
  string arg_source, arg_dest;
  string what_to_log;
  int i, siz, success;

  if ((int)this_player()->query_level() < CREATE) return 0;
  if (arg) arg = (string)file_arg_check(arg);  
  
  if(!arg)
  {
    notify_fail("Usage: 'mv <file> <dest>'\nSee 'man mv' and 'man paths' for more info.\n");
    file_arg_check("");
    return 0;
  }

  seteuid(geteuid());

  if (sscanf(arg, "%s %s", arg_source, arg_dest) != 2)
  {
    arg_source = arg;
    arg_dest = (string)this_player()->query_pwd();
  }

  arg_source = normalize_path(arg_source);
  arg_dest = normalize_path(arg_dest);
  
  /* 
   * Single file being renamed
   */
  if (file_size(arg_source) > -1)
  {
    printf("MV: %s to %s\n", arg_source, arg_dest);
    
    if (rename(arg_source, arg_dest))
    {
      printf("MV: Error encountered...file not renamed.\n");
      file_arg_check("");
      return 1;
    }

    /* File renamed */
    what_to_log = sprintf("%s: %-11s (MV) %s to %s\n", ctime()
    , (string)this_player()->query_real_name(), arg_source, arg_dest);
    log_file(MODIFY, what_to_log);
    log_file(FILE_MOVE, what_to_log);
    file_arg_check("");
    return 1;
  }
    
  /*
   * Multiple files being renamed
   */
  if (!get_files(arg_source))
  {
    printf("MV: No files found: %s\n", arg_source);
    file_arg_check("");
    return 0;
  }
  
  i = file_size(arg_dest);
  
  if (i == -1)
  {
    printf("MV: Invalid destination (does not exist): %s\n", arg_dest);
    file_arg_check("");
    return 1;
  }
  
  if (i > -1)
  {
    printf("MV: Invalid destination (not a directory): %s\n", arg_dest);
    file_arg_check("");
    return 1;
  }

  if (arg_dest[<1] != '/')
    arg_dest = sprintf("%s/", arg_dest);
  
  success = 0;
  siz = sizeof(all_info);
  printf("MV: %d files: %s to %s\n", siz, arg_source, arg_dest);
  what_to_log = sprintf("%s: %-11s (MV) %s to %s\n", ctime()
  , (string)this_player()->query_real_name(), arg_source, arg_dest);
  log_file(MODIFY, what_to_log);
  log_file(FILE_MOVE, what_to_log);

  printf("--------------------------------------------------------------------------------");
   
  for (i = 0; i < siz; i++)
  {
    printf("\n--> %s to %s%s ...", all_info[i][1], arg_dest, all_info[i][0]);
    
    if (rename(all_info[i][1], arg_dest))
      write("Failed.");
    else
    {
      success++;
      what_to_log = sprintf("--> (MV) %s to %s\n"
      , (string)this_player()->query_real_name(), all_info[i][1]
      , arg_dest, all_info[i][0]);
      log_file(MODIFY, what_to_log);
      log_file(FILE_MOVE, what_to_log);
      write("Success.");
    }
  }
  
  printf("--------------------------------------------------------------------------------\n");
  printf("MV: Successfully renamed %d of %d files.\n", success, siz);
  file_arg_check("");
  return 1;
}    
