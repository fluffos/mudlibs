#include <std.h>
#include <zolenia.h>
inherit OBJECT;
void create()
{
 ::create();
 set_name("portal");
 set_short("%^BOLD%^%^GREEN%^a glowing portal%^RESET%^");
 set_id( ({ "portal" }) );
 set_long("%^BOLD%^%^GREEN%^This is a swirling portal created by the sorcerers of Zolenia for warriors to attack the city of Roston.  Type <leap portal> to use the portal.%^RESET%^");
 set_prevent_get("The portal is not real!");
}
 
void init() {
    ::init();
    add_action("cmd_leap", "leap");
}
int cmd_leap(string str)
{
    if (!str || str=="") 
    {
        notify_fail("Leap where?\n");
        return 0;
    }
    if (str!="portal")
    {
        notify_fail("You cannot do that.\n");
        return 0;
    }
        write("You leap into the the portal!");
        say(this_player()->query_cap_name()+" leaps into the portal!");
        this_player()->move_player("/d/roston/rooms/roston", "into the
portal.");
        say(this_player()->query_cap_name()+" appears in a flash of light!");

    return 1;
}

