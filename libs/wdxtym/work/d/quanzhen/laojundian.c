// laojundian.c 老君殿
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "老君殿");
	set("long", @LONG
这里是供奉太上老君的大殿。殿的正中塑着老君的塑像，老君骑
在青牛上，正临云而去。两旁塑着两个童子，都栩栩如生。殿中的地
都是以青砖一块块的铺成，打扫得一尘不染。
LONG
	);
	set("exits", ([
		"east" : __DIR__"houtang1",
		"south" : __DIR__"tongtiandian",
		"north" : __DIR__"yuanshidian",
		"west" : __DIR__"datang3",
	]));
	set("objects", ([
		CLASS_D("quanzhen") + "/qiu" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	object guarder;

	if (dir != "east" )
		return 1;

	if(! objectp(guarder = present("qiu chuji", this_object())))
		return 1;

	return guarder->permit_pass(me, dir);
}
