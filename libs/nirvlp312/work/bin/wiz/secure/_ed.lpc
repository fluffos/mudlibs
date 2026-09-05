/*
 *      File:                   /bin/wiz/secure/_ed.c
 *      Function:               Ed command
 *      Author(s):              Earwax@Nirvana
 *      Copyright:              Copyright (c) 2006 Earwax (David Halek)
 *                                      All Rights Reserved.
 *      Source:                 08/01/06
 *      Notes:                  
 *      Change History:
 */

#include "/sys/security.h"

nomask status cmd_ed(string arg)
{
  string arg1, arg2;
  status valid_write;

  if ((int)this_player()->query_level() < CREATE)
    return 0;

  if (in_editor(this_player()))
  {
    write("You can only 'ed' one file at a time.\n");
    return 1;
  }

  arg = file_arg_check(arg);

  if (!arg)
    ;
  else 
    arg = normalize_path(arg);

/*
  if (arg) arg = arg[1..];
*/

  seteuid(geteuid());
  valid_write = (string)this_player()->valid_write(arg) == arg;

  if (valid_write)
    reserve_ed_privileges(this_player(), arg);
  else
    printf("ED: [Read-Only : use 'q' or 'Q' to exit] opening %s ...\n", arg);

  if (arg)this_player()->remote_ed(arg); else this_player()->remote_ed();
  file_arg_check(0);
  return 1;
}
