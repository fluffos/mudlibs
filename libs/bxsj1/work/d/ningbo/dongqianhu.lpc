// Room: /u/beyond/ningbo/dongqianhu.c 东前湖
// Beyond make 1997.6.8
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "东钱湖");
	set("long", @LONG
你走在一条青石路上，两旁是一片茂密的柳树林，头上小喜鹊唧唧喳喳的
叫个不停。一阵微风吹过，使你感觉到一股潮湿的空气扑面而来，这时你已走
到了东钱湖畔，只见水光空朦，四周山色如黛，湖光山色瑰丽多姿。几条小舟
泛舟湖上，使你觉得更有诗情画意。
LONG
	);
	set("outdoors", "宁波");
	set("exits",([
		"west" : __DIR__"ningbo",
		"north" : __DIR__"xikou",
		"southwest" : __DIR__"kedian",
		"south" : __DIR__"xuedoushan",
	]));
	setup();
}
