//      Hacked out of biography.(created by Descartes of Borg 30 march 1993)

#include <std.h>

inherit DAEMON;

int cmd_lastkiller(string str) {
    int max;
    mixed *deaths;

    if(!(deaths=(mixed *)this_player()->query_deaths()) ||
      !(max = sizeof(deaths)))
        write("You have never experienced the pain of death.");
    else
        write("You were last killed by "+capitalize(deaths[max-1][0])+"");
    return 1;
}

int help()
{
  write( @EndText
Syntax: lastkiller
Effect: gives you the name of the last creature or player who killed you.
EndText
  );
  return 1;
}
