inherit ROOM;
#include "/d/parties/public/change_name.h"
void init()
{
    add_action("do_gua","gua");
    add_action("do_gua","guashang");
    add_action("do_zhai","zhai");
}
void create()
{
	set("short", "卧房");
	set("long", @LONG
这是一间卧房，放置了很多床铺。你可以在这里休息(sleep)一会。
LONG);

	set("sleep_room", "1");
	set("no_fight", "1");
	set("exits", ([
		"east" : __DIR__"biguanchu",
	]));
    set("no_reset",1);
    set("no_clean_up", 1);
	setup();
}

