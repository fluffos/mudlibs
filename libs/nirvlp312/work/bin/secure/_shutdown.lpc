/* 08/03/06 Earwax */
/* Basically just daemonized what was in the wiz soul */

#include "/sys/security.h"

nomask status cmd_shutdown(string arg)
{
  int minutes;

  if ((int)this_player()->query_level() < SHUTDOWN)
    return 0;

  if (!arg)
    minutes = 5;
  else if (arg == "now")
    shutdown();
  else
  {
    if (sscanf(arg, ""+"%d", minutes) != 1)
    {
      write("SHUTDOWN: You must supply a time (in minutes or 'now').\n");
      return 1;
    }
  }

  shout(sprintf("!Game is being shut down by %s in %d minutes!\n", 
    (string)this_player()->query_name(), minutes));
  printf("Game will shut down in %d minutes.\n", minutes);
  log_file("SHUTDOWN", sprintf("%s: Game is being shut down by %s in %d minutes.\n",
    ctime(), capitalize((string)this_player()->query_real_name()), minutes));
  "/obj/shut"->shut(minutes);
  return 1;
}
