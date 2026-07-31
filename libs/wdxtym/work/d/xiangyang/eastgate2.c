// Room: /d/xiangyang/eastgate2.c
inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "青龙外门");
	set("long", 
"这里是襄阳城的东城门，只见城门上方是三个大字。"HIG"
		      青龙门
"NOR"\n"
"近年来蒙古屡次侵犯襄阳城，故这儿把守相当严密，一些官兵
们正在盘查要离襄阳城的人。两边是很大的草地。\n"
 );
	set("outdoors", "xiangyang");

	set("exits", ([
		"west"  : __DIR__"eastgate1",
	]));
	set("objects", ([
		__DIR__"npc/pi"   : 1,
		__DIR__"npc/bing" : 2,
	]));
	setup();
}

