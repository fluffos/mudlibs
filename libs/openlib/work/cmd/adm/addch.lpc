/*  -*- LPC -*-  */
#include <command.h>
#include <daemons.h>

#define USAGE "usage: addch <channelname> (<descrip>) [guild] <min level>\n"

int
main(string str)
{
  string name, desc, guild;
  int lev;

  if(!str)
    return notify_fail(USAGE);

  if(sscanf(str, "%s (%s) %s %d", name, desc, guild, lev) != 4 &&
     sscanf(str, "%s (%s) %d", name, desc, lev) != 3)
    return notify_fail(USAGE);


  if(CHAT_D->add_channel(name, desc, lev, guild)) {
    printf("Channel %s added\n", name);
    return 1;
  } else {
    write("Failed.\n");
    return 1;
  }
}
