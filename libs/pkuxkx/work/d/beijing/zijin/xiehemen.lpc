#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"协和门"NOR);
	set("long",
HIC"这扇门平时都紧紧关闭着，只有在早中晚三刻才打开，供卫士们
换班使用。\n"NOR
	);

	set("exits", ([
		"east" : __DIR__"wenhuamen",
        "west" : __DIR__"guang2",
	]));
	set("outdoors","beijing");

	setup();
	replace_program(ROOM);
}
