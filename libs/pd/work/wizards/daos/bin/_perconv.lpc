#include <std.h>

inherit DAEMON;

int cmd_perconv()
{
    int perc;

    perc = to_int(100 * this_player()->query_hp() / this_player()->query_max_hp());

    write(""+perc +"%");

    return 1;
} 
