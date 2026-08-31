#include <std.h>
#include <vampq.h>

inherit ROOM;

void create()
{
    object ob;
    ::create();
    set_properties(([  "no bump" : 1, "light" : 2, "no scry" : 1, "outdoors" : 1, "night light" : 0 ]));
    set("short", "Outdoors");
    set("long", "%^RESET%^%^ORANGE%^The door heading back to the %^BOLD%^%^WHITE%^'%^RED%^Hall of mirrors%^WHITE%^'%^RESET%^%^ORANGE%^ has closed and faded away. The %^BOLD%^%^ORANGE%^sun shines brightly%^RESET%^%^ORANGE%^ to the north, however here it is quite shaded and protecting you from it's harmful rays. On the ground a few %^BOLD%^%^BLACK%^ashes%^RESET%^%^ORANGE%^ lay scatterd and some still even %^BOLD%^%^BLACK%^smoking%^RESET%^%^ORANGE%^.%^RESET%^.\n");
    set_smell("default", "%^BOLD%^%^BLACK%^Fresh ash enlightens the senses%^RESET%^.");
	set_exits( ([ "north" : VR"od_2" ]) );
	}

void reset() {
    if(!present("sign"))
        new(VO"od_sign")->move(this_object());
}
