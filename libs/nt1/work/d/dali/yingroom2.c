// Code of ShenZhou
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "泥潭小屋");
	set("long", @LONG
墙里是个院子，分为两半，左一半是实土，右一半却是水塘。内堂前
是个月洞，仍无门扉。只见当前摆了一张长桌，上面放了七盏油灯，排成
天罡北斗之形。地下乱七八糟地摆了一根根的无数竹片，那些竹片都是长
约四寸，阔约二分，似乎是计数用的算子。
LONG );
	set("exits", ([
		"out" : __DIR__"maze2",
        ]));
	set("objects", ([
                CLASS_D("dali") + "/yinggu" : 1,
		]) );
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
}
