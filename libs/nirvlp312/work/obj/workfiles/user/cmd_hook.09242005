/*
// cmd_hook.c
//
// This file catches any call to a daemonized command, and calls the
// daemon.
// Added by Shadowhawk in the tradition of TMI.
// eval cost dropped some by Verte,
// added multi-directory support [/bin/ is getting way too big]
*/

int
cmd_hook(string str) {
  string command, arg, cmd_ob_file;
  int   level;

  if (!str || str == "")
    return 0;
 /* dot dot bug */
  if(strlen(str) >= 2 && (str[0..1] == ".."))
    return 0;
  /* end dot dot bug */
  if (sscanf(str, "%s %s", command, arg) != 2)
    command = str;

    level = (int)this_player()->query_level();

    if(level >= 21)
    {
      cmd_ob_file = "/bin/wiz/_" + command;
      if(file_size(cmd_ob_file + ".c") > 0)
        return (int)call_other(cmd_ob_file, "cmd_" + command, arg);
    }
    if(level >= 1000)
    {
      cmd_ob_file = "/closed/bin/_" + command;
      if(file_size(cmd_ob_file + ".c") > 0)
        return (int)call_other(cmd_ob_file, "cmd_" + command, arg);
    }   
  
    cmd_ob_file = "/bin/play/_" + command;
    if (file_size(cmd_ob_file + ".c") > 0)
      return (int)call_other(cmd_ob_file, "cmd_" + command, arg);

    cmd_ob_file = "/bin/soul/_" + command;

    if (file_size(cmd_ob_file + ".c") > 0)
      return (int)call_other(cmd_ob_file, "cmd_" + command, arg);

    else
      return 0;
}
