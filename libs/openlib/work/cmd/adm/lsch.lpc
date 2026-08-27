#include <command.h>
#include <net/daemons.h>

int
main()
{
  string text;
  string* list;

  text = sprintf("%-15.15s     %-20.20s    %s\n", "Channel", "Mud", "State");
  foreach(string key, mixed* arr in INTERMUD_D->GetChannelList()) {
    text += sprintf("%-15.15s     %-20.20s    %d\n", key, arr[0], arr[1]);
  }

  list = explode(text, "\n");
  this_player()->more(list);

  return 1;
}
