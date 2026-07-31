// Room: banfang.c

inherit ROOM;

void create()
{
	set("short", HIY"密室"NOR"");
	set("long", @LONG
这里是朱府的密室，十分隐蔽。
LONG
	);
	set("exits", ([
		"southeast" : __DIR__"room3",
		"southwest" : __DIR__"room4",
	]));
	set("objects", ([
		__DIR__"npc/zongguan": 1,
	]));
	setup();
}
#include "/d/fuben/room_fb.h"