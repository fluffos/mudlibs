/* 07/17/07 Earwax */

#include <ansi.h>

int cmd_report(string arg) 
{
  string str;

  write("You report: \n");
  say((string)this_player()->query_name()+" reports: \n");
  this_player()->print_monitor(environment(this_player()));
  return 1;
}
/*
  tell_room(environment(this_player()), NORM+"\n");
  str = (string)this_player()->query_monitor_string();
  if (str)
  {
    str = (string)this_player()->replace_read(str);
    tell_room(environment(this_player()), str);
  }
  else
  {
    tell_room(environment(this_player()), "No monitor set.\n");
  }

*/
