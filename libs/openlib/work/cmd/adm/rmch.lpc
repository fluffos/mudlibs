/*  -*- LPC -*-  */
#include <command.h>
#include <daemons.h>

#define USAGE "usage: rmch <channelname>\n"

int
main(string str)
{
  if(!str)
    return notify_fail(USAGE);

  if(CHAT_D->remove_channel(str)) {
    printf("Channel %s removed.\n", str);
    return 1;
  } else {
    write("Failed.\n");
    return 1;
  }
}
