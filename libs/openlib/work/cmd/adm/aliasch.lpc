// aliasch.c:  Create local aliases for intermud channels
//
// Created by Tim 18 Jul 1996
//
#include <command.h>
#include <daemons.h>

int
main(string args)
{
  string local, remote;

  if( !args || sscanf(args, "%s %s", local, remote) != 2 )
    return notify_fail("usage: aliasch <local alias> <remote name>\n");

  CHAT_D->set_alias(local, remote);

  message("system", "Remote channel name '" + remote +"' will now map to "
	  "local channel '" + local +"'\n", this_player());
  return 1;
}
