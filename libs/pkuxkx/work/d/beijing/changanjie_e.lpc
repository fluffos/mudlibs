// Room: /d/beijing/changanjie_e.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"东长安街"NOR);
	set("long",
CYN"这是繁华热闹的长安街，大街北面就是守卫森严的紫禁城南门天安门了。这
里时常有巡逻的侍卫盘查过路的行人。大街两边是各种店铺，你看的眼都花了。\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
                "east"  : __DIR__"chongwenmen",
		"west"  : __DIR__"changanjie_e2",
//		"southwest" : __DIR__"rongbaozhai",
]));

	set("outdoors", "beijing");
	setup();
	replace_program(ROOM);
}
