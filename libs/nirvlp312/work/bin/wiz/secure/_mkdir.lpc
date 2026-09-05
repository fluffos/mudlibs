/* 08/01/06 Earwax */

#include "/sys/security.h"
#include "/sys/logs.h"

nomask int cmd_mkdir(string str)
{
  string what_to_log;

 if((int)this_player()->query_level() < CREATE)
  return 0;

  str = file_arg_check(str);

 if(!str)
 {
  write("Usage: 'mkdir <directory>'\n");
  return 1;
 }

  str = normalize_path(str);

  printf("MKDIR: %s ... ", str);

  if (mkdir(str))
  {
    write("Done.\n");
    what_to_log = sprintf("%s: %-11s (MKDIR) %s\n", ctime()
      , (string)this_player()->query_real_name(), str);
    log_file(MODIFY, what_to_log);
    log_file(FILE_MOVE, what_to_log);
  }
  else write("Failed.\n");

  file_arg_check(0);
 return 1;
}

