#include <daemons.h>
#include <std.h>
#include <socket.h>

inherit DAEMON;

int cmd_finger(string str) {
    object ob;
    string wer, wo;
    if(!str)
      this_player()->more(explode((string)FINGER_D->general_finger_display(),
        "\n"));
    else
      this_player()->more(explode((string)FINGER_D->user_finger_display(str),"\n"));
    return 1;
}

int help()  {
  write("reports some stats about players. \nUsage: `finger` or `finger [user]`");
  return 1;
}