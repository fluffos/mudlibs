// /bin/pub/_cost.c
// Show stat etc. costs even if you're not in guild.
// Coded by Graah 7-Jul-97

#include <std_lib>
#include <areas.h>

nomask int
cost_cmd(string str)
{
    // Could probably call lib/guild...
    if ((int)this_player()->query_level() < 25)
	return (int)(AREA_TRISTEZA + "adv_guild/adv_guild")->cost_cmd();
    return (int)(AREA_TRISTEZA + "rooms/lords_guild")->cost();
}
