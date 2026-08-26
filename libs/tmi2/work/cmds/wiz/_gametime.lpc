// _gametime.c
// Returns the time and date in game units not in real time.
// Moby, 6-29-93

#include <mudlib.h>
#include <daemons.h>

inherit DAEMON ;

int cmd_gametime() {
	write (WEATHER_D->query_game_time()+"\n") ;
	return 1 ;
}

int help() {
        write("Usage: gametime\n\n"+@HELP
This command returns the date and time within the mud.
HELP
                );
        return 1;
}
