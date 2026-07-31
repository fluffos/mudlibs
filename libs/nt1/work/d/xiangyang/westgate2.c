// Room: /d/xiangyang/westgate2.c
// Date: Jan. 8 1999 by Winder

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "白虎外门");
	set("long", @LONG
这里是襄阳城的西城门，只见城门上方是三个大字“白虎门”。近年
来蒙古屡次侵犯襄阳城，故这儿把守相当严密，一些官兵们正在盘查要离
襄阳城的人，两边是很大的草地。
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"east"  : __DIR__"westgate1",
        "west" : "/d/bianliang/yidao1",
	]));
	set("objects", ([
                __DIR__"npc/pi"   : 1,
                __DIR__"npc/bing"   : 1,
	]));
	setup();
 //         replace_program(ROOM);
}

