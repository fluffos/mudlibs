/*
 *      File:                   /wiz/bin/_rm.c
 *      Function:               Cp command
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2005 Earwax (David Halek)
 *                                      All Rights Reserved.
 *      Source:                 11/06/05
 *      Notes:                  See wizhelp files for 'rm' 'paths' 
 *      Change History:
 */

#include <ansi.h>
#include <security.h>
/* This obviously will have to be switched. */
#define WILDCARDS "/obj/daemons/wildcards"

/* 
 * Function name:  cmd_rm
 * Description:    Function called by command hook.
 * Arguments:      string arg - what the user typed in
 * Returns:        status - 0 is failure, 1 success
 */

status cmd_rm(string path) 
{
  int i, siz, q;
  string *files;
  
log_file("WSOUL", ctime()+": /closed/wiz/unixcmds/_rm.c called by "
+(string)this_player()->query_real_name()+" by "+file_name(previous_object())+"\n");
  if(!path)
  {
    notify_fail("Usage: 'rm <filemask>'\n");
    return 0;
  }

  path = resolve_path(path);
  
  /* It's a single file. */
  if (file_size(path) > -1)
  {

    if (rm(path))
      write("RM: "+path+"\n");
    else
      write("Error encountered deleting: "+path+"\n");
      
    return 1;
  }
  
  siz = sizeof(files = (string *)WILDCARDS->get_files(path));

  if (!siz)
  {
    write("Aborting, no files to rm: "+path+"\n");
    return 1;
  }
  
  write("RM: "+path);
  write("\n----------------------------------------------------------------------\n");
  q = 0;
  
  for (i = 0; i < siz; i++)
  {
    if (!text_contains(files[i], "..") && files[i][strlen(files[i])-1] != '.')
    {
      if (rm(files[i]))
      {
        write("RM: "+files[i]+"\n");
        q++;
      }
      else
        write("Error encountered in RM: "+files[i]+"\n");
    }
  }
  write("----------------------------------------------------------------------\n");
  write(q+" files affected.\n");
  return 1;
}
