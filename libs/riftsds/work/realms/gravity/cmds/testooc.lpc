//  /bin/user/_ooc.c
//  created by Gravity
//  allows players to communicate out-of-character

#include <std.h>
#include <daemons.h>

int cmd_ooc(string str)
{
  if (!str || str == "")
  {
    return notify_fail("OOC what?\n");
  }

  write("You %^BOLD%^%^RED%^[%^RESET%^BOLD%^OOC%^RED%^]%^RESET%^ %^BOLD%^WHITE%^" + str + "%^RESET%^");
  say(this_player()->query_cap_name() + " %^BOLD%^%^RED%^[%^RESET%^BOLD%^OOC%^RED%^]%^RESET%^ %^BOLD%^WHITE%^" + str + "%^RESET%^");

  return 1;
}

int help()
{
  write("Command: OOC \nSyntax: ooc <message>\n"
        "       This command allows you to send a message out-of-character. \n"
		"       All in-room, but out of game communication must be done \n"
		"		using this command. Everyone can see this text. \n");
  return 1;
}