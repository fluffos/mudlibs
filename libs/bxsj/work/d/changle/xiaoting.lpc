// Room: /d/changle/dating.c
// River 2003.2.26
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIG"小厅"NOR);
	set("long", @long
这是帮主及总管商讨机密大事的所在，正中是一张太师椅，门上吊着半旧
的红绸软帘。墙上附庸风雅地挂着几张山水字画，一望可知均是俗手之作。窗
前几盆菊花倒是十分繁茂。
long
	);

	set("exits", ([
                "east" : __DIR__"huayuan",
                "north" : __DIR__"woshi",
                "south" : __DIR__"zoulang4",
	]));

	set("objects", ([
		__DIR__"npc/bei" : 2,
		__DIR__"npc/mi": 1,
	]));

	setup();
}
