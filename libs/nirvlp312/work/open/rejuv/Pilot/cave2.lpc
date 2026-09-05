#include <lib.h>
inherit ROOM;

void
create()
{
    ::create();
    set_short("Newbie Entrance");
    set_long("\
This is the entrance to Scathe's House of Newbie Horrors\n\
Procede south if you are level 5 and under, otherwise,\n\
keep going down......\n");
    set_exits(([
        "up":   "/players/scathe/cave/entry",
        "down": "/players/scathe/cave/caved",
        "south":this_object(),
        ]));
    set_light(1);
}

mixed
south(string arg)
{
    if ((int) this_player()->query_level() > 5) {
        write("I said level 5 or lower!\n");
        return 1;
    }
    return "/players/scathe/cave/cave3";
}
