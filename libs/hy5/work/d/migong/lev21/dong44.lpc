
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"暗黑教会"NOR);
	set("long", HIM @LONG
这里是空荡荡的暗黑教会的走廊,四周的墙壁尽然是
用人骨做成，在些人骨有小孩的，妇女的。而且还在不
停的颤抖。处处都允满了鬼异可怕的声音。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);
	set("exits", ([
		"southwest" : __DIR__"dong45",
                "northeast" : __DIR__"dong3"+(random(6)+4),
		"westsouth" : __DIR__"dong42",
                "eastnorth" : __DIR__"dong3"+(random(9)+1),
	]));
if (random(3)==0)
	set("exits", ([
		"south" : __DIR__"dong4"+(random(6)+1),
                "north" : __DIR__"dong3"+(random(6)+4),
		"west" : __DIR__"dong4"+(random(6)+1),
                "east" : __DIR__"dong3"+(random(6)+4),
	]));
if (random(3)==0)
	set("exits", ([
		"east" : __DIR__"dong45",
                "west" : __DIR__"dong3"+(random(6)+4),
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

