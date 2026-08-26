// The orginal TIMES command, Qixx@Hero
// Help added by Pallado (93-02-05)
//
#include <mudlib.h>
#include <daemons.h>

inherit DAEMON;

int cmd_commands(string arg) {
	CMD_D -> show_cmds(arg) ;
    return 1;
}

int help()
{
  write( ""+
"Syntax: commands\n"+
"Effect: Lists the commands defined in each cmds directory.\n"+
  "" );
  return 1;
}
