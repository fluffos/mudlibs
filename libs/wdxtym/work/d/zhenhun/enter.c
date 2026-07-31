#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{	set("outdoors","zhenhun");
	set("short", "镇魂塔入口");
	set("long","这里是画饼一族镇压墓地的地方。\n"
	"北走选择合适区域。");
	set("exits", ([
		"north" : "d/zhenhun/chuji/chuji",
	]));
	setup();
}