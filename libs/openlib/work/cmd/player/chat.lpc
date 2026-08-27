/*  -*- LPC -*-  */
#include <command.h>
#include <daemons.h>

#define USAGE "usage: chat <chan> <message>\n" \
              "       chat emote <chan> <message>\n" \
              "       chat feeling <chan> <feeling>\n"\
              "       chat list <chan>[@<mud>]\n"

int
main(string str)
{
  notify_fail(USAGE);

  if(!str || str == "")
    return 0;

  return (int) CHAT_D->chat(str);
}
