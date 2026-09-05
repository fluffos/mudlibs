// Modified by iszt@pkuxkx, 2007-04-20

#include <ansi.h>

inherit ROOM;

void create ()
{
	set("short",HIC"西街"NOR);
	set("outdoors","xiangyang");
	set("long",YEL @LONG
这里是襄阳西街。兵荒马乱的年月，这里早失去了往日的繁华。南边是一座
威严的宅子，门口守军来回巡逻，原来这就是襄阳守军的帅府，郭靖临时在这里
调兵谴将，发号施令。帅府如果失陷，襄阳也就不保了。
LONG NOR);
	set("exits", ([
		"north" : __DIR__"dangpu",
		"west" : __DIR__"xywest3",
		"east" : __DIR__"xywest1",
		"south" : __DIR__"sfgate",
	]));
	setup();
	replace_program(ROOM);
}